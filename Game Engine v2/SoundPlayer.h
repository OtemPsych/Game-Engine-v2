#ifndef SoundPlayer_H_
#define SoundPlayer_H_

#include "ResourceTypedefs.h"

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Audio/Sound.hpp>

#include <list>

namespace gE
{
	template <typename SoundID>
	class SoundPlayer : private sf::NonCopyable
	{
	private:
		// Private Struct(s)
		struct SoundCoords {
			float listenerZ,
				attenuation,
				minDistance2D,
				minDistance3D;
		};
	private:
		// Private Member(s)
		SoundBufferHolder<SoundID> mSoundBuffers;
		std::list<sf::Sound>	   mSounds;
		SoundCoords				   mSoundCoords;

	private:
		// Private Method(s)
		void calculateMinDistance3D();
	public:
		// Constructor(s)
		SoundPlayer();
		// Public Method(s)
		void play(SoundID effect);
		void play(SoundID effect, sf::Vector2f position);

		void insertSoundFile(SoundID id, const std::string& filename);

		void removeStoppedSounds();

		void		 setListenerPosition(sf::Vector2f position);
		sf::Vector2f getListenerPosition() const;
	};
}
#include "SoundPlayer.inl"
#endif