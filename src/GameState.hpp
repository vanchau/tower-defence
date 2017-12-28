#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP
#define _CRT_SECURE_NO_WARNINGS 1
#include <memory>
#include <fstream>
#include<ctime>
#include <SFML/Audio.hpp>
#include "Monster.hpp"
#include "Tower.hpp"
#include "Tilemap.hpp"
#include "Projectile.hpp"
#include "Types.hpp"
#include "Scores.hpp"

//forward declaration things to work (?)
class Tower;
class Projectile;

class GameState
{
public:
	void Start();
	void update(sf::Time elapsedTime);
	int getPoints() const { return points; };
	void losePoints(int point) { points -= point; }
	bool isTimeOt() { return timeOut; }
	int tillNextRound() { return timeOutTime - timeOutClock.getElapsedTime().asSeconds(); }
	int getPlayerHP() { return playerHP; }
	bool allDead();
	int getRound() { return round; }
	void setName(std::string playername) { name = playername; }
	void setPoints(int poin) { points = poin; }
	void setHP(int poin) { playerHP = poin; }
	void setRound(int poin) { round = poin; }
	void gameEnded();
	bool isGameEnded() { return end; }
	void addTimeOut(int time) { timeOutTime += time; }
	void zeroTimeOut() { timeOutTime = 0; }
	TileMap map;
	sf::RenderWindow window;
	std::vector<Monster> monsters;
	std::vector<Tower> towers;
	std::vector<Scores> topScoresVec;
	int projectileIndex = 0;
	void createTower(Types::NPC type, float x, float y);
	void createMonsters(Types::NPC type);
	void createMonsters(Types::NPC type, float x, float y, int flag, float distance);
	std::vector<std::shared_ptr<Projectile>> projectiles;
	bool showTopScore();

private:
	std::string name;
	bool end = false;
	int round = 0;
	void loadMap(int mapId);
	void newLevel();
	void watchForTimeout();
	int points = 1500;
	int playerHP = 100;
	sf::Clock timeOutClock;
	bool timeOut = true;
	sf::Clock clock;
	sf::Clock showTopScoreClk;
	int spawnInterval = 1000;
	int maxPerRound;
	int timeOutTime = 30;
	float spawnX = 0;
	float spawnY = 0;
	int raidbossFlag;
	float raidbossDistance;
	int waves[10][6] = { { 10,0,0,0,0,0 },{ 20,10,0,0,0,0 },{ 15,25,5,0,0,0 },
	{ 20,25,2,2,0,0 },{ 20,20,0,0,1,0 },{ 25,20,10,5,0,0 },
	{ 0,0,25,0,0,0 },{ 0,0,0,0,0,1 },{ 30,30,15,15,1,0 },{ 50,50,20,20,1,1 } };
	int soldiersSpawned = 0;
	int infantriesSpawned = 0;
	int tanksSpawned = 0;
	int aircraftsSpawned = 0;
	int supersoldiersSpawned = 0;
	int raidbossesSpawned = 0;
	int spawnCount = 0;	//for monster id
	sf::Music mainMusic;
};

#endif