//============================= include section ==============================
#include "Food.h"
#include "SFML/Graphics.hpp"
#include "Macros.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
Food::Food(b2World& world, const sf::Vector2f& location,
	const sf::Vector2f& size,
	char objectType,int ID)
	: StaticObject(world, location, size, objectType,ID),
	m_is_collected(false) {}
//============================== gets section ================================
//============================ methods section ===============================
bool Food::is_collected()const { return (m_is_collected); }
////============================================================================
void Food::draw(sf::RenderWindow& window) {
	if (!m_is_collected)
		GameObject::draw(window);
}
//============================================================================
/*this method change the state of the food after the player collected it.*/
void Food::collect() { 
	m_is_collected = true;
}
//============================================================================
void Food::reset()
{
	m_is_collected = false;
}
