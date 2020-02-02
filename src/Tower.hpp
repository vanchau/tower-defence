#ifndef Tower_hpp
#define Tower_hpp

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "GameState.hpp"
#include "Types.hpp"


class GameState;	//forward declaration

class Tower 
{
public:
	Tower(GameState* game, Types::NPC type, float x, float y);
	Tower() {};
	void loadFromSavedFile(GameState* newGame) { game = newGame; }
	
	void initSprite();
	void initTexture();
	Types::NPC getType() const;
	void hit(Monster& monster);


	sf::Sprite getTower();
	void setDamage();
	void setRange();
	void setFireRate();
	void resetTarget();
	void setPauseTime(float time) { pauseTime = time; }

	sf::Sprite tower;
	sf::Sound shootSound;
	sf::CircleShape circle;
	sf::Sprite fireratePlatform;
	sf::Sprite damagePlatform;
	sf::Sprite rangePlatform;
	sf::Sprite infobox;

	bool draw_range = false;
	bool upgrade_selected = false; 
	bool textureInit = false;
	bool upgrade_firerate = true;
	bool upgrade_range = true;
	bool upgrade_damage = true;

	int getFirerateLevel();
	int getRangeLevel();
	int getDamageLevel();
	int getPrice();

	template <typename Archive>
	void serialize(Archive& ar, const unsigned int version)
	{
		ar & type;
		ar & x;
		ar &y;
		ar &Damage;
		ar &damageLevel;
		ar &range;
		ar &rangeLevel;
		ar &fireRate;
		ar &firerateLevel;
	}

private:
	float pauseTime = 0;
	//save
	Types::NPC type;
	bool canHit(Monster const monster);
	void setAngle(Monster const monster);
	float targetId; //for aiming
	//save both
	float x;
	float y;
	GameState* game;
	//save
	int Damage;
	//save
	float range;
	//save
	int fireRate;
	int price;

	//save all
	int firerateLevel = 0;
	int rangeLevel = 0;
	int damageLevel = 0;

	sf::Font font;

	sf::Clock clock;


};

#endif