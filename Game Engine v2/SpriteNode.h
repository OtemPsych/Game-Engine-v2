#ifndef SpriteNode_H_
#define SpriteNode_H_

#include "SceneNode.h"

#include <SFML/Graphics/Sprite.hpp>

namespace gE
{
	class SpriteNode : public SceneNode
	{
	protected:
		// Protected Member(s)
		sf::Sprite	  mSprite;

	private:
		// Private Method(s)
		virtual void drawCurrent(sf::RenderTarget& target,
								 sf::RenderStates states) const;
	public:
		// Constructor(s)
		explicit SpriteNode(const sf::Texture& texture);
				 SpriteNode(const sf::Texture& texture,
							const sf::IntRect& rect);
		// Public Method(s)
		virtual void centerOrigin();
		virtual sf::FloatRect getBounds();

		inline const sf::Texture& getTexture() const { return *mSprite.getTexture(); }
	};
}
#endif