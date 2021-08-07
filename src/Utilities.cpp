//============================= include section ==============================
#include "Utilities.h"
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <iostream>
#include "Exterminator.h"
#include "Scooter.h"
#include "Enemy.h"
#include <cmath>
//============================ functions section ==============================
sf::Vector2f calcScale(const sf::Vector2f& size,
	const sf::Vector2f& scale,
	const sf::Vector2f& textureSize) {
	float x = (size.x / scale.x) / textureSize.x,
		y = (size.y / scale.y) / textureSize.y;

	return sf::Vector2f((size.x / scale.x) / textureSize.x,
		(size.y / scale.y) / textureSize.y);
}
//========================================================================
sf::Vector2f calcScreenLocation(const sf::Vector2f& ScreenSize,
	const sf::Vector2f& mapSize,
	const sf::Vector2f& location) {
	return sf::Vector2f((ScreenSize.x / mapSize.x) * location.x,
		(ScreenSize.y / mapSize.y) * location.y);
}
//========================================================================
float calcDistance(const sf::Vector2f& from, const sf::Vector2f& to) {
	return std::sqrt(std::pow(to.x - from.x, 2) +
					std::pow(to.y - from.y, 2) * 1.0);
}

void setText(sf::Text& message, std::string str, sf::Vector2f pos)
{
	message.setFont(Resources::instance().getFont());
	message.setString(str);
	message.setPosition(pos);
	message.setCharacterSize(50);
	message.setFillColor(sf::Color(0, 0, 0, 255));
}