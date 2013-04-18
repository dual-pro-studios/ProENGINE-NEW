#pragma once
#include <string>
#include <SFML\Graphics.hpp>
#include "pro_camera.hpp"
#define RAWFP 0
#define PERSC 1

namespace pro {

class renderer
{
public:
	renderer(void);
	enum windowState {OPEN, CLOSED};
	enum fpsType {RAW, PERSECOND};
	windowState state;
	void start(bool fullscreen = false, float width = 640, float height = 480, const std::string title = "The NEW ProENGINE");
	void begin_scene();
	void end_scene();
	void render_scene();
	void close_window();
	void setWindowState(windowState state);
	float getFPS(fpsType type);
	sf::RenderWindow getRW();
	sf::RenderWindow window;
	pro::camera& getWindowCam();
	~renderer(void);
private:
	pro::camera windowCam;
	sf::RectangleShape shape;
	sf::Clock fpsClock;
	sf::Time fpsTime;
	float fps[2];
};

}