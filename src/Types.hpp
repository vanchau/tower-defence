#ifndef TYPES_HPP
#define TYPES_HPP

class Types
{
public:
	enum NPC
	{
		Turret,			// Basic tower
		Fire,			// High fire rate
		Missile,		// AoE
		BasicSoldier,	// Basic soldier
		Infantry,		// Basic soldier but a little faster
		Tank,			// Takes half damage from fire
		Aircraft,		// Speeds up at half hp
		SuperSoldier,	// Invisibility - cannot be hit during invisibility
		Raidboss		// Big tanky tank, spawns three smaller tanks upon death
	};

};

#endif