//============================ include section ===============================
#pragma once
#include "MovingObject.h"
/*============================================================================
* Class: Enemy.
* This class is the base class of the diff types of the enemies. 
 ============================================================================*/
class Enemy: public MovingObject
{
	//========================== public section ==============================
public:
	//================= constractors and destractors section =================
    explicit Enemy(float, b2World&, const sf::Vector2f & = { 0,0 },
		const sf::Vector2f & = { 0,0 }, char objectType = NOTHING, int ID = 0);
	void updateAnimation(const sf::Time&) override;
	//=========================== method section =============================
	//========================= private section ==============================
private:
	float m_distanceLimit;
};