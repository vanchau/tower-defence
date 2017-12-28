#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP
#include "Types.hpp"
#include "Tower.hpp"

class Projectile
{
public:
	Projectile(int damage, float x, float y, Types::NPC type, int target);
	//rule of five
	virtual ~Projectile() { }								// Destructor
	Projectile(const Projectile&) = default;               // Copy constructor
	Projectile(Projectile&&) = default;                    // Move constructor
	Projectile& operator=(const Projectile&) & = default;  // Copy assignment operator
	Projectile& operator=(Projectile&&) & = default;       // Move assignment operator
	virtual void move(sf::Time elapsedTime, std::vector<Monster>& monsters);
	virtual int impact(std::vector<Monster>& monsters) = 0;
	void initTexture();
	sf::Sprite getProjectile() const;
	Types::NPC getOriginType() const;
	bool isDestroyed();
	bool textureInit = false;
	bool drawArea = false;
	sf::Sprite projectile_spr;
	sf::Sprite explosion;
	sf::CircleShape damageArea;
	sf::Clock clock;

protected:
	int damage;
	float x;
	float y;
	float velocity = 500;
	Types::NPC type;
	int target;
	bool destroyed = false;
};

class TurretProjectile : public Projectile
{
public:
	TurretProjectile(int damage, float x, float y, Types::NPC type, int target);
	int impact(std::vector<Monster>& monsters);
private:
	float velocity = 1000;
};

class FireProjectile : public Projectile
{
public:
	FireProjectile(int damage, float x, float y, Types::NPC type, int target);
	int impact(std::vector<Monster>& monsters);
private:
	float velocity = 750;
};

class MissileProjectile : public Projectile
{
public:
	MissileProjectile(int damage, float x, float y, Types::NPC type, int target);
	int impact(std::vector<Monster>& monsters);
private:
	float velocity = 600;
};

#endif