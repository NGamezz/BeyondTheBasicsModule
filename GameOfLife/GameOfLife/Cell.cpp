#include "Cell.h"

void Cell::SetActive(bool state)
{
	isActive = state;
	Vertex.color = state ? sf::Color::White : sf::Color::Black;
}

bool Cell::CheckState() const
{
	return isActive;
}

Cell::Cell(sf::Vector2f position)
{
	Position = position;
	Vertex = sf::Vertex();
	Vertex.position = position;

	int random = std::rand();
	SetActive((random % 2));
}
