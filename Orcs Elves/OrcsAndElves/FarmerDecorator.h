#pragma once

#include "Decorator.h"

class FarmerDecorator : virtual public Decorator
{
public:
	~FarmerDecorator() = default;
	void Decorate(NPC& npc) override;
};