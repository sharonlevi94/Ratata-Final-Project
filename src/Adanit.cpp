//============================= include section ==============================
#include "Adanit.h"
//============================= public section ===============================
//==================== Constructors & distructors section ====================
Adanit::Adanit(b2World& world, const sf::Vector2f& location, const sf::Vector2f& size, int ID)
	: StaticObject(world, location, size, raffleTexture(), ID) {}

//============================== gets section ================================
//============================ methods section ===============================
int Adanit::raffleTexture() { return (rand() % 3) + ADANIT_KAHOL_T; }