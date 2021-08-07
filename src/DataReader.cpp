//============================= include section ==============================
#include "DataReader.h"
#include "Macros.h"
#include "Utilities.h"
#include <vector>
#include <iostream>
using std::endl;
using std::vector;
//============================= public section ===============================
//==================== Constructors & distructors section ====================
DataReader::DataReader()
        : m_levelSize({}), m_levelTime(NO_LEVEL_TIME) {
    try {
        this->m_boardReader.open(BOARD_PATH);
    }
    catch (...){
        std::cout << "Cannot open the levels file, pls make sure the file is exist";
    }
}
//========================================================================
DataReader::~DataReader() {
    this->m_boardReader.close();
}
/*============================ methods section ===============================
* this function read the size of the level and the time if exist.
*/
void DataReader::receiveLevelParameters() {
    m_boardReader >> m_levelSize.x >> m_levelSize.y;
    m_boardReader >> m_levelTime;
    //eat white space
    m_boardReader.get();
}
//========================================================================
/*
  This function return true if a new level is exist in the inputed file
  or false if all the levels is over.
*/
bool DataReader::isThereNextLevel()const {
    return (!this->m_boardReader.eof());
}
//========================================================================
/*
* this function read the parameters from the level and then level itself
* from the file.
*/
vector<vector<char>> DataReader::readNextLevel() {
    //1. allocate 2D vector of chars
    vector<vector<char>> newLevel = {};
    //2. check first if there is more level in the file
    if (this->isThereNextLevel()) {
        char input;
        //3. receive size & time of the level
        this->receiveLevelParameters();
        //4. read the level itself from the file
        for (int i = 0; i < m_levelSize.x; i++) {
            std::vector<char> row = {};
            for (int j = 0; j < m_levelSize.y; j++) {
                m_boardReader.get(input);
                switch (input)
                {
                    case PLAYER: {
                        row.push_back(PLAYER);
                        break;
                    }
                    case EXTERMINATOR: {
                        row.push_back(EXTERMINATOR);
                        break;
                    }
                    case OLD_WOMAN: {
                        row.push_back(OLD_WOMAN);
                        break;
                    }
                    case SCOOTER: {
                        row.push_back(SCOOTER);
                        break;
                    }
                    case SPECIAL_FOOD: {
                        row.push_back(SPECIAL_FOOD);
                        break;
                    }
                    case REGULAR_FOOD: {
                        row.push_back(REGULAR_FOOD);
                        break;
                    }
                    case TOXIC_FOOD: {
                        row.push_back(TOXIC_FOOD);
                        break;
                    }
                    case ROAD: {
                        row.push_back(ROAD);
                        break;
                    }
                    case ADANIT: {
                        row.push_back(ADANIT);
                        break;
                    }
                    case TRASH: {
                        row.push_back(TRASH);
                        break;
                    }
                    case DYNAMIC_FLOOR: {
                        row.push_back(DYNAMIC_FLOOR);
                        break;
                    }
                    case PORTAL_TRASH: {
                        row.push_back(PORTAL_TRASH);
                        break;
                    }
                    default: {
                        row.push_back(NOTHING); // inputed ' '
                        break;
                    }
                }
            }
            if (m_boardReader.peek() != '\0')
                m_boardReader.get(input);
            newLevel.push_back(row);
        }
        m_boardReader.get(input);
    }
    return newLevel;
}
//========================================================================
sf::Vector2f DataReader::getLevelSize()const { return this->m_levelSize; }
//========================================================================
int DataReader::getLevelTime()const { return this->m_levelTime; }
//========================================================================
/*this function return the file descriptor to the beginning of the file
* and clear the current vector of the map.
 */
void DataReader::resetRead() {
    this->m_boardReader.clear();
    this->m_boardReader.seekg(0);
    this->m_levelSize = { 0, 0 };
}
