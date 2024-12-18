#pragma once

namespace Category
{
	enum Type
	{
		None             = 0,
		SceneAirLayer    = 1 << 0,
		PlayerAircraft   = 1 << 1,
		AliedAircraft    = 1 << 2,
		EnemyAircraft    = 1 << 3,
		Pickup           = 1 << 4,
		AlliedProjectile = 1 << 5,
		EnemyProjectile  = 1 << 6,
		ParticleSystem   = 1 << 7,
		SoundEffect		 = 1 << 8,
		Network			 = 1 << 9,

		Aircraft = PlayerAircraft | AliedAircraft | EnemyAircraft,
		Projectile = AlliedProjectile | EnemyProjectile,
	};
}