#include "NPC.h"

NPC::NPC(std::string name)
{
	Name = name;
}

void NPC::Render() const
{
	std::cout << "NPC Name is = " << Name << "\n";
	std::cout << "NPC Type is = " << Type << "\n";

	if (Jobs.size() < 1)
	{
		std::cout << "NPC has no job.\n";
	}
	else
	{
		for (auto& job : Jobs)
		{
			std::cout << "Job = " << job << "\n";
		}
	}
	std::cout << std::endl;
}