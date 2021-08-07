#include "Enemy.h"

Enemy::Enemy(float distanceLim, b2World& world ,const sf::Vector2f& location, 
    const sf::Vector2f& size, char objectType, int ID)
        : MovingObject(world, location, size, objectType, ID), m_distanceLimit(distanceLim){
}

void Enemy::updateAnimation(const sf::Time& deltaTime) {
    setAnimationTime(deltaTime);
    int spritesNum = (int)(getAnimationTime().asSeconds() / ANIMATIONS_RATE);
    if (Resources::instance().getNumOfSprites(ENEMY) <= spritesNum) {
        resetAnimationTime();
    }
    else {
        sf::IntRect updatedRect = getIntRect();
        updatedRect.left = spritesNum * 600;
        if (updatedRect.width < 0)
            updatedRect.left += 600;
        setOrigin();
        setIntRect(updatedRect);
    }
}