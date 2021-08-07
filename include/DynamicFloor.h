#pragma once
#include "MovingObject.h"

class DynamicFloor: public MovingObject
{
public:
	DynamicFloor(b2World&, const sf::Vector2f & = sf::Vector2f(0, 0),
		const sf::Vector2f & = sf::Vector2f(0, 0), int ID = 0);

	virtual void move(const sf::Time &, Board &) override;
	void updateAnimation(const sf::Time&) override;
	void setCollision();
private:
	bool m_collided = false;
};

