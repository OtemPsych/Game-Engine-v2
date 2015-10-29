#ifndef ResourceHolder_H_
#define ResourceHolder_H_

#include <SFML/System/NonCopyable.hpp>

#include <memory>
#include <map>

namespace gE
{
	template <typename ID, typename Res>
	class ResourceHolder : private sf::NonCopyable
	{
	private:
		// Private Typedef(s)
		using ResPtr = std::unique_ptr<Res>;
	private:
		// Private Member(s)
		std::map<ID, ResPtr> mResourceMap;

	private:
		// Private Method(s)
		void insertResource(ID id, ResPtr resource);
	public:
		// Public Method(s)
		void load(ID id, const std::string& filename);
		template <typename Param>
		void load(ID id, const std::string& filename, Param param);

		Res& get(ID id);
		const Res& get(ID id) const;
	};
}
#include "ResourceHolder.inl"
#endif