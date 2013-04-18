#include "pro_sprite.hpp"

using namespace pro;

sprite::sprite(void)
{
}


sprite::~sprite(void)
{
}

void sprite::loadTexture(const char* filename) {
	m_texture.loadFromFile(filename);
	m_sprite.setTexture(m_texture);
}

void sprite::draw(sf::RenderWindow &window) {
	window.draw(m_sprite);
}