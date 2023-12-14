#pragma once

#include <vector>
#include <string>
#include <iostream>

class NPC
{
public:
	NPC(std::string name);
	std::string Name;
	std::string Type = "NPC has no type";
	std::vector<std::string> Jobs;
	void Render() const;
};

