#ifndef PRO_SPRITE_HPP
#define PRO_SPRITE_HPP

#include <SFML/Graphics.hpp>
#include "pro_vector.hpp"

#define LEFT 1
#define RIGHT 2
#define UP 3
#define DOWN 4

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
    void setFrameX(int x);
    void setFrameY(int y);
    void setFrame(pro::vector<int> framenum);
    void setFrame(int x, int y);
    void setCurrentFrame(int x, int y);
    void setSpeed(float speed);
    void move(float x, float y);
    pro::vector<float> getPos();
    pro::vector<int> getFrames();
    float getPosX();
    float getPosY();
    int getFrameX();
    int getFrameY();
	void draw(sf::RenderWindow &window); // Draw it to the RenderWindow
    sf::Texture &getTexture(); // Get the sf::Texture of the sprite
    sf::Sprite &getSprite(); // Get the sf::Sprite of the sprite
    void animate();
private:
	sf::Sprite m_sprite; // The sf::Sprite
	sf::Texture m_texture; // The sf::Texture
    sf::Clock m_clock;
    sf::Time m_dt;
    int m_dir;
    float m_time;
    float m_speed;
    pro::vector<float> m_pos;
    pro::vector<int> m_frames;
    pro::vector<unsigned int> m_currentframe;
};

}

#endif