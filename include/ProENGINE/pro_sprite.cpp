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

void sprite::setPosX(float x) {
    m_pos.setX(x);
    m_sprite.setPosition(m_pos.getX(), m_pos.getY());
}

void sprite::setPosY(float y) {
    m_pos.setY(y);
    m_sprite.setPosition(m_pos.getX(), m_pos.getY());
}

void sprite::setPos(pro::vector<float> pos) {
    m_pos = pos;
    m_sprite.setPosition(m_pos.getX(), m_pos.getY());
}

void sprite::setPos(float x, float y) {
    m_pos.setX(x);
    m_pos.setY(y);
    m_sprite.setPosition(m_pos.getX(), m_pos.getY());
}

vector<float> sprite::getPos() {
    return m_pos;
}

float sprite::getPosX() {
    return m_pos.getX();
}

float sprite::getPosY() {
    return m_pos.getY();
}

void sprite::move(float x, float y) {
    m_pos.setX(m_pos.getX() + x);
    m_pos.setY(m_pos.getY() + y);
    m_sprite.setPosition(m_pos.getX(), m_pos.getY());
}