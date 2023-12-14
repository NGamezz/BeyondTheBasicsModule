#include "ShamanDecorator.h"

void ShamanDecorator::Decorate(NPC& npc)
{
	npc.Jobs.push_back("Shaman");
}