#include "MusicPlayer.h"

MusicPlayer::MusicPlayer()
	: mMusic()
	, mFilenames()
	, mVolume(0.f)
{
	mFilenames[Music::MenuTheme]    = "Media/Music/MenuTheme.ogg";
	mFilenames[Music::MissionTheme] = "Media/Music/MissionTheme.ogg";
}

void MusicPlayer::play(Music theme)
{
	std::string filename = mFilenames[theme];
	
	if(!mMusic.openFromFile(filename))
		throw std::runtime_error("Music " + filename + " could not be loaded.");

	mMusic.setVolume(mVolume);
	mMusic.setLoop(true);
	mMusic.play();
}

void MusicPlayer::stop()
{
	mMusic.stop();
}

void MusicPlayer::setPaused(bool paused)
{
	if(paused)
		mMusic.pause();
	else
		mMusic.play();
}

void MusicPlayer::setVolume(float volume)
{
	mVolume = volume;
}
