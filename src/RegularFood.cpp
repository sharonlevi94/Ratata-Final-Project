//============================= include section ==============================
#include "RegularFood.h"
#include "Macros.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
RegularFood::RegularFood(b2World& world, const sf::Vector2f& location,
	const sf::Vector2f& size, int ID)
	:Food(world, location, size, raffleFood(), ID) {
	++m_foodCounter;
}
//========================== statics declaretions ============================
unsigned int RegularFood::m_foodCounter = 0;
//============================================================================
unsigned int RegularFood::getFoodCounter() { return m_foodCounter; }
//============================================================================
void RegularFood::collect()
{
    /// doing this if/else because some unsigned variable bugs. when using '--' it
    /// went to the top value possible of unsigned int.
	Food::collect();
	if (m_foodCounter-1 == 0 or m_foodCounter == 0) m_foodCounter = 0;
	else
	    --m_foodCounter;
}
//============================================================================
int RegularFood::raffleFood()
{
	return (rand() % 3) + WATERMELON_T;
}
//============================================================================
void RegularFood::resetFoodCounter() {
    m_foodCounter = 0;
}
//============================================================================