#include "ButtonNode.h"

namespace gE {
	namespace GUI {
		// Public Method(s)
			// Handle Event
		bool ButtonNode::handleEvent(const sf::Event& event, sf::RenderWindow& window)
		{
			if (event.key.code == sf::Mouse::Left)
			{
				sf::Vector2i mousePos = sf::Mouse::getPosition(window);
				sf::IntRect mouseRect(mousePos.x, mousePos.y, mousePos.x, mousePos.y);

				auto contBounds = mContainer->getBounds();
				if (mousePos.x > contBounds.left && mousePos.x < contBounds.left + contBounds.width
					&& mousePos.y > contBounds.top && mousePos.y < contBounds.top + contBounds.height)
					return true;
				else
					return false;
			}
			return false;
		}
			// Set Container Properties
		void ButtonNode::setContainerProperties(const sf::Texture& texture,
												const sf::IntRect& rect)
		{
			std::unique_ptr<SpriteNode> container(rect == sf::IntRect(0, 0, 0, 0)
												  ? new SpriteNode(texture)
												  : new SpriteNode(texture, rect));
			mContainer = container.get();
			attachChild(std::move(container));

			centerOrigin();
		}
			// Set Text Properties
		void ButtonNode::setTextProperties(const std::string& str, const sf::Font& font,
										   unsigned charSize)
		{
			std::unique_ptr<TextNode> text(new TextNode(str, font, charSize));
			mText = text.get();
			attachChild(std::move(text));

			centerOrigin();
		}
			// Center Origin
		void ButtonNode::centerOrigin()
		{
			mContainer->centerOrigin();
		}
	}
}