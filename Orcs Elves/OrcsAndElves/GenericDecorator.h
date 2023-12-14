#pragma once
#include "Decorator.h"

class GenericDecorator : virtual public Decorator
{
public:
	GenericDecorator(std::string, bool isJob);
	void Decorate(NPC& npc) override;
private:
	std::string type;
	bool isJob;
};