#include "stdafx.h"
#include "SFML/Graphics.hpp"
#include <stdlib.h>
#include <time.h>
#include "Box.h" 

Box::Box() {

	shape.setPointCount(4);
	shape.setOrigin(sf::Vector2f(0,0));
	shape.setPosition(sf::Vector2f(rand() % 760 + 10, rand() % 560 + 10));

	shape.setPoint(0, sf::Vector2f(-20, -20));
	shape.setPoint(1, sf::Vector2f(20, -20));
	shape.setPoint(2, sf::Vector2f(20,20));
	shape.setPoint(3, sf::Vector2f(-20,20));

	corners.push_back(sf::Vector2f(shape.getPosition().x - 20, shape.getPosition().y - 20));
	corners.push_back(sf::Vector2f(corners[0].x + 40, corners[0].y));
	corners.push_back(sf::Vector2f(corners[0].x + 40, corners[0].y + 40));
	corners.push_back(sf::Vector2f(corners[0].x, corners[0].y + 40));
}
