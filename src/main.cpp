//#define WINDOWS
#define MAC
#include "ProENGINE.hpp"
#if defined(WINDOWS)
#include <Windows.h>
#endif
#include <iostream>

int main(int argc, char* argv[]) {
	sf::RectangleShape test;
	sf::CircleShape test2(100.f, 100);
	pro::sprite ts;
	ts.loadTexture("chrono.png");
	float atime = 0;
	float rtime = 0.001f;
	float btime = 0;
	float speed = 0.8f;
	bool rtest = true;
	test.setPosition(0, 0);
	test.setFillColor(sf::Color::Green);
	test.setSize(sf::Vector2f(32, 32));
	test2.setPosition(110, 110);
	test2.setFillColor(sf::Color::Red);
	pro::renderer* render = new pro::renderer;
	pro::debug* debug = pro::debug::getInstance();
	debug->open("main.dbg");
	debug->log("Starting renderer with default params...");
	render->start();
	render->window.setVerticalSyncEnabled(false);
	debug->log("Renderer started!");
	debug->log("Entering main loop...");
	while(render->window.isOpen()) {
		atime += render->getFPS(ProRAW);
		btime += render->getFPS(ProRAW);
		sf::Event evt;
		while(render->window.pollEvent(evt)) {
			if(evt.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				render->close_window();
				debug->log("The window has been closed!");
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				std::cout << render->getFPS(ProPERSECOND) << std::endl;
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && atime >= rtime) {
			atime = 0;
		}
		else {
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && atime >= rtime) {
				atime = 0;
				render->getWindowCam().move(speed, 0);
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && atime >= rtime) {
				atime = 0;
				render->getWindowCam().move(-speed, 0);
			}
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && atime >= rtime) {
			atime = 0;
		}
		else {
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && atime >= rtime) {
				atime = 0;
				render->getWindowCam().move(0, -speed);
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && atime >= rtime) {
				atime = 0;
				render->getWindowCam().move(0, speed);
			}
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && btime >= 0.15) {
			btime = 0;
			rtest = !rtest;
		}
		//render->getWindowCam().move(0, 1);
		render->begin_scene();
		if(rtest) {
			render->window.draw(test);
			render->window.draw(test2);
			ts.draw(render->window);
		}
		render->end_scene();
	}
	debug->log("Main loop has exited!");

	debug->close();

	return 0;
}