#include "Context.h"

void Context::SetStrategy(Strategy* strategy)
{
	this->strategy = std::move(strategy);
}

void Context::PerformStrategy(Cell& cell) const
{
	if (strategy)
	{
		strategy->Execute(cell);
	}
}