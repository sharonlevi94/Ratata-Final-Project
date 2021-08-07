#include "Listener.h"
#include <vector>
#include <iostream>

void Listener::PreSolve(b2Contact* contact, const b2Manifold* oldManifold) {
	
	b2Fixture* f1 = contact->GetFixtureA();
	b2Fixture* f2 = contact->GetFixtureB();

	b2Body* b1 = f1->GetBody();
	b2Body* b2 = f2->GetBody();

	auto obj1 = m_board->getObjWithId(int(size_t(b1->GetUserData())));
	auto obj2 = m_board->getObjWithId(int(size_t(b2->GetUserData())));

	m_board->getCollisionObj().HandleCollision(*obj1, *obj2);
}

void Listener::setCurrentBoard(Board& board)
{
	m_board = &board;
}