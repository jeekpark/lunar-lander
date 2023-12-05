/**
 * @file Sound.cpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "llan/Sound/Sound.hpp"

namespace Llan
{
	Sound::Sound(const std::string& filePath)
	{
		mBuffer.loadFromFile(filePath);
		mSound.setBuffer(mBuffer);
		mSound.setLoop(false);
		mIsPlaying = false;
	}

	Sound::~Sound()
	{

	}

	void Sound::play()
	{
		mSound.play();
	}

	void Sound::play(bool isPlaying)
	{
		if (isPlaying && !mIsPlaying)
		{
			mSound.play();
			mIsPlaying = true;
		}
		else if (!isPlaying && mIsPlaying)
		{
			mSound.pause();
			mIsPlaying = false;
		}
	}

	void Sound::pause()
	{
		mSound.pause();
	}

	void Sound::stop()
	{
		mSound.stop();
	}

	void Sound::setLoop(bool loop)
	{
		mSound.setLoop(loop);
	}

	void Sound::setPitch(float pitch)
	{
		mSound.setPitch(pitch);
	}
}