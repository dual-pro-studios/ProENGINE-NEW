#pragma once

#include <SFML/Graphics.hpp>

namespace pro {

class sprite
{
public:
	sprite(void);
	~sprite(void);
	void loadTexture(const char* filename);
	void draw(sf::RenderWindow &window);
private:
	sf::Sprite m_sprite;
	sf::Texture m_texture;
};

}