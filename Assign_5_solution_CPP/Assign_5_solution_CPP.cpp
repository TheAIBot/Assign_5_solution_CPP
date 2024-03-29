// Assign_5_solution_CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <nmmintrin.h>
#include <immintrin.h>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <limits>
#include <string>
#include <sstream>
#include <cctype>
#include <cstdint>
#include <cstring>

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

template<typename T>
int bitsCount()
{
	return sizeof(T) * 8;
}

template<typename T>
int getByteIndex(int index)
{
	return index / bitsCount<T>();
}

template<typename T>
int getBitIndex(int index)
{
	return index & (bitsCount<T>() - 1);
}

template<typename T>
struct bitIndices
{
public:
	int byteIndex;
	int bitIndex;

	bitIndices(int index)
	{
		byteIndex = getByteIndex<T>(index);
		bitIndex = getBitIndex<T>(index);
	}
};

template<typename T1, typename T2>
int getSizeDiff()
{
	return sizeof(T1) / sizeof(T2);
}

template<typename T>
int getItemsNeededForBits(int length)
{
	int len = length / bitsCount<T>();
	if (length % bitsCount<T>() != 0)
	{
		len++;
	}

	return len;
}

struct bitArraySlim
{
private:
	uint64_t* array;
public:
	int length;

	bitArraySlim(int len, int realLen)
	{
		length = len;
		int arrayLength = getItemsNeededForBits<__m256i>(realLen) + 1;
		arrayLength *= getSizeDiff<__m256i, uint64_t>();
		array = (uint64_t*)_mm_malloc(arrayLength * sizeof(uint64_t), sizeof(__m256i));
		std::fill(array, array + arrayLength, 0);
	}

	bitArraySlim(int len) : bitArraySlim(len, len)
	{
	}

	void copyTo(bitArraySlim& other) const
	{
		int copyLength = getCurrentArrayLength();
		int fillLength = other.getCurrentArrayLength() - copyLength;
		std::copy(array, array + copyLength, other.array);

		uint64_t* fillStart = other.array + copyLength;
		uint64_t* fillEnd = other.array + copyLength + fillLength + getSizeDiff<__m256i, uint64_t>();
		std::fill(fillStart, fillEnd, 0);
	}

	int size() const
	{
		return length;
	}

	uint64_t operator[](int index) const
	{
		bitIndices<uint64_t> indices(index);
		return (array[indices.byteIndex] >> indices.bitIndex) & 1;
	}

	void forceSet(int index, uint64_t value)
	{
		bitIndices<uint64_t> indices(index);
		array[indices.byteIndex] ^= (-(int64_t)value ^ array[indices.byteIndex]) & (((uint64_t)1) << indices.bitIndex);
	}

	void reuse(int newLength)
	{
		length = newLength;
	}

	int getCurrentArrayLength() const
	{
		return getItemsNeededForBits<uint64_t>(length);
	}

	uint64_t* begin() const
	{
		return array;
	}

	~bitArraySlim()
	{
		_mm_free(array);
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

struct bitArrayStorage
{
private:
	std::vector<bitArraySlim*>* arrays;
	int maxSum;

public:
	bitArrayStorage(int maxSuaam)
	{
		arrays = new std::vector<bitArraySlim*>();
		maxSum = maxSuaam;
	}

	bitArraySlim* pop(int length)
	{
		if (arrays->empty())
		{
			return new bitArraySlim(length, maxSum + 1);
		}
		else
		{
			bitArraySlim* arr = arrays->back();
			arrays->pop_back();
			arr->reuse(length);
			return arr;
		}
	}

	void push(bitArraySlim* arr)
	{
		arrays->push_back(arr);
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
	bitArraySlim* sums;
	bitArrayStorage* storage;

	PartialSumsData(int maxSum) : storage(new bitArrayStorage(maxSum))
	{
		foundData = new std::unordered_set<int>();
		datas = BestSumsData();
		minuniques = std::numeric_limits<int>::max();
		sumsCount = -1;
		created = 0;
		sums = nullptr;
	}
};

int BoolArrayTrueCount(bitArraySlim& array)
{
	int trueCount = 0;
	for (auto i = array.begin(); i != array.begin() + array.getCurrentArrayLength(); i++)
	{
		trueCount += _mm_popcnt_u64(*i);
	}

	return trueCount;
}

inline void moveSumsNoShift(__m256i* lastPtr, __m256i* currPtr)
{
	_mm256_storeu_si256(lastPtr, _mm256_or_si256(_mm256_loadu_si256(lastPtr), _mm256_loadu_si256(currPtr)));
}

inline void moveSumsNoShift(__m128i* lastPtr, __m128i* currPtr)
{
	_mm_storeu_si128(lastPtr, _mm_or_si128(_mm_loadu_si128(lastPtr), _mm_loadu_si128(currPtr)));
}

inline void moveSumsNoShift(uint64_t* lastPtr, uint64_t* currPtr)
{
	*lastPtr |= *currPtr;
}

inline void moveSumsWithShift(__m256i* lastPtr, __m256i* currPtr, int shift)
{
	__m256i unalignedPart = _mm256_loadu_si256((__m256i*)(((uint64_t*)currPtr) - 1));
	__m256i before = _mm256_srli_epi64(unalignedPart, bitsCount<uint64_t>() - shift);
	__m256i after = _mm256_slli_epi64(_mm256_loadu_si256(currPtr), shift);
	__m256i combined = _mm256_or_si256(before, after);
	_mm256_storeu_si256(lastPtr, _mm256_or_si256(_mm256_loadu_si256(lastPtr), combined));
}

inline void moveSumsWithShift(__m128i* lastPtr, __m128i* currPtr, int shift)
{
	__m128i unalignedPart = _mm_loadu_si128((__m128i*)(((uint64_t*)currPtr) - 1));
	__m128i before = _mm_srli_epi64(unalignedPart, bitsCount<uint64_t>() - shift);
	__m128i after = _mm_slli_epi64(_mm_loadu_si128(currPtr), shift);
	__m128i combined = _mm_or_si128(before, after);
	_mm_storeu_si128(lastPtr, _mm_or_si128(_mm_loadu_si128(lastPtr), combined));
}

inline void moveSumsWithShift(uint64_t* lastPtr, uint64_t* currPtr, int shift)
{
	uint64_t before = *(currPtr - 1) >> (bitsCount<uint64_t>() - shift);
	uint64_t after = *currPtr << shift;
	uint64_t combined = before | after;
	*lastPtr |= combined;
}

template<typename T>
void createSumsVectorized(int z, int number, bitArraySlim& newSums)
{
	bitIndices<uint64_t> numberOffset(number);

	int length = ((z + number) / bitsCount<uint64_t>());
	uint64_t* lastPtr = newSums.begin() + length;
	uint64_t* currPtr = lastPtr - numberOffset.byteIndex;

	int sizeFromUint = sizeof(T) / sizeof(uint64_t);

	int iterations = length - numberOffset.byteIndex;
	int rest = (sizeFromUint - (iterations % sizeFromUint)) % sizeFromUint;
	iterations += rest;
	lastPtr += rest;
	currPtr += rest;

	if (numberOffset.bitIndex % bitsCount<uint8_t>() == 0)
	{
		int offset = numberOffset.bitIndex / bitsCount<uint8_t>();
		lastPtr = (uint64_t*)(((uint8_t*)lastPtr) + offset);

		for (int i = 0; i <= iterations; i += sizeFromUint)
		{
			moveSumsNoShift((T*)(lastPtr - i), (T*)(currPtr - i));
		}
	}
	else
	{
		for (int i = -1; i <= iterations - 1; i += sizeFromUint)
		{
			moveSumsWithShift((T*)(lastPtr - i), (T*)(currPtr - i), numberOffset.bitIndex);
		}

		uint64_t affter = currPtr[-iterations] << numberOffset.bitIndex;
		lastPtr[-iterations] |= affter;
	}
}

bitArraySlim* CreatePartialSums(span<int> numbers, bitArraySlim& currSums, bitArrayStorage* storage)
{
	int maxSum = currSums.size();
	for (int i = 0; i < numbers.length; i++)
	{
		maxSum += numbers[i];
	}

	bitArraySlim* newSums = storage->pop(maxSum);
	currSums.copyTo(*newSums);

	int prevMaxSum = currSums.size() - 1;
	for (int i = 0; i < numbers.length; i++)
	{
		createSumsVectorized<__m256i>(prevMaxSum, numbers[i], *newSums);
		//createSumsVectorized<__m128i>(prevMaxSum, numbers[i], *newSums);
		//createSumsVectorized<uint64_t>(prevMaxSum, numbers[i], *newSums);
		prevMaxSum += numbers[i];
	}

	return newSums;
}

void CreateAllSums(int number, bitArraySlim& currSums, PartialSumsData& data)
{
	span<int> dwa(1);
	dwa[0] = number;
	data.sums = CreatePartialSums(dwa, currSums, data.storage);
	delete[] dwa.array;
}

PreSumsData FinishCreateSumsData(int number, bitArraySlim& currSums, int currSumsCount, PartialSumsData& data)
{
	if (data.sumsCount != -1)
	{
		int uniques = data.sumsCount - currSumsCount;
		return PreSumsData(&currSums, uniques);
	}

	if (data.sumsCount == -1)
	{
		CreateAllSums(number, currSums, data);
		data.sumsCount = BoolArrayTrueCount(*data.sums);
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

		bitArraySlim* secondPartSums = CreatePartialSums(secondPart, currSums, data.storage);
		if (!CreateAllSumsDatas(firstPart, *secondPartSums, data))
		{
			data.storage->push(secondPartSums);
		}

		bitArraySlim* firstPartSums = CreatePartialSums(firstPart, currSums, data.storage);
		if (!CreateAllSumsDatas(secondPart, *firstPartSums, data))
		{
			data.storage->push(firstPartSums);
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
			BestSumsData newData(number, FinishCreateSumsData(number, currSums, actualSumCount, data));
			data.minuniques = std::min(data.minuniques, data.datas.Data.uniques);

			if (newData.Data.uniques < data.datas.Data.uniques ||
				(newData.Data.uniques == data.datas.Data.uniques &&
					newData.Number < data.datas.Number))
			{
				if (data.datas.Data.bitArray != nullptr)
				{
					data.storage->push(data.datas.Data.bitArray);
				}
				data.datas = newData;
				return true;
			}
		}
	}
	return false;
}

Result CreateCollisionAvoidanceArray(bitArraySlim& sums, BestSumsData bestData, PartialSumsData& data)
{
	SumsData sumData = bestData.Data.ToSumsData(bestData.Number, data.sumsCount);

	for (auto uniqueNumber = sumData.Uniques->begin(); uniqueNumber != sumData.Uniques->end(); uniqueNumber++)
	{
		sums.forceSet(*uniqueNumber, 0);
	}

	for (int i = 1; i <= sums.size();)
	{
		bool foundObstacle = false;
		for (auto newSum = sumData.NewSums->begin(); newSum != sumData.NewSums->end(); newSum++)
		{
			int overlapIndex = *newSum - (bestData.Number - i);
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

	int maxSum = 0;
	for (int i = 0; i < numbers.length; i++)
	{
		maxSum += numbers[i];
	}

	PartialSumsData data(maxSum);

	bitArraySlim* currSums = new bitArraySlim(1);
	currSums->forceSet(0, 1);

	CreateAllSumsDatas(numbers, *currSums, data);
	delete currSums;
	delete data.foundData;

	return CreateCollisionAvoidanceArray(*data.sums, data.datas, data);
}

int main()
{
	//int numberCount;
	//std::cin >> numberCount;

	//std::cin >> std::ws;

	//span<int> numbers(numberCount);

	//std::string numbersAsString;
	//std::getline(std::cin, numbersAsString);

	//int index = 0;
	//int stringIndex = 0;
	//while (stringIndex < numbersAsString.size())
	//{
	//	int digitCount = 0;
	//	while (digitCount + stringIndex < numbersAsString.size() && std::isdigit(numbersAsString[digitCount + stringIndex]))
	//	{
	//		digitCount++;
	//	}

	//	if (digitCount == numbersAsString.size())
	//	{
	//		break;
	//	}

	//	std::string numberAsString = numbersAsString.substr(stringIndex, digitCount);

	//	int number = std::stoi(numberAsString);
	//	numbers[index++] = number;

	//	stringIndex += digitCount;
	//	stringIndex++;
	//}

	//Result result = Solve(numbers);
	//delete[] numbers.array;

	int numbers[] = { 64, 69, 77, 87, 102, 106, 110, 112, 126, 128, 129, 131, 132, 151, 163, 172, 173, 186, 197, 206, 208, 209, 227, 228, 231, 231, 232, 234, 240, 260, 270, 274, 294, 298, 303, 327, 334, 350, 352, 357, 374, 376, 384, 389, 389, 392, 411, 415, 419, 422, 425, 433, 434, 443, 451, 458, 504, 505, 514, 517, 520, 543, 569, 577, 584, 587, 599, 610, 616, 619, 626, 628, 632, 633, 637, 645, 648, 651, 654, 673, 675, 691, 694, 695, 696, 698, 705, 708, 711, 714, 722, 724, 725, 728, 734, 735, 757, 766, 803, 822, 823, 827, 833, 834, 834, 836, 838, 840, 842, 847, 848, 852, 857, 859, 864, 875, 904, 905, 907, 922, 925, 926, 928, 929, 942, 946, 960, 972, 973, 978, 981, 987, 990, 992, 994, 1015, 1016, 1016, 1021, 1027, 1027, 1033, 1035, 1037, 1053, 1055, 1055, 1057, 1058, 1068, 1074, 1076, 1081, 1084, 1110, 1118, 1123, 1135, 1136, 1154, 1169, 1170, 1170, 1171, 1177, 1177, 1185, 1188, 1200, 1215, 1220, 1229, 1231, 1237, 1240, 1262, 1265, 1267, 1270, 1275, 1276, 1285, 1299, 1301, 1302, 1306, 1308, 1312, 1321, 1327, 1335, 1336, 1339, 1348, 1353, 1358, 1374, 1387, 1392, 1402, 1415, 1428, 1433, 1439, 1459, 1461, 1462, 1463, 1464, 1483, 1487, 1490, 1503, 1505, 1513, 1520, 1522, 1530, 1535, 1535, 1537, 1540, 1544, 1557, 1558, 1561, 1565, 1569, 1570, 1573, 1586, 1589, 1592, 1597, 1608, 1610, 1621, 1633, 1636, 1671, 1678, 1707, 1707, 1715, 1722, 1725, 1727, 1742, 1751, 1769, 1773, 1780, 1797, 1798, 1798, 1800, 1809, 1810, 1813, 1813, 1813, 1818, 1826, 1845, 1845, 1849, 1850, 1852, 1864, 1866, 1872, 1873, 1873, 1878, 1881, 1882, 1883, 1884, 1884, 1897, 1898, 1932, 1935, 1943, 1960, 1960, 1966, 1973, 1977, 1978, 1979, 1992, 2010, 2020, 2021, 2026, 2036, 2038, 2038, 2044, 2052, 2053, 2055, 2072, 2080, 2086, 2088, 2089, 2099, 2100, 2102, 2109, 2116, 2118, 2123, 2127, 2143, 2154, 2155, 2157, 2169, 2170, 2172, 2180, 2193, 2200, 2206, 2208, 2221, 2222, 2226, 2243, 2257, 2269, 2273, 2275, 2276, 2288, 2304, 2308, 2321, 2323, 2342, 2345, 2365, 2366, 2369, 2371, 2385, 2423, 2425, 2429, 2437, 2438, 2442, 2445, 2450, 2460, 2461, 2461, 2463, 2487, 2492, 2510, 2514, 2534, 2546, 2547, 2554, 2559, 2561, 2564, 2565, 2574, 2584, 2585, 2599, 2604, 2611, 2614, 2615, 2624, 2641, 2644, 2653, 2663, 2669, 2671, 2678, 2681, 2685, 2697, 2697, 2697, 2709, 2714, 2715, 2718, 2723, 2726, 2729, 2741, 2745, 2751, 2758, 2762, 2780, 2781, 2784, 2800, 2814, 2816, 2816, 2832, 2834, 2835, 2837, 2837, 2853, 2859, 2863, 2870, 2873, 2884, 2886, 2898, 2905, 2906, 2907, 2907, 2908, 2909, 2917, 2920, 2930, 2942, 2951, 2974, 2983, 2992, 2999, 3012, 3022, 3024, 3028, 3041, 3046, 3049, 3054, 3067, 3073, 3080, 3091, 3115, 3125, 3130, 3132, 3134, 3144, 3148, 3158, 3161, 3169, 3172, 3172, 3173, 3175, 3177, 3178, 3179, 3180, 3185, 3196, 3202, 3205, 3211, 3211, 3214, 3223, 3223, 3229, 3240, 3242, 3258, 3261, 3264, 3264, 3285, 3286, 3291, 3292, 3295, 3296, 3305, 3312, 3334, 3334, 3335, 3348, 3357, 3361, 3370, 3375, 3379, 3380, 3383, 3395, 3403, 3406, 3409, 3415, 3431, 3434, 3437, 3453, 3454, 3475, 3481, 3494, 3500, 3515, 3519, 3523, 3526, 3528, 3539, 3541, 3541, 3542, 3548, 3559, 3568, 3576, 3581, 3594, 3595, 3600, 3611, 3613, 3624, 3626, 3629, 3642, 3644, 3647, 3653, 3659, 3659, 3667, 3670, 3678, 3680, 3682, 3683, 3687, 3699, 3705, 3712, 3725, 3740, 3748, 3749, 3751, 3753, 3755, 3764, 3770, 3776, 3785, 3793, 3807, 3810, 3819, 3852, 3856, 3856, 3872, 3873, 3915, 3920, 3925, 3934, 3944, 3950, 3951, 3956, 3957, 3958, 3960, 3963, 3966, 3967, 3969, 3969, 3977, 3983, 3993, 3994, 3999, 4005, 4014, 4019, 4028, 4032, 4035, 4039, 4039, 4072, 4081, 4084, 4096, 4100, 4103, 4114, 4115, 4122, 4128, 4130, 4130, 4132, 4132, 4132, 4139, 4158, 4166, 4170, 4170, 4178, 4180, 4188, 4193, 4207, 4211, 4213, 4219, 4220, 4240, 4249, 4254, 4258, 4259, 4269, 4286, 4295, 4295, 4298, 4302, 4305, 4309, 4312, 4319, 4327, 4327, 4333, 4336, 4339, 4340, 4342, 4356, 4381, 4382, 4385, 4387, 4392, 4396, 4400, 4409, 4420, 4434, 4439, 4446, 4452, 4462, 4499, 4500, 4510, 4510, 4512, 4514, 4517, 4521, 4534, 4535, 4540, 4540, 4546, 4552, 4554, 4557, 4564, 4568, 4589, 4591, 4601, 4608, 4613, 4633, 4650, 4658, 4662, 4665, 4683, 4687, 4698, 4702, 4705, 4710, 4725, 4743, 4745, 4747, 4772, 4774, 4783, 4785, 4791, 4794, 4802, 4812, 4815, 4823, 4836, 4836, 4852, 4854, 4856, 4866, 4871, 4879, 4879, 4881, 4884, 4884, 4885, 4890, 4891, 4896, 4900, 4902, 4914, 4923, 4926, 4928, 4954, 4958, 4965, 4966, 4970, 4975, 4976, 4980, 4989, 4989, 4994, 5007, 5017, 5032, 5040, 5042, 5042, 5044, 5050, 5065, 5075, 5076, 5086, 5086, 5089, 5089, 5094, 5141, 5146, 5151, 5157, 5167, 5188, 5193, 5204, 5212, 5212, 5213, 5214, 5216, 5222, 5227, 5233, 5237, 5237, 5246, 5251, 5285, 5286, 5287, 5293, 5294, 5295, 5302, 5303, 5314, 5317, 5326, 5334, 5335, 5336, 5337, 5353, 5363, 5366, 5375, 5376, 5381, 5384, 5393, 5396, 5401, 5403, 5408, 5409, 5419, 5420, 5428, 5431, 5447, 5449, 5456, 5456, 5459, 5461, 5464, 5470, 5474, 5477, 5486, 5508, 5511, 5521, 5535, 5541, 5543, 5554, 5560, 5569, 5580, 5588, 5593, 5595, 5617, 5623, 5623, 5629, 5630, 5641, 5645, 5656, 5662, 5677, 5680, 5687, 5689, 5710, 5714, 5715, 5715, 5731, 5742, 5744, 5747, 5754, 5755, 5763, 5772, 5778, 5786, 5787, 5794, 5795, 5825, 5851, 5854, 5861, 5862, 5880, 5882, 5894, 5895, 5898, 5900, 5901, 5912, 5914, 5927, 5930, 5934, 5936, 5938, 5940, 5945, 5946, 5948, 5955, 5958, 5967, 5967, 5968, 5983, 5984, 5995, 5995, 5998, 6009, 6032, 6033, 6035, 6070, 6081, 6081, 6087, 6098, 6108, 6108, 6109, 6112, 6117, 6122, 6124, 6124, 6127, 6136, 6148, 6150, 6166, 6197, 6201, 6204, 6227, 6227, 6228, 6233, 6249, 6260, 6264, 6266, 6269, 6271, 6281, 6285, 6285, 6286, 6286, 6287, 6299, 6302, 6303, 6313, 6331, 6332, 6336, 6346, 6346, 6347, 6358, 6360, 6372, 6384, 6386, 6395, 6406, 6409, 6425, 6426, 6436, 6444, 6448, 6449, 6478, 6486, 6496, 6499, 6505, 6508, 6508, 6526, 6529, 6536, 6537, 6546, 6556, 6557, 6558, 6558, 6576, 6586, 6588, 6593, 6597, 6600, 6601, 6610, 6617, 6631, 6636, 6641, 6645, 6669, 6681, 6687, 6699, 6707, 6707, 6712, 6712, 6714, 6717, 6725, 6726, 6736, 6737, 6739, 6743, 6752, 6754, 6761, 6766, 6769, 6769, 6775, 6777, 6780, 6797, 6806, 6810, 6818, 6833, 6840, 6843, 6847, 6856, 6858, 6896, 6899, 6909, 6912, 6921, 6933, 6939, 6941, 6952, 6954, 6967, 6981, 6985, 6985, 6985, 6993, 7014, 7022, 7035, 7043, 7050, 7060, 7075, 7091, 7095, 7109, 7114, 7122, 7122, 7126, 7133, 7153, 7154, 7157, 7182, 7185, 7188, 7189, 7197, 7200, 7207, 7211, 7212, 7238, 7242, 7258, 7270, 7271, 7280, 7280, 7284, 7285, 7285, 7296, 7299, 7303, 7303, 7314, 7315, 7316, 7323, 7331, 7331, 7335, 7335, 7343, 7347, 7355, 7356, 7362, 7369, 7371, 7409, 7409, 7410, 7411, 7422, 7424, 7439, 7445, 7457, 7468, 7468, 7476, 7480, 7480, 7481, 7486, 7495, 7508, 7515, 7518, 7520, 7522, 7526, 7542, 7552, 7555, 7556, 7573, 7579, 7589, 7591, 7595, 7602, 7610, 7616, 7649, 7655, 7688, 7695, 7698, 7728, 7735, 7737, 7738, 7741, 7752, 7771, 7783, 7789, 7791, 7811, 7816, 7823, 7835, 7850, 7853, 7853, 7855, 7862, 7867, 7869, 7907, 7910, 7911, 7923, 7925, 7930, 7931, 7932, 7932, 7934, 7938, 7949, 7955, 7958, 7982, 7986, 7988, 7990, 7999, 8007, 8028, 8033, 8041, 8050, 8051, 8066, 8080, 8088, 8089, 8098, 8100, 8102, 8108, 8116, 8117, 8118, 8129, 8129, 8133, 8133, 8139, 8142, 8163, 8163, 8164, 8203, 8219, 8225, 8227, 8228, 8238, 8242, 8244, 8245, 8252, 8259, 8260, 8276, 8282, 8282, 8285, 8288, 8291, 8295, 8325, 8328, 8339, 8359, 8371, 8385, 8397, 8400, 8405, 8410, 8413, 8417, 8422, 8423, 8432, 8433, 8469, 8478, 8480, 8485, 8485, 8509, 8517, 8539, 8541, 8547, 8556, 8561, 8567, 8568, 8572, 8583, 8587, 8594, 8595, 8597, 8606, 8606, 8611, 8613, 8621, 8624, 8628, 8629, 8633, 8639, 8642, 8645, 8647, 8652, 8678, 8679, 8683, 8692, 8705, 8712, 8725, 8740, 8743, 8746, 8746, 8747, 8749, 8751, 8764, 8775, 8775, 8783, 8784, 8797, 8799, 8811, 8828, 8830, 8834, 8836, 8836, 8847, 8850, 8854, 8858, 8858, 8858, 8864, 8880, 8882, 8885, 8893, 8895, 8908, 8910, 8913, 8914, 8914, 8920, 8932, 8949, 8952, 8957, 8975, 8981, 8985, 8993, 9004, 9009, 9018, 9021, 9025, 9026, 9026, 9027, 9031, 9034, 9036, 9040, 9046, 9052, 9052, 9054, 9083, 9089, 9097, 9101, 9105, 9106, 9111, 9116, 9119, 9130, 9135, 9138, 9140, 9145, 9160, 9173, 9179, 9194, 9205, 9214, 9223, 9231, 9236, 9238, 9246, 9257, 9263, 9264, 9265, 9265, 9290, 9303, 9306, 9320, 9336, 9336, 9341, 9353, 9357, 9358, 9381, 9385, 9387, 9389, 9430, 9440, 9444, 9451, 9456, 9456, 9458, 9460, 9466, 9466, 9467, 9480, 9500, 9514, 9540, 9543, 9548, 9556, 9559, 9560, 9561, 9568, 9579, 9583, 9596, 9604, 9607, 9609, 9613, 9615, 9625, 9635, 9646, 9662, 9668, 9676, 9677, 9690, 9708, 9715, 9718, 9718, 9730, 9734, 9736, 9757, 9763, 9766, 9780, 9792, 9792, 9792, 9794, 9796, 9797, 9798, 9802, 9806, 9812, 9817, 9827, 9835, 9836, 9841, 9842, 9846, 9847, 9852, 9880, 9884, 9889, 9889, 9895, 9898, 9915, 9917, 9919, 9920, 9923, 9928, 9935, 9937, 9944, 9947, 9956, 9960, 9966, 9968, 9971, 9974, 9979, 9981, 9985, 9990, 9991, 10012, 10013, 10014, 10017, 10034, 10034, 10035, 10038, 10046, 10061, 10062, 10065, 10078, 10089, 10095, 10100, 10102, 10103, 10103, 10107, 10113, 10117, 10120, 10150, 10151, 10160, 10171, 10177, 10180, 10189, 10197, 10202, 10210, 10220, 10223, 10230, 10235, 10238, 10259, 10263, 10264, 10268, 10269, 10278, 10288, 10289, 10292, 10294, 10297, 10299, 10306, 10320, 10321, 10322, 10333, 10339, 10340, 10349, 10355, 10360, 10364, 10374, 10378, 10384, 10391, 10398, 10402, 10409, 10444, 10445, 10445, 10447, 10447, 10452, 10454, 10455, 10459, 10476, 10478, 10491, 10507, 10512, 10513, 10516, 10522, 10524, 10524, 10536, 10541, 10545, 10549, 10549, 10573, 10595, 10598, 10601, 10601, 10605, 10607, 10609, 10610, 10615, 10618, 10627, 10633, 10643, 10643, 10647, 10657, 10672, 10673, 10686, 10692, 10722, 10727, 10732, 10747, 10764, 10767, 10776, 10785, 10796, 10798, 10800, 10811, 10828, 10829, 10830, 10835, 10847, 10856, 10862, 10866, 10866, 10866, 10871, 10878, 10888, 10903, 10914, 10917, 10922, 10925, 10943, 10946, 10951, 10954, 10954, 10955, 10960, 10989, 10995, 10997, 10999, 11002, 11029, 11033, 11035, 11050, 11052, 11059, 11062, 11069, 11079, 11088, 11125, 11125, 11136, 11152, 11158, 11161, 11162, 11177, 11183, 11186, 11187, 11189, 11189, 11193, 11205, 11217, 11224, 11230, 11238, 11241, 11249, 11251, 11251, 11253, 11258, 11259, 11263, 11264, 11269, 11270, 11274, 11275, 11281, 11284, 11287, 11287, 11291, 11291, 11292, 11295, 11303, 11319, 11319, 11325, 11329, 11340, 11348, 11354, 11375, 11377, 11377, 11379, 11388, 11394, 11397, 11409, 11420, 11421, 11429, 11438, 11441, 11443, 11463, 11463, 11473, 11475, 11476, 11481, 11483, 11490, 11500, 11500, 11501, 11509, 11521, 11521, 11525, 11531, 11560, 11562, 11571, 11573, 11576, 11601, 11613, 11637, 11637, 11650, 11654, 11661, 11677, 11681, 11681, 11683, 11691, 11694, 11696, 11699, 11708, 11709, 11709, 11710, 11731, 11732, 11733, 11743, 11746, 11760, 11764, 11776, 11780, 11785, 11789, 11801, 11807, 11812, 11813, 11830, 11831, 11839, 11846, 11858, 11864, 11871, 11882, 11883, 11893, 11894, 11899, 11903, 11910, 11911, 11915, 11920, 11925, 11930, 11931, 11931, 11971, 11973, 11979, 11982, 11983, 12006, 12013, 12018, 12024, 12029, 12035, 12049, 12055, 12056, 12057, 12068, 12089, 12100, 12101, 12106, 12110, 12116, 12125, 12135, 12145, 12153, 12155, 12162, 12174, 12178, 12182, 12182, 12184, 12189, 12192, 12195, 12197, 12198, 12207, 12210, 12223, 12225, 12226, 12231, 12235, 12243, 12251, 12254, 12255, 12278, 12280, 12284, 12309, 12312, 12320, 12339, 12343, 12344, 12348, 12349, 12368, 12372, 12385, 12385, 12388, 12393, 12394, 12402, 12418, 12420, 12426, 12448, 12456, 12463, 12463, 12464, 12467, 12480, 12484, 12489, 12491, 12494, 12504, 12516, 12519, 12525, 12532, 12532, 12539, 12542, 12544, 12545, 12570, 12573, 12581, 12586, 12586, 12587, 12627, 12648, 12650, 12650, 12654, 12666, 12682, 12694, 12697, 12718, 12723, 12729, 12733, 12740, 12740, 12765, 12766, 12776, 12790, 12793, 12798, 12800, 12806, 12812, 12814, 12828, 12830, 12836, 12849, 12860, 12866, 12866, 12875, 12884, 12884, 12902, 12905, 12905, 12908, 12910, 12910, 12929, 12930, 12936, 12939, 12993, 12994, 13000, 13000, 13002, 13003, 13003, 13013, 13014, 13016, 13022, 13026, 13031, 13031, 13035, 13039, 13047, 13047, 13048, 13055, 13075, 13079, 13088, 13088, 13093, 13095, 13107, 13108, 13111, 13112, 13137, 13138, 13145, 13161, 13165, 13166, 13173, 13173, 13178, 13188, 13192, 13201, 13208, 13211, 13213, 13223, 13224, 13231, 13235, 13238, 13239, 13247, 13248, 13251, 13258, 13275, 13279, 13285, 13315, 13319, 13321, 13326, 13330, 13335, 13336, 13336, 13359, 13362, 13375, 13396, 13410, 13415, 13424, 13435, 13437, 13441, 13451, 13453, 13456, 13474, 13477, 13479, 13486, 13495, 13499, 13501, 13507, 13507, 13511, 13512, 13515, 13534, 13541, 13547, 13574, 13574, 13579, 13590, 13591, 13601, 13602, 13603, 13608, 13611, 13612, 13619, 13619, 13620, 13621, 13628, 13629, 13702, 13709, 13713, 13716, 13739, 13743, 13744, 13757, 13770, 13796, 13800, 13808, 13811, 13815, 13824, 13826, 13838, 13839, 13852, 13858, 13873, 13878, 13880, 13884, 13885, 13888, 13889, 13906, 13906, 13906, 13909, 13912, 13915, 13938, 13971, 13975, 13977, 13980, 14006, 14028, 14029, 14033, 14034, 14035, 14040, 14043, 14046, 14047, 14056, 14071, 14075, 14078, 14083, 14089, 14093, 14094, 14102, 14119, 14122, 14134, 14162, 14162, 14173, 14184, 14191, 14208, 14224, 14232, 14241, 14242, 14242, 14254, 14278, 14284, 14298, 14305, 14310, 14311, 14322, 14323, 14327, 14329, 14331, 14342, 14345, 14348, 14357, 14370, 14376, 14389, 14407, 14412, 14418, 14419, 14424, 14434, 14436, 14450, 14452, 14461, 14465, 14481, 14490, 14501, 14502, 14518, 14528, 14537, 14540, 14541, 14543, 14550, 14550, 14552, 14552, 14558, 14567, 14570, 14572, 14574, 14574, 14584, 14586, 14587, 14595, 14597, 14603, 14609, 14611, 14643, 14645, 14646, 14648, 14650, 14660, 14670, 14677, 14678, 14680, 14681, 14682, 14684, 14685, 14688, 14697, 14698, 14700, 14703, 14704, 14709, 14711, 14721, 14722, 14742, 14743, 14746, 14759, 14776, 14778, 14784, 14794, 14795, 14795, 14800, 14811, 14814, 14819, 14823, 14825, 14833, 14834, 14844, 14851, 14860, 14870, 14872, 14887, 14896, 14906, 14906, 14916, 14920, 14920, 14928, 14945, 14956, 14959, 14960, 14961, 14962, 14966, 14976, 14988, 14989, 14992, 14994, 15005, 15014, 15030, 15032, 15042, 15051, 15062, 15067, 15068, 15069, 15077, 15083, 15096, 15097, 15109, 15111, 15116, 15117, 15140, 15141, 15142, 15174, 15174, 15178, 15179, 15185, 15197, 15205, 15206, 15209, 15211, 15215, 15220, 15223, 15226, 15231, 15232, 15241, 15261, 15270, 15278, 15285, 15290, 15292, 15294, 15301, 15311, 15329, 15335, 15336, 15337, 15345, 15366, 15366, 15371, 15378, 15415, 15419, 15426, 15431, 15445, 15446, 15448, 15453, 15459, 15460, 15460, 15460, 15463, 15467, 15475, 15492, 15494, 15498, 15498, 15516, 15519, 15521, 15529, 15531, 15536, 15539, 15542, 15562, 15571, 15572, 15578, 15579, 15583, 15588, 15596, 15619, 15620, 15621, 15622, 15624, 15628, 15630, 15630, 15632, 15634, 15635, 15639, 15641, 15647, 15658, 15660, 15670, 15673, 15688, 15691, 15691, 15691, 15695, 15696, 15696, 15701, 15703, 15704, 15705, 15717, 15722, 15732, 15734, 15748, 15759, 15764, 15767, 15773, 15780, 15783, 15783, 15787, 15787, 15800, 15804, 15810, 15827, 15835, 15837, 15843, 15846, 15857, 15867, 15869, 15879, 15880, 15883, 15907, 15909, 15913, 15923, 15925, 15929, 15929, 15938, 15938, 15949, 15957, 15968, 15977, 15992, 15995, 15995, 16003, 16003, 16005, 16015, 16036, 16044, 16054, 16055, 16065, 16070, 16088, 16092, 16095, 16100, 16113, 16114, 16129, 16132, 16139, 16144, 16151, 16155, 16171, 16175, 16175, 16176, 16176, 16179, 16185, 16189, 16190, 16190, 16192, 16215, 16219, 16225, 16233, 16236, 16239, 16242, 16259, 16277, 16280, 16291, 16292, 16293, 16328, 16330, 16341, 16358, 16360, 16360, 16367, 16370, 16390, 16391, 16397, 16400, 16401, 16423, 16430, 16430, 16451, 16467, 16471, 16472, 16473, 16475, 16477, 16484, 16486, 16487, 16490, 16493, 16498, 16505, 16506, 16510, 16518, 16519, 16522, 16522, 16523, 16530, 16535, 16554, 16554, 16564, 16568, 16570, 16573, 16578, 16593, 16594, 16595, 16601, 16606, 16619, 16625, 16629, 16630, 16644, 16651, 16655, 16659, 16676, 16680, 16692, 16727, 16733, 16745, 16748, 16764, 16766, 16771, 16779, 16797, 16801, 16811, 16813, 16819, 16822, 16823, 16831, 16848, 16864, 16871, 16875, 16895, 16903, 16903, 16910, 16911, 16936, 16936, 16940, 16944, 16951, 16951, 16954, 16956, 16961, 16970, 16974, 16989, 16996, 17005, 17010, 17017, 17025, 17032, 17032, 17039, 17039, 17043, 17045, 17049, 17056, 17057, 17058, 17063, 17066, 17088, 17095, 17103, 17104, 17105, 17114, 17123, 17134, 17146, 17148, 17150, 17155, 17156, 17164, 17168, 17169, 17172, 17199, 17201, 17210, 17216, 17217, 17221, 17222, 17222, 17234, 17255, 17256, 17267, 17276, 17285, 17298, 17306, 17311, 17315, 17316, 17321, 17333, 17333, 17335, 17336, 17336, 17337, 17360, 17378, 17379, 17384, 17386, 17391, 17404, 17406, 17416, 17420, 17424, 17425, 17435, 17440, 17447, 17490, 17497, 17512, 17517, 17521, 17522, 17529, 17538, 17554, 17555, 17557, 17569, 17574, 17577, 17594, 17599, 17608, 17617, 17618, 17623, 17630, 17633, 17637, 17652, 17662, 17678, 17683, 17687, 17689, 17696, 17703, 17703, 17707, 17712, 17713, 17717, 17719, 17720, 17726, 17730, 17736, 17740, 17742, 17743, 17745, 17751, 17751, 17754, 17757, 17761, 17779, 17791, 17797, 17805, 17808, 17817, 17820, 17824, 17834, 17834, 17836, 17838, 17848, 17849, 17855, 17856, 17875, 17888, 17893, 17895, 17895, 17912, 17922, 17929, 17951, 17968, 17971, 17972, 17985, 17989, 17989, 17991, 17997, 17998, 18002, 18009, 18014, 18018, 18020, 18023, 18025, 18027, 18044, 18050, 18051, 18066, 18070, 18071, 18080, 18080, 18089, 18094, 18097, 18102, 18114, 18126, 18128, 18130, 18131, 18132, 18142, 18157, 18158, 18160, 18163, 18165, 18191, 18193, 18202, 18207, 18208, 18229, 18232, 18248, 18253, 18261, 18261, 18282, 18297, 18312, 18323, 18343, 18349, 18351, 18355, 18357, 18357, 18366, 18374, 18386, 18388, 18394, 18396, 18400, 18400, 18419, 18421, 18426, 18432, 18434, 18442, 18452, 18456, 18458, 18462, 18472, 18477, 18486, 18500, 18500, 18509, 18517, 18520, 18536, 18540, 18549, 18550, 18552, 18557, 18561, 18566, 18570, 18578, 18603, 18604, 18610, 18628, 18630, 18648, 18660, 18667, 18675, 18685, 18688, 18700, 18703, 18707, 18712, 18716, 18739, 18743, 18771, 18771, 18777, 18793, 18801, 18802, 18819, 18829, 18829, 18831, 18833, 18837, 18848, 18851, 18856, 18858, 18865, 18876, 18878, 18891, 18911, 18915, 18919, 18929, 18947, 18947, 18960, 18968, 18976, 18983, 18991, 19003, 19003, 19004, 19006, 19012, 19015, 19033, 19051, 19055, 19055, 19059, 19061, 19064, 19086, 19089, 19090, 19091, 19120, 19130, 19132, 19132, 19149, 19149, 19156, 19171, 19174, 19176, 19177, 19186, 19186, 19187, 19191, 19208, 19216, 19225, 19236, 19238, 19243, 19246, 19248, 19292, 19309, 19310, 19312, 19312, 19314, 19323, 19333, 19343, 19345, 19349, 19351, 19362, 19362, 19375, 19390, 19391, 19408, 19409, 19410, 19427, 19429, 19431, 19440, 19456, 19458, 19460, 19463, 19464, 19475, 19481, 19494, 19516, 19518, 19518, 19520, 19536, 19536, 19537, 19549, 19554, 19555, 19557, 19565, 19568, 19573, 19584, 19612, 19613, 19621, 19623, 19643, 19644, 19647, 19658, 19674, 19675, 19679, 19691, 19699, 19728, 19735, 19741, 19752, 19752, 19752, 19753, 19756, 19756, 19772, 19775, 19779, 19782, 19788, 19795, 19797, 19798, 19803, 19812, 19822, 19824, 19828, 19829, 19830, 19832, 19839, 19840, 19855, 19858, 19874, 19874, 19876, 19895, 19899, 19902, 19903, 19913, 19913, 19914, 19919, 19927, 19929, 19930, 19937, 19967, 19989, 19996, 19999 };
	//int numbers[] = { 1, 1, 2, 4, 8, 16, 32, 64, 128, 256 };
	span<int> spanNumbers((int*)numbers, (int)(sizeof(numbers) / sizeof(int)), true);
	auto result = Solve(spanNumbers);

	std::cout << result.Number << std::endl;
	std::cout << result.NewNumber << std::endl;
}