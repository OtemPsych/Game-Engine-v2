#ifndef MusicPlayer_H_
#define MusicPlayer_H_

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Audio/Music.hpp>

namespace gE
{
	template <typename MusicID>
	class MusicPlayer : private sf::NonCopyable
	{
	private:
		// Private Member(s)
		sf::Music					   mMusic;
		std::map<MusicID, std::string> mFilenames;
		float						   mVolume;

	public:
		// Constructor(s)
		MusicPlayer();
		// Public Method(s)
		void play(MusicID theme);
		void stop();

		void insertMusicFile(MusicID musicID, const std::string& filename);

		void		setPaused(bool paused);
		inline void setVolume(float volume) { mVolume = volume; }
	};
}
#include "MusicPlayer.inl"
#endif