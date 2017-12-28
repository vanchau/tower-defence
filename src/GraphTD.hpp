#ifndef GRAPHTD_HPP
#define GRAPHTD_HPP
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Tilemap.hpp"
#include "Monster.hpp"
#include "GameState.hpp"

class GraphTD
{
public:
	GraphTD(GameState* game);
	void setText(sf::Text& text, float x, float y, sf::Font font, int size);
	template <class t>
	bool insideBounds(t sprite, sf::Vector2f pos);
	template <class t>
	bool insideBounds(t sprite, sf::Vector2i pos);
	bool inRoad(sf::Vector2f pos);
	void createTower(Types::NPC type, int losePoints);
	void Start();
	void setUpgradeButtonColors(float posx, float posy, std::vector<Tower>::value_type& tow);
	void drawMovableTower(float posx, float posy, sf::Vector2f pos);
	void upgradePressed(sf::Vector2i mouse, std::vector<Tower>::value_type& tow);
	void canUpgrade(sf::Vector2i pos, Tower& tow);
	void render();
	void processEvents();
	void processEndInput();
	void processPause();
	void showHiscores();

private:
	GameState* game;
	const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
	static const float soldierSpeed;
	std::vector<sf::Sprite> towers;
	std::vector<sf::Text> topScores;
	int flag = 0;
	std::string firerate_price;
	std::string range_price;
	std::string damage_price;
	bool nameFinished = false;
	bool copyBasic = false;
	bool copyFire = false;
	bool copyMissile = false;
	bool tower_selected = false;
	bool tower_released = false;
	bool topScoresInit = false;
	bool blocked = true;
	bool menu_blocked = true;
	bool paused = false;
	bool upgrade_selected = false;
	bool cannot_upgrade = false;
	sf::Clock pauseClock;
	sf::Texture turretProjectileTexture;
	sf::Texture fireProjectileTexture;
	sf::Texture missileProjectileTexture;
	sf::Texture soldierMonsterTexture;
	sf::Texture infantryMonsterTexture;
	sf::Texture aircraftMonsterTexture;
	sf::Texture tankMonsterTexture;
	sf::Texture supersoldierTexture;
	sf::Texture raidbossTexture;
	sf::Texture basicTowerTexture;
	sf::Texture fireTowerTexture;
	sf::Texture missileTowerTexture;
	sf::Texture explosionTexture;
	sf::Texture cursorTexture;
	sf::Texture red;
	sf::Texture t_platform;
	sf::Texture t_damagePlatform;
	sf::Texture t_rangePlatform;
	sf::Texture t_infobox;
	sf::Sprite cursor;
	sf::Sprite t_basic;
	sf::Sprite t_fire;
	sf::Sprite t_missile;
	sf::Sprite cross;
	sf::CircleShape circleTurret;
	sf::CircleShape circleFire;
	sf::CircleShape circleMissile;
	sf::RectangleShape road1;
	sf::RectangleShape road2;
	sf::RectangleShape road3;
	sf::RectangleShape road4;
	sf::RectangleShape road5;
	sf::RectangleShape road6;
	sf::RectangleShape road7;
	sf::RectangleShape menu;
	sf::RectangleShape pauseScreen;
	sf::RectangleShape firerate;
	sf::RectangleShape range;
	sf::RectangleShape damage;
	sf::Font font;
	sf::String playerName;
	sf::Text skipWaiting;
	sf::Text pause;
	sf::Text pausedTitle;
	sf::Text continueButton;
	sf::Text muteButton;
	sf::Text exitButton;
	sf::Text saveButton;
	sf::Text nameInput;
	sf::Text gameOver;
	sf::Text playerHP;
	sf::Text levelLabel;
	sf::Text pointsLabel;
	sf::Text timeOutLabel;
	sf::Text basicTowerPrice;
	sf::Text fireTowerPrice;
	sf::Text missileTowerPrice;
	sf::Text firerateUpgrade;
	sf::Text rangeUpgrade;
	sf::Text damageUpgrade;
	sf::Text infoText1;
	sf::Text infoText2;
	sf::Text infoText3;
	sf::Text infoText4;
	sf::Text infoText5;
	sf::Text infoText6;
	sf::Text infoText7;
	sf::Text infoText8;
	sf::SoundBuffer fireSoundBuffer;
	sf::SoundBuffer missileSoundBuffer;
	sf::SoundBuffer turretSoundBuffer;
	sf::SoundBuffer clickSoundBuffer;
	sf::SoundBuffer dropSoundBuffer;
	sf::SoundBuffer deniedSoundBuffer;
	sf::SoundBuffer upgradeSoundBuffer;
	sf::SoundBuffer missileImpactSB;
	sf::Sound fireSound;
	sf::Sound missileSound;
	sf::Sound turretSound;
	sf::Sound upgradeSound;
	sf::Sound clickSound;
	sf::Sound dropSound;
	sf::Sound deniedSound;
	sf::Sound missileImpact;	
};

#endif