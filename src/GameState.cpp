#include "GameState.hpp"
#include <iostream>
#include <fstream>
#include <string> 
#include <algorithm>
#include "GraphTD.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

void GameState::Start()
{
	mainMusic.openFromFile("Resources/MainMusic.wav");
	mainMusic.setVolume(3);
	mainMusic.setLoop(true);
	mainMusic.play();
	loadMap(1);
	clock.restart();
	GraphTD graph(this);
	graph.Start();
	mainMusic.stop();
}

void GameState::update(sf::Time elapsedTime)
{
	if (round == 0)
	{
		watchForTimeout();
	}
	else
	{
		for (auto& monster : monsters)
		{
			auto monPos = monster.monster.getPosition();
			monster.move(monPos, elapsedTime);
			monster.applySpecialty();	//applies the monster's unique ability (if any)
			if (monster.isDead() && monster.getType() == Types::NPC::Raidboss && !monster.getTanksSpawned())
			{
				monster.setTanksSpawned();
				spawnX = monster.monster.getPosition().x;
				spawnY = monster.monster.getPosition().y;
				raidbossDistance = monster.getDistanceTravelled();
				raidbossFlag = monster.getFlag();
			}
			if (monster.monster.getPosition().x >= 1984 && !monster.isDead()) // reached goal
			{
				if(playerHP>0)
				{
					switch (monster.getType())
					{
					case(Types::NPC::BasicSoldier):
						playerHP -= 1;
						break;
					case(Types::NPC::Infantry):
						playerHP -= 1;
						break;
					case(Types::NPC::Tank):
						playerHP -= 5;
						break;
					case(Types::NPC::Aircraft):
						playerHP -= 10;
						break;
					case(Types::NPC::SuperSoldier):
						playerHP -= 50;
						break;
					case(Types::NPC::Raidboss):
						playerHP -= 50;
						break;
					}
				}
				monster.setDead();
			}
		}
		if (spawnX != 0 && spawnY != 0)
		{
			createMonsters(Types::NPC::Tank, spawnX, spawnY, raidbossFlag-1, raidbossDistance);
			if (raidbossFlag % 2 == 0)
			{
				createMonsters(Types::NPC::Tank, spawnX - 50, spawnY, raidbossFlag-1, raidbossDistance -50);
				createMonsters(Types::NPC::Tank, spawnX + 50, spawnY, raidbossFlag-1, raidbossDistance + 50);
			}
			else
			{
				createMonsters(Types::NPC::Tank, spawnX, spawnY + 50, raidbossFlag-1, raidbossDistance - 50);
				createMonsters(Types::NPC::Tank, spawnX, spawnY - 50, raidbossFlag-1, raidbossDistance + 50);
			}
			spawnX = 0;
			spawnY = 0;
		}
		std::sort(monsters.rbegin(), monsters.rend());
		for (auto& monster : monsters)
		{
			for (auto& tower : towers)
			{
				if (playerHP > 0)
					tower.hit(monster);
			}
		}
		for (auto& tower : towers)
		{
			tower.resetTarget();
		}
		for (std::vector<std::shared_ptr<Projectile>>::iterator it = projectiles.begin(); it != projectiles.end(); )
		{

			if (!it->get()->isDestroyed())
			{
				it->get()->move(elapsedTime, monsters);
				points += it->get()->impact(monsters);
				++it;
			}
			else
			{
				it = projectiles.erase(it);
			}

		}
		if (round <= 10)
		{
			if (clock.getElapsedTime().asMilliseconds() > spawnInterval && soldiersSpawned < waves[round - 1][0])
			{
				createMonsters(Types::NPC::BasicSoldier);
				if (rand() % 2 == 1 && infantriesSpawned < waves[round - 1][1])
				{
					createMonsters(Types::NPC::Infantry);
					infantriesSpawned++;
				}
				if (rand() % 3 == 1 && tanksSpawned < waves[round - 1][2])
				{
					createMonsters(Types::NPC::Tank);
					tanksSpawned++;
				}
				if (rand() % 4 == 1 && aircraftsSpawned < waves[round - 1][3])
				{
					createMonsters(Types::NPC::Aircraft);
					aircraftsSpawned++;
				}
				soldiersSpawned++;
				clock.restart();
			}
			if (clock.getElapsedTime().asMilliseconds() > spawnInterval && infantriesSpawned < waves[round - 1][1])
			{
				createMonsters(Types::NPC::Infantry);
				infantriesSpawned++;
				clock.restart();
			}
			if (clock.getElapsedTime().asMilliseconds() > spawnInterval && tanksSpawned < waves[round - 1][2])
			{
				createMonsters(Types::NPC::Tank);
				tanksSpawned++;
				clock.restart();
			}
			if (clock.getElapsedTime().asMilliseconds() > spawnInterval && aircraftsSpawned < waves[round - 1][3])
			{
				createMonsters(Types::NPC::Aircraft);
				aircraftsSpawned++;
				clock.restart();
			}
			if (clock.getElapsedTime().asMilliseconds() > spawnInterval && supersoldiersSpawned < waves[round - 1][4])
			{
				createMonsters(Types::NPC::SuperSoldier);
				supersoldiersSpawned++;
				clock.restart();
			}
			if (clock.getElapsedTime().asMilliseconds() > spawnInterval && raidbossesSpawned < waves[round - 1][5])
			{
				createMonsters(Types::NPC::Raidboss);
				raidbossesSpawned++;
				clock.restart();
			}
		}
		else
		{
			if (clock.getElapsedTime().asMilliseconds() > spawnInterval && monsters.size() < maxPerRound)
			{
				int random = rand() % 6 + 1;
				switch (random)
				{
				case 1:
					createMonsters(Types::NPC::BasicSoldier);
					break;
				case 2:
					createMonsters(Types::NPC::Tank);
					break;
				case 3:
					createMonsters(Types::NPC::Aircraft);
					break;
				case 4:
					createMonsters(Types::NPC::SuperSoldier);
					break;
				case 5:
					createMonsters(Types::NPC::Raidboss);
					break;
				case 6:
					createMonsters(Types::NPC::Infantry);
					break;
				}
				clock.restart();
			}
		}
		if (monsters.size() == maxPerRound && playerHP > 0)
			watchForTimeout();
	}
}

bool GameState::allDead()
{
	if (monsters.size() < 1)
		return false;
	for (int i = 0; i < monsters.size(); ++i)
	{
		if (!monsters[i].isDead())
			return false;
	}
	return true;
}

void GameState::gameEnded()
{
	if (!end)
	{
		showTopScoreClk.restart();
		std::ofstream out;
		out.open("Resources/scores.txt", std::ios::app);
		out << "pvm" << ";" << name << ";" << points << ';' << round << ';';
		end = true;
		out.close();
		std::string line;
		std::ifstream myfile("scores.txt");
		if (myfile.is_open())
		{
			int i = 1;
			Scores temp;
			while (getline(myfile, line, ';'))
			{
				std::cout << line << '\n';
				switch (i)
				{
				case 1:
					temp.date = line;
					break;
				case 2:
					temp.name = line;
					break;
				case 3:
					temp.points = stoi(line);
					break;
				case 4:
					temp.level = stoi(line);
					break;
				}
				i++;
				if (i > 4) {
					i = 1;
					topScoresVec.push_back(temp);
					Scores temp;
				}
			}
			myfile.close();
			std::sort(topScoresVec.begin(), topScoresVec.end());
		}
		else std::cout << "Unable to open file";
	}
}

void GameState::watchForTimeout()
{
	if (allDead() && !timeOut)
	{
		timeOut = true;
		timeOutClock.restart();
	}
	if(timeOutClock.getElapsedTime().asSeconds()>timeOutTime && timeOut)
	{
		monsters.clear();
		newLevel();
		timeOut = false;
		timeOutTime = 10;
	}
}

void GameState::createMonsters(Types::NPC type)
{
	Monster&& tmp = Monster(type, spawnCount, 0, 0);
	tmp.initSprite(0.f, 160.f);
	monsters.push_back(tmp);
	spawnCount++;
}

void GameState::createMonsters(Types::NPC type, float x, float y, int flag, float distance)
{
	Monster&& tmp = Monster(type, spawnCount, flag, distance);
	tmp.initSprite(x,y);
	monsters.push_back(tmp);
	spawnCount++;
}

bool GameState::showTopScore()
{
	if (end&& showTopScoreClk.getElapsedTime().asSeconds()>1)
	{
		return true;
	}
	return false;
}

void GameState::createTower(Types::NPC type, float x,float y)
{

	Tower&& tmp = Tower(this, type, x, y);
	tmp.initSprite();
	towers.push_back(tmp);
}

// Loads map from txt
void GameState::loadMap(int mapId)
{
	std::string mapPath = "Resources/Map"+ std::to_string (mapId)+".txt";
	std::ifstream mapFile(mapPath);
	std::string value;
	int y = 0;
	int level[510];
	while(std::getline(mapFile,value,','))
	{
		level[y] =std::stoi(value);
		y++;
	}
	if (!map.load("Resources/tilesheet.png", sf::Vector2u(64, 64), level, 30, 17))
		std::cout << "Problem when loading the map" << std::endl;
		return;
}

void GameState::newLevel()
{
	// Re-initializing <monster>Spawned to 0 for spawning system
	soldiersSpawned = 0;
	infantriesSpawned = 0;
	tanksSpawned = 0;
	aircraftsSpawned = 0;
	supersoldiersSpawned = 0;
	raidbossesSpawned = 0;
	spawnCount = 0;
	// Hardcoded rounds until round 10
	if (round < 10)
		maxPerRound = waves[round][0] + waves[round][1] + waves[round][2] + waves[round][3] + waves[round][4] + waves[round][5]*4;
	else
		maxPerRound = round * 15;
	points += 500;
	round++;
	// For targeting system, fixed random missing
	monsters.reserve(maxPerRound);
	std::cout << "Wave " << round << " started!" << std::endl;
}

