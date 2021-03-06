#include <cassert>
#include <iostream>

namespace gE {
	// Private Method(s)
		// Insert Resource
	template <typename ID, typename Res>
	void ResourceHolder<ID, Res>::insertResource(ID id, ResPtr resource)
	{
		auto inserted = mResourceMap.insert(std::make_pair(id, std::move(resource)));
		assert(inserted.second);
	}

	// Public Method(s)
		// Load
	template <typename ID, typename Res>
	void ResourceHolder<ID, Res>::load(ID id, const std::string& filename)
	{
		ResPtr resource(new Res());
		try {
			if (!resource->loadFromFile(filename))
				throw std::runtime_error("ResourceHolder::load - Failed to load " + filename);
		}
		catch (std::runtime_error& e) {
			std::cout << "\nEXCEPTION: " << e.what() << std::endl;
			return;
		}

		insertResource(id, std::move(resource));
	}
		// Load | Extra Param
	template <typename ID, typename Res>
	template <typename Param>
	void ResourceHolder<ID, Res>::load(ID id, const std::string& filename, Param param)
	{
		ResPtr resource(new Res());
		try {
			if (!resource->loadFromFile(filename))
				throw std::runtime_error("ResourceHolder::load - Failed to load " + filename);
		}
		catch (std::runtime_error& e) {
			std::cout << "\nEXCEPTION: " << e.what() << std::endl;
			return;
		}

		insertResource(id, std::move(resource));
	}
		// Get
	template <typename ID, typename Res>
	Res& ResourceHolder<ID, Res>::get(ID id)
	{
		auto found = mResourceMap.find(id);
		assert(found != mResourceMap.end());

		return *found->second;
	}
		// Const Get
	template <typename ID, typename Res>
	const Res& ResourceHolder<ID, Res>::get(ID id) const
	{
		auto found = mResourceMap.find(id);
		assert(found != mResourceMap.end());

		return *found->second;
	}
}