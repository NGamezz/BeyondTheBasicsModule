#include "Utility.h"

void Utility::ConvertToUpper(std::vector<std::string>& vectorToConvert)
{
	for (auto& string : vectorToConvert)
	{
		std::transform(string.begin(), string.end(), string.begin(), ::toupper);
	}
}

void Utility::ConverToLower(std::vector<std::string>& vectorToConvert)
{
	for (auto& string : vectorToConvert)
	{
		std::transform(string.begin(), string.end(), string.begin(), ::tolower);
	}
}