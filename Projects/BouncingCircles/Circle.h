#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {
private:
	sf::Vector2f position;
	sf::CircleShape circle;
	float angle;
	sf::Vector2f velocity;


public:
	Circle();
	void Move();
	void Bounce();
	void Draw(sf::RenderWindow &window);
};

#endif