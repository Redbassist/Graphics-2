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
#include "Circle.h"
#include "Triangle.h"
#include "Box.h"

#include <iostream>

////////////////////////////////////////////////////////////
///Entrypoint of application
////////////////////////////////////////////////////////////

int main()
{
	int const numCircles = 20;
	int const numTriangles = 20;
	int const numBoxes = 20;

	srand(time(NULL));
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(800, 600, 32), "SFML First Program");
	//load a font
	sf::Font font;
	font.loadFromFile("C:\\Windows\\Fonts\\GARA.TTF");

	Circle circles[numCircles];
	Triangle triangles[numTriangles];
	Box boxes[numBoxes];

	for (int i = 0; i < numCircles; i++) {
		circles[i] = Circle();
	}	

	for (int i = 0; i < numTriangles; i++) {
		triangles[i] = Triangle();
	}

	for (int i = 0; i < numBoxes; i++) {
		boxes[i] = Box();
	}

	// Start game loop
	while (window.isOpen())
	{
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

		for (int i = 0; i < numCircles; i++) {
			circles[i].Move();
			circles[i].Bounce();
		}

		for (int i = 0; i < numTriangles; i++) {
			triangles[i].Move();
			triangles[i].Bounce();
		}

		for (int i = 0; i < numBoxes; i++) {
			boxes[i].Move();
			boxes[i].Bounce();
		}
		for (int i = 0; i < numCircles; i++) {
			circles[i].Draw(window);
		}
		for (int i = 0; i < numTriangles; i++) {
			triangles[i].Draw(window);
		}
		for (int i = 0; i < numBoxes; i++) {
			boxes[i].Draw(window);
		}



		// Finally, display rendered frame on screen
		window.display();
	} //loop back for next frame
	return EXIT_SUCCESS;
}