#include "FarmerDecorator.h"

void FarmerDecorator::Decorate(NPC& npc)
{
	npc.Jobs.push_back("Farmer");
}