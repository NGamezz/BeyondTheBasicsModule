#pragma once

#include "Decorator.h"

class ShamanDecorator : virtual public Decorator
{
public:
	~ShamanDecorator() = default;
	void Decorate(NPC& npc) override;
};