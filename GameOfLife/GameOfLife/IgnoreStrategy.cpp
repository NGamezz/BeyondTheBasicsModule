#include "IgnoreStrategy.h"

void IgnoreStrategy::Execute(Cell& cell)
{
}

bool IgnoreStrategy::CheckCondition(bool state, int aliveNeighbours) const
{
	if ((!state && aliveNeighbours < 3) || (aliveNeighbours == 2 || aliveNeighbours == 3 && state))
	{
		return true;
	}
	return false;
}