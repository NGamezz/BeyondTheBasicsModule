#include "Matrix.h"

void Matrix::UpdateCells(sf::RenderWindow* window)
{
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			auto& currentCell = grid[x][y];
			int aliveNeighbours = CellNeighbours(currentCell.Position, grid);

			for (int i = 0; i < strategies.size(); i++)
			{
				if (strategies[i]->CheckCondition(currentCell.CheckState(), aliveNeighbours))
				{
					context.SetStrategy(std::move(strategies[i]));
				}
			}

			context.PerformStrategy(currentCell);

			int index = x * height + y;
			if (index < vertexArray.getVertexCount())
			{
				vertexArray[x * height + y] = currentCell.Vertex;
			}
		}
	}
	window->draw(&vertexArray[0], vertexArray.getVertexCount(), sf::Points);
}

void Matrix::SetRules()
{
	strategies.push_back(new IgnoreStrategy());
	strategies.push_back(new CellDieStrategy());
	strategies.push_back(new CellReviveStrategy());
}

bool Matrix::CreateMatrix(int _width, int _height)
{
	width = _width;
	height = _height;

	vertexArray = sf::VertexArray();

	for (int i = 0; i < width; i++)
	{
		std::vector<Cell> row;

		for (int j = 0; j < height; j++)
		{
			Cell cell(sf::Vector2f(i, j));
			vertexArray.append(cell.Vertex);
			row.push_back(cell);
		}
		grid.push_back(row);
	}
	SetRules();
	return true;
}

int Matrix::CellNeighbours(sf::Vector2f position, std::vector<std::vector<Cell>>& grid) const
{
	auto amount = 0;

	for (int x = -1; x <= 1; x++)
	{
		for (int y = -1; y <= 1; y++)
		{
			int xPos = position.x + x;
			int yPos = position.y + y;

			if (yPos >= height || yPos < 0 || xPos >= width || xPos < 0)
			{
				continue;
			}
			if (!grid[xPos][yPos].CheckState())
			{
				continue;
			}

			amount++;
		}
	}
	return amount;
}