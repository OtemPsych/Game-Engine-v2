#ifndef Button_H_
#define Button_H_

#include "SpriteNode.h"
#include "TextNode.h"

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace gE {
	namespace GUI 
	{
		class ButtonNode : public SceneNode
		{
		private:
			// Private Member(s)
			SpriteNode* mContainer;
			TextNode*	mText;

		public:
			// Public Method(s)
			bool handleEvent(const sf::Event& event, sf::RenderWindow& window);

			void setContainerProperties(const sf::Texture& texture,
										const sf::IntRect& rect = sf::IntRect(0, 0, 0, 0));
			void setTextProperties(const std::string& str, const sf::Font& font,
								   unsigned charSize = 30);

			virtual void centerOrigin();
		};
	}
}
#endif