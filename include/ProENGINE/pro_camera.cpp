#include "pro_camera.hpp"

using namespace pro;

camera::camera(void) : posx(0), posy(0), width(640), height(480) // Default Position and size
{
}


camera::~camera(void)
{
}

// Sets the size of the camera viewport
void camera::setSize(float width, float height) {
	this->width = width; // Set the width
	this->height = height; // Set the height
	cameraView.reset(sf::FloatRect(posx, posy, this->width, this->height)); // Resize the viewport
}

// Sets the position of the camera
void camera::setPosition(float x, float y) {
	this->posx = x;
	this->posy = y;
	cameraView.reset(sf::FloatRect(posx, posy, width, height));
}

// Gets the viewport
sf::View &camera::getCameraView() {
	return cameraView;
}

// Move the camera
void camera::move(float offsetx, float offsety) {
	cameraView.move(offsetx, offsety);
}

// Get the X position of the camera
float camera::getX() {
    return this->posx; // Return X
}

// Get the Y position of the camera
float camera::getY() {
    return this->posy; // Return Y
}