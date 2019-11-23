// Assign_5_solution_CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <limits>
#include <string>
#include <sstream>
#include <cctype>>

template<typename T>
struct span
{
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

	span<T> slice(int startIndex, int len)
	{
		return span<T>(&(array[startIndex]), len);
	}

	span<T> slice(int startIndex)
	{
		return span<T>(&(array[startIndex]), length - startIndex);
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
		trueCount += array.array[i];
	}

	return trueCount;
}

span<char> CreatePartialSums(span<int> numbers, span<char> currSums)
{
	int maxSum = currSums.length;
	for (int i = 0; i < numbers.length; i++)
	{
		maxSum += numbers.array[i];
	}

	span<char> newSums(maxSum);
	std::copy(currSums.array, currSums.array + currSums.length, newSums.array);

	int prevMaxSum = currSums.length - 1;
	for (int i = 0; i < numbers.length; i++)
	{
		for (int z = prevMaxSum; z >= 0; z--)
		{
			newSums.array[z + numbers.array[i]] |= newSums.array[z];
		}
		prevMaxSum += numbers.array[i];
	}

	return newSums;
}

SumsData FinishCreateSumsData(int number, span<char> currSums)
{
	std::vector<int>* newSums = new std::vector<int>();
	std::unordered_set<int>* uniques = new std::unordered_set<int>();

	for (int i = 0; i < currSums.length; i++)
	{
		if (currSums.array[i] == 1)
		{
			int newSum = i + number;
			if (newSum >= currSums.length)
			{
				uniques->insert(newSum);
			}
			else if (currSums.array[newSum] == 0)
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
	dwa.array[0] = number;

	span<char> allSums = CreatePartialSums(dwa, currSums);
	data.sumsCount = BoolArrayTrueCount(allSums);

	data.sums = span<int>(data.sumsCount - 1);
	int sumsIndex = 0;
	for (int i = 1; i < allSums.length; i++)
	{
		if (allSums.array[i] == 1)
		{
			data.sums.array[sumsIndex++] = i;
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

		if (data.created > data.maxCreated)
		{
			return;
		}

		span<char> firstPartSums = CreatePartialSums(firstPart, currSums);
		CreateAllSumsDatas(secondPart, firstPartSums, data);
	}
	else
	{
		data.created++;

		int actualSumCount = BoolArrayTrueCount(currSums);
		if (data.sumsCount - actualSumCount > data.minuniques)
		{
			return;
		}

		int number = numbers.array[0];
		if (data.foundData->find(number) == data.foundData->end())
		{
			BestSumsData newData(number, FinishCreateSumsData(number, currSums));

			if (newData.Data.Replications > data.datas.Data.Replications ||
				(newData.Data.Replications == data.datas.Data.Replications &&
					newData.Number < data.datas.Number))
			{
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
		maxSum += numbers.array[i];
	}

	span<char> newSums(maxSum);
	newSums.array[0] = true;

	int prevMaxSum = 0;
	for (int i = 0; i < numbers.length; i++)
	{
		if (newSums.array[numbers.array[i]])
		{
			return i;
		}
		for (int z = prevMaxSum; z >= 0; z--)
		{
			newSums.array[z + numbers.array[i]] |= newSums.array[z];
		}
		prevMaxSum += numbers.array[i];
	}

	return numbers.length;
}

Result CreateCollisionAvoidanceArray(span<int> sortedSums, BestSumsData bestData)
{
	SumsData sumData = bestData.Data;

	int highestSum = sortedSums.array[sortedSums.length - 1] + 1;
	std::unordered_set<int> filteredSums;

	for (int i = 0; i < sortedSums.length; i++)
	{
		int sum = sortedSums.array[i];
		if (sumData.Uniques->find(sum) != sumData.Uniques->end())
		{
			continue;
		}
		filteredSums.insert(sum);
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
	std::vector<int> temp;
	for (int i = 0; i < numbers.length; i++)
	{
		temp.push_back(numbers.array[i]);
	}
	std::sort(temp.begin(), temp.end());
	for (int i = 0; i < numbers.length; i++)
	{
		numbers.array[i] = temp[i];
	}

	int maxCreated = GetFirstReplicateIndex(numbers);

	span<char> currSums = span<char>(1);
	currSums.array[0] = 1;

	PartialSumsData data;
	data.foundData = new std::unordered_set<int>();
	data.minuniques = std::numeric_limits<int>::max();
	data.sumsCount = -1;
	data.created = 0;
	data.maxCreated = maxCreated;

	CreateAllSumsDatas(numbers, currSums, data);

	return CreateCollisionAvoidanceArray(data.sums, data.datas);
}

int main()
{
	int numberCount;
	std::cin >> numberCount;

	std::cin >> std::ws;

	span<int> numbers(numberCount);
	std::vector<int> temp;

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
		numbers.array[index++] = number;
		temp.push_back(number);

		stringIndex += digitCount;
		stringIndex++;
	}

	//int[] numbers = new int[] { 7, 45, 2, 6, 2, 3, 8, 6, 2, 8, 45, 2, 6, 2, 3, 8, 6, 2, 8, 2, 6, 2, 56, 23, 65, 23, 45, 2, 6, 2, 3, 8, 6, 2, 8, 45, 2, 6, 2, 3, 8, 6, 2, 8, 2, 6, 2, 56, 23, 65, 23, 45, 2, 6, 2, 3, 8, 6, 2, 8, 45, 2, 6, 2, 3, 8, 6, 2, 8, 2, 6, 2, 56, 23, 65, 45, 2, 6, 2, 3, 8, 6, 2, 8, 45, 2, 6, 2, 3, 8, 6, 2, 8, 2, 6, 2, 56, 23, 65, 23, 45, 2, 6, 2, 3, 8, 6, 2, 8, 45, 2, 6, 2, 3, 8, 6, 2, 8, 2, 6, 2, 56, 23, 65, 23, 45, 2, 6, 2, 3, 8, 6, 2, 8, 45, 2, 6, 2, 3, 8, 6, 2, 8, 2, 6, 2, 56, 23, 65, 23, 45, 2, 6, 2, 3, 8, 6, 2, 8, 45, 2, 6, 2, 3, 8, 6, 2, 8, 2, 6, 2, 56, 23, 65, 23, 45, 2, 6, 2, 3, 8, 6, 2, 8, 45, 2, 6, 2, 3, 8, 6, 2, 8, 2, 6, 2, 56, 23, 65, 23, 45, 2, 6, 2, 3, 8, 6, 2, 8, 45, 2, 6, 2, 3, 8, 6, 2, 8, 2, 6, 2, 56, 23, 65, 23, 45, 2, 6, 2, 3, 8, 6, 2, 8, 45, 2, 6, 2, 3, 8, 6, 2, 8, 2, 6, 2, 56, 23, 65, 23, 45, 2, 6, 2, 3, 8, 6, 2, 8, 45, 2, 6, 2, 3, 8, 6, 2, 8, 2, 6, 2, 56, 23, 65, 23, 45, 2, 6, 2, 3, 8, 6, 2, 8, 45, 2, 6, 2, 3, 8, 6, 2, 8, 2, 6, 2, 56, 23, 65, 23, 23, 45, 2, 6, 2, 3, 8, 6, 2, 8, 45, 2, 6, 2, 3, 8, 6, 2, 8, 2, 6, 2, 56, 23, 65, 23, 7, 45, 2, 6, 2, 3, 8, 6, 2, 8, 45, 2, 6, 2, 3, 8, 6, 2, 8, 2, 6, 2, 56, 23, 65, 23, 45, 2, 6, 2, 3, 8, 6, 2, 8, 45, 2, 6, 2, 3, 8, 6, 2, 8, 2, 6, 2, 56, 23, 65, 23, 45, 2, 6, 2, 3, 8, 6, 2, 8, 45, 2, 6, 2, 3, 8, 6, 2, 8, 2, 6, 2, 56, 23, 65, 45, 2, 6, 2, 3, 8, 6, 2, 8, 45, 2, 6, 2, 3, 8, 6, 2, 8, 2, 6, 2, 56, 23, 65, 23, 45, 2, 6, 2, 3, 8, 6, 2, 8, 45, 2, 6, 2, 3, 8, 6, 2, 8, 2, 6, 2, 56, 23, 65, 23, 45, 2, 6, 2, 3, 8, 6, 2, 8, 45, 2, 6, 2, 3, 8, 6, 2, 8, 2, 6, 2, 56, 23, 65, 23, 45, 2, 6, 2, 3, 8, 6, 2, 8, 45, 2, 6, 2, 3, 8, 6, 2, 8, 2, 6, 2, 56, 23, 65, 23, 45, 2, 6, 2, 3, 8, 6, 2, 8, 45, 2, 6, 2, 3, 8, 6, 2, 8, 2, 6, 2, 56, 23, 65, 23, 45, 2, 6, 2, 3, 8, 6, 2, 8, 45, 2, 6, 2, 3, 8, 6, 2, 8, 2, 6, 2, 56, 23, 65, 23, 45, 2, 6, 2, 3, 8, 6, 2, 8, 45, 2, 6, 2, 3, 8, 6, 2, 8, 2, 6, 2, 56, 23, 65, 23, 45, 2, 6, 2, 3, 8, 6, 2, 8, 45, 2, 6, 2, 3, 8, 6, 2, 8, 2, 6, 2, 56, 23, 65, 23, 45, 2, 6, 2, 3, 8, 6, 2, 8, 45, 2, 6, 2, 3, 8, 6, 2, 8, 2, 6, 2, 56, 23, 65, 23, 23, 45, 2, 6, 2, 3, 8, 6, 2, 8, 45, 2, 6, 2, 3, 8, 6, 2, 8, 2, 6, 2, 56, 23, 65, 23, 7, 45, 2, 6, 2, 3, 8, 6, 2, 8, 45, 2, 6, 2, 3, 8, 6, 2, 8, 2, 6, 2, 56, 23, 65, 23, 45, 2, 6, 2, 3, 8, 6, 2, 8, 45, 2, 6, 2, 3, 8, 6, 2, 8, 2, 6, 2, 56, 23, 65, 23, 45, 2, 6, 2, 3, 8, 6, 2, 8, 45, 2, 6, 2, 3, 8, 6, 2, 8, 2, 6, 2, 56, 23, 65, 45, 2, 6, 2, 3, 8, 6, 2, 8, 45, 2, 6, 2, 3, 8, 6, 2, 8, 2, 6, 2, 56, 23, 65, 23, 45, 2, 6, 2, 3, 8, 6, 2, 8, 45, 2, 6, 2, 3, 8, 6, 2, 8, 2, 6, 2, 56, 23, 65, 23, 45, 2, 6, 2, 3, 8, 6, 2, 8, 45, 2, 6, 2, 3, 8, 6, 2, 8, 2, 6, 2, 56, 23, 65, 23, 45, 2, 6, 2, 3, 8, 6, 2, 8, 45, 2, 6, 2, 3, 8, 6, 2, 8, 2, 6, 2, 56, 23, 65, 23, 45, 2, 6, 2, 3, 8, 6, 2, 8, 45, 2, 6, 2, 3, 8, 6, 2, 8, 2, 6, 2, 56, 23, 65, 23, 45, 2, 6, 2, 3, 8, 6, 2, 8, 45, 2, 6, 2, 3, 8, 6, 2, 8, 2, 6, 2, 56, 23, 65, 23, 45, 2, 6, 2, 3, 8, 6, 2, 8, 45, 2, 6, 2, 3, 8, 6, 2, 8, 2, 6, 2, 56, 23, 65, 23, 45, 2, 6, 2, 3, 8, 6, 2, 8, 45, 2, 6, 2, 3, 8, 6, 2, 8, 2, 6, 2, 56, 23, 65, 23, 45, 2, 6, 2, 3, 8, 6, 2, 8, 45, 2, 6, 2, 3, 8, 6, 2, 8, 2, 6, 2, 56, 23, 65, 23, 23, 45, 2, 6, 2, 3, 8, 6, 2, 8, 45, 2, 6, 2, 3, 8, 6, 2, 8, 2, 6, 2, 56, 23, 65, 23 };
	//int[] numbers = new int[1000];
	//Random rand = new Random(5263);
	//for (int i = 0; i < numbers.Length; i++)
	//{
	//    //numbers[i] = 20_000;
	//    numbers[i] = rand.Next(1, 20_001);
	//}

	//Console.WriteLine(numbers.Length);
	//Stopwatch watch = new Stopwatch();
	//watch.Start();
	Result result = Solve(numbers);
	//watch.Stop();
	//Console.WriteLine($"Time: {watch.ElapsedMilliseconds}");

	std::cout << result.Number << std::endl;
	std::cout << result.NewNumber << std::endl;
}