#pragma once
//============================ include section ===============================
#include <map>
#include <typeinfo>
#include <typeindex>

#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "Exterminator.h"
#include "Scooter.h"
#include "Road.h"
#include "Trash.h"
#include "Food.h"
#include "SpecialFood.h"
#include "ToxicFood.h"
#include "RegularFood.h"
#include "DynamicFloor.h"
#include "Adanit.h"
#include "Music.h"
#include "PortalTrash.h"
#include "Stats.h"
#include <iostream> //for debug
//============================== using section ===============================
using HitFunctionPtr = void (*)(GameObject&, GameObject&);
using Key = std::pair<std::type_index, std::type_index>;
using HitMap = std::map<Key, HitFunctionPtr>;
//===========================================================================
class Collisions
{
public:

    Collisions();

    void HandleCollision(GameObject& object1, GameObject& object2);
    HitFunctionPtr findHandler(const std::type_index& class1, const std::type_index& class2);
    HitMap initializeCollisionMap();
};
//===========================================================================
namespace
{
    void playerEnemy(GameObject& object1, GameObject& object2)
    {
        Music::instance().playEnemyAte();
        auto& player = dynamic_cast<Player&>(object1);
        player.setState(DIE, PLAYER_BOX_HEIGHT, PLAYER_BOX_WIDTH, PLAYER_OFFSET, PLAYER_SPECIAL_OFFSET);
        player.setLife(-1);
    }
    void enemyPlayer(GameObject& object1, GameObject& object2)
    {
        playerEnemy(object2, object1);
    }
    //-------------------------------------------------------------------------

    void playerPortalTrash(GameObject& object1, GameObject& object2)
    {
        if (RegularFood::getFoodCounter() == 0) {
            auto& player = dynamic_cast<Player&>(object1);
            player.setLevelUp();
        }
    }
    void portalTrashPlayer(GameObject& object1, GameObject& object2)
    {
        playerPortalTrash(object2, object1);
    }
    //-------------------------------------------------------------------------

    void adanitDynamicFloor(GameObject& object1, GameObject& object2)
    {
        auto& floor = dynamic_cast<DynamicFloor&>(object2);
        b2Vec2 dirFromKey = b2Vec2(0, 0);
        if (floor.getDirection() == RIGHT)
            floor.setDirection(LEFT);
        else
            floor.setDirection(RIGHT);
    }
    void dynamicFloorAdanit(GameObject& object1, GameObject& object2)
    {
        adanitDynamicFloor(object2, object1);
    }

    //-------------------------------------------------------------------------

    void exterminatorTrash(GameObject& object1, GameObject& object2)
    {
        auto& enemy = dynamic_cast<Exterminator&>(object1);
        enemy.setCollision(TRASH_C);
    }
    void trashExterminator(GameObject& object1, GameObject& object2)
    {
        exterminatorTrash(object2, object1);
    }

    //-------------------------------------------------------------------------

    void exterminatorAdanit(GameObject& object1, GameObject& object2)
    {
        auto& enemy = dynamic_cast<Exterminator&>(object1);
        enemy.setCollision(ADANIT_C);
    }
    void adanitExterminator(GameObject& object1, GameObject& object2)
    {
        exterminatorAdanit(object2, object1);
    }

    //-------------------------------------------------------------------------

    void scooterObstacle(GameObject& object1, GameObject& object2)
    {
        auto& enemy = dynamic_cast<Scooter&>(object1);
        if (enemy.getDirection() == RIGHT)
            enemy.setDirection(LEFT);
        else
            enemy.setDirection(RIGHT);

        enemy.flipSprite(sf::Vector2f(-1.f, 1.f));
    }
    void obstacleScooter(GameObject& object1, GameObject& object2)
    {
        scooterObstacle(object2, object1);
    }

     ////-------------------------------------------------------------------------

    void playerFood(GameObject& object1, GameObject& object2)
    {
        Food& food = dynamic_cast<Food&>(object2);
        Player& player = dynamic_cast<Player&>(object1);
        food.collect();
        int type = rand() % 2;

        if (dynamic_cast<SpecialFood*>(&object2)) {
            Music::instance().playSpecialFood();
            if (type == TIME)
                player.ChangeTime(BONUS_TIME);
            else
                player.setScore(BONUS_SCORE);
        }
        else if (dynamic_cast<RegularFood*>(&object2)) {
            Music::instance().playFood();
            player.setScore(10);
        }
        else if (dynamic_cast<ToxicFood*>(&object2)) {
            Music::instance().playToxicFood();
            if (type == TIME)
                player.ChangeTime(LESS_TIME);
            else
                player.setScore(LESS_SCORE);
        }
    }
    void foodPlayer(GameObject& object1, GameObject& object2)
    {
        playerFood(object2, object1);
    }
}
