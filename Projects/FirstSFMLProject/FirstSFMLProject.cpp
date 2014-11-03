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
#include <iostream>
 
 
////////////////////////////////////////////////////////////
///Entrypoint of application
////////////////////////////////////////////////////////////
 
int main()
{
// Create the main window
sf::RenderWindow window(sf::VideoMode(800, 600, 32), "SFML First Program");
//load a font
sf::Font font;
font.loadFromFile("C:\\Windows\\Fonts\\GARA.TTF");
 
//create a formatted text string
sf::Text text;
text.setFont(font);
text.setString("Hello World");
text.setStyle(sf::Text::Underlined| sf::Text::Italic | sf::Text::Bold);
text.setPosition(20,40);
text.setCharacterSize(40);

//creating a line
sf::RectangleShape line(sf::Vector2f(150,2));
line.setPosition(0,100);
line.rotate(60);

//creating a star
sf::ConvexShape convex;
convex.setPointCount(10);

convex.setPoint(0, sf::Vector2f(6.5, 0));
convex.setPoint(1, sf::Vector2f(9, 5));
convex.setPoint(2, sf::Vector2f(14, 5.5));
convex.setPoint(3, sf::Vector2f(10.5, 9));
convex.setPoint(4, sf::Vector2f(12, 14));
convex.setPoint(5, sf::Vector2f(6.5, 11.5));
convex.setPoint(6, sf::Vector2f(2, 14));
convex.setPoint(7, sf::Vector2f(3.5, 9));
convex.setPoint(8, sf::Vector2f(0, 5.5));
convex.setPoint(9, sf::Vector2f(5, 5));

//creating a sprite
sf::Texture texture;
texture.loadFromFile("Deadpool.png");

sf::Sprite mySprite;
mySprite.setTexture(texture);
mySprite.setScale(0.5f,0.5f);
mySprite.setColor(sf::Color::White);
mySprite.setPosition(20, 150);

//creating a rectangle
sf::RectangleShape rectangle;
rectangle.setSize(sf::Vector2f(50, 70));
rectangle.setOutlineColor(sf::Color::Blue);
rectangle.setOutlineThickness(10);
rectangle.setPosition(500, 200);

//create a circle
sf::CircleShape circle(50);
circle.setPosition(300,200);

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
	 
	//draw frame items
	window.draw(text);
 
	window.draw(line);
	window.draw(convex);
	window.draw(mySprite);
	window.draw(rectangle);
	window.draw(circle);
	// Finally, display rendered frame on screen
	window.display();
} //loop back for next frame
return EXIT_SUCCESS;
}