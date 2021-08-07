//============================= include section ==============================
#include "Trash.h"
#include "PortalTrash.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
Trash::Trash(b2World& world,const sf::Vector2f& location, const sf::Vector2f& size, int ID, bool isPortal)
	: StaticObject(world, location, size, raffleTrash(isPortal), ID) {}
//============================================================================
int Trash::raffleTrash(bool isPortal)
{
	if (isPortal)
		return PORTAL_TRASH_T;
	return (rand() % 2) + TRASH_RED_T;
}
//============================== gets section ================================
//============================ methods section ===============================