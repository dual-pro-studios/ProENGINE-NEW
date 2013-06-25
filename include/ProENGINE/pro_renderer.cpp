#include "pro_renderer.hpp"

using namespace pro;
using namespace std;



// Default Initializer
renderer::renderer(void) {

}

// Destructor
renderer::~renderer(void) {

}

// Starts the renderer with the given params
// bool fullscreen(start in fullscreen mode or not) NOTE: if you start in fullscreen, the width and height params will be ignored.
// float width(start with the given width)
// float height(start with the given height)
// const string title(the title of the window)
void renderer::start(bool fullscreen, float width, float height, const string title) {
	pro::debug* renderer_debug = pro::debug::getInstance();
    // If fullscreen, start with the desktop resolution
	if(fullscreen) {
		window.create(sf::VideoMode::getDesktopMode(), title, sf::Style::Fullscreen);
		windowCam.setSize((float)sf::VideoMode::getDesktopMode().width, (float)sf::VideoMode::getDesktopMode().height);
		renderer_debug->log("Renderer is starting in fullscreen mode!");
	}
    // Otherwise start with the given width and height
	else {
		window.create(sf::VideoMode((int)width, (int)height), title);
		windowCam.setSize(width, height); // Set the camera size
		string temp = "Renderer is starting with the params: width = ";
		string temp2;
		stringstream tmp;
		tmp << (int)width;
		tmp >> temp2;
		temp += temp2 + ", height = ";
		tmp.clear();
		tmp << (int)height;
		tmp >> temp2;
		temp += temp2;
		renderer_debug->log(temp);
	}
    // Make the window viewport the camera's
	window.setView(windowCam.getCameraView());
}

// Begin drawing the things
void renderer::begin_scene() {
	window.setView(windowCam.getCameraView()); // Update the window's view
	window.clear(sf::Color::Color(0, 0, 0, 0)); // Clear the screen with black
}

// Stop drawing the things and display them
void renderer::end_scene() {
	window.display(); // Display whatever has been drawn
	fpsTime = fpsClock.restart(); // sf::Time for frametime or FPS
	fps[0] = fpsTime.asSeconds(); // The frametime
	fps[1] = 1.f / fpsTime.asSeconds(); // The FPS
}

// Do both, not recommended.
void renderer::render_scene() {
	begin_scene();
	end_scene();
}

// Close the window, need to revise
void renderer::close_window() {
	window.close(); // Close the RenderWindow
}

// Set the window's state
void renderer::setWindowState(windowState state) {
	this->state = state;
}

// Get the FPS or frametime
float renderer::getFPS(fpsType type) {
	float tempfps; // The returned time
	if(type == RAW) // If the parameter is frametime
		tempfps = fps[RAWFP]; // Set the returned time to frametime
	else if(type == PERSECOND) // Else if the parameter is FPS
		tempfps = fps[PERSC]; // Set the returned time to FPS
	return tempfps; // Return the requested time
}

// Return the renderer's RenderWindow
sf::RenderWindow &renderer::getRW() {
    return window;
}

// Get the camera used by the window
camera &renderer::getWindowCam() {
	return windowCam; // Return the camera of the window
}