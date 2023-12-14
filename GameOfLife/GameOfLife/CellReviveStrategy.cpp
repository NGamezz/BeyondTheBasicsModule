#include "CellReviveStrategy.h"

void CellReviveStrategy::Execute(Cell& cell)
{
	cell.SetActive(true);
}

bool CellReviveStrategy::CheckCondition(bool state, int aliveNeighbours) const
{
	if (aliveNeighbours == 3)
	{
		return true;
	}
	return false;
}