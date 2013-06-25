#ifndef PRO_CAMERA_HPP
#define PRO_CAMERA_HPP

#include <SFML/Graphics.hpp>

namespace pro {

class camera // Camera class
{
public:
	camera(void); // Default Initializer
	~camera(void); // Destructor
	void move(float offsetx, float offsety);
	void setSize(float width, float height);
	void setPosition(float x, float y);
    float getX(); // Returns the camera's X position
    float getY(); // Returns the camera's Y position
	sf::View &getCameraView(); // Returns the cameraView
	sf::View cameraView; // The cameraView
private:
	float posx; // X
	float posy; // Y
	float width; // Width of the view
	float height; // Height of the view
};

}

#endif

