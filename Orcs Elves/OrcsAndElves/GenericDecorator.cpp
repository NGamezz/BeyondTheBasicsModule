#include "GenericDecorator.h"

void GenericDecorator::Decorate(NPC& npc)
{
	if (isJob)
	{
		npc.Jobs.push_back(type);
	}
	else
	{
		npc.Type = type;
	}
}

GenericDecorator::GenericDecorator(std::string type, bool isJob)
{
	this->type = type;
	this->isJob = isJob;
}