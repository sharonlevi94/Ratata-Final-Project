#include "Exterminator.h"
#include "Macros.h"
#include "Board.h"
#include <cstdlib>
//=============================================================================

Exterminator::Exterminator(float distanceLim,b2World& world, const sf::Vector2f& location,
	const sf::Vector2f& size, int ID)
	: Enemy(distanceLim, world, location, size, EXTERMINATOR_T, ID) {
	flipSprite(sf::Vector2f(-1.f, 1.f));
}
//=============================================================================

void Exterminator::setCollision(int collisionState) { m_collided = collisionState; }

//=============================================================================

void Exterminator::flipDirection(int direction)
{
	if (direction == LEFT) {
		if (getDirection() == RIGHT) {
			setDirection(LEFT);
			flipSprite(sf::Vector2f(-1.f, 1.f));
		}
	}
	else {
		if (getDirection() == LEFT) {
			setDirection(RIGHT);
			flipSprite(sf::Vector2f(-1.f, 1.f));
		}
	}
}

//=============================================================================

void Exterminator::move(const sf::Time& deltaTime, Board& currentLevel) {
	sf::Vector2f playerLocation = currentLevel.getPlayerLoc();
	int playerState = currentLevel.getPlayerState();
	b2Vec2 dirFromKey = b2Vec2(0, 0);

	updateAnimation(deltaTime);
	switch (m_collided)
	{
	case TRASH_C:
		if (getDirection() == RIGHT)
			dirFromKey = b2Vec2(MRIGHT.x, MUP.y);
		else
			dirFromKey = b2Vec2(MLEFT.x, MUP.y);
		m_collided = NOT_COLLIDED;
		break;
	case ADANIT_C:
		dirFromKey = b2Vec2(0, getLinearVelocity().y);
		m_collided = NOT_COLLIDED;
		break;
	default: //not collided
		//the enemy is right to player:
		if (getLocation().x > playerLocation.x) {
			dirFromKey = b2Vec2(MLEFT.x, getLinearVelocity().y);
			if(getLocation().x - playerLocation.x > 20)
				flipDirection(LEFT);
			//updateAnimation(deltaTime);
			
		} //enemy is left to player:
		else if (getLocation().x < playerLocation.x) {
			dirFromKey = b2Vec2(MRIGHT.x, getLinearVelocity().y);
			if (playerLocation.x - getLocation().x > 20)
				flipDirection(RIGHT);
		}
		break;
	}
	setPhysicsObjectPos(sf::Vector2f(getLocation().x + dirFromKey.x, getLocation().y+ dirFromKey.y), dirFromKey);
}