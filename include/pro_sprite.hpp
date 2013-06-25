#ifndef PRO_SPRITE_HPP
#define PRO_SPRITE_HPP

#include <SFML/Graphics.hpp>

namespace pro {

class sprite // Alternative to sf::Sprite
{
public:
	sprite(void); // Default constructor
	~sprite(void); // Destructor
	bool loadTexture(const char* filename); // Load the texture for the sprite, and set it
	void draw(sf::RenderWindow &window); // Draw it to the RenderWindow
    sf::Texture &getTexture(); // Get the sf::Texture of the sprite
    sf::Sprite &getSprite(); // Get the sf::Sprite of the sprite
private:
	sf::Sprite m_sprite; // The sf::Sprite
	sf::Texture m_texture; // The sf::Texture
};

}

#endif