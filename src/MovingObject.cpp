#include "MovingObject.h"
#include "Resources.h"
#include <iostream>
//==================== Constructors & destructors section ====================
MovingObject::MovingObject(b2World& world, const sf::Vector2f& location,
    const sf::Vector2f& size, int objectType,int ID)
    : GameObject(DYNAMIC, world, location, size, objectType, true,ID),
	m_direction(RIGHT), m_state(IDLE), m_initialLocation(location)
{
    m_objectSprite = getSpritePtr();
}

//===========================================================================
void MovingObject::setState(int state, int height, int width, int regOffset, int specialOffset) {
    int offset;
    switch (state) {
        case RUN:
            offset = height + regOffset;
            break;
        case JUMP: /// Also applies to 'FALL' state
            offset = 2 * height + regOffset + specialOffset;
            break;
        case DIE:
            offset = DIE * height + regOffset + specialOffset;
            break;
        default:
            offset = 0;
            break;
    }
    //std:: cout << offset << " state: " << state << " mstate  " << m_state << '\n';

	if (m_state != state) {
		sf::IntRect updatedRect = getIntRect();
		updatedRect.top = offset;
		updatedRect.left = 0;
		if (updatedRect.width < 0)
			updatedRect.left += width;
		setIntRect(updatedRect);
	}
	m_state = state;
}
//===========================================================================
int MovingObject::getState()const {
    return m_state;
}
//===========================================================================
void MovingObject::setDirection(int direction) {
    m_direction = direction;
}
//===========================================================================
int MovingObject::getDirection()const {
    return m_direction;
}
//===========================================================================
sf::Vector2f MovingObject::getInitialLocation() const
{
	return m_initialLocation;
}
//===========================================================================
void MovingObject::reset()
{
    setState(IDLE, PLAYER_BOX_HEIGHT, PLAYER_BOX_WIDTH, PLAYER_OFFSET, PLAYER_SPECIAL_OFFSET);
    setPhysicsObjectPos(getInitialLocation(), b2Vec2(0, 0));
}
//===========================================================================
void MovingObject::resetAnimationTime() {
    m_animationTime = sf::seconds(0);
}
//===========================================================================
//sf::Sprite MovingObject::getObjectSprite() {
//    return *m_objectSprite;
//}
//===========================================================================
void MovingObject::setAnimationTime(const sf::Time & deltaTime) {
    m_animationTime += deltaTime;
}
//===========================================================================
sf::Time MovingObject::getAnimationTime() const {
    return m_animationTime;
}