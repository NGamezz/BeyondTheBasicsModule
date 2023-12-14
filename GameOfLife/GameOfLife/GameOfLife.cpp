#include "Matrix.h"
#include <Windows.h>

using namespace std;

int main()
{
	auto width = 800;
	auto height = 800;

	auto matrix = Matrix();
	if (!matrix.CreateMatrix(width, height))
	{
		return 0;
	};
	cout << "Created Matrix " << endl;

	sf::RenderWindow window(sf::VideoMode(width, height), "Game Of LIfe Window");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		window.clear(sf::Color::Black);
		matrix.UpdateCells(&window);

		window.display();
		Sleep(200);
	}
}