#pragma once
#include "Strategy.h"

class IgnoreStrategy : virtual public Strategy
{
public:
	~IgnoreStrategy() = default;
	void Execute(Cell& cell) override;
	bool CheckCondition(bool state, int aliveNeighbours) const override;
};