#include <Music.h>
#include <Macros.h>
//-----------------------------------------------------------------------------

Music::Music()
{
	loadSounds();
	setSounds();
}
//-----------------------------------------------------------------------------
Music& Music::instance()
{
	static Music instance;
	return instance;
}

//-----------------------------------------------------------------------------
void Music::playEnemyAte()
{
	m_sounds[(int)Sound::enemyAte].play();
}
//-----------------------------------------------------------------------------
void Music::playFood()
{
	m_sounds[(int)Sound::eatFood].play();
}
//-----------------------------------
void Music::playToxicFood()
{
	m_sounds[(int)Sound::eatToxic].play();
}
//-----------------------------------------------------------------------------
void Music::playMenu()
{
	m_sounds[(int)Sound::menu].play();
}
//-----------------------------------------------------------------------------
void Music::playLevelMusic(const int & level)
{
	switch (level)
	{
	case 1:
		m_sounds[(int)Sound::level1].play();
		break;
	case 2:
		m_sounds[(int)Sound::level2].play();
		break;
	case 3:
		m_sounds[(int)Sound::level3].play();
		break;
	case 4:
		m_sounds[(int)Sound::level4].play();
		break;
	case 5:
		m_sounds[(int)Sound::level5].play();
		break;
	default:
		break;
	}
}
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
void Music::stopMenu()
{
	m_sounds[(int)Sound::menu].stop();
}
//-----------------------------------------------------------------------------
void Music::stopGame()
{
	m_sounds[(int)Sound::level1].stop();
}

void Music::stopHiScoreMenu()
{
	m_sounds[(int)Sound::hiScore].stop();
}

//-----------------------------------------------------------------------------

void Music::playWonGame()
{
	m_sounds[(int)Sound::wonGame].play();
}
//-----------------------------------------------------------------------------
void Music::stopWonGame()
{
	m_sounds[(int)Sound::wonGame].stop();
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

void Music::playInfoMenu()
{
	m_sounds[(int)Sound::infoMenu].play();
}
//-----------------------------------------------------------------------------
void Music::stopInfoMenu()
{
	m_sounds[(int)Sound::infoMenu].stop();
}

void Music::playSpecialFood()
{
	m_sounds[(int)Sound::SpecialFood].play();
}
void Music::playCredits()
{
	m_sounds[(int)Sound::credits].play();
}
void Music::stopCredits()
{
	m_sounds[(int)Sound::credits].stop();
}
void Music::stopLevelMusic(const int& level)
{
	switch (level)
	{
	case 1:
		m_sounds[(int)Sound::level1].stop();
		break;
	case 2:
		m_sounds[(int)Sound::level2].stop();
		break;
	case 3:
		m_sounds[(int)Sound::level3].stop();
		break;
	case 4:
		m_sounds[(int)Sound::level4].stop();
		break;
	case 5:
		m_sounds[(int)Sound::level5].stop();
		break;
	default:
		break;
	}
}
//----------------------------------------------------------------------

//-----------------------------------------------------------------------------
void Music::playLostGame()
{
	m_sounds[(int)Sound::lostGame].play();
}
//-----------------------------------------------------------------------------

void Music::playBack()
{
	m_sounds[(int)Sound::back].play();
}
void Music::playHiScoreMenu()
{
	m_sounds[(int)Sound::hiScore].play();
}
//-----------------------------------------------------------------------------
const sf::SoundBuffer& Music::getSound(const Sound name)  const
{
	return m_soundBuff[(int)name];
}
//-----------------------------------------------------------------------------
void Music::loadSounds()
{
	loadSound("MainMenu.ogg");
	loadSound("EatFood.wav");
	loadSound("EatToxic.wav");
	loadSound("EnemyEat.wav");
	loadSound("WonGame.wav");
	loadSound("Life1up.wav");
	loadSound("LostGame.wav");
	loadSound("TimeEnd.wav");
	loadSound("Back.wav");
	loadSound("HiScore.wav");
	loadSound("GameTheme.ogg");
	loadSound("InfoMenu.ogg");
	loadSound("EatSpecialFood.wav");
	loadSound("Credits.wav");
	loadSound("Level2Music.ogg");
	loadSound("Level3Music.ogg");
	loadSound("Level4Music.ogg");
	loadSound("Level5Music.ogg");
}

//-----------------------------------------------------------------------------

void Music::loadSound(const std::string path)
{
	sf::SoundBuffer temp;
	temp.loadFromFile(path);
	m_soundBuff.push_back(temp);
}
//-----------------------------------------------------------------------------
void Music::setSounds()
{
	for (int i = 0; i < AUDIOS; i++)
	{
		m_sounds.push_back(sf::Sound(getSound(Sound(i))));
		m_sounds[i].setVolume(VOL);
	}
}


