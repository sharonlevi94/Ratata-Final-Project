#pragma once
//============================ include section ===============================
#include <vector>
#include "DataReader.h"
#include "GameObject.h"
#include "MovingObject.h"
#include <unordered_map>
#include "Collisions.h"
//========================== forward declarations ============================
class Player;
//============================== using section ===============================
using std::vector;
/*============================================================================
 * Class: Board.
 * the board contain and draw the level's objects.
 * alse the board helps the 
 * read the levels from the file by one of its member.
 * also the board help
 */
class Board
{
public:
	//================= constructors and destructors section =================
	Board(const sf::Vector2f& location = sf::Vector2f(0,0),
		const sf::Vector2f& size = sf::Vector2f(0,0));
	~Board() = default;
	//============================ gets section ==============================
	int getLevelTime()const;
	const sf::Vector2f& getLevelSize() const;
	const sf::Vector2f& getLocation() const;
	sf::Vector2f getObjectSize()const;
	GameObject* getObjWithId(int);
	Collisions getCollisionObj() const { return m_collision; }
	const sf::Vector2f& getPlayerLoc()const;
	int getPlayerState()const;
	//=========================== method section =============================
	void draw(sf::RenderWindow& window, const sf::Time&);
	std::vector<MovingObject*> loadNewLevel(b2World&);
	void removeFood(b2World& world);
	bool isNextLvlExist()const;
	void gameOver(b2World&);
	void loadLevelEffects();
	void resetObjects();
	void levelUp(b2World&);
private:
	//========================= members section ==============================
	vector<vector<std::unique_ptr<GameObject>>> m_map;
	std::unordered_map<int, GameObject*> m_ObjWithID;
	sf::Vector2f m_location;
	DataReader m_levelReader;
	sf::RectangleShape m_background;
	Player* m_player;
	Collisions m_collision;
    vector<std::unique_ptr<Food>> m_takenFood;
	//====================== privete methods section =========================
	void clearParameters();	
};