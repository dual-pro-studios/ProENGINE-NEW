#include "pro_camera.hpp"

using namespace pro;

camera::camera(void) : posx(0), posy(0), width(640), height(480)
{
}


camera::~camera(void)
{
}

void camera::setSize(float width, float height) {
	this->width = width;
	this->height = height;
	cameraView.reset(sf::FloatRect(posx, posy, this->width, this->height));
}

void camera::setPosition(float x, float y) {
	this->posx = x;
	this->posy = y;
	cameraView.reset(sf::FloatRect(posx, posy, width, height));
}

sf::View camera::getCameraView() {
	return cameraView;
}

void camera::move(float offsetx, float offsety) {
	cameraView.move(offsetx, offsety);
}