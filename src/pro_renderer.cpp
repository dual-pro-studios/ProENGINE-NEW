#include "pro_renderer.hpp"

using namespace pro;
using namespace std;

renderer::renderer(void) {

}


renderer::~renderer(void) {

}

void renderer::start(bool fullscreen, float width, float height, const string title) {
	if(fullscreen) {
		window.create(sf::VideoMode::getDesktopMode(), title, sf::Style::Fullscreen);
		windowCam.setSize((float)sf::VideoMode::getDesktopMode().width, (float)sf::VideoMode::getDesktopMode().height);
	}
	else {
		window.create(sf::VideoMode((int)width, (int)height), title);
		windowCam.setSize(width, height);
	}
	window.setView(windowCam.getCameraView());
}

void renderer::begin_scene() {
	window.setView(windowCam.getCameraView());
	window.clear(sf::Color::Color(75, 75, 75, 0));
}

void renderer::end_scene() {
	window.display();
	fpsTime = fpsClock.restart();
	fps[0] = fpsTime.asSeconds();
	fps[1] = 1.f / fpsTime.asSeconds();
}

void renderer::render_scene() {
	begin_scene();
	end_scene();
}

void renderer::close_window() {
	window.close();
}

void renderer::setWindowState(windowState state) {
	this->state = state;
}

float renderer::getFPS(fpsType type) {
	float tempfps;
	if(type == RAW)
		tempfps = fps[RAWFP];
	else if(type == PERSECOND)
		tempfps = fps[PERSC];
	return tempfps;
}

camera& renderer::getWindowCam() {
	return windowCam;
}