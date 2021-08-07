//============================= include section ==============================
#include "ToxicFood.h"
#include "Macros.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
ToxicFood::ToxicFood(b2World& world, const sf::Vector2f& location,
	const sf::Vector2f& size, int ID)
	:Food(world, location, size, APPLE_T, ID) {}
//============================================================================