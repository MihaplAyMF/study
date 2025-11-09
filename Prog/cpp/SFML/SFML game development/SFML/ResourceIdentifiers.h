#pragma once

namespace sf
{
	class Texture;
	class Font;
	class Shader;
	class SoundBuffer;
}

enum class Textures
{
	Entities,
	Jungle,
	TitleScreen,
	Buttons,
	Explosion,
	Particle,
	FinishLine,
};

enum class Shaders
{
	BrightnessPass,
	DownSamplePass,
	GaussianBlurPass,
	AddPass,
};

enum class Fonts
{
	Main,
};

enum class SoundEffect
{
	AlliedGunfire,
	EnemyGunfire,
	Explosion1,
	Explosion2,
	LaunchMissile,
	CollectPickup,
	Button,
};

enum class Music
{
	MenuTheme,
	MissionTheme,
};

template <typename Resource, typename Identifier>
class ResourceHolder;

typedef ResourceHolder<sf::Texture, Textures>			TextureHolder;
typedef ResourceHolder<sf::Font, Fonts>					FontHolder;
typedef ResourceHolder<sf::Shader, Shaders>				ShaderHolder;
typedef ResourceHolder<sf::SoundBuffer, SoundEffect>	SoundBufferHolder;