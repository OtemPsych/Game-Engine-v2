#include <SFML/Audio/Listener.hpp>

namespace gE {
	// Constructor(s)
		// Default
	template <typename SoundID>
	SoundPlayer<SoundID>::SoundPlayer()
	{
		mSoundCoords.listenerZ = 300.f;
		mSoundCoords.attenuation = 8.f;
		mSoundCoords.minDistance2D = 200.f;
		calculateMinDistance3D();

		sf::Listener::setDirection(0.f, 0.f, -1.f);
	}

	// Private Method(s)
		// Calculate MinDistance3D
	template <typename SoundID>
	void SoundPlayer<SoundID>::calculateMinDistance3D()
	{
		mSoundCoords.minDistance3D
			= std::sqrt(std::pow(mSoundCoords.minDistance2D, 2)
			+ std::pow(mSoundCoords.listenerZ, 2));
	}

	// Public Method(s)
		// Play
	template <typename SoundID>
	void SoundPlayer<SoundID>::play(SoundID effect)
	{
		play(effect, getListenerPosition());
	}
		// Play | Position
	template <typename SoundID>
	void SoundPlayer<SoundID>::play(SoundID effect, sf::Vector2f position)
	{
		mSounds.push_back(sf::Sound());
		sf::Sound& sound = mSounds.back();

		sound.setBuffer(mSoundBuffers.get(effect));
		sound.setPosition(position.x, -position.y, 0.f);
		sound.setAttenuation(mSoundCoords.attenuation);
		sound.setMinDistance(mSoundCoords.minDistance3D);

		sound.play();
	}
		// Insert Sound File
	template <typename SoundID>
	void SoundPlayer<SoundID>::insertSoundFile(SoundID effect, const std::string& filename)
	{
		mSoundBuffers.load(effect, filename);
	}
		// Remove Stopped Sounds
	template <typename SoundID>
	void SoundPlayer<SoundID>::removeStoppedSounds()
	{
		mSounds.remove_if([](const sf::Sound& s)
		{
			return s.getStatus() == sf::Sound::Stopped;
		});
	}
		// Set Listener Position
	template <typename SoundID>
	void SoundPlayer<SoundID>::setListenerPosition(sf::Vector2f position)
	{
		sf::Listener::setPosition(position.x, -position.y, mSoundCoords.listenerZ);
		calculateMinDistance3D();
	}
		// Get Listener Position
	template <typename SoundID>
	sf::Vector2f SoundPlayer<SoundID>::getListenerPosition() const
	{
		sf::Vector3f position = sf::Listener::getPosition();
		return sf::Vector2f(position.x, -position.y);
	}
}