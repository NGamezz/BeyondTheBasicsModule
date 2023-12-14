#pragma once

#include "Decorator.h"

class OrcDecorator : virtual public Decorator
{
public:
	~OrcDecorator() = default;
	void Decorate(NPC& npc) override;
};