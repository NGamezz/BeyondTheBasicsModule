#include <iostream>

#include "Utility.h"
#include <numeric>

int main() {
	std::vector<std::string> colours{ "red", "green", "white", "blue", "orange", "green", "orange", "black", "purple" };
	// gebruik functies uit <algorithm> en <functional> om (steeds vanuit een ORIGINELE copie van deze vector)
	// 1) de vector in 2 nieuwe vectoren te splitsen: 1 met alles wat alfabetisch voor 'purple' komt, 1 met alles er na

	//Regular Sorted Copy
	auto newSortedVector = Utility::CreateSortedCopy(colours);
	//Inverse Sorted Copy
	auto newInverseSortedVector = Utility::CreateInversedSortedCopy(colours);
	for (auto& component : newSortedVector)
	{
		std::cout << component << std::endl;
	}

	{
		std::vector<std::string> colours{ "red", "green", "white", "blue", "orange", "green", "orange", "black", "purple" };
		// 2) alle elementen UPPERCASE te maken.
		Utility::ConvertToUpper(colours);
		for (auto& component : colours)
		{
			std::cout << component << std::endl;
		}
	}

	{
		std::vector<std::string> colours{ "red", "green", "white", "blue", "orange", "green", "orange", "black", "purple" };
		Utility::RemoveDoubles(colours);
		for (auto& component : colours)
		{
			std::cout << component << std::endl;
		}
		// 3) alle dubbele te verwijderen
	}

	// gebruik functies uit <algorithm> en <functional> om (steeds vanuit een ORIGINELE copie van deze vector)
	{
		std::vector<double> numbers{ 10, 324422, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635 };
		numbers.erase(std::remove_if(numbers.begin(), numbers.end(), [](int i) { return i < 0; }), numbers.end());
		for (auto& component : numbers)
		{
			std::cout << component << std::endl;
		}
		// 1) alle negatieve elementen te verwijderen
	}

	{
		std::vector<double> numbers{ 10, 324422, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635 };

		//Erase Odd numbers.
		numbers.erase(std::remove_if(numbers.begin(), numbers.end(), [](int i) {return (i % 2) != 0; }), numbers.end());
		//Erase Even numbers.
		//numbers.erase(std::remove_if(numbers.begin(), numbers.end(), [](int i) {return (i % 2) == 0; }), numbers.end());

		for (auto& component : numbers)
		{
			std::cout << component << std::endl;
		}
		// 2) voor alle elementen te bepalen of ze even of oneven zijn
	}

	{
		std::vector<double> numbers{ 10, 324422, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635 };

		const auto sum = std::accumulate(numbers.begin(), numbers.end(), 0.0f);
		const auto average = std::accumulate(numbers.begin(), numbers.end(), 0.0f) / numbers.size();
		const auto product = std::accumulate(numbers.begin(), numbers.end(), 1.0f, std::multiplies<>{});;

		std::cout << sum << std::endl;
		std::cout << average << std::endl;
		std::cout << product << std::endl;
		// 3) de som, het gemiddelde, en het product van alle getallen te berekenen
	}

	return 0;
}