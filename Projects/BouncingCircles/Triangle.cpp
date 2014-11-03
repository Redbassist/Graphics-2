#include "stdafx.h"
#include "SFML/Graphics.hpp"
#include <stdlib.h>
#include <time.h>
#include "Triangle.h" 

Triangle::Triangle() {
	rotation = (float)(rand() % 10 + 2) / 100;

	translationTransform = sf::Transform();
	translationTransform.translate(0,0);

	rotationTransform = sf::Transform();
	rotationTransform.rotate(rotation);

	translationTransform.combine(rotationTransform);

	triangle.setPointCount(3);
	triangle.setOrigin(sf::Vector2f(0,0));
	triangle.setPosition(sf::Vector2f(rand() % 760 + 10, rand() % 560 + 10));
	triangle.setPoint(0, sf::Vector2f(0, -15));
	triangle.setPoint(1, sf::Vector2f(20, 15));
	triangle.setPoint(2, sf::Vector2f(-20,15));
	corner1 = sf::Vector2f(triangle.getPosition().x, triangle.getPosition().y - 15);
	corner2 = sf::Vector2f(corner1.x - 20, corner1.y + 30);
	corner3 = sf::Vector2f(corner1.x + 20, corner1.y + 30);
	angle = rand() % 6;
	velocity.x = cos(angle) / 20;
	velocity.y = sin(angle) / 20;
}

void Triangle::Move() {
	
	corner1 -= triangle.getPosition();
	corner2 -= triangle.getPosition();
	corner3 -= triangle.getPosition();
	
	corner1 = translationTransform.transformPoint(corner1);
	corner2 = translationTransform.transformPoint(corner2);
	corner3 = translationTransform.transformPoint(corner3);

	triangle.setPosition(triangle.getPosition() + velocity);

	corner1 += triangle.getPosition();
	corner2 += triangle.getPosition();
	corner3 += triangle.getPosition();

	triangle.rotate(rotation);
}

void Triangle::Draw(sf::RenderWindow &window) {
	window.draw(triangle);
}

void Triangle::Bounce() {
	if (corner1.x < 0 || corner2.x < 0 || corner3.x < 0) {
		velocity.x = -(velocity.x);
		corner1 += sf::Vector2f(1,0);
		corner2 += sf::Vector2f(1,0);
		corner3 += sf::Vector2f(1,0);
		triangle.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
	}
	else if (corner1.y < 0 || corner2.y < 0 || corner3.y < 0) {
		velocity.y = -(velocity.y);
		corner1 += sf::Vector2f(0,1);
		corner2 += sf::Vector2f(0,1);
		corner3 += sf::Vector2f(0,1);
		triangle.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
	}
	else if (corner1.x > 800 || corner2.x > 800 || corner3.x > 800) {
		velocity.x = -(velocity.x);
		corner1 += sf::Vector2f(-1,0);
		corner2 += sf::Vector2f(-1,0);
		corner3 += sf::Vector2f(-1,0);
		triangle.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
	}
	else if (corner1.y > 600 || corner2.y > 600 || corner3.y > 600) {
		velocity.y = -(velocity.y);
		corner1 += sf::Vector2f(0,-1);
		corner2 += sf::Vector2f(0,-1);
		corner3 += sf::Vector2f(0,-1);
		triangle.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
	}
}