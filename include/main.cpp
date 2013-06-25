#include "ProENGINE/ProENGINE.hpp"
#include <iostream>

/*int main(int argc, char* argv[]) {
    pro::debug* debug = pro::debug::getInstance();
	debug->open("main.dbg");
	sf::RectangleShape test;
	sf::CircleShape test2(100.f, 100);
	pro::sprite ts;
    debug->log(version.c_str());
    debug->log("Loading chrono.png...");
	if(!ts.loadTexture("chrono.png"))
		debug->log("COULD NOT LOAD chrono.png!!", pro::debug::DBG_TYPE::ERR);
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
	debug->log("Starting renderer with default params...");
    render = new pro::renderer;
	render->start();
	render->window.setVerticalSyncEnabled(false);
	debug->log("\tRenderer started!");
	debug->log("\t\tEntering main loop...");
	while(render->window.isOpen()) {
		atime += render->getFPS(FRAMETIME);
		btime += render->getFPS(FRAMETIME);
		sf::Event evt;
		while(render->window.pollEvent(evt)) {
			if(evt.type == sf::Event::Closed || pro::getInput() == ESC) {
				render->close_window();
				debug->log("\t\tThe window has been closed!");
			}
		}
        if(pro::getInput() == q) {
            std::cout << render->getFPS(FPS) << std::endl;
        }
		if(pro::getInput() == LEFTRIGHT && atime >= rtime) {
			atime = 0;
		}
		else {
			if(pro::getInput() == RIGHT && atime >= rtime) {
				atime = 0;
				render->getWindowCam().move(speed, 0);
			}
			if(pro::getInput() == LEFT && atime >= rtime) {
				atime = 0;
				render->getWindowCam().move(-speed, 0);
			}
		}
		if(pro::getInput() == UPDOWN && atime >= rtime) {
			atime = 0;
		}
		else {
            //std::stringstream ss;
            //ss << pro::getInput();
            //std::string temp = ss.str();
            //debug->log(temp.c_str());
			if(pro::getInput() == UP && atime >= rtime) {
				atime = 0;
				render->getWindowCam().move(0, -speed);
			}
			if(pro::getInput() == DOWN && atime >= rtime) {
				atime = 0;
				render->getWindowCam().move(0, speed);
			}
		}
		if(pro::getInput() == SPACE && btime >= 0.15) {
			btime = 0;
			rtest = !rtest;
		}
		//render->getWindowCam().move(0, 1);
		render->begin_scene();
		if(rtest) {
			render->getRW().draw(test);
			render->getRW().draw(test2);
			ts.draw(render->window);
		}
		render->end_scene();
	}
	debug->log("\t\tMain loop has exited!");
    debug->log("\tRenderer stopped!");
    debug->log("Closing debug file...");
    
	debug->close();

	return 0;
}*/

int main(int argc, char* argv[]) {
	pro::debug* main_debug = pro::debug::getInstance();
	main_debug->open("main_debug.txt");
	main_debug->log(version);
	main_debug->log("-----------------------------------");
	main_debug->log("Starting renderer with default parameters...");
	render = new pro::renderer;
	render->start();
	main_debug->log("\tRenderer started!");
	main_debug->log("\t\tEntering main loop...");
	while(render->window.isOpen()) {
		sf::Event evt;
		while(render->window.pollEvent(evt)) {
			bool keypressed[5];
			keypressed[0] = evt.KeyPressed && evt.key.code == sf::Keyboard::Escape;
			if(keypressed[0] || evt.type == sf::Event::Closed) {
				render->window.close();
				main_debug->log("\t\tThe render window has been closed!");
				
			}
		}
		render->window.clear();
		render->window.display();
	}
	main_debug->log("\t\tMain loop has exited!");

	delete render;
	render = 0;

	main_debug->log("\tRenderer stopped and deallocated!");
	main_debug->log("Closing debug file, good bye :)");
	
	main_debug->close();

	std::cin.get();

	return 0;
}