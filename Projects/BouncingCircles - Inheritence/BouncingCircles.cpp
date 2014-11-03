////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "stdafx.h"
#ifdef _DEBUG
#pragma comment(lib,"sfml-graphics-d.lib")
#pragma comment(lib,"sfml-audio-d.lib")
#pragma comment(lib,"sfml-system-d.lib")
#pragma comment(lib,"sfml-window-d.lib")
#pragma comment(lib,"sfml-network-d.lib")
#else
#pragma comment(lib,"sfml-graphics.lib")
#pragma comment(lib,"sfml-audio.lib")
#pragma comment(lib,"sfml-system.lib")
#pragma comment(lib,"sfml-window.lib")
#pragma comment(lib,"sfml-network.lib")
#endif
#pragma comment(lib,"opengl32.lib")
#pragma comment(lib,"glu32.lib")
#include "SFML/Graphics.hpp"
#include "SFML/OpenGL.hpp"
#include "Triangle.h"
#include "Box.h"
#include "CollisionManager.h"

#include <iostream>

////////////////////////////////////////////////////////////
///Entrypoint of application
////////////////////////////////////////////////////////////

int main()
{
	sf::Clock clock;

	int const numTriangles = 10;
	int const numBoxes = 10;

	srand(time(NULL));
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(800, 600, 32), "SFML First Program");
	window.setFramerateLimit(60);

	//load a font
	sf::Font font;
	font.loadFromFile("C:\\Windows\\Fonts\\GARA.TTF");

	std::vector<Triangle> triangles;
	triangles.reserve(numTriangles);
	std::vector<Box> boxes;
	boxes.reserve(numBoxes);

	for (int i = 0; i < numTriangles; i++) {
		triangles.push_back(Triangle());
	}

	for (int i = 0; i < numBoxes; i++) {
		boxes.push_back(Box());
	}

	// Start game loop
	while (window.isOpen())
	{
		float frameRate = 1.f / clock.getElapsedTime().asSeconds();
		clock.restart();
		// Process events
		sf::Event Event;
		while (window.pollEvent(Event))
		{
			// Close window : exit
			if (Event.type == sf::Event::Closed)
				window.close();
			// Escape key : exit
			if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Escape))
				window.close();
		}
		//prepare frame
		window.clear();

		//movement and bouncing
		int triSize = triangles.size();
		int boxSize = boxes.size();

		for (int i = 0; i < triangles.size(); i++) {
			triangles[i].Move();
			triangles[i].Bounce();
		}
		for (int i = 0; i < boxSize; i++) {
			boxes[i].Move();
			boxes[i].Bounce();
			for (int j = 0; j < triSize; j++) {				
				if (CollisionManager::Instance()->DetectCollision(boxes[i], triangles[j])) {
					boxes[i].shape.setFillColor(sf::Color::Blue);
					triangles[j].shape.setFillColor(sf::Color::Green);
				}
			}
		}

		//handles the drawing of the shapes
		for (int i = 0; i < triangles.size(); i++) {
			triangles[i].Draw(window);
		}
		for (int i = 0; i < boxes.size() ; i++) {
			boxes[i].Draw(window);
		}



		// Finally, display rendered frame on screen
		window.display();
	} //loop back for next frame
	return EXIT_SUCCESS;
}