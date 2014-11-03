#include "stdafx.h"
#include "SFML/Graphics.hpp"
#include <stdlib.h>
#include <time.h>
#include "BouncyThing.h"
#include "CollisionManager.h" 
#include <math.h>

CollisionManager* CollisionManager::m_instance = NULL;

CollisionManager* CollisionManager::Instance() {
	if (!m_instance)
		m_instance = new CollisionManager();

	return m_instance;
}

CollisionManager::CollisionManager() {
}

bool CollisionManager::DetectCollision(BouncyThing &shape1, BouncyThing &shape2) {
	
	std::vector<sf::Vector2f> axis = shape1.getAxes();
	sf::Vector2f smallestAxis;
	double smallestOverlap = 100000000;
	bool shape1SA = false;
	bool shape2SA = false;

	for (int i = 0; i < shape1.getAxes().size(); i++) {

		sf::Vector2f p = Projection(shape1,axis[i]);
		sf::Vector2f p2 = Projection(shape2,axis[i]);
		
		//checking if there is a gap between the shapes on the project axis
		if (p.y < p2.x || p.x > p2.y)
			return false;

		//getting the smallest overlap value between the two shapes (MTV)
		if (p.y > p2.y) {
			if ((p2.y - p.x) < smallestOverlap) {
				smallestOverlap = p2.y - p.x;
				smallestAxis = axis[i];
				shape1SA = true;
			}
		}
		else {
			if ((p.y - p2.x) < smallestOverlap) {
				smallestOverlap =p.y - p2.x;
				smallestAxis = axis[i];
				shape1SA = true;
			}
		}
	}
	
	axis = shape2.getAxes();

	for (int i = 0; i < shape2.getAxes().size(); i++) {

		sf::Vector2f p = Projection(shape2,axis[i]);
		sf::Vector2f p2 = Projection(shape1,axis[i]);
		
		//checking if there is a gap between the shapes on the projection axis
		if (p.y < p2.x || p.x > p2.y)
			return false;

		//getting the smallest overlap value between the two shapes (MTV)
		if (p.y > p2.y) {
			if ((p2.y - p.x) < smallestOverlap) {
				smallestOverlap = p2.y - p.x;
				smallestAxis = axis[i];
				shape1SA = false;
				shape2SA = true;
			}
		}
		else {
			if ((p.y - p2.x) < smallestOverlap) {
				smallestOverlap =p.y - p2.x;
				smallestAxis = axis[i];
				shape1SA = false;
				shape2SA = true;
			}
		}
	}

	//if we get to this point, then every axis had an overlap-----------------------------------------------------------------------------------------
	//if we get to this point, then every axis had an overlap-----------------------------------------------------------------------------------------

	//getting the minimum translation vector and applying it to the two shapes to seperate them.
	smallestAxis.x = (smallestAxis.x * smallestOverlap) /2;
	smallestAxis.y = (smallestAxis.y * smallestOverlap) /2;

	if (shape1SA = true) {
		shape1.applyMove(smallestAxis);
		shape2.applyMove(-smallestAxis);
	}
	else if (shape2SA = true) {
		shape2.applyMove(smallestAxis);
		shape1.applyMove(-smallestAxis);
	}

	//reflecting the two shapes vectors using the normal between the two mid points of the shapes
	sf::Vector2f normal = shape1.shape.getPosition() - shape2.shape.getPosition();
	normal = normal / sqrt((normal.x * normal.x) + (normal.y * normal.y));
	sf::Vector2f outVect1 = shape1.velocity - (((DotProduct(normal, shape1.velocity) * normal)) + ((DotProduct(normal, shape1.velocity) * normal)));
	normal = -normal;
	sf::Vector2f outVect2 = shape2.velocity - (((DotProduct(normal, shape2.velocity) * normal)) + ((DotProduct(normal, shape2.velocity) * normal)));

	shape1.velocity = outVect1;
	shape2.velocity = outVect2;

	return true;
}

sf::Vector2f CollisionManager::Projection(BouncyThing & sentShape, sf::Vector2f axis) {
	float min = DotProduct(axis, sentShape.corners[0]);
	float max = min;

	int corners = sentShape.shape.getPointCount();

	for (int i = 0; i < corners; i++) {
		float p = DotProduct(axis, sentShape.corners[i]);
		if (p < min)
			min = p;
		else if (p > max)
			max = p;
	}

	return sf::Vector2f(min, max);

}

float CollisionManager::DotProduct(sf::Vector2f one, sf::Vector2f two) {
	return (one.x * two.x) + (one.y * two.y);
}