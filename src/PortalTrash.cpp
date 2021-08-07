//============================= include section ==============================
#include "PortalTrash.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
PortalTrash::PortalTrash(b2World& world, const sf::Vector2f& location, const sf::Vector2f& size, int ID,bool isPortal)
	: Trash(world, location, size, ID, isPortal) {}
//============================================================================
