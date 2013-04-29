#pragma once

#include <SFML/Graphics.hpp>

namespace pro {

class sprite // Alternative to sf::Sprite
{
public:
	sprite(void); // Default constructor
	~sprite(void); // Destructor
	void loadTexture(const char* filename); // Load the texture for the sprite, and set it
	void draw(sf::RenderWindow &window); // Draw it to the RenderWindow
    sf::Texture &getTexture();
    sf::Sprite &getSprite();
private:
	sf::Sprite m_sprite; // The sprite
	sf::Texture m_texture; // The texture
};

}