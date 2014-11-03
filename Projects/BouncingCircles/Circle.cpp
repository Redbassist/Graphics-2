#include "stdafx.h"
#include "SFML/Graphics.hpp"
#include <stdlib.h>
#include <time.h>
#include "Circle.h"

Circle::Circle() {
	circle.setRadius(20);
	circle.setOrigin(circle.getPosition().x + 10, circle.getPosition().y + 10);
	circle.setPosition((rand() % 760 + 10), (rand() % 560 + 10));
	angle = rand() % 6;
	velocity.x = cos(angle) / 20;
	velocity.y = sin(angle) / 20;
}

void Circle::Move() {
	circle.setPosition(circle.getPosition() + velocity);
}

void Circle::Draw(sf::RenderWindow &window) {
	window.draw(circle); 
}

void Circle::Bounce() {
	if (circle.getPosition().x < 10) {
		circle.setPosition(sf::Vector2f(10, circle.getPosition().y));
		velocity.x = -(velocity.x);
		circle.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
	}
	else if (circle.getPosition().y < 10) {
		circle.setPosition(sf::Vector2f(circle.getPosition().x, 10));
		velocity.y = -(velocity.y);
		circle.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
	}
	else if (circle.getPosition().x > 775) {
		circle.setPosition(sf::Vector2f(775, circle.getPosition().y));
		velocity.x = -(velocity.x);
		circle.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
	}
	else if (circle.getPosition().y > 575) {
		circle.setPosition(sf::Vector2f(circle.getPosition().x, 575));
		velocity.y = -(velocity.y);
		circle.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
	}
}