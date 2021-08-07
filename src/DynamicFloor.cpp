#include "DynamicFloor.h"

DynamicFloor::DynamicFloor(b2World& world, const sf::Vector2f& location,
	const sf::Vector2f& size, int ID)
	: MovingObject(world, location, size, DYNAMIC_FLOOR_T, ID){}

void DynamicFloor::move(const sf::Time &deltaTime, Board &board) {
	b2Vec2 dirFromKey = b2Vec2(0, 0);
	if (getDirection() == RIGHT)
		dirFromKey = MRIGHT;
	else
		dirFromKey = MLEFT;
	setPhysicsObjectPos(sf::Vector2f(getLocation().x + dirFromKey.x, getLocation().y + dirFromKey.y), dirFromKey);
}

void DynamicFloor::updateAnimation(const sf::Time&){}


void DynamicFloor::setCollision()
{
	m_collided = true;
}
