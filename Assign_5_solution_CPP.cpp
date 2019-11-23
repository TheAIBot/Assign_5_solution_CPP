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

template<typename T>
struct span
{
public:
	T* array;
	int length;

	span(T* arr, int len) : array(arr), length(len)
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

struct SumsData
{
public:
	std::vector<int>* NewSums;
	std::unordered_set<int>* Uniques;
	int Replications;

	SumsData(std::vector<int>* newSums, std::unordered_set<int>* uniques) : NewSums(newSums), Uniques(uniques), Replications(newSums->size() - uniques->size())
	{
	}

	SumsData(std::vector<int>* newSums, std::unordered_set<int>* uniques, int reps) : NewSums(newSums), Uniques(uniques), Replications(reps)
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
	span<int> sums;

	PartialSumsData()
	{
	}
};

int BoolArrayTrueCount(span<char> array)
{
	int trueCount = 0;
	for (int i = 0; i < array.length; i++)
	{
		trueCount += array[i];
	}

	return trueCount;
}

span<char> CreatePartialSums(span<int> numbers, span<char> currSums)
{
	int maxSum = currSums.length;
	for (int i = 0; i < numbers.length; i++)
	{
		maxSum += numbers[i];
	}

	span<char> newSums(maxSum);
	currSums.copyTo(newSums);

	int prevMaxSum = currSums.length - 1;
	for (int i = 0; i < numbers.length; i++)
	{
		for (int z = prevMaxSum; z >= 0; z--)
		{
			newSums[z + numbers[i]] |= newSums[z];
		}
		prevMaxSum += numbers[i];
	}

	return newSums;
}

SumsData FinishCreateSumsData(int number, span<char> currSums)
{
	std::vector<int>* newSums = new std::vector<int>();
	std::unordered_set<int>* uniques = new std::unordered_set<int>();

	for (int i = 0; i < currSums.length; i++)
	{
		if (currSums[i] == 1)
		{
			int newSum = i + number;
			if (newSum >= currSums.length)
			{
				uniques->insert(newSum);
			}
			else if (currSums[newSum] == 0)
			{
				uniques->insert(newSum);
			}
			newSums->push_back(newSum);
		}
	}

	return SumsData(newSums, uniques);
}

void CreateAllSums(int number, span<char> currSums, PartialSumsData& data)
{
	span<int> dwa(1);
	dwa[0] = number;
	span<char> allSums = CreatePartialSums(dwa, currSums);
	delete[] dwa.array;

	data.sumsCount = BoolArrayTrueCount(allSums);

	data.sums = span<int>(data.sumsCount - 1);
	int sumsIndex = 0;
	for (int i = 1; i < allSums.length; i++)
	{
		if (allSums[i] == 1)
		{
			data.sums[sumsIndex++] = i;
		}
	}
}

void CreateAllSumsDatas(span<int> numbers, span<char> currSums, PartialSumsData& data)
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

		span<char> secondPartSums = CreatePartialSums(secondPart, currSums);
		CreateAllSumsDatas(firstPart, secondPartSums, data);
		delete[] secondPartSums.array;

		if (data.created > data.maxCreated)
		{
			return;
		}

		span<char> firstPartSums = CreatePartialSums(firstPart, currSums);
		CreateAllSumsDatas(secondPart, firstPartSums, data);
		delete[] firstPartSums.array;
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

Result CreateCollisionAvoidanceArray(span<int> sortedSums, BestSumsData bestData)
{
	SumsData sumData = bestData.Data;

	int highestSum = sortedSums[sortedSums.length - 1] + 1;
	std::unordered_set<int> filteredSums(sortedSums.begin(), sortedSums.end());

	for (auto q = sumData.Uniques->begin(); q != sumData.Uniques->end(); q++)
	{
		int uniqueNumber = *q;
		filteredSums.erase(uniqueNumber);
	}

	for (int i = 1; i <= highestSum; i++)
	{
		bool foundObstacle = false;
		for (auto q = sumData.NewSums->begin(); q != sumData.NewSums->end(); q++)
		{
			int newSum = *q;

			int overlapIndex = newSum - (bestData.Number - i);
			if (filteredSums.find(overlapIndex) != filteredSums.end())
			{
				foundObstacle = true;
				break;
			}

			int offset = 0;
			while (filteredSums.find(overlapIndex + offset) != filteredSums.end())
			{
				offset++;
			}

			i += offset;
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

	span<char> currSums = span<char>(1);
	currSums[0] = 1;

	PartialSumsData data;
	data.foundData = new std::unordered_set<int>();
	data.minuniques = std::numeric_limits<int>::max();
	data.sumsCount = -1;
	data.created = 0;
	data.maxCreated = maxCreated;

	CreateAllSumsDatas(numbers, currSums, data);
	delete[] currSums.array;
	delete data.foundData;

	return CreateCollisionAvoidanceArray(data.sums, data.datas);
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