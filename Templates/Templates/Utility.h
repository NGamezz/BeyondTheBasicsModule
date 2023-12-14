#pragma once

#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

namespace Custom
{
	class Utility
	{
	public:
		template<typename T>
		static void Sort(std::vector<T>& collection);
		template<typename T>
		static void PrintContents(std::vector<T> collection);
	};

	template<typename T>
	void Utility::PrintContents(std::vector<T> collection)
	{
		for (auto x : collection)
		{
			std::cout << x << std::endl;
		}
	};

	template<typename T>
	void Utility::Sort(std::vector<T>& collection)
	{
		std::sort(collection.begin(), collection.end());

	};
}