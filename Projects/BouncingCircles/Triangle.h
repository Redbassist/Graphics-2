
#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle {
private:
	sf::ConvexShape triangle;
	float angle;
	sf::Vector2f velocity;
	sf::Vector2f corner1;
	sf::Vector2f corner2;
	sf::Vector2f corner3;
	float rotation;
	sf::Transform translationTransform;
	sf::Transform rotationTransform;

public:
	Triangle();
	void Move();
	void Bounce();
	void Draw(sf::RenderWindow &window);
};

#endif