#pragma once

#include "Decorator.h"

class SoldierDecorator : virtual public Decorator
{
public:
	~SoldierDecorator() = default;
	void Decorate(NPC& npc) override;
};