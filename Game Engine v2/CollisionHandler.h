#ifndef CollisionHandler_H_
#define CollisionHandler_H_

#include "SpriteNode.h"

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Image.hpp>

#include <vector>

namespace gE
{
	class CollisionHandler : private sf::NonCopyable
	{
	private:
		// Private Method(s)
		bool checkBoundingBoxCollision(SpriteNode& t, SpriteNode& k);
		bool checkPixelCollision(SpriteNode& t, SpriteNode& k);
	public:
		// Public Method(s)
		bool checkCollision(SpriteNode& t, SpriteNode& k,
							bool pixelCollision = false);
	};
}
#endif