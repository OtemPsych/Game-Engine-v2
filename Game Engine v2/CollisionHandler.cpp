#include "CollisionHandler.h"

#include <SFML/Graphics/Texture.hpp>

namespace gE {
	// Private Method(s)
		// Check Bounding Box Collision
	bool CollisionHandler::checkBoundingBoxCollision(SpriteNode& t, SpriteNode& k)
	{
		if (t.getBounds().intersects(k.getBounds()))
			return true;
		else
			return false;
	}
		// Check Pixel Collision
	bool CollisionHandler::checkPixelCollision(SpriteNode& t, SpriteNode& k)
	{
		/*sf::Image tImage = t.getTexture().copyToImage();
		sf::Image kImage = k.getTexture().copyToImage();

		sf::FloatRect tBounds = t.getBounds();
		sf::FloatRect kBounds = k.getBounds();
		sf::FloatRect pixelRect(tBounds.left,
								tBounds.top,
								tBounds.width,
								tBounds.height);

		for (float i = pixelRect.left; i < pixelRect.width; i++) {
			for (float j = pixelRect.top; j < pixelRect.height; j++)
			{
				sf::Color tColor = tImage.getPixel(tBounds.width - i, tBounds.height - j);
				sf::Color kColor = kImage.getPixel(kBounds.width - i, kBounds.height - j);

				if (tColor.a > 0 && kColor.a > 0)
					return true;
			}
		}
	*/
		return false;
	}

	// Public Method(s)
		// Check Collision
	bool CollisionHandler::checkCollision(SpriteNode& t, SpriteNode& k,
										  bool pixelCollision)
	{
		if (checkBoundingBoxCollision(t, k)) 
		{
			if (pixelCollision) 
			{
				if (checkPixelCollision(t, k))
					return true;
				else
					return false;
			}
			else
				return true;
		}
		else
			return false;
	}
}