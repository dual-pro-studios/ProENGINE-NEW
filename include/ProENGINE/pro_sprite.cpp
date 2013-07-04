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

void sprite::setFrameX(int x) {
    m_frames.setX(x);
}

void sprite::setFrameY(int y) {
    m_frames.setY(y);
}

void sprite::setFrame(pro::vector<int> framenum) {
    m_frames = framenum;
}

void sprite::setFrame(int x, int y) {
    m_frames.setX(x);
    m_frames.setY(y);
}

vector<int> sprite::getFrames() {
    return m_frames;
}

int sprite::getFrameX() {
    return m_frames.getX();
}

int sprite::getFrameY() {
    return m_frames.getY();
}

void sprite::setSpeed(float speed) {
    m_speed = speed;
}

void sprite::animate() {
    m_dt = m_clock.restart();
    m_time += m_dt.asSeconds();
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        m_dir = LEFT;
        if(m_time >= m_speed) {
            m_currentframe.setY(1);
            m_currentframe.setX(0);
            m_sprite.setTextureRect(sf::IntRect(m_texture.getSize().x / m_frames.getX() * m_currentframe.getX(), m_texture.getSize().y / m_frames.getY() * m_currentframe.getY(), m_texture.getSize().x / m_frames.getX(), m_texture.getSize().y / m_frames.getY()));
            if(m_time >= m_speed * 2) {
                m_currentframe.setX(1);
                m_sprite.setTextureRect(sf::IntRect(m_texture.getSize().x / m_frames.getX() * m_currentframe.getX(), m_texture.getSize().y / m_frames.getY() * m_currentframe.getY(), m_texture.getSize().x / m_frames.getX(), m_texture.getSize().y / m_frames.getY()));
                if(m_time >= m_speed * 3) {
                    m_currentframe.setX(2);
                    m_sprite.setTextureRect(sf::IntRect(m_texture.getSize().x / m_frames.getX() * m_currentframe.getX(), m_texture.getSize().y / m_frames.getY() * m_currentframe.getY(), m_texture.getSize().x / m_frames.getX(), m_texture.getSize().y / m_frames.getY()));
                    if(m_time >= m_speed * 4) {
                        m_currentframe.setX(3);
                        m_sprite.setTextureRect(sf::IntRect(m_texture.getSize().x / m_frames.getX() * m_currentframe.getX(), m_texture.getSize().y / m_frames.getY() * m_currentframe.getY(), m_texture.getSize().x / m_frames.getX(), m_texture.getSize().y / m_frames.getY()));
                        m_time = 0;
                    }
                }
            }
        }
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        if(m_time >= m_speed) {
            m_currentframe.setY(2);
            m_currentframe.setX(0);
            m_sprite.setTextureRect(sf::IntRect(m_texture.getSize().x / m_frames.getX() * m_currentframe.getX(), m_texture.getSize().y / m_frames.getY() * m_currentframe.getY(), m_texture.getSize().x / m_frames.getX(), m_texture.getSize().y / m_frames.getY()));
            if(m_time >= m_speed * 2) {
                m_currentframe.setX(1);
                m_sprite.setTextureRect(sf::IntRect(m_texture.getSize().x / m_frames.getX() * m_currentframe.getX(), m_texture.getSize().y / m_frames.getY() * m_currentframe.getY(), m_texture.getSize().x / m_frames.getX(), m_texture.getSize().y / m_frames.getY()));
                if(m_time >= m_speed * 3) {
                    m_currentframe.setX(2);
                    m_sprite.setTextureRect(sf::IntRect(m_texture.getSize().x / m_frames.getX() * m_currentframe.getX(), m_texture.getSize().y / m_frames.getY() * m_currentframe.getY(), m_texture.getSize().x / m_frames.getX(), m_texture.getSize().y / m_frames.getY()));
                    if(m_time >= m_speed * 4) {
                        m_currentframe.setX(3);
                        m_sprite.setTextureRect(sf::IntRect(m_texture.getSize().x / m_frames.getX() * m_currentframe.getX(), m_texture.getSize().y / m_frames.getY() * m_currentframe.getY(), m_texture.getSize().x / m_frames.getX(), m_texture.getSize().y / m_frames.getY()));
                        m_time = 0;
                    }
                }
            }
        }
        m_dir = RIGHT;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        if(m_time >= m_speed) {
            m_currentframe.setY(3);
            m_currentframe.setX(0);
            m_sprite.setTextureRect(sf::IntRect(m_texture.getSize().x / m_frames.getX() * m_currentframe.getX(), m_texture.getSize().y / m_frames.getY() * m_currentframe.getY(), m_texture.getSize().x / m_frames.getX(), m_texture.getSize().y / m_frames.getY()));
            if(m_time >= m_speed * 2) {
                m_currentframe.setX(1);
                m_sprite.setTextureRect(sf::IntRect(m_texture.getSize().x / m_frames.getX() * m_currentframe.getX(), m_texture.getSize().y / m_frames.getY() * m_currentframe.getY(), m_texture.getSize().x / m_frames.getX(), m_texture.getSize().y / m_frames.getY()));
                if(m_time >= m_speed * 3) {
                    m_currentframe.setX(2);
                    m_sprite.setTextureRect(sf::IntRect(m_texture.getSize().x / m_frames.getX() * m_currentframe.getX(), m_texture.getSize().y / m_frames.getY() * m_currentframe.getY(), m_texture.getSize().x / m_frames.getX(), m_texture.getSize().y / m_frames.getY()));
                    if(m_time >= m_speed * 4) {
                        m_currentframe.setX(3);
                        m_sprite.setTextureRect(sf::IntRect(m_texture.getSize().x / m_frames.getX() * m_currentframe.getX(), m_texture.getSize().y / m_frames.getY() * m_currentframe.getY(), m_texture.getSize().x / m_frames.getX(), m_texture.getSize().y / m_frames.getY()));
                        m_time = 0;
                    }
                }
            }
        }
        m_dir = UP;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        if(m_time >= m_speed) {
            m_currentframe.setY(0);
            m_currentframe.setX(0);
            m_sprite.setTextureRect(sf::IntRect(m_texture.getSize().x / m_frames.getX() * m_currentframe.getX(), m_texture.getSize().y / m_frames.getY() * m_currentframe.getY(), m_texture.getSize().x / m_frames.getX(), m_texture.getSize().y / m_frames.getY()));
            if(m_time >= m_speed * 2) {
                m_currentframe.setX(1);
                m_sprite.setTextureRect(sf::IntRect(m_texture.getSize().x / m_frames.getX() * m_currentframe.getX(), m_texture.getSize().y / m_frames.getY() * m_currentframe.getY(), m_texture.getSize().x / m_frames.getX(), m_texture.getSize().y / m_frames.getY()));
                if(m_time >= m_speed * 3) {
                    m_currentframe.setX(2);
                    m_sprite.setTextureRect(sf::IntRect(m_texture.getSize().x / m_frames.getX() * m_currentframe.getX(), m_texture.getSize().y / m_frames.getY() * m_currentframe.getY(), m_texture.getSize().x / m_frames.getX(), m_texture.getSize().y / m_frames.getY()));
                    if(m_time >= m_speed * 4) {
                        m_currentframe.setX(3);
                        m_sprite.setTextureRect(sf::IntRect(m_texture.getSize().x / m_frames.getX() * m_currentframe.getX(), m_texture.getSize().y / m_frames.getY() * m_currentframe.getY(), m_texture.getSize().x / m_frames.getX(), m_texture.getSize().y / m_frames.getY()));
                        m_time = 0;
                    }
                }
            }
        }
        m_dir = DOWN;
    }
    if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        if(m_dir == DOWN) {
            m_sprite.setTextureRect(sf::IntRect(0, m_texture.getSize().y / m_frames.getY() * 0, m_texture.getSize().x / m_frames.getX(), m_texture.getSize().y / m_frames.getY()));
        }
        else if(m_dir == LEFT) {
            m_sprite.setTextureRect(sf::IntRect(0, m_texture.getSize().y / m_frames.getY() * 1, m_texture.getSize().x / m_frames.getX(), m_texture.getSize().y / m_frames.getY()));
        }
        else if(m_dir == RIGHT) {
            m_sprite.setTextureRect(sf::IntRect(0, m_texture.getSize().y / m_frames.getY() * 2, m_texture.getSize().x / m_frames.getX(), m_texture.getSize().y / m_frames.getY()));
        }
        else if(m_dir == UP) {
            m_sprite.setTextureRect(sf::IntRect(0, m_texture.getSize().y / m_frames.getY() * 3, m_texture.getSize().x / m_frames.getX(), m_texture.getSize().y / m_frames.getY()));
        }
    }
    //m_sprite.setTextureRect(sf::IntRect(m_texture.getSize().x / 4 * 0, 0, 48, 72));
}