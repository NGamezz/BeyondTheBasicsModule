#pragma once
#include "Strategy.h"

class CellReviveStrategy : virtual public Strategy
{
public:
	~CellReviveStrategy() = default;
	void Execute(Cell& cell)  override;
	bool CheckCondition(bool state, int aliveNeighbours) const override;
};