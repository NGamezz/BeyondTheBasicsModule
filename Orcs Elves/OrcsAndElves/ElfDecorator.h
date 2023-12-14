#pragma once

#include "Decorator.h"

class ElfDecorator : virtual public Decorator
{
public:
	~ElfDecorator() = default;
	void Decorate(NPC& npc) override;
};