#ifndef BOUNCY_THING_H
#define BOUNCY_THING_H

class BouncyThing {
private:

public:
	BouncyThing();
	//methods
	void Move();
	void Bounce();
	void Draw(sf::RenderWindow &window);
	std::vector<sf::Vector2f> getAxes();
	void applyMove(sf::Vector2f move);
	
	//variables
	sf::ConvexShape shape;
	sf::Vector2f velocity;
	float angle;
	float rotation;
	sf::Transform translationTransform;
	sf::Transform rotationTransform;

	std::vector<sf::Vector2f> faceNormals;
	std::vector<sf::Vector2f> corners;
	std::vector<sf::Vector2f> axes;
	/*
	sf::Vector2f corner1;
	sf::Vector2f corner2;
	sf::Vector2f corner3;
	sf::Vector2f corner4;*/

};

#endif