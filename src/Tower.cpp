#include "Tower.hpp"
#include "GameState.hpp"
#include <memory>
#include <cmath>

Tower::Tower(GameState* game, Types::NPC type, float x, float y) :  game(game), type(type), x(x),y(y)
{
	switch (type)
	{
	case(Types::NPC::Turret):
		Damage = 225;
		range = 250;
		fireRate = 450;
		price = 500;
		break;

	case(Types::NPC::Fire):
		Damage = 85;
		range = 150;
		fireRate = 120;
		price = 1000;
		break;

	case(Types::NPC::Missile):
		Damage = 500; //1000 to target, 500 to surroundings
		range = 500;
		fireRate = 2500;
		price = 2000;
		break;
	}


}

void Tower::setDamage()
{
	Damage = 1.2 * Damage;
	damageLevel += 1;

	if (damageLevel == 2)
	{
		damagePlatform.setColor(sf::Color(246, 234, 234));
	}

	switch (this->type)
	{
	case (Types::NPC::Turret):
		game->losePoints((damageLevel + 1) * 250);
		break;

	case (Types::NPC::Fire):
		game->losePoints((damageLevel + 1) * 500);
		break;

	case (Types::NPC::Missile):
		game->losePoints((damageLevel + 1) * 1000);
		break;
	}
}

void Tower::setRange()
{
	range = 1.2 * range;
	rangeLevel += 1;

	if (rangeLevel == 2)
	{
		rangePlatform.setColor(sf::Color(255, 215, 0));
	}

	circle.setRadius(range);
	circle.setOrigin(range, range);

	switch (this->type)
	{
	case (Types::NPC::Turret):
		game->losePoints((rangeLevel + 1) * 250);
		break;

	case (Types::NPC::Fire):
		game->losePoints((rangeLevel + 1) * 500);
		break;

	case (Types::NPC::Missile):
		game->losePoints((rangeLevel + 1) * 1000);
		break;
	}

}

void Tower::setFireRate()
{
	fireRate = 0.8 * fireRate;
	firerateLevel += 1;

	if (firerateLevel == 2)
	{
		fireratePlatform.setColor(sf::Color(0, 0, 0, 70));
	}

	switch (this->type)
	{
	case (Types::NPC::Turret):
		game->losePoints((firerateLevel + 1) * 250);
		break;

	case (Types::NPC::Fire):
		game->losePoints((firerateLevel + 1) * 500);
		break;

	case (Types::NPC::Missile):
		game->losePoints((firerateLevel + 1) * 1000);
		break;
	}
}

int Tower::getFirerateLevel()
{
	return firerateLevel;
}

int Tower::getRangeLevel()
{
	return rangeLevel;
}

int Tower::getDamageLevel()
{
	return damageLevel;
}

Types::NPC Tower::getType() const
{
	return type;
}

void Tower::resetTarget()
{
	targetId = -1;
}


void Tower::initSprite()
{
	tower.setPosition(x, y);
	tower.setOrigin(32.f, 32.f);

	circle.setPosition(x, y);
	circle.setOrigin(range, range);
	circle.setRadius(range);
	circle.setFillColor(sf::Color(0, 102, 102, 100));

	infobox.setPosition(1440, 10);
	infobox.setScale(0.65f, 0.6f);

	fireratePlatform.setPosition(x, y);
	fireratePlatform.setOrigin(64.f, 64.f);
	fireratePlatform.setScale(0.7f, 0.7f);

	damagePlatform.setPosition(x, y);
	damagePlatform.setOrigin(64.f, 64.f);
	damagePlatform.setScale(0.7f, 0.7f);

	rangePlatform.setPosition(x, y);
	rangePlatform.setOrigin(90.5, 90.5);
	rangePlatform.setScale(0.8f, 0.8f);
}

void Tower::initTexture()
{	
	textureInit = true;
}

void Tower::hit(Monster& monster)
{

	if (targetId == -1 && canHit(monster))
		targetId = monster.getId();

	if (targetId == monster.getId() && canHit(monster))
		setAngle(monster);

	if (targetId == monster.getId() && canHit(monster) && clock.getElapsedTime().asMilliseconds() - pauseTime > fireRate)
	{
		try
		{
			shootSound.setVolume(1);
			shootSound.play();
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		clock.restart();
		pauseTime = 0;
		if (type == Types::NPC::Turret)
		{
			std::shared_ptr<TurretProjectile> p = std::make_shared<TurretProjectile>(Damage, x, y, type, monster.getId());
			game->projectiles.push_back(p);
		}
		else if (type == Types::NPC::Fire)
		{
			std::shared_ptr<FireProjectile> p = std::make_shared<FireProjectile>(Damage, x, y, type, monster.getId());
			game->projectiles.push_back(p);
		}
		else if (type == Types::NPC::Missile)
		{
			std::shared_ptr<MissileProjectile> p = std::make_shared<MissileProjectile>(Damage, x, y, type, monster.getId());
			game->projectiles.push_back(p);
		}
	}
	
}


bool Tower::canHit(Monster monster)
{
	if (monster.isDead() || monster.isInvisible())
		return false;
	float xDiff = abs(monster.monster.getPosition().x - tower.getPosition().x);
	float yDiff = abs(monster.monster.getPosition().y - tower.getPosition().y);
	return sqrt(pow(xDiff, 2) + pow(yDiff, 2)) < range;
}

void Tower::setAngle(Monster monster)
{
	sf::Vector2f aim = -tower.getPosition() + monster.monster.getPosition();
	double angle = 2 * 3.1415 - atan2(aim.x, aim.y);
	angle = angle * 360 / (2 * 3.1415);
	tower.setRotation(angle + 180);
}

sf::Sprite Tower::getTower()
{
	return tower;
}

int Tower::getPrice()
{
	return price;
}
