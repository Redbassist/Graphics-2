#include "stdafx.h"
#include "SFML/Graphics.hpp"
#include <stdlib.h>
#include <time.h>
#include "Box.h" 

Box::Box() {
	rotation = (float)(rand() % 10 + 2) / 100;

	translationTransform = sf::Transform();
	translationTransform.translate(0,0);

	rotationTransform = sf::Transform();
	rotationTransform.rotate(rotation);

	translationTransform.combine(rotationTransform);

	box.setPointCount(4);
	box.setOrigin(sf::Vector2f(0,0));
	box.setPosition(sf::Vector2f(rand() % 760 + 10, rand() % 560 + 10));

	box.setPoint(0, sf::Vector2f(-20, -20));
	box.setPoint(1, sf::Vector2f(20, -20));
	box.setPoint(2, sf::Vector2f(20,20));
	box.setPoint(3, sf::Vector2f(-20,20));

	corner1 = sf::Vector2f(box.getPosition().x - 20, box.getPosition().y - 20);
	corner2 = sf::Vector2f(corner1.x + 40, corner1.y);
	corner3 = sf::Vector2f(corner1.x + 40, corner1.y + 40);
	corner4 = sf::Vector2f(corner1.x, corner1.y + 40);

	angle = rand() % 6;
	velocity.x = cos(angle) / 20;
	velocity.y = sin(angle) / 20;
}

void Box::Move() {
	
	corner1 -= box.getPosition();
	corner2 -= box.getPosition();
	corner3 -= box.getPosition();
	corner4 -= box.getPosition();
	
	corner1 = translationTransform.transformPoint(corner1);
	corner2 = translationTransform.transformPoint(corner2);
	corner3 = translationTransform.transformPoint(corner3);
	corner4 = translationTransform.transformPoint(corner4);

	box.setPosition(box.getPosition() + velocity);

	corner1 += box.getPosition();
	corner2 += box.getPosition();
	corner3 += box.getPosition();
	corner4 += box.getPosition();

	box.rotate(rotation);
}

void Box::Draw(sf::RenderWindow &window) {
	window.draw(box);
}

void Box::Bounce() {
	if (corner1.x < 0 || corner2.x < 0 || corner3.x < 0 || corner4.x < 0) {
		velocity.x = -(velocity.x);
		corner1 += sf::Vector2f(1,0);
		corner2 += sf::Vector2f(1,0);
		corner3 += sf::Vector2f(1,0);
		corner4 += sf::Vector2f(1,0);
		box.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
	}
	else if (corner1.y < 0 || corner2.y < 0 || corner3.y < 0 || corner4.y < 0) {
		velocity.y = -(velocity.y);
		corner1 += sf::Vector2f(0,1);
		corner2 += sf::Vector2f(0,1);
		corner3 += sf::Vector2f(0,1);
		corner4 += sf::Vector2f(0,1);
		box.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
	}
	else if (corner1.x > 800 || corner2.x > 800 || corner3.x > 800 || corner4.x > 800) {
		velocity.x = -(velocity.x);
		corner1 += sf::Vector2f(-1,0);
		corner2 += sf::Vector2f(-1,0);
		corner3 += sf::Vector2f(-1,0);
		corner4 += sf::Vector2f(-1,0);
		box.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
	}
	else if (corner1.y > 600 || corner2.y > 600 || corner3.y > 600 || corner4.y > 600) {
		velocity.y = -(velocity.y);
		corner1 += sf::Vector2f(0,-1);
		corner2 += sf::Vector2f(0,-1);
		corner3 += sf::Vector2f(0,-1);
		corner4 += sf::Vector2f(0,-1);
		box.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
	}
}