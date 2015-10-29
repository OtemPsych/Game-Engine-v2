#include <iostream>
#include <cassert>

namespace gE {
	// Constructor(s)
		// Default
	template <typename MusicID>
	MusicPlayer<MusicID>::MusicPlayer()
		: mVolume(100.f)
	{
	}

	// Public Method(s)
		// Play
	template <typename MusicID>
	void MusicPlayer<MusicID>::play(MusicID theme)
	{
		std::string filename = mFilenames[theme];

		try {
			if (!mMusic.openFromFile(filename))
				throw std::runtime_error("Music " + filename + " could not be loaded.");
		}
		catch (std::runtime_error& e) {
			std::cout << "\nEXCEPTION: " << e.what() << std::endl;
			return;
		}

		mMusic.setVolume(mVolume);
		mMusic.setLoop(true);
		mMusic.play();
	}
		// Stop
	template <typename MusicID>
	void MusicPlayer<MusicID>::stop()
	{
		mMusic.stop();
	}
		// Insert Music File
	template <typename MusicID>
	void MusicPlayer<MusicID>::insertMusicFile(MusicID musicID, const std::string& filename)
	{
		auto inserted = mFilenames.insert(std::make_pair(musicID, filename));
		assert(inserted.second);
	}
		// Set Paused
	template <typename MusicID>
	void MusicPlayer<MusicID>::setPaused(bool paused)
	{
		if (paused)
			mMusic.pause();
		else
			mMusic.play();
	}
}