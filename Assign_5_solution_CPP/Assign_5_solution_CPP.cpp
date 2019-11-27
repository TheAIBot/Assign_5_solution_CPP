// Assign_5_solution_CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <limits>
#include <string>
#include <sstream>
#include <cctype>
#include <cstdint>

template<typename T>
struct span
{
public:
	T* array;
	int length;

	span(T* arr, int len) : array(arr), length(len)
	{
	}

	span(T* arr, int len, bool nothing) : array(arr), length(len)
	{
	}

	span(int len) : array(new T[len]()), length(len)
	{
	}

	span() : array(nullptr), length(0)
	{
	}

	span<T> slice(int startIndex, int len) const
	{
		return span<T>(&(array[startIndex]), len);
	}

	span<T> slice(int startIndex) const
	{
		return span<T>(&(array[startIndex]), length - startIndex);
	}

	void copyTo(span<T>& other) const
	{
		std::copy(array, array + length, other.array);
	}

	T& operator[](int index) const
	{
		return array[index];
	}

	int* begin() const
	{
		return array;
	}

	int* end() const
	{
		return array + length;
	}
};

struct bitIndices
{
public:
	int byteIndex;
	int bitIndex;

	bitIndices(int index)
	{
		byteIndex = index >> 3;
		bitIndex = index & 0b0000'0111;
	}
};

struct bitArraySlim
{
private:
	uint8_t* array;
	int arrayLength;
public:
	int length;

	bitArraySlim(int len)
	{
		length = len;
		arrayLength = (length / 8) + 1;
		array = new uint8_t[arrayLength]();
	}

	void copyTo(bitArraySlim& other) const
	{
		std::copy(array, array + arrayLength, other.array);
	}

	int size() const
	{
		return length;
	}

	int getActualSize() const
	{
		return arrayLength;
	}

	uint8_t operator[](int index) const
	{
		int byteIndex = index >> 3;
		int bitIndex = index & 0b0000'0111;

		return (array[byteIndex] >> bitIndex) & 1;
	}

	void set(int index, uint8_t value)
	{
		int byteIndex = index >> 3;
		int bitIndex = index & 0b0000'0111;

		array[byteIndex] |= value << bitIndex;
	}

	void forceSet(int index, uint8_t value)
	{
		int byteIndex = index >> 3;
		int bitIndex = index & 0b0000'0111;

		array[byteIndex] ^= (-value ^ array[byteIndex]) & (1 << bitIndex);
	}

	uint8_t* begin() const
	{
		return array;
	}

	uint8_t* end() const
	{
		return array + arrayLength;
	}

	~bitArraySlim()
	{
		delete[] array;
	}
};

struct SumsData
{
public:
	std::vector<int>* NewSums;
	std::vector<int>* Uniques;
	int Replications;

	SumsData(std::vector<int>* newSums, std::vector<int>* uniques) : NewSums(newSums), Uniques(uniques), Replications(newSums->size() - uniques->size())
	{
	}

	SumsData(std::vector<int>* newSums, std::vector<int>* uniques, int reps) : NewSums(newSums), Uniques(uniques), Replications(reps)
	{
	}
};

class BestSumsData
{
public:
	SumsData Data;
	int Number;

	BestSumsData() : Data(SumsData(nullptr, nullptr, std::numeric_limits<int>::min())), Number(-1)
	{
	}

	BestSumsData(int number, SumsData data) : Data(data), Number(number)
	{
	}
};

struct Result
{
	const int Number;
	const int NewNumber;

	Result(int number, int newNumber) : Number(number), NewNumber(newNumber)
	{
	}
};

struct PartialSumsData
{
public:
	std::unordered_set<int>* foundData;
	BestSumsData datas;
	int minuniques;
	int sumsCount;
	int created;
	int maxCreated;
	bitArraySlim* sums;

	PartialSumsData()
	{
	}
};

int BoolArrayTrueCount(bitArraySlim& array)
{
	int trueCount = 0;
	for (int i = 0; i < array.size(); i++)
	{
		trueCount += array[i];
	}

	return trueCount;
}

template<typename T>
int bitsCount()
{
	return sizeof(T) * 8;
}

bitArraySlim* CreatePartialSums(span<int> numbers, bitArraySlim& currSums)
{
	int maxSum = currSums.size();
	for (int i = 0; i < numbers.length; i++)
	{
		maxSum += numbers[i];
	}

	bitArraySlim* newSums = new bitArraySlim(maxSum);
	currSums.copyTo(*newSums);

	int prevMaxSum = currSums.size() - 1;
	for (int i = 0; i < numbers.length; i++)
	{
		int z = prevMaxSum;
		for (; z >= bitsCount<uint64_t>(); z -= (bitsCount<uint64_t>() - bitsCount<uint8_t>()))
		{
			bitIndices indicesFromSum(z);
			bitIndices indicesFromNewSum(z + numbers[i]);

			uint64_t* sumULongPtr = (uint64_t*)(newSums->begin() + indicesFromSum.byteIndex - sizeof(uint64_t) + 1);
			uint64_t* newSumULongPtr = (uint64_t*)(newSums->begin() + indicesFromNewSum.byteIndex - sizeof(uint64_t) + 1);

			uint64_t fromSum = ((*sumULongPtr) >> indicesFromSum.bitIndex) << indicesFromNewSum.bitIndex;

			*newSumULongPtr |= fromSum;

		}

		for (; z >= 0; z--)
		{
			newSums->set(z + numbers[i], (*newSums)[z]);
		}
		prevMaxSum += numbers[i];
	}

	return newSums;
}

SumsData FinishCreateSumsData(int number, bitArraySlim& currSums)
{
	std::vector<int>* newSums = new std::vector<int>();
	std::vector<int>* uniques = new std::vector<int>();

	for (int i = 0; i < currSums.size(); i++)
	{
		if (currSums[i] == 1)
		{
			int newSum = i + number;
			if (newSum >= currSums.size())
			{
				uniques->push_back(newSum);
			}
			else if (currSums[newSum] == 0)
			{
				uniques->push_back(newSum);
			}
			newSums->push_back(newSum);
		}
	}

	return SumsData(newSums, uniques);
}

void CreateAllSums(int number, bitArraySlim& currSums, PartialSumsData& data)
{
	span<int> dwa(1);
	dwa[0] = number;
	data.sums = CreatePartialSums(dwa, currSums);
	delete[] dwa.array;

	data.sumsCount = BoolArrayTrueCount(*data.sums);
}

void CreateAllSumsDatas(span<int> numbers, bitArraySlim& currSums, PartialSumsData& data)
{
	if (numbers.length > 1)
	{
		int midPoint = numbers.length / 2;
		span<int> firstPart = numbers.slice(0, midPoint);
		span<int> secondPart = numbers.slice(midPoint);

		if (data.created > data.maxCreated)
		{
			return;
		}

		bitArraySlim* secondPartSums = CreatePartialSums(secondPart, currSums);
		CreateAllSumsDatas(firstPart, *secondPartSums, data);
		delete secondPartSums;

		if (data.created > data.maxCreated)
		{
			return;
		}

		bitArraySlim* firstPartSums = CreatePartialSums(firstPart, currSums);
		CreateAllSumsDatas(secondPart, *firstPartSums, data);
		delete firstPartSums;
	}
	else
	{
		data.created++;

		int actualSumCount = BoolArrayTrueCount(currSums);
		if (data.sumsCount - actualSumCount > data.minuniques)
		{
			return;
		}

		int number = numbers[0];
		if (data.foundData->find(number) == data.foundData->end())
		{
			BestSumsData newData(number, FinishCreateSumsData(number, currSums));

			if (newData.Data.Replications > data.datas.Data.Replications ||
				(newData.Data.Replications == data.datas.Data.Replications &&
					newData.Number < data.datas.Number))
			{
				if (data.datas.Data.Uniques != nullptr)
				{
					delete data.datas.Data.Uniques;
					delete data.datas.Data.NewSums;
				}
				data.datas = newData;
			}

			if (data.sumsCount == -1)
			{
				CreateAllSums(number, currSums, data);
			}

			data.minuniques = std::min(data.minuniques, (int)data.datas.Data.Uniques->size());
		}
	}
}

int GetFirstReplicateIndex(span<int> numbers)
{
	int maxSum = 1;
	for (int i = 0; i < numbers.length; i++)
	{
		maxSum += numbers[i];
	}

	span<char> newSums(maxSum);
	newSums[0] = true;

	int prevMaxSum = 0;
	for (int i = 0; i < numbers.length; i++)
	{
		if (newSums[numbers[i]])
		{
			return i;
		}
		for (int z = prevMaxSum; z >= 0; z--)
		{
			newSums[z + numbers[i]] |= newSums[z];
		}
		prevMaxSum += numbers[i];
	}
	delete[] newSums.array;

	return numbers.length;
}

Result CreateCollisionAvoidanceArray(bitArraySlim& sums, BestSumsData bestData)
{
	SumsData sumData = bestData.Data;

	for (auto q = sumData.Uniques->begin(); q != sumData.Uniques->end(); q++)
	{
		int uniqueNumber = *q;
		sums.forceSet(uniqueNumber, 0);
	}

	for (int i = 1; i <= sums.size();)
	{
		bool foundObstacle = false;
		for (auto q = sumData.NewSums->begin(); q != sumData.NewSums->end(); q++)
		{
			int newSum = *q;

			int overlapIndex = newSum - (bestData.Number - i);
			int offset = 0;
			while (overlapIndex + offset < sums.size() && sums[overlapIndex + offset] == 1)
			{
				offset++;
			}

			i += offset;

			if (offset > 0)
			{
				foundObstacle = true;
				break;
			}
		}

		if (!foundObstacle)
		{
			return Result(bestData.Number, i);
		}
	}

	return Result(-1, -1);
}

Result Solve(span<int> numbers)
{
	std::sort(numbers.begin(), numbers.end());

	int maxCreated = GetFirstReplicateIndex(numbers);

	bitArraySlim* currSums = new bitArraySlim(1);
	currSums->forceSet(0, 1);

	PartialSumsData data;
	data.foundData = new std::unordered_set<int>();
	data.minuniques = std::numeric_limits<int>::max();
	data.sumsCount = -1;
	data.created = 0;
	data.maxCreated = maxCreated;

	CreateAllSumsDatas(numbers, *currSums, data);
	delete currSums;
	delete data.foundData;

	return CreateCollisionAvoidanceArray(*data.sums, data.datas);
}

int main()
{
	int numberCount;
	std::cin >> numberCount;

	std::cin >> std::ws;

	span<int> numbers(numberCount);

	std::string numbersAsString;
	std::getline(std::cin, numbersAsString);

	int index = 0;
	int stringIndex = 0;
	while (stringIndex < numbersAsString.size())
	{
		int digitCount = 0;
		while (digitCount + stringIndex < numbersAsString.size() && std::isdigit(numbersAsString[digitCount + stringIndex]))
		{
			digitCount++;
		}

		if (digitCount == numbersAsString.size())
		{
			break;
		}

		std::string numberAsString = numbersAsString.substr(stringIndex, digitCount);

		int number = std::stoi(numberAsString);
		numbers[index++] = number;

		stringIndex += digitCount;
		stringIndex++;
	}

	Result result = Solve(numbers);
	delete[] numbers.array;

	std::cout << result.Number << std::endl;
	std::cout << result.NewNumber << std::endl;
}