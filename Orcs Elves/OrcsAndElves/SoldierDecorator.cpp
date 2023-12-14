#include "SoldierDecorator.h"

void SoldierDecorator::Decorate(NPC& npc)
{
	npc.Jobs.push_back("Soldier");
}