
#ifndef BOX_H
#define BOX_H

class Box {
private:
	sf::ConvexShape box;
	float angle;
	sf::Vector2f velocity;
	sf::Vector2f corner1;
	sf::Vector2f corner2;
	sf::Vector2f corner3;
	sf::Vector2f corner4;
	float rotation;
	sf::Transform translationTransform;
	sf::Transform rotationTransform;

public:
	Box();
	void Move();
	void Bounce();
	void Draw(sf::RenderWindow &window);
};

#endif