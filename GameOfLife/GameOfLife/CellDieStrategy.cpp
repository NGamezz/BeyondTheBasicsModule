#include "CellDieStrategy.h"

void CellDieStrategy::Execute(Cell& cell)
{
	cell.SetActive(false);
}

bool CellDieStrategy::CheckCondition(bool state, int aliveNeighbours) const
{
	if (aliveNeighbours > 3 || aliveNeighbours < 2)
	{
		return true;
	}
	return false;
}