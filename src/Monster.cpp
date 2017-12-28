#include "Monster.hpp"

Monster::Monster(Types::NPC type, int id, int flag, float distance) : type(type), id(id), flag(flag), distanceTravelled(distance), movement1(200.f, 0.f), movement2(0.f, 200.f), movement3(0.f, 0.f)
{
	switch (type)
	{
	case(Types::NPC::BasicSoldier):
		value = 50;
		HP = 1000;
		velocity = 0.8;
		break;

	case(Types::NPC::Infantry):
		value = 75;
		HP = 1000;
		velocity = 1.05;
		break;

	case(Types::NPC::Aircraft):
		value = 100;
		HP = 2500;
		velocity = 1.25;
		break;

	case(Types::NPC::Tank):
		value = 150;
		HP = 5000;
		velocity = 0.6;
		break;

	case(Types::NPC::SuperSoldier):
		value = 500;
		HP = 25000;
		velocity = 1;
		break;

	case(Types::NPC::Raidboss):
		value = 100000;
		HP = 100;
		velocity = 0.25;
		break;
	}
}

Types::NPC Monster::getType() const
{
	return type;
}

void Monster::initSprite(float x, float y)
{
	monster.setPosition(x, y);
	HPbar.setSize(sf::Vector2f(64, 3));
	base.setSize(sf::Vector2f(64, 3));
	HPbar.setOrigin(32.f, 3/2.f);
	base.setOrigin(sf::Vector2f(32.f, 3/2.f));
	HPbar.setFillColor(sf::Color::Green);
	base.setFillColor(sf::Color::Red);
	if (type == Types::NPC::BasicSoldier || type == Types::NPC::Aircraft || type == Types::NPC::Tank || type == Types::NPC::Infantry)
	{
		monster.setOrigin(32.f, 32.f);
		HPbar.setPosition(0.f, 140.f);
		base.setPosition(0.f, 140.f);
	}
	else
	{
		monster.setOrigin(64.f, 64.f);
		HPbar.setPosition(0.f, 120.f);
		base.setPosition(0.f, 120.f);
	}
}

void Monster::initTexture()
{
	textureInit = true;
}

float Monster::getDistanceTravelled() const
{
	return distanceTravelled;
}

int Monster::getId() const
{
	return id;
}

int Monster::getHit(int damage)
{

	HP -= damage;
	if (HP < 0)
	{
		HP = 0;
	}
	if (type == Types::NPC::BasicSoldier || type == Types::NPC::Infantry)
	{
		HPbar.setSize(sf::Vector2f(HP * 8 / 125, 3));
	}
	else if (type == Types::NPC::Aircraft)
	{
		HPbar.setSize(sf::Vector2f(HP * 16 / 625, 3));
	}
	else if (type == Types::NPC::Tank)
	{
		HPbar.setSize(sf::Vector2f(HP * 8 / 625, 3));
	}
	else if (type == Types::NPC::SuperSoldier)
	{
		HPbar.setSize(sf::Vector2f(HP * 8 / 3125, 3));
	}
	else if (type == Types::NPC::Raidboss)
	{
		HPbar.setSize(sf::Vector2f(HP * 2 / 3125, 3));
	}
	if (HP <= 0)
	{
		monster.setColor(sf::Color::Black);
		base.setFillColor(sf::Color::Transparent);
		dead = true;
		clock.restart();
		return value;
	}
	else
	{
		return 0; // still alive, no points
	}
}

void Monster::setPauseTime(float time)
{
	pauseTime = time;
}

int Monster::getHP()
{
	return HP;
}

int Monster::getValue() const
{
	return value;
}

void Monster::setDead()
{
	dead = true;
}

bool Monster::isDead()
{
	return dead;
}

bool Monster::isInvisible()
{
	return invisible;
}

void Monster::applySpecialty()
{
	if (type == Types::NPC::Aircraft && HP <= 2500 / 2 && !speedup)	//aircraft speeds up at half HP
	{
		velocity = 1.5*velocity;
		speedup = true;
	}
	if (type == Types::NPC::SuperSoldier && dead == false)
	{
		if (invisibilityClock.getElapsedTime().asMilliseconds() - pauseTime > 8000)	//supersoldier goes invisible after 8 seconds
		{
			monster.setColor(sf::Color(255, 255, 255, 75)); //visual effect for being invisible
			invisibilityClock.restart();
			pauseTime = 0;
			invisible = true;
		}
		if (invisibilityClock.getElapsedTime().asMilliseconds() - pauseTime > 3000 && invisible == true)	//...and turns back normal after 2 seconds
		{
			monster.setColor(sf::Color(255, 255, 255, 255)); // back to normal
			invisibilityClock.restart();
			pauseTime = 0;
			invisible = false;
		}
	}
}

void Monster::move(sf::Vector2f vector, sf::Time elapsedTime)
{
	if (dead) return;
	if (vector.x < 352)		//1
		monster.move(velocity*movement1*elapsedTime.asSeconds());
	else if (vector.x >= 352 && vector.x < 800 && vector.y < 864) {	//2
		if (flag <= 0)
		{
			flag = 1;
			monster.setRotation(90);
		}
		monster.move(velocity*movement2*elapsedTime.asSeconds());
	}
	else if ( vector.x < 800 && vector.y >= 864) { //3
		if (flag == 1)
		{
			flag = 2;
			monster.setRotation(0);
		}
		monster.move(velocity*movement1*elapsedTime.asSeconds());
	}
	else if (vector.x >= 800 && vector.x < 1248 && vector.y >= 160) { //4
		if (flag == 2)
		{
			flag = 3;
			monster.setRotation(-90);
		}
		monster.move(velocity*-movement2*elapsedTime.asSeconds());
	}
	else if (vector.x >= 700 && vector.x < 1248 && vector.y < 160) { //5
		if (flag == 3)
		{
			flag = 4;
			monster.setRotation(0);
		}
		monster.move(velocity*movement1*elapsedTime.asSeconds());
	}
	else if (vector.x >= 1248 && vector.y < 864) { //6
		if (flag == 4)
		{
			flag = 5;
			monster.setRotation(90);
		}
		monster.move(velocity*movement2*elapsedTime.asSeconds());
	}
	else if (vector.x >= 1000 && vector.y >= 864) { //7
		if (flag == 5)
		{
			flag = 6;
			monster.setRotation(0);
		}
		monster.move(velocity*movement1*elapsedTime.asSeconds());
	}
	else
		monster.move(velocity*movement3*elapsedTime.asSeconds());

	distanceTravelled += velocity * 0.16;

	if (type == Types::NPC::BasicSoldier || type == Types::NPC::Aircraft || type == Types::NPC::Tank || type == Types::NPC::Infantry)
		HPbar.setPosition(monster.getPosition().x, monster.getPosition().y - 20.f);
	else
		HPbar.setPosition(monster.getPosition().x, monster.getPosition().y - 40.f);
	base.setPosition(HPbar.getPosition());
}

