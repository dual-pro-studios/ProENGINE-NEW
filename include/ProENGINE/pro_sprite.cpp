#include "pro_sprite.hpp"

using namespace pro;

// Default Constructor
sprite::sprite(void)
{
}

// Destructor
sprite::~sprite(void)
{
}

// Load the texture for the sprite and set it
// const char* filename(the file to load the texture from)
bool sprite::loadTexture(const char* filename) {
	bool success;
	if(m_texture.loadFromFile(filename)) // Load the texture
		success = true;
	else
		success = false;
	if(success)
		m_sprite.setTexture(m_texture); // Set the texture
	return success;
}

// Draw the sprite to a RenderWindow
void sprite::draw(sf::RenderWindow &window) {
	window.draw(m_sprite);
}

// Get the source texture
sf::Texture &sprite::getTexture() {
    return m_texture; // Return the source texture
}

// Get the source sprite
sf::Sprite &sprite::getSprite() {
    return m_sprite; // Return the source sprite
}