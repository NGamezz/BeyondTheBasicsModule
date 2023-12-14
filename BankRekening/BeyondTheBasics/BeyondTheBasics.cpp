#include "Bankrekening.h"
#include "Transactie.h"
#include <Windows.h>
#include <limits>
#include "BeyondTheBasics.h"
#undef max

int main()
{
	bool solutionRunning = true;
	Bankrekening bankAccount;
	int inputValue;

	while (solutionRunning)
	{
		std::cout << "Enter an amount for the transaction " << std::endl;

		while (!(std::cin >> inputValue)) {

			std::cin.clear();

			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cout << "Invalid input. Please Enter Only Numbers : ";
		}

		auto transaction(inputValue);

		bankAccount = bankAccount + transaction;

		std::cout << bankAccount << std::endl;

		std::cout << "Press BackSpace for another Transaction, Escape for exit." << std::endl;
		auto waitinForResponse = true;

		while (waitinForResponse)
		{
			if (GetKeyState(VK_ESCAPE) & 0x8000 && waitinForResponse)
			{
				waitinForResponse = false;
				solutionRunning = false;
			}
			if (GetKeyState(VK_BACK) & 0x8000 && waitinForResponse)
			{
				waitinForResponse = false;
			}
		}
	}
}