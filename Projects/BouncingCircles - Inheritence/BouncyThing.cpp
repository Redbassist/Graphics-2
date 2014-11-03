#include "stdafx.h"
#include "SFML/Graphics.hpp"
#include <stdlib.h>
#include <time.h>
#include "BouncyThing.h" 
#include "math.h"

BouncyThing::BouncyThing() {
	rotation = (float)(rand() % 10 + 2) / 100;

	translationTransform = sf::Transform();
	translationTransform.translate(0,0);

	rotationTransform = sf::Transform();
	rotationTransform.rotate(rotation);

	translationTransform.combine(rotationTransform);

	angle = rand() % 6;
	velocity.x = cos(angle) / 1;
	velocity.y = sin(angle) / 1;	

	axes.reserve(shape.getPointCount());
}

//NEEDS A COLLISION OCCURRED METHOD



void BouncyThing::Move() {
	
	for(int i = 0; i < corners.size(); i++) {

		corners[i] -= shape.getPosition();

		corners[i] = translationTransform.transformPoint(corners[i]);
	}

	shape.setPosition(shape.getPosition() + velocity);

	for(int i = 0; i < corners.size(); i++) {
			corners[i] += shape.getPosition();
	}
	shape.rotate(rotation);
}

void BouncyThing::Bounce() {

	for(int i = 0; i < corners.size(); i++) {
		if (corners[i].x < 0) {
			velocity.x = -(velocity.x);
			for(int j = 0; j < corners.size(); j++)
				corners[j] += sf::Vector2f(1,0);
			shape.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
			break;
		}
		else if (corners[i].y < 0) {
			velocity.y = -(velocity.y);
			for(int j = 0; j < corners.size(); j++)
				corners[j] += sf::Vector2f(0,1);
			shape.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
			break;
		}
		else if (corners[i].x > 800) {
			velocity.x = -(velocity.x);
			for(int j = 0; j < corners.size(); j++)
				corners[j] += sf::Vector2f(-1,0);
			shape.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
			break;
		}
		else if (corners[i].y > 600) { 
			velocity.y = -(velocity.y);
			for(int j = 0; j < corners.size(); j++)
				corners[i] += sf::Vector2f(0,-1);
			shape.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
			break;
		}
	}
	/*
	if (shape.getPointCount() == 4) {
		if (corner1.x < 0 || corner2.x < 0 || corner3.x < 0 || corner4.x < 0) {
			velocity.x = -(velocity.x);
			corner1 += sf::Vector2f(1,0);
			corner2 += sf::Vector2f(1,0);
			corner3 += sf::Vector2f(1,0);
			corner4 += sf::Vector2f(1,0);
			shape.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
		}
		else if (corner1.y < 0 || corner2.y < 0 || corner3.y < 0 || corner4.y < 0) {
			velocity.y = -(velocity.y);
			corner1 += sf::Vector2f(0,1);
			corner2 += sf::Vector2f(0,1);
			corner3 += sf::Vector2f(0,1);
			corner4 += sf::Vector2f(0,1);
			shape.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
		}
		else if (corner1.x > 800 || corner2.x > 800 || corner3.x > 800 || corner4.x > 800) {
			velocity.x = -(velocity.x);
			corner1 += sf::Vector2f(-1,0);
			corner2 += sf::Vector2f(-1,0);
			corner3 += sf::Vector2f(-1,0);
			corner4 += sf::Vector2f(-1,0);
			shape.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
		}
		else if (corner1.y > 600 || corner2.y > 600 || corner3.y > 600 || corner4.y > 600) {
			velocity.y = -(velocity.y);
			corner1 += sf::Vector2f(0,-1);
			corner2 += sf::Vector2f(0,-1);
			corner3 += sf::Vector2f(0,-1);
			corner4 += sf::Vector2f(0,-1);
			shape.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
		}
	}

	else {
		if (corner1.x < 0 || corner2.x < 0 || corner3.x < 0) {
			velocity.x = -(velocity.x);
			corner1 += sf::Vector2f(1,0);
			corner2 += sf::Vector2f(1,0);
			corner3 += sf::Vector2f(1,0);
			shape.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
		}
		else if (corner1.y < 0 || corner2.y < 0 || corner3.y < 0) {
			velocity.y = -(velocity.y);
			corner1 += sf::Vector2f(0,1);
			corner2 += sf::Vector2f(0,1);
			corner3 += sf::Vector2f(0,1);
			shape.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
		}
		else if (corner1.x > 800 || corner2.x > 800 || corner3.x > 800) {
			velocity.x = -(velocity.x);
			corner1 += sf::Vector2f(-1,0);
			corner2 += sf::Vector2f(-1,0);
			corner3 += sf::Vector2f(-1,0);
			shape.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
		}
		else if (corner1.y > 600 || corner2.y > 600 || corner3.y > 600) {
			velocity.y = -(velocity.y);
			corner1 += sf::Vector2f(0,-1);
			corner2 += sf::Vector2f(0,-1);
			corner3 += sf::Vector2f(0,-1);
			shape.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
		}
	}*/
}
	
void BouncyThing::Draw(sf::RenderWindow &window) {
	window.draw(shape);
}

void BouncyThing::applyMove(sf::Vector2f move) {
	for (int i = 0; i < corners.size(); i++)
		corners[i] += move;
	shape.setPosition(shape.getPosition() + move);
}

std::vector<sf::Vector2f> BouncyThing::getAxes() {
	//returns a normal to all the sides of the shape
	axes.clear();	
	sf::Vector2f temp;
	float length;
	int points = shape.getPointCount();

	for (int i = 0; i < points; i++) {

		//temp = sf::Vector2f(-(corners[i + 1].y - corners[i].y), corners[i + 1].x - corners[i].x);
		
		if (points - 1 > i) {
			temp = sf::Vector2f(-(corners[i + 1].y - corners[i].y), corners[i + 1].x - corners[i].x);
			length = (float)(sqrt(temp.x * temp.x + temp.y * temp.y));
			axes.push_back(sf::Vector2f(temp.x / length, temp.y / length));
		}
		else {
			temp = sf::Vector2f(-(corners[points - 1].y - corners[0].y), corners[points - 1].x - corners[0].x);
			length = (float)(sqrt(temp.x * temp.x + temp.y * temp.y));
			axes.push_back(sf::Vector2f(temp.x / length, temp.y / length));
		}
		

	}

	return axes;
}