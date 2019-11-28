// Assign_5_solution_CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <nmmintrin.h>
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

int getByteIndex(int index)
{
	return index >> 3;
}

int getBitIndex(int index)
{
	return index & 0b0000'0111;
}

struct bitIndices
{
public:
	int byteIndex;
	int bitIndex;

	bitIndices(int index)
	{
		byteIndex = getByteIndex(index);
		bitIndex = getBitIndex(index);
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

struct PreSumsData
{
public:
	bitArraySlim* bitArray;
	int uniques;

	PreSumsData(bitArraySlim* bits, int uniqs)
	{
		bitArray = bits;
		uniques = uniqs;
	}

	PreSumsData()
	{
		bitArray = nullptr;
		uniques = std::numeric_limits<int>::max();
	}

	SumsData ToSumsData(int number, int totalSums)
	{
		std::vector<int>* newSums = new std::vector<int>();
		std::vector<int>* uniqasdues = new std::vector<int>();

		newSums->reserve(totalSums);
		uniqasdues->reserve(uniques);

		for (int i = 0; i < bitArray->size(); i++)
		{
			if ((*bitArray)[i] == 1)
			{
				int newSum = i + number;
				if (newSum >= bitArray->size())
				{
					uniqasdues->push_back(newSum);
				}
				else if ((*bitArray)[newSum] == 0)
				{
					uniqasdues->push_back(newSum);
				}
				newSums->push_back(newSum);
			}
		}

		return SumsData(newSums, uniqasdues);
	}
};

class BestSumsData
{
public:
	PreSumsData Data;
	int Number;

	BestSumsData()
	{
		Data = PreSumsData();
		Number = -1;
	}

	BestSumsData(int number, PreSumsData data)
	{
		Data = data;
		Number = number;
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

template<typename T>
int bitsCount()
{
	return sizeof(T) * 8;
}

int BoolArrayTrueCount(bitArraySlim& array)
{
	int trueCount = 0;
	int i = 0;

	uint64_t* u64intArray = (uint64_t*)(array.begin());
	for (; i < array.size() - bitsCount<uint64_t>(); i += bitsCount<uint64_t>())
	{
		//trueCount += __builtin_popcountll(u64intArray[i / bitsCount<uint64_t>()]);
		trueCount += _mm_popcnt_u64(u64intArray[i / bitsCount<uint64_t>()]);
	}

	uint32_t* u32intArray = (uint32_t*)(array.begin());
	for (; i < array.size() - bitsCount<uint32_t>(); i += bitsCount<uint32_t>())
	{
		//trueCount += __builtin_popcount(u32intArray[i / bitsCount<uint32_t>()]);
		trueCount += _mm_popcnt_u64(u32intArray[i / bitsCount<uint32_t>()]);
	}

	for (; i < array.size(); i++)
	{
		trueCount += array[i];
	}

	return trueCount;
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
		if (z >= bitsCount<uint64_t>() * 2)
		{
			z -= bitsCount<uint64_t>();

			bitIndices currSumIndices(z);
			bitIndices newSumIndices(z + numbers[i]);

			uint64_t nextSet = *((uint64_t*)(newSums->begin() + currSumIndices.byteIndex + 1));
			do
			{
				uint64_t* newSumULongPtr = (uint64_t*)(newSums->begin() + newSumIndices.byteIndex + 1);
				newSumIndices.byteIndex -= (sizeof(uint64_t) - sizeof(uint8_t));
				currSumIndices.byteIndex -= (sizeof(uint64_t) - sizeof(uint8_t));

				uint64_t next = *((uint64_t*)(newSums->begin() + currSumIndices.byteIndex + 1));
				uint64_t fromSum = ((nextSet) >> currSumIndices.bitIndex) << newSumIndices.bitIndex;
				nextSet = next;

				*newSumULongPtr |= fromSum;

				z -= (bitsCount<uint64_t>() - bitsCount<uint8_t>());
			} while (z >= 64);

			uint64_t* newSumULongPtr = (uint64_t*)(newSums->begin() + newSumIndices.byteIndex + 1);
			uint64_t fromSum = ((nextSet) >> currSumIndices.bitIndex) << newSumIndices.bitIndex;
			*newSumULongPtr |= fromSum;

			z -= (bitsCount<uint64_t>() - bitsCount<uint8_t>());
			z += bitsCount<uint64_t>();
		}

		for (; z >= 0; z--)
		{
			newSums->set(z + numbers[i], (*newSums)[z]);
		}
		prevMaxSum += numbers[i];
	}

	return newSums;
}

void CreateAllSums(int number, bitArraySlim& currSums, PartialSumsData& data)
{
	span<int> dwa(1);
	dwa[0] = number;
	data.sums = CreatePartialSums(dwa, currSums);
	delete[] dwa.array;

	data.sumsCount = BoolArrayTrueCount(*data.sums);
}

PreSumsData FinishCreateSumsData(int number, bitArraySlim& currSums, PartialSumsData& data)
{
	if (data.sumsCount != -1)
	{
		int currSumsCount = BoolArrayTrueCount(currSums);
		int uniques = data.sumsCount - currSumsCount;
		return PreSumsData(&currSums, uniques);
	}

	if (data.sumsCount == -1)
	{
		CreateAllSums(number, currSums, data);
	}

	int uniques = 0;

	for (int i = 0; i < currSums.size(); i++)
	{
		if (currSums[i] == 1)
		{
			int newSum = i + number;
			if (newSum >= currSums.size())
			{
				uniques++;
			}
			else if (currSums[newSum] == 0)
			{
				uniques++;
			}
		}
	}

	return PreSumsData(&currSums, uniques);
}

bool CreateAllSumsDatas(span<int> numbers, bitArraySlim& currSums, PartialSumsData& data)
{
	if (numbers.length > 1)
	{
		int midPoint = numbers.length / 2;
		span<int> firstPart = numbers.slice(0, midPoint);
		span<int> secondPart = numbers.slice(midPoint);

		if (data.created > data.maxCreated)
		{
			return false;
		}

		bitArraySlim* secondPartSums = CreatePartialSums(secondPart, currSums);
		if (!CreateAllSumsDatas(firstPart, *secondPartSums, data))
		{
			delete secondPartSums;
		}

		if (data.created > data.maxCreated)
		{
			return false;
		}

		bitArraySlim* firstPartSums = CreatePartialSums(firstPart, currSums);
		if (!CreateAllSumsDatas(secondPart, *firstPartSums, data))
		{
			delete firstPartSums;
		}
	}
	else
	{
		data.created++;

		int actualSumCount = BoolArrayTrueCount(currSums);
		if (data.sumsCount - actualSumCount > data.minuniques)
		{
			return false;
		}

		int number = numbers[0];
		if (data.foundData->find(number) == data.foundData->end())
		{
			BestSumsData newData(number, FinishCreateSumsData(number, currSums, data));
			data.minuniques = std::min(data.minuniques, (int)data.datas.Data.uniques);

			if (newData.Data.uniques < data.datas.Data.uniques ||
				(newData.Data.uniques == data.datas.Data.uniques &&
					newData.Number < data.datas.Number))
			{
				if (data.datas.Data.bitArray != nullptr)
				{
					delete data.datas.Data.bitArray;
				}
				data.datas = newData;
				return true;
			}
		}
	}
	return false;
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

Result CreateCollisionAvoidanceArray(bitArraySlim& sums, BestSumsData bestData, PartialSumsData& data)
{
	SumsData sumData = bestData.Data.ToSumsData(bestData.Number, data.sumsCount);

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

	return CreateCollisionAvoidanceArray(*data.sums, data.datas, data);
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