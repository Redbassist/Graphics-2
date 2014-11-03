#ifndef COLLISION_MANAGER_H
#define COLLISION_MANAGER_H

class CollisionManager {
public:
	static CollisionManager* Instance();
	bool DetectCollision(BouncyThing &shape1, BouncyThing &shape2);
	sf::Vector2f Projection(BouncyThing &sentShape, sf::Vector2f axis);
	float DotProduct(sf::Vector2f one, sf::Vector2f two);

private:
	CollisionManager();
	static CollisionManager* m_instance;

};

#endif