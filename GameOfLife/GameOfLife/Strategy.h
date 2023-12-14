#pragma once

#include "Cell.h"

class Strategy
{
public:
	virtual ~Strategy() = default;
	virtual void Execute(Cell& cell) = 0;
	virtual bool CheckCondition(bool state, int aliveNeighbours) const;
};