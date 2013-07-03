#ifndef PRO_SPRITE_HPP
#define PRO_SPRITE_HPP

#include <SFML/Graphics.hpp>
#include "pro_vector.hpp"

namespace pro {

class sprite // Alternative to sf::Sprite
{
public:
	sprite(void); // Default constructor
	~sprite(void); // Destructor
	bool loadTexture(const char* filename); // Load the texture for the sprite, and set it
    void setPosX(float x);
    void setPosY(float y);
    void setPos(pro::vector<float> pos);
    void setPos(float x, float y);
    void move(float x, float y);
    pro::vector<float> getPos();
    float getPosX();
    float getPosY();
	void draw(sf::RenderWindow &window); // Draw it to the RenderWindow
    sf::Texture &getTexture(); // Get the sf::Texture of the sprite
    sf::Sprite &getSprite(); // Get the sf::Sprite of the sprite
private:
	sf::Sprite m_sprite; // The sf::Sprite
	sf::Texture m_texture; // The sf::Texture
    pro::vector<float> m_pos;
};

}

#endif