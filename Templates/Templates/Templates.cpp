#include "Queue.h"
#include "Utility.h"

int main()
{
	std::vector<std::string> stringVector{ "b", "woudhawd", "iuug", "iuhwuiagugdwa", "a" };
	std::vector<float> floatVector{ 1.5f, 890, 2, 3987341, 98721, 2 };

	Custom::Utility::Sort(floatVector);
	Custom::Utility::PrintContents(floatVector);

	Custom::Utility::Sort(stringVector);
	Custom::Utility::PrintContents(stringVector);

	Custom::Queue<std::string> stringQueue;
	stringQueue.Put("First Element.");
	stringQueue.Put("Last Element.");
	std::cout << stringQueue.Get() << std::endl;
	std::cout << stringQueue.Size() << std::endl;
}