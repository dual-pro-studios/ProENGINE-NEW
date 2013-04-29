#ifndef PRO_RENDERER_HPP
#define PRO_RENDERER_HPP
#include <string>
#include <SFML/Graphics.hpp>
#include "pro_camera.hpp"
#define RAWFP 0 // Frametime
#define PERSC 1 // FPS

namespace pro {

// Renderer class
class renderer
{
public:
	renderer(void); // Default initializer
	enum windowState {OPEN, CLOSED}; // The state of the window
	enum fpsType {RAW, PERSECOND}; // The type of time returned by the getFPS(fpsType type) function
	windowState state; // The window state
	void start(bool fullscreen = false, float width = 640, float height = 480, const std::string title = "ProENGINE 1.5.1A"); // Start the renderer with the given params
	void begin_scene(); // Begin drawing the things
	void end_scene(); // Stop drawing the things and display them
	void render_scene(); // Do begin_scene() and end_scene, not recommended.
	void close_window(); // Close the window
	void setWindowState(windowState state); // Change the window state
	float getFPS(fpsType type); // Get the frametime or FPS
	sf::RenderWindow &getRW(); // Get the RenderWindow of the renderer
	sf::RenderWindow window; // The RenderWindow of the renderer
	pro::camera& getWindowCam(); // Get the camera of the window
	~renderer(void); // Destructor
private:
	pro::camera windowCam; // The window's camera and viewport
	sf::Clock fpsClock; // The sf::Clock used for gathering frametime and FPS
	sf::Time fpsTime; // The sf::Time for converting the sf::Clock time into a float
	float fps[2]; // The two times, frametime and FPS
};

}
#endif