#ifndef TextNode_H_
#define TextNode_H_

#include "SceneNode.h"

#include <SFML/Graphics/Text.hpp>

namespace gE
{
	class TextNode : public SceneNode
	{
	private:
		// Private Member(s)
		sf::Text mText;

	private:
		// Private Method(s)
		virtual void drawCurrent(sf::RenderTarget& target,
								 sf::RenderStates states) const;
	public:
		// Constructor(s)
		TextNode(const std::string& str, const sf::Font& font,
				 unsigned charSize = 30);
		// Public Method(s)
		void fadeIn(float rate, float limit = 255.f);
		void fadeOut(float rate, float limit = 0.f);

		void centerOrigin();

		virtual sf::FloatRect getBounds();
	};
}
#endif