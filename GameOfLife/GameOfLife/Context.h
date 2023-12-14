#pragma once
#include "Strategy.h"
#include <memory>

class Context
{
public:
	void SetStrategy(Strategy* strategy);
	void PerformStrategy(Cell& cell) const;
private:
	Strategy* strategy;
};