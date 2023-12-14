#pragma once

#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>

class Utility
{
public:
	static void ConvertToUpper(std::vector<std::string>& vectorToConvert);
	static void ConverToLower(std::vector<std::string>& vectorToConvert);

	template<typename T>
	static std::vector<T> CreateInversedSortedCopy(std::vector<T> original);
	template<typename T>
	static std::vector<T> CreateSortedCopy(std::vector<T> original);
	template<typename T>
	static void RemoveDoubles(std::vector<T>& vectorToAdjust);
};

template<typename T>
inline void Utility::RemoveDoubles(std::vector<T>& vectorToAdjust)
{
	std::sort(vectorToAdjust.begin(), vectorToAdjust.end());
	vectorToAdjust.erase(std::unique(vectorToAdjust.begin(), vectorToAdjust.end()), vectorToAdjust.end());
}

template<typename T>
inline std::vector<T> Utility::CreateInversedSortedCopy(std::vector<T> original)
{
	std::sort(original.rbegin(), original.rend());
	return original;
}

template<typename T>
inline std::vector<T> Utility::CreateSortedCopy(std::vector<T> original)
{
	std::sort(original.begin(), original.end());
	return original;
}