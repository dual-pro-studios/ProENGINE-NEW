#pragma once

#include <SFML/Graphics.hpp>

namespace pro {

class camera
{
public:
	camera(void);
	~camera(void);
	void move(float offsetx, float offsety);
	void setSize(float width, float height);
	void setPosition(float x, float y);
	sf::View getCameraView();
	sf::View cameraView;
private:
	float posx;
	float posy;
	float width;
	float height;
};

}

