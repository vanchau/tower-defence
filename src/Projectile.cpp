#include "Projectile.hpp"

Projectile::Projectile(int damage, float x, float y, Types::NPC type, int target) : damage(damage), x(x), y(y), type(type), target(target) {}

void Projectile::initTexture()
{
	textureInit = true;
}

sf::Sprite Projectile::getProjectile() const
{
	return projectile_spr;
}

Types::NPC Projectile::getOriginType() const
{
	return type;
}

bool Projectile::isDestroyed()
{
	return destroyed;
}

void Projectile::move(sf::Time elapsedTime, std::vector<Monster>& monsters)
{
	for (auto& mons : monsters)
	{
		if (mons.getId() == target)
		{
			sf::Vector2f aim = -projectile_spr.getPosition() + mons.monster.getPosition();
			float angle = 2 * 3.1415 - atan2(aim.x, aim.y);
			angle = angle * 360 / (2 * 3.1415); // to radians
			projectile_spr.setRotation(angle + 180);
			float magnitude = sqrt(pow(aim.x, 2) + pow(aim.y, 2));
			sf::Vector2f unit_vector(aim.x / magnitude, aim.y / magnitude);

			projectile_spr.move(velocity*unit_vector*elapsedTime.asSeconds());
			break;
		}
	}
}

TurretProjectile::TurretProjectile(int damage, float x, float y, Types::NPC type, int target) : Projectile(damage, x, y, type, target) 
{
	projectile_spr.setPosition(x, y);
	projectile_spr.setOrigin(32.f, 32.f);
}

int TurretProjectile::impact(std::vector<Monster>& monsters)
{
	int value = 0;
	for (auto& mons : monsters)
	{
		if (mons.getId() == target && abs(getProjectile().getPosition().x - mons.monster.getPosition().x) <= 10 && abs(getProjectile().getPosition().y - mons.monster.getPosition().y) <= 10 && destroyed == false)
		{
			if (!mons.isDead() && !mons.isInvisible())
			{
				value = mons.getHit(damage);
			}
			destroyed = true; // projectile
			break;
		}
	}
	return value;
}


FireProjectile::FireProjectile(int damage, float x, float y, Types::NPC type, int target) : Projectile(damage, x, y, type, target) 
{
	projectile_spr.setPosition(x, y);
	projectile_spr.setOrigin(32.f, 32.f);
}

int FireProjectile::impact(std::vector<Monster>& monsters)
{
	int value = 0;
	for (auto& mons : monsters)
	{
		if (mons.getId() == target && abs(getProjectile().getPosition().x - mons.monster.getPosition().x) <= 10 && abs(getProjectile().getPosition().y - mons.monster.getPosition().y) <= 10 && destroyed == false)
		{
			if (!mons.isDead() && !mons.isInvisible())
			{
				if (mons.getType() == Types::NPC::Tank)
					value = mons.getHit(damage*0.5);
				else
					value = mons.getHit(damage);
			}
			destroyed = true; // projectile
			break;
		}
	}
	return value;
}

MissileProjectile::MissileProjectile(int damage, float x, float y, Types::NPC type, int target) : Projectile(damage, x, y, type, target) 
{
	projectile_spr.setPosition(x, y);
	projectile_spr.setOrigin(32.f, 32.f);
}

int MissileProjectile::impact(std::vector<Monster>& monsters)
{
	int value = 0;
	for (auto& mons : monsters)
	{
		if (mons.getId() == target && abs(getProjectile().getPosition().x - mons.monster.getPosition().x) <= 10 && abs(getProjectile().getPosition().y - mons.monster.getPosition().y) <= 10 && destroyed == false)
		{
			if (!mons.isDead() && !mons.isInvisible())
			{
				value = mons.getHit(damage);
			}
			explosion.setOrigin(46.f, 45.f);
			explosion.setScale(2, 2);
			explosion.setPosition(mons.monster.getPosition().x, mons.monster.getPosition().y);
			damageArea.setOrigin(100.f, 100.f);
			damageArea.setRadius(100);
			damageArea.setPosition(mons.monster.getPosition().x, mons.monster.getPosition().y);
			damageArea.setFillColor(sf::Color(216, 30, 0, 100));
			for (auto& m : monsters)
			{
				if (damageArea.getGlobalBounds().contains(m.monster.getPosition().x, m.monster.getPosition().y) && !m.isDead()) // surroundings will get hit even if the target is already dead
				{
					if (!m.isDead() && !m.isInvisible())  //adding value if area damage kills additional monsters
					{
						value += m.getHit(damage);
					}
				}
			}
			drawArea = true;
			clock.restart();
			destroyed = true; // projectile
			break;
		}
	}
	return value;
}