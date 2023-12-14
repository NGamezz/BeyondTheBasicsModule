#pragma once

#include "NPC.h"

class Decorator
{
public:
	virtual ~Decorator() = default;
	virtual void Decorate(NPC& npc) = 0;
};