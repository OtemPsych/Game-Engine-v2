#include "SpriteNode.h"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>

namespace gE {
	// Constructor(s)
		// Constructor 1
	SpriteNode::SpriteNode(const sf::Texture& texture)
		: mSprite(texture)
	{
	}
		// Constructor 2
	SpriteNode::SpriteNode(const sf::Texture& texture,
						   const sf::IntRect& rect)
		: mSprite(texture, rect)
	{
	}

	// Private Method(s)
		// Draw Current
	void SpriteNode::drawCurrent(sf::RenderTarget& target,
		sf::RenderStates states) const
	{
		target.draw(mSprite, states);
	}

	// Public Method(s)
		// Center Origin
	void SpriteNode::centerOrigin()
	{
		auto bounds = mSprite.getLocalBounds();
		mSprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
	}
		// Get Bounds
	sf::FloatRect SpriteNode::getBounds()
	{
		auto worldPos = getWorldPosition();
		auto spriteBounds = mSprite.getGlobalBounds();
		if (mSprite.getOrigin() != sf::Vector2f(0.f, 0.f)) {
			worldPos.x -= spriteBounds.width / 2.f;
			worldPos.y -= spriteBounds.height / 2.f;
		}
		return sf::FloatRect(worldPos.x,
							 worldPos.y,
							 spriteBounds.width,
							 spriteBounds.height);
	}
}