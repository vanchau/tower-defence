#ifndef MONSTER_HPP
#define MONSTER_HPP
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Types.hpp"

class Monster
{
public:
	Monster(Types::NPC type, int id, int flag, float distance);
	int getHP();
	Types::NPC getType() const;
	void initSprite(float x, float y);
	void initTexture();
	void setPauseTime(float time);
	void move(sf::Vector2f position, sf::Time time);
	void applySpecialty();
	void setTanksSpawned() { tanksSpawned = true; } // For raidboss' death (smaller tank spawning)
	void setDead();
	float getDistanceTravelled() const;
	int getHit(int damage);
	int getFlag() const { return flag; } // For raidboss's smaller tanks
	int getValue() const;
	int getId() const;
	bool operator<(const Monster& m) const { return (distanceTravelled < m.distanceTravelled); } // for sorting
	bool getTanksSpawned() { return tanksSpawned; }
	bool textureInit = false;
	bool isDead();
	bool isInvisible(); // for supersoldier
	sf::Sprite monster;
	sf::RectangleShape HPbar;
	sf::RectangleShape base;
	sf::Clock clock;

private:
	Types::NPC type;
	sf::Vector2f movement1; // forward
	sf::Vector2f movement2;	// up/down
	sf::Vector2f movement3;	// stop
	float distanceTravelled = 0;
	float pauseTime = 0;
	float velocity;
	int HP;
	int value;
	int id;		// for projectiles to be able to recognize monsters
	int flag = 0;	// for movement
	bool dead = false;
	bool speedup = false;		// for aircraft
	bool tanksSpawned = false;
	bool invisible = false;		// supersoldier
	sf::Clock invisibilityClock; // supersoldier
};


#endif
