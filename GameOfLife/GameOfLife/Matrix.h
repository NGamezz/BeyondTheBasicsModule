#pragma once

#include <vector>
#include "Cell.h"
#include "Context.h"
#include "Strategy.h"
#include "CellDieStrategy.h"
#include "IgnoreStrategy.h"
#include "CellReviveStrategy.h"
#include "SFML/Window.hpp"
#include <iostream>
#include <chrono>
#include <thread>

class Matrix
{
public:
	void UpdateCells(sf::RenderWindow* window);
	bool CreateMatrix(int width, int height);

private:
	void SetRules();
	int CellNeighbours(sf::Vector2f position, std::vector<std::vector<Cell>>& grid) const;
	Context context;
	sf::VertexArray vertexArray;
	std::vector<std::vector<Cell>> grid;
	int width = 0;
	int height = 0;
	std::vector<Strategy*> strategies;
};