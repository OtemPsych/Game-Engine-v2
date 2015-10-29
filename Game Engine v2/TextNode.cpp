#include "TextNode.h"

#include <SFML/Graphics/RenderTarget.hpp>

namespace gE {
	// Constructor(s)
		// Constructor 1
	TextNode::TextNode(const std::string& str, const sf::Font& font,
					   unsigned charSize)
		: mText(str, font, charSize)
	{
		centerOrigin();
	}

	// Private Method(s)
		// Center Origin
	void TextNode::centerOrigin()
	{
		auto bounds = mText.getLocalBounds();
		mText.setOrigin(bounds.width / 2.f, bounds.height);
	}
		// Draw Current
	void TextNode::drawCurrent(sf::RenderTarget& target,
							   sf::RenderStates states) const
	{
		target.draw(mText, states);
	}

	// Public Method(s)
		// Fade In
	void TextNode::fadeIn(float rate, float limit)
	{
		auto color = mText.getColor();
		mText.setColor(sf::Color(color.r, color.g, color.b,
								 color.a + rate > limit ? limit : color.a + rate));
	}
		// Fade Out
	void TextNode::fadeOut(float rate, float limit)
	{
		auto color = mText.getColor();
		mText.setColor(sf::Color(color.r, color.g, color.b,
								 color.a - rate < limit ? limit : color.a - rate));
	}
		// Get Bounds
	sf::FloatRect TextNode::getBounds()
	{
		auto worldPos = getWorldPosition();
		auto textBounds = mText.getGlobalBounds();
		if (mText.getOrigin() != sf::Vector2f(0.f, 0.f)) {
			worldPos.x -= textBounds.width / 2.f;
			worldPos.y -= textBounds.height / 2.f;
		}
		return sf::FloatRect(worldPos.x,
							 worldPos.y,
							 textBounds.width,
							 textBounds.height);
	}
}