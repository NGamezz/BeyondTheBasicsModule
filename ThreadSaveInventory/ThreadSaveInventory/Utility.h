#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

namespace Custom
{
	class Utility
	{
	public:
		template<typename T>
		static void PrintContents(std::vector<T> collection);
	};

	template<typename T>
	void Utility::PrintContents(std::vector<T> collection)
	{
		for (auto x : collection)
		{
			std::cout << x << "\n";
		}
	};
}