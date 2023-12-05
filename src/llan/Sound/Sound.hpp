/**
 * @file Sound.hpp
 * @author Jeekun Park (jeekunp@naver.com)
 * @brief 
 * @version 0.1
 * @date 2023-12-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "SFML/Audio/SoundBuffer.hpp"
#include "llan/common.hpp"

namespace Llan
{
	class Sound
	{
	public:
		Sound(const std::string& filePath);
		~Sound();

		void play();
		void play(bool isPlaying);
		void pause();
		void stop();
		void setLoop(bool loop);
		void setPitch(float pitch);
	private:
		sf::SoundBuffer mBuffer;
		sf::Sound mSound;
		bool mIsPlaying;
	};
}