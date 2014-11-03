#include "stdafx.h"
#include "SFML/Graphics.hpp"
#include <stdlib.h>
#include <time.h>
#include "Triangle.h" 

Triangle::Triangle() {

	shape.setPointCount(3);
	shape.setOrigin(sf::Vector2f(0,0));
	shape.setPosition(sf::Vector2f(rand() % 760 + 10, rand() % 560 + 10));

	shape.setPoint(0, sf::Vector2f(0, -15));
	shape.setPoint(1, sf::Vector2f(20, 15));
	shape.setPoint(2, sf::Vector2f(-20,15));

	corners.push_back(sf::Vector2f(shape.getPosition().x, shape.getPosition().y - 15));
	corners.push_back(sf::Vector2f(corners[0].x - 20, corners[0].y + 30));
	corners.push_back(sf::Vector2f(corners[0].x + 20, corners[0].y + 30));
}