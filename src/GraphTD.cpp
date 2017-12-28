#include "GraphTD.hpp"
#include <iostream>

GraphTD::GraphTD(GameState* game) : game(game)
{
	game->window.create(sf::VideoMode(1920, 1080), "Tower Defence 5", sf::Style::None);
	game->window.setMouseCursorVisible(false);
	game->window.setKeyRepeatEnabled(false);
	font.loadFromFile("Resources/GROBOLD.ttf");
	cursorTexture.loadFromFile("Resources/cursor.png");
	basicTowerTexture.loadFromFile("Resources/tower_basic.png");
	fireTowerTexture.loadFromFile("Resources/tower_fire.png");
	missileTowerTexture.loadFromFile("Resources/tower_missile.png");
	turretProjectileTexture.loadFromFile("Resources/projectile_basic.png");
	fireProjectileTexture.loadFromFile("Resources/projectile_fire.png");
	missileProjectileTexture.loadFromFile("Resources/projectile_missile.png");
	explosionTexture.loadFromFile("Resources/explosion.png");
	infantryMonsterTexture.loadFromFile("Resources/monster_infantry.png");
	soldierMonsterTexture.loadFromFile("Resources/monster_soldier.png");
	aircraftMonsterTexture.loadFromFile("Resources/monster_aircraft.png");
	tankMonsterTexture.loadFromFile("Resources/monster_tank.png");
	supersoldierTexture.loadFromFile("Resources/monster_supersoldier.png");
	raidbossTexture.loadFromFile("Resources/monster_raidboss.png");
	red.loadFromFile("Resources/redcross.png");
	t_platform.loadFromFile("Resources/platform.png");
	t_damagePlatform.loadFromFile("Resources/damage_platform.png");
	t_rangePlatform.loadFromFile("Resources/range_platform.png");
	t_infobox.loadFromFile("Resources/infobox.png");
	clickSoundBuffer.loadFromFile("Resources/click.ogg");
	dropSoundBuffer.loadFromFile("Resources/drop.ogg");
	deniedSoundBuffer.loadFromFile("Resources/denied.wav");
	upgradeSoundBuffer.loadFromFile("Resources/upgrade.wav");
	missileSoundBuffer.loadFromFile("Resources/missile_launch.ogg");
	turretSoundBuffer.loadFromFile("Resources/turret.ogg");
	fireSoundBuffer.loadFromFile("Resources/fire.wav");
	missileImpactSB.loadFromFile("Resources/missile_impact.ogg");
	skipWaiting.setFont(font);
	skipWaiting.setString("START");
	setText(skipWaiting, 1700.f, 130.f, font, 24);
	pause.setFont(font);
	pause.setString("OPTIONS");
	setText(pause, 1700.f, 460.f, font, 24);
	nameInput.setFont(font);
	setText(nameInput, 590.f, 500.f, font, 50);
	playerHP.setFont(font);
	setText(playerHP, 1700.f, 650.f, font, 24);
	levelLabel.setFont(font);
	setText(levelLabel, 1700.f, 10.f, font, 24);
	pointsLabel.setFont(font);
	setText(pointsLabel, 1700.f, 50.f, font, 24);
	timeOutLabel.setFont(font);
	setText(timeOutLabel, 1700.f, 90.f, font, 24);
	gameOver.setFont(font);
	setText(gameOver, 590.f, 300.f, font, 50);
	pausedTitle.setFont(font);
	pausedTitle.setString("PAUSED");
	setText(pausedTitle, 800.f, 400.f, font, 68);
	continueButton.setFont(font);
	continueButton.setString("RESUME");
	setText(continueButton, 875.f, 510.f, font, 32);
	exitButton.setFont(font);
	exitButton.setString("EXIT");
	setText(exitButton, 895.f, 570.f, font, 32);
	basicTowerPrice.setFont(font);
	setText(basicTowerPrice, 1780.f, 210.f, font, 20);
	basicTowerPrice.setString("500");
	fireTowerPrice.setFont(font);
	setText(fireTowerPrice, 1780.f, 310.f, font, 20);
	fireTowerPrice.setString("1000");
	missileTowerPrice.setFont(font);
	setText(missileTowerPrice, 1780.f, 410.f, font, 20);
	missileTowerPrice.setString("2500");
	firerateUpgrade.setFont(font);
	firerateUpgrade.setPosition(1700.f, 505.f);
	firerateUpgrade.setCharacterSize(20);
	rangeUpgrade.setFont(font);
	rangeUpgrade.setPosition(1700.f, 555.f);
	rangeUpgrade.setCharacterSize(20);
	damageUpgrade.setFont(font);
	damageUpgrade.setPosition(1700.f, 605.f);
	damageUpgrade.setCharacterSize(20);
	infoText1.setFont(font);
	infoText1.setPosition(1480, 25);
	infoText1.setCharacterSize(24);
	infoText2.setFont(font);
	infoText2.setPosition(1455, 70);
	infoText2.setCharacterSize(20);
	infoText3.setFont(font);
	infoText3.setPosition(1453, 125);
	infoText3.setCharacterSize(16);
	infoText4.setFont(font);
	infoText4.setPosition(1465, 175);
	infoText4.setCharacterSize(16);
	infoText5.setFont(font);
	infoText5.setPosition(1455, 225);
	infoText5.setCharacterSize(16);
	infoText6.setFont(font);
	infoText6.setPosition(1525, 145);
	infoText6.setCharacterSize(16);
	infoText7.setFont(font);
	infoText7.setPosition(1525, 195);
	infoText7.setCharacterSize(16);
	infoText8.setFont(font);
	infoText8.setPosition(1525, 245);
	infoText8.setCharacterSize(16);
	circleTurret.setOrigin(250.f, 250.f);
	circleTurret.setRadius(250.f);
	circleTurret.setFillColor(sf::Color(0, 102, 102, 100));
	circleFire.setOrigin(150.f, 150.f);
	circleFire.setRadius(150.f);
	circleFire.setFillColor(sf::Color(0, 102, 102, 100));
	circleMissile.setOrigin(500.f, 500.f);
	circleMissile.setRadius(500.f);
	circleMissile.setFillColor(sf::Color(0, 102, 102, 100));
	t_basic.setTexture(basicTowerTexture);
	t_basic.setPosition(1740, 220);
	t_basic.setOrigin(32.f, 32.f);
	t_fire.setTexture(fireTowerTexture);
	t_fire.setPosition(1740, 320);
	t_fire.setOrigin(32.f, 32.f);
	t_missile.setTexture(missileTowerTexture);
	t_missile.setPosition(1740, 420);
	t_missile.setOrigin(32.f, 32.f);
	cursor.setTexture(cursorTexture);
	cross.setTexture(red);
	cross.setScale(0.25f, 0.25f);
	firerate.setSize(sf::Vector2f(210, 45));
	firerate.setPosition(1690, 495);
	firerate.setFillColor(sf::Color(102, 204, 0));
	range.setSize(sf::Vector2f(210, 45));
	range.setPosition(1690, 545);
	range.setFillColor(sf::Color(102, 178, 255));
	damage.setSize(sf::Vector2f(210, 45));
	damage.setPosition(1690, 595);
	damage.setFillColor(sf::Color(255, 128, 0));
	road1.setSize(sf::Vector2f(448, 192));
	road1.setPosition(0, 64);
	road2.setSize(sf::Vector2f(192, 704));
	road2.setPosition(256, 256);
	road3.setSize(sf::Vector2f(448, 192));
	road3.setPosition(448, 768);
	road4.setSize(sf::Vector2f(192, 704));
	road4.setPosition(704, 64);
	road5.setSize(sf::Vector2f(448, 192));
	road5.setPosition(896, 64);
	road6.setSize(sf::Vector2f(192, 704));
	road6.setPosition(1152, 256);
	road7.setSize(sf::Vector2f(576, 192));
	road7.setPosition(1344, 768);
	menu.setSize(sf::Vector2f(256, 704));
	menu.setPosition(1664, 0);
	pauseScreen.setSize(sf::Vector2f(1920, 1080));
	pauseScreen.setFillColor(sf::Color(0, 0, 0, 150));
	clickSound.setBuffer(clickSoundBuffer);
	dropSound.setBuffer(dropSoundBuffer);
	deniedSound.setBuffer(deniedSoundBuffer);
	upgradeSound.setBuffer(upgradeSoundBuffer);
	missileImpact.setBuffer(missileImpactSB);
}

void GraphTD::setText(sf::Text& text, float x, float y, sf::Font font, int size)
{
	text.setPosition(x, y);
	text.setCharacterSize(size);
}

template <class t>
bool GraphTD::insideBounds(t sprite, sf::Vector2f pos)
{
	return sprite.getGlobalBounds().contains(pos);
}

template <class t>
bool GraphTD::insideBounds(t sprite, sf::Vector2i pos)
{
	return sprite.getGlobalBounds().contains(pos.x, pos.y);
}

bool GraphTD::inRoad(sf::Vector2f pos)
{
	return (insideBounds(road1, pos) || insideBounds(road2, pos) ||
		insideBounds(road3, pos) || insideBounds(road4, pos) ||
		insideBounds(road5, pos) || insideBounds(road6, pos) ||
		insideBounds(road7, pos) || insideBounds(menu, pos));
}

void GraphTD::createTower(Types::NPC type, int losePoints)
{
	dropSound.play();
	game->createTower(type, sf::Mouse::getPosition(game->window).x, sf::Mouse::getPosition(game->window).y);
	game->losePoints(losePoints);
}

void GraphTD::processEndInput()
{
	sf::Event event;
	while (game->window.pollEvent(event))
	{
		switch (event.type)
		{
		case(sf::Event::TextEntered):
			if (event.text.unicode == '\b' && !nameFinished)
			{
				if (playerName.isEmpty())
					break;
				else
				{
					playerName.erase(playerName.getSize() - 1, 1);
					nameInput.setString(playerName);
				}
			}
			else if (event.text.unicode == '\ ')
			{
				break;
			}
			else if (event.text.unicode == '\r')
			{
				if (playerName.isEmpty())
					break;
				else
				{
					nameFinished = true;
					game->setName(playerName);
					nameInput.setString(playerName + "\nPRESS ESC TO LEAVE");
					game->gameEnded();
				}
			}
			else if (event.text.unicode < 128 && !nameFinished && playerName.getSize() < 16)
			{
				playerName.insert(playerName.getSize(), event.text.unicode);
				nameInput.setString(playerName);
			}
			break;

		case(sf::Event::KeyPressed):
			if (event.key.code == sf::Keyboard::Escape)
			{
				game->window.close();
				break;
			}
		}
	}
}

void GraphTD::showHiscores()
{
	if (game->showTopScore())
	{
		if (!topScoresInit)
		{
			topScoresInit = true;


			float y = 1200.f;
			int i = 1;
			for (auto& score : game->topScoresVec)
			{
				sf::Text tmp;
				tmp.setFont(font);
				tmp.setCharacterSize(50);
				tmp.setPosition(590.f, y);
				tmp.setString(std::to_string(i) + ". " + score.name + " - Score: " + std::to_string(score.points) + " - Wave: " + std::to_string(score.level));
				topScores.push_back(tmp);
				y += 150.f;
				i++;
			}
		}
			for (auto& text : topScores)
			{
				text.setPosition(text.getPosition().x, text.getPosition().y - 2.5);
			}
	}
}

void GraphTD::processPause()
{
	sf::Event event;
	while (game->window.pollEvent(event))
	{
		sf::Vector2i mouse(sf::Mouse::getPosition(game->window).x, sf::Mouse::getPosition(game->window).y);
		if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left) || event.type == sf::Event::KeyPressed)
		{
				if (continueButton.getGlobalBounds().contains(mouse.x, mouse.y) || event.key.code == sf::Keyboard::Escape)
				{
					game->addTimeOut(pauseClock.getElapsedTime().asSeconds());
					clickSound.play();
					for (auto& tow : game->towers)
					{
						tow.setPauseTime(pauseClock.getElapsedTime().asMilliseconds());
					}
					for (auto& mons : game->monsters)
					{
						mons.setPauseTime(pauseClock.getElapsedTime().asMilliseconds());
					}
					paused = !paused;
				}

				else if (exitButton.getGlobalBounds().contains(mouse.x, mouse.y))
				{
					game->window.close();
				}
		}
		else if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
		{
			game->window.close();
		}
	}
}

void GraphTD::Start()
{
	while (game->window.isOpen())
	{
		sf::Clock clock;
		sf::Time timeSinceLastUpdate = sf::Time::Zero;
		while (game->window.isOpen())
		{
			if (game->getPlayerHP() > 0 && !paused)
				processEvents();

			timeSinceLastUpdate += clock.restart();

			while (timeSinceLastUpdate > TimePerFrame)
			{
				timeSinceLastUpdate -= TimePerFrame;
				if (game->getPlayerHP() > 0 && !paused)
				{
					processEvents();
					game->update(TimePerFrame);
				}
				else if (paused)
				{
					processPause();
				}
				else
				{
					game->update(TimePerFrame);
					processEndInput();
					if (game->isGameEnded())
					{
						showHiscores();
					}
				}
			}
			render();
		}
	}
}


void GraphTD::setUpgradeButtonColors(float posx, float posy, std::vector<Tower>::value_type& tow)
{
	if (tow.upgrade_selected)
	{
		//if upgrade selected show upgrade button with different colors
		if (firerate.getGlobalBounds().contains(posx, posy) || !tow.upgrade_firerate)
		{
			firerate.setFillColor(sf::Color(160, 160, 160));
		}

		else
		{
			firerate.setFillColor(sf::Color(102, 204, 0));
		}

		if (range.getGlobalBounds().contains(posx, posy) || !tow.upgrade_range)
		{
			range.setFillColor(sf::Color(160, 160, 160));
		}
		else
		{
			range.setFillColor(sf::Color(102, 178, 255));
		}

		if (damage.getGlobalBounds().contains(posx, posy) || !tow.upgrade_damage)
		{
			damage.setFillColor(sf::Color(160, 160, 160));
		}

		else
		{
			damage.setFillColor(sf::Color(255, 128, 0));
		}
	}
}

void GraphTD::drawMovableTower(float posx, float posy, sf::Vector2f pos)
{
	bool can_draw = true;
	for (auto& tow : game->towers)
	{
		if (tow.tower.getGlobalBounds().contains(posx, posy))
		{
			can_draw = false;
			break;
		}
	}
	if (inRoad(pos) || !can_draw)
	{
		blocked = true;

		if (!(menu.getGlobalBounds().contains(posx, posy)))
		{
			cross.setPosition(posx - 31, posy - 28);
		}

		else
		{
			menu_blocked = true;
		}
	}
	else
	{
		tower_selected = true;
		blocked = false;
		menu_blocked = false;
	}
	tower_released = false;
}

void GraphTD::upgradePressed(sf::Vector2i mouse, std::vector<Tower>::value_type& tow)
{
	if (tow.upgrade_selected &&
		(firerate.getGlobalBounds().contains(mouse.x, mouse.y) ||
			range.getGlobalBounds().contains(mouse.x, mouse.y) ||
			damage.getGlobalBounds().contains(mouse.x, mouse.y)))
	{
		upgrade_selected = true;
		if (firerate.getGlobalBounds().contains(mouse.x, mouse.y))
		{
			if (tow.upgrade_firerate)
			{
				upgradeSound.play();
				tow.setFireRate();
				firerate.setFillColor(sf::Color(102, 204, 0));
			}
			else
			{
				deniedSound.play();
			}
		}
		else if (range.getGlobalBounds().contains(mouse.x, mouse.y))
		{
			if (tow.upgrade_range)
			{
				upgradeSound.play();
				tow.setRange();
				range.setFillColor(sf::Color(102, 178, 255));
			}
			else
			{
				deniedSound.play();
			}
		}
		else if (damage.getGlobalBounds().contains(mouse.x, mouse.y))
		{
			if (tow.upgrade_damage)
			{
				upgradeSound.play();
				tow.setDamage();
				damage.setFillColor(sf::Color(255, 128, 0));
			}
			else
			{
				deniedSound.play();
			}
		}
		else
		{
			deniedSound.play();
			tow.upgrade_selected = false;
		}
	}
	else
	{
		upgrade_selected = false;
	}
}

void GraphTD::canUpgrade(sf::Vector2i pos, Tower& tow)
{
	if (tow.upgrade_selected &&
		(firerate.getGlobalBounds().contains(pos.x, pos.y) ||
			range.getGlobalBounds().contains(pos.x, pos.y) ||
			damage.getGlobalBounds().contains(pos.x, pos.y)))
	{
		if ((tow.getType() == Types::NPC::Turret && game->getPoints() < (tow.getFirerateLevel() + 1) * 250) ||
			(tow.getType() == Types::NPC::Fire && game->getPoints() < (tow.getFirerateLevel() + 1) * 500) ||
			(tow.getType() == Types::NPC::Missile && game->getPoints() < (tow.getFirerateLevel() + 1) * 1000))
		{
			firerate.setFillColor(sf::Color(160, 160, 160));
			tow.upgrade_firerate = false;
			cannot_upgrade = true;
		}
		else
		{
			firerate.setFillColor(sf::Color(102, 204, 0));
			tow.upgrade_firerate = true;
			cannot_upgrade = false;
		}
		if ((tow.getType() == Types::NPC::Turret && game->getPoints() < (tow.getRangeLevel() + 1) * 250) ||
			(tow.getType() == Types::NPC::Fire && game->getPoints() < (tow.getRangeLevel() + 1) * 500) ||
			(tow.getType() == Types::NPC::Missile && game->getPoints() < (tow.getRangeLevel() + 1) * 1000))
		{
			range.setFillColor(sf::Color(160, 160, 160));
			tow.upgrade_range = false;
			cannot_upgrade = true;
		}
		else
		{
			range.setFillColor(sf::Color(102, 178, 255));
			tow.upgrade_range = true;
			cannot_upgrade = false;
		}
		if ((tow.getType() == Types::NPC::Turret && game->getPoints() < (tow.getDamageLevel() + 1) * 250) ||
			(tow.getType() == Types::NPC::Fire && game->getPoints() < (tow.getDamageLevel() + 1) * 500) ||
			(tow.getType() == Types::NPC::Missile && game->getPoints() < (tow.getDamageLevel() + 1) * 1000))
		{
			damage.setFillColor(sf::Color(160, 160, 160));
			tow.upgrade_damage = false;
			cannot_upgrade = true;
		}
		else
		{
			damage.setFillColor(sf::Color(255, 128, 0));
			tow.upgrade_damage = true;
			cannot_upgrade = false;
		}
		if (tow.getFirerateLevel() >= 2 || tow.getRangeLevel() >= 2 || tow.getDamageLevel() >= 2)
		{
			if (tow.getFirerateLevel() >= 2)
			{
				firerate.setFillColor(sf::Color(160, 160, 160));
				tow.upgrade_firerate = false;
				cannot_upgrade = true;
			}

			if (tow.getRangeLevel() >= 2)
			{
				range.setFillColor(sf::Color(160, 160, 160));
				tow.upgrade_range = false;
				cannot_upgrade = true;
			}

			if (tow.getDamageLevel() >= 2)
			{
				damage.setFillColor(sf::Color(160, 160, 160));
				tow.upgrade_damage = false;
				cannot_upgrade = true;
			}
		}
		if (!cannot_upgrade)
		{
			firerate.setFillColor(sf::Color(102, 204, 0));
			range.setFillColor(sf::Color(102, 178, 255));
			damage.setFillColor(sf::Color(255, 128, 0));

			tow.upgrade_firerate = true;
			tow.upgrade_range = true;
			tow.upgrade_damage = true;
			cannot_upgrade = false;
		}
	}
	else if (insideBounds(tow.tower, pos))
	{
		clickSound.play();
		tow.upgrade_selected = true;
		upgrade_selected = true;
		if ((tow.getType() == Types::NPC::Turret && game->getPoints() < (tow.getFirerateLevel() + 1) * 250) ||
			(tow.getType() == Types::NPC::Fire && game->getPoints() < (tow.getFirerateLevel() + 1) * 500) ||
			(tow.getType() == Types::NPC::Missile && game->getPoints() < (tow.getFirerateLevel() + 1) * 1000))
		{
			firerate.setFillColor(sf::Color(160, 160, 160));
			tow.upgrade_firerate = false;
			cannot_upgrade = true;
		}
		else
		{
			firerate.setFillColor(sf::Color(102, 204, 0));
			tow.upgrade_firerate = true;
			cannot_upgrade = false;
		}
		if ((tow.getType() == Types::NPC::Turret && game->getPoints() < (tow.getRangeLevel() + 1) * 250) ||
			(tow.getType() == Types::NPC::Fire && game->getPoints() < (tow.getRangeLevel() + 1) * 500) ||
			(tow.getType() == Types::NPC::Missile && game->getPoints() < (tow.getRangeLevel() + 1) * 1000))
		{
			range.setFillColor(sf::Color(160, 160, 160));
			tow.upgrade_range = false;
			cannot_upgrade = true;
		}
		else
		{
			range.setFillColor(sf::Color(102, 178, 255));
			tow.upgrade_range = true;
			cannot_upgrade = false;
		}
		if ((tow.getType() == Types::NPC::Turret && game->getPoints() < (tow.getDamageLevel() + 1) * 250) ||
			(tow.getType() == Types::NPC::Fire && game->getPoints() < (tow.getDamageLevel() + 1) * 500) ||
			(tow.getType() == Types::NPC::Missile && game->getPoints() < (tow.getDamageLevel() + 1) * 1000))
		{
			damage.setFillColor(sf::Color(160, 160, 160));
			tow.upgrade_damage = false;
			cannot_upgrade = true;
		}
		else
		{
			damage.setFillColor(sf::Color(255, 128, 0));
			tow.upgrade_damage = true;
			cannot_upgrade = false;
		}
		if (tow.getFirerateLevel() >= 2 || tow.getRangeLevel() >= 2 || tow.getDamageLevel() >= 2)
		{
			if (tow.getFirerateLevel() >= 2)
			{
				firerate.setFillColor(sf::Color(160, 160, 160));
				tow.upgrade_firerate = false;
				cannot_upgrade = true;
			}

			if (tow.getRangeLevel() >= 2)
			{
				range.setFillColor(sf::Color(160, 160, 160));
				tow.upgrade_range = false;
				cannot_upgrade = true;
			}

			if (tow.getDamageLevel() >= 2)
			{
				damage.setFillColor(sf::Color(160, 160, 160));
				tow.upgrade_damage = false;
				cannot_upgrade = true;
			}
		}
		if (!cannot_upgrade)
		{
			firerate.setFillColor(sf::Color(102, 204, 0));
			range.setFillColor(sf::Color(102, 178, 255));
			damage.setFillColor(sf::Color(255, 128, 0));

			tow.upgrade_firerate = true;
			tow.upgrade_range = true;
			tow.upgrade_damage = true;
			cannot_upgrade = false;
		}
	}
	else
	{
		tow.upgrade_selected = false;
		upgrade_selected = false;
	}
}

void GraphTD::processEvents()
{
	sf::Event event;
	while (game->window.pollEvent(event))
	{
		sf::Vector2i mouse(sf::Mouse::getPosition(game->window).x, sf::Mouse::getPosition(game->window).y);
		float posx = event.mouseMove.x;
		float posy = event.mouseMove.y;
		sf::Vector2f pos(posx, posy);
		if (event.type == sf::Event::Closed)
		{
			game->window.close();
			break;
		}
		if (event.type == sf::Event::MouseMoved)
		{
			if (insideBounds(t_basic, pos))
			{
				t_basic.setColor(sf::Color(0, 100, 175));
			}
			else
			{
				t_basic.setColor(sf::Color(255, 255, 255));
			}
			for (auto& tow : game->towers)
			{
				//if mouse over tower, draw fire range circle
				if ((insideBounds(tow.tower, pos) && !tower_selected) || tow.upgrade_selected)
				{
					tow.draw_range = true;
				}
				else
				{
					tow.draw_range = false;
				}

				setUpgradeButtonColors(posx, posy, tow);
			}
			//if new tower is moved on screen
			if (copyBasic)
			{
				t_basic.setPosition(posx, posy);
				circleTurret.setPosition(posx, posy);

				drawMovableTower(posx, posy, pos);
			}
			else if (copyFire)
			{
				t_fire.setPosition(posx, posy);
				circleFire.setPosition(posx, posy);

				drawMovableTower(posx, posy, pos);
			}
			else if (copyMissile)
			{
				t_missile.setPosition(posx, posy);
				circleMissile.setPosition(posx, posy);

				drawMovableTower(posx, posy, pos);
			}
			else
			{
				tower_released = true;
				blocked = false;
			}
		}
		if (event.type == sf::Event::MouseButtonReleased)
		{
			if ((copyBasic || copyFire || copyMissile) && tower_released && !blocked)
			{
				tower_selected = true;
			}
			else if (menu_blocked && copyBasic && tower_selected)
			{
				t_basic.setPosition(1740, 220);
				copyBasic = false;
				tower_released = true;
				tower_selected = false;
			}
			else if (menu_blocked && copyFire && tower_selected)
			{
				t_fire.setPosition(1740, 320);
				copyFire = false;
				tower_released = true;
				tower_selected = false;
			}
			else if (menu_blocked && copyMissile && tower_selected)
			{
				t_missile.setPosition(1740, 420);
				copyMissile = false;
				tower_released = true;
				tower_selected = false;
			}
			else
			{
				tower_selected = false;
			}
		}
		if (!blocked)
		{
			//if button is pressed on the screen
			if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left) || event.type == sf::Event::KeyPressed)
			{
				if (skipWaiting.getGlobalBounds().contains(mouse.x, mouse.y) && game->isTimeOt())
				{
					game->zeroTimeOut();
					clickSound.play();
				}
				else if (pause.getGlobalBounds().contains(mouse.x, mouse.y) || event.key.code == sf::Keyboard::Escape)
				{
					pauseClock.restart();
					clickSound.play();
					paused = !paused;
				}
				else if (copyBasic && tower_selected && !menu_blocked)
				{
					createTower(Types::NPC::Turret, 500);
					t_basic.setPosition(1740, 220);
				}
				else if (copyFire && tower_selected && !menu_blocked)
				{
					createTower(Types::NPC::Fire, 1000);
					t_fire.setPosition(1740, 320);
				}
				else if (copyMissile && tower_selected && !menu_blocked)
				{
					createTower(Types::NPC::Missile, 2500);
					t_missile.setPosition(1740, 420);
				}

				if (insideBounds(t_basic, mouse) && game->getPoints() >= 500)
				{
					clickSound.play();
					tower_selected = true;
					copyBasic = true;
					menu_blocked = true;
				}
				else if (insideBounds(t_fire, mouse) && game->getPoints() >= 1000)
				{
					clickSound.play();
					tower_selected = true;
					copyFire = true;
					menu_blocked = true;
				}
				else if (insideBounds(t_missile, mouse) && game->getPoints() >= 2500)
				{
					clickSound.play();
					tower_selected = true;
					copyMissile = true;
					menu_blocked = true;
				}
				else
				{
					copyBasic = false;
					copyFire = false;
					copyMissile = false;
				}
				for (auto& tow : game->towers)
				{
					upgradePressed(mouse, tow);
				}

				for (auto& tow : game->towers)
				{
					canUpgrade(mouse, tow);
				}
			}
		}
		if (blocked)
		{
			if (event.type == sf::Event::MouseButtonPressed)
			{
				deniedSound.play();
				if (menu_blocked && copyBasic && tower_selected)
				{
					t_basic.setPosition(1740, 220);
					copyBasic = false;
				}
				else if (menu_blocked && copyFire && tower_selected)
				{
					t_fire.setPosition(1740, 320);
					copyFire = false;
				}
				else if (menu_blocked && copyMissile && tower_selected)
				{
					t_missile.setPosition(1740, 420);
					copyMissile = false;
				}
			}
		}
	}
}

void GraphTD::render()
{
	game->window.clear();
	game->window.draw(game->map);
	cursor.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(game->window)));
	for (auto& monster : game->monsters)
	{
		if (!monster.textureInit)
		{
			monster.initTexture();
			if (monster.getType() == Types::NPC::BasicSoldier)
			{
				monster.monster.setTexture(soldierMonsterTexture);
			}
			else if (monster.getType() == Types::NPC::Infantry)
			{
				monster.monster.setTexture(infantryMonsterTexture);
			}
			else if (monster.getType() == Types::NPC::Aircraft)
			{
				monster.monster.setTexture(aircraftMonsterTexture);
			}
			else if (monster.getType() == Types::NPC::Tank)
			{
				monster.monster.setTexture(tankMonsterTexture);
			}
			else if (monster.getType() == Types::NPC::SuperSoldier)
			{
				monster.monster.setTexture(supersoldierTexture);
			}
			else
			{
				monster.monster.setTexture(raidbossTexture);
			}
		}
		if (!monster.isDead() || monster.clock.getElapsedTime().asMilliseconds() < 1000)
		{
			game->window.draw(monster.monster);
			game->window.draw(monster.base);
			game->window.draw(monster.HPbar);
		}
	}
	for (auto& tow : game->towers)
	{
		if (!tow.textureInit)
		{
			tow.initTexture();
			tow.fireratePlatform.setTexture(t_platform);
			tow.damagePlatform.setTexture(t_damagePlatform);
			tow.rangePlatform.setTexture(t_rangePlatform);
			if (tow.getType() == Types::NPC::Turret)
			{
				try
				{
					tow.tower.setTexture(basicTowerTexture);
					tow.shootSound.setBuffer(turretSoundBuffer);
				}
				catch (std::exception& e)
				{
					std::cout << e.what() << std::endl;
				}
			}
			else if (tow.getType() == Types::NPC::Fire)
			{
				try
				{
					tow.tower.setTexture(fireTowerTexture);
					tow.shootSound.setBuffer(fireSoundBuffer);
				}
				catch (std::exception& e)
				{
					std::cout << e.what() << std::endl;
				}
			}
			else
			{
				try
				{
					tow.tower.setTexture(missileTowerTexture);
					tow.shootSound.setBuffer(missileSoundBuffer);
				}
				catch (std::exception& e)
				{
					std::cout << e.what() << std::endl;
				}
			}
		}
		if (tow.draw_range)
		{
			game->window.draw(tow.circle);
		}
		if (tow.upgrade_selected || upgrade_selected)
		{
			tow.infobox.setTexture(t_infobox);
			game->window.draw(tow.infobox);
			if (tow.getType() == Types::NPC::Turret)
				infoText2.setString("Basic and reliable!");
			else if (tow.getType() == Types::NPC::Fire)
				infoText2.setString("Deals less damage\n        to tanks");
			else
				infoText2.setString("Deals AoE damage");
			infoText3.setString("Fire Rate Upgrade Level");
			infoText4.setString("Range Upgrade Level");
			infoText5.setString("Damage Upgrade Level");
			infoText6.setString(std::to_string(tow.getFirerateLevel()) + " / 2");
			infoText7.setString(std::to_string(tow.getRangeLevel()) + " / 2");
			infoText8.setString(std::to_string(tow.getDamageLevel()) + " / 2");
			if (tow.getType() == Types::NPC::Turret)
			{  
				infoText1.setString("Basic Tower");
				firerate_price = std::to_string(((tow.getFirerateLevel() + 1) * 250));
				if (firerate_price == "750")
				{
					firerate_price = "";
				}
				range_price = std::to_string(((tow.getRangeLevel() + 1) * 250));
				if (range_price == "750")
				{
					range_price = "";
				}
				damage_price = std::to_string(((tow.getDamageLevel() + 1) * 250));
				if (damage_price == "750")
				{
					damage_price = "";
				}
				firerateUpgrade.setString(firerate_price + "  FIRE RATE");
				rangeUpgrade.setString(range_price + "  RANGE");
				damageUpgrade.setString(damage_price + "  DAMAGE");
			}
			else if (tow.getType() == Types::NPC::Fire)
			{
				infoText1.setString("Fire Tower");
				firerate_price = std::to_string(((tow.getFirerateLevel() + 1) * 500));
				if (firerate_price == "1500")
				{
					firerate_price = "";
				}
				range_price = std::to_string(((tow.getRangeLevel() + 1) * 500));
				if (range_price == "1500")
				{
					range_price = "";
				}
				damage_price = std::to_string(((tow.getDamageLevel() + 1) * 500));
				if (damage_price == "1500")
				{
					damage_price = "";
				}
				firerateUpgrade.setString(firerate_price + "  FIRE RATE");
				rangeUpgrade.setString(range_price + "  RANGE");
				damageUpgrade.setString(damage_price + "  DAMAGE");
			}
			else if (tow.getType() == Types::NPC::Missile)
			{
				infoText1.setString("Missile Tower");
				firerate_price = std::to_string(((tow.getFirerateLevel() + 1) * 1000));
				if (firerate_price == "3000")
				{
					firerate_price = "";
				}
				range_price = std::to_string(((tow.getRangeLevel() + 1) * 1000));
				if (range_price == "3000")
				{
					range_price = "";
				}
				damage_price = std::to_string(((tow.getDamageLevel() + 1) * 1000));
				if (damage_price == "3000")
				{
					damage_price = "";
				}
				firerateUpgrade.setString(firerate_price + "  FIRE RATE");
				rangeUpgrade.setString(range_price + "  RANGE");
				damageUpgrade.setString(damage_price + "  DAMAGE");
			}
			game->window.draw(firerate);
			game->window.draw(range);
			game->window.draw(damage);
			game->window.draw(firerateUpgrade);
			game->window.draw(rangeUpgrade);
			game->window.draw(damageUpgrade);
			game->window.draw(infoText1);
			game->window.draw(infoText2);
			game->window.draw(infoText3);
			game->window.draw(infoText4);
			game->window.draw(infoText5);
			game->window.draw(infoText6);
			game->window.draw(infoText7);
			game->window.draw(infoText8);
		}
		if (tow.getFirerateLevel() > 0)
		{
			game->window.draw(tow.fireratePlatform);
		}
		if (tow.getRangeLevel() > 0)
		{
			game->window.draw(tow.rangePlatform);
		}
		if (tow.getDamageLevel() > 0)
		{
			game->window.draw(tow.damagePlatform);
		}
		game->window.draw(tow.getTower());
	}
	for (auto& projectile : game->projectiles)
	{
		if (!projectile->textureInit)
		{
			projectile->initTexture();
			if (projectile->getOriginType() == Types::NPC::Turret)
			{
				projectile->projectile_spr.setTexture(turretProjectileTexture);
			}
			else if (projectile->getOriginType() == Types::NPC::Fire)
			{
				projectile->projectile_spr.setTexture(fireProjectileTexture);
			}
			else
			{
				projectile->projectile_spr.setTexture(missileProjectileTexture);
			}
		}
		if (!projectile->isDestroyed())
		{
			game->window.draw(projectile->getProjectile());
		}

		if (projectile->drawArea)
		{
			projectile->explosion.setTexture(explosionTexture);
			game->window.draw(projectile->explosion);
		}
	}
	playerHP.setString("Lives: " + std::to_string(game->getPlayerHP()));
	levelLabel.setString("Wave: " + std::to_string(game->getRound()));
	pointsLabel.setString("Points: " + std::to_string(game->getPoints()));
	game->window.draw(playerHP);
	game->window.draw(levelLabel);
	game->window.draw(pointsLabel);
	game->window.draw(pause);
	if (game->isTimeOt())
	{
		game->window.draw(skipWaiting);
	}
	if (game->getPoints() < 500)
	{
		t_basic.setColor(sf::Color(128, 128, 128));
	}
	else
	{
		t_basic.setColor(sf::Color(255, 255, 255));
	}
	if (game->getPoints() < 1000)
	{
		t_fire.setColor(sf::Color(128, 128, 128));
	}
	else
	{
		t_fire.setColor(sf::Color(255, 255, 255));
	}
	if (game->getPoints() < 2500)
	{
		t_missile.setColor(sf::Color(128, 128, 128));
	}
	else
	{
		t_missile.setColor(sf::Color(255, 255, 255));
	}
	if (copyBasic && !tower_released)
	{
		game->window.draw(circleTurret);
	}
	else if (copyFire && !tower_released)
	{
		game->window.draw(circleFire);
	}
	else if (copyMissile && !tower_released)
	{
		game->window.draw(circleMissile);
	}
	game->window.draw(t_basic);
	game->window.draw(t_fire);
	game->window.draw(t_missile);
	game->window.draw(basicTowerPrice);
	game->window.draw(fireTowerPrice);
	game->window.draw(missileTowerPrice);
	if (blocked && !menu_blocked)
	{
		game->window.draw(cross);
		menu_blocked = false;
	}
	if (game->isTimeOt() && !paused)
	{
		timeOutLabel.setString("Next wave in: " + std::to_string(game->tillNextRound()));
	}
	else
	{
		timeOutLabel.setString("Next wave in: ");
	}
	game->window.draw(timeOutLabel);
	if (game->getPlayerHP() <= 0 && !game->showTopScore())
	{
		gameOver.setString("YOU HAVE BEEN DEFEATED!\nWAVES SURVIVED: " + std::to_string(game->getRound() - 1) + "\nTOTAL SCORE: " + std::to_string(game->getPoints()) + "\nPLAYER NAME: ");
		game->window.draw(nameInput);
		game->window.draw(gameOver);
	}
	for (auto& text : topScores)
	{
		game->window.draw(text);
	}
	if (paused)
	{
		game->window.draw(pauseScreen);
		game->window.draw(pausedTitle);
		game->window.draw(continueButton);
		game->window.draw(exitButton);
	}
	game->window.draw(cursor);
	game->window.display();
}