#include "ProENGINE/ProENGINE.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
	pro::debug* main_debug = pro::debug::getInstance();
	pro::vector<float> velocity;
	pro::sprite player;
	sf::Clock gt;
	sf::Time gtt;
	float dtime;
    const float kspeed = 200.f;
	float speed = 200.f;
	main_debug->open("main_debug.txt");
	main_debug->log(version);
	main_debug->log("-----------------------------------");
	main_debug->log("Loading 'chrono_hd.png'");
	if(player.loadTexture("chrono_hd.png"))
		main_debug->log("\tLoad successful!");
	else
		main_debug->log("\tCould not load file!", pro::debug::DBG_TYPE::ERR);
    player.setFrame(pro::vector<int>(4, 4));
    player.setSpeed(0.20);
    player.getSprite().setTextureRect(sf::IntRect(player.getTexture().getSize().x / 4 * 0, 0, 48, 72));
	main_debug->log("Starting renderer with default parameters...");
	// render = new pro::renderer();
	render->start();
    render->window.setVerticalSyncEnabled(true);
	main_debug->log("Renderer started!");
	main_debug->log("\tEntering main loop...");
	while(render->window.isOpen()) {
		sf::Event evt;
		dtime = gtt.asSeconds();
		velocity.setX(0.f);
		velocity.setY(0.f);

		bool keypressed[5];
		keypressed[0] = sf::Keyboard::isKeyPressed(sf::Keyboard::Escape);
		keypressed[1] = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
		keypressed[2] = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
		keypressed[3] = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
		keypressed[4] = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);

		while(render->window.pollEvent(evt)) {
			if(keypressed[0] || evt.type == sf::Event::Closed) {
				render->window.close();
				main_debug->log("\t\tThe render window has been closed!");
			}
		}
        
        player.animate();

		if(keypressed[1] && keypressed[2]) {
			velocity.setX(0.f);
		}
		else if(keypressed[1]) {
			velocity.setX(-speed);
		}
		else if(keypressed[2]) {
			velocity.setX(speed);
		}

		if(keypressed[3] && keypressed[4]) {
			velocity.setY(0.f);
		}
		else if(keypressed[3]) {
			velocity.setY(-speed);
		}
		else if(keypressed[4]) {
			velocity.setY(speed);
		}
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
            speed = 500;
            player.setSpeed(0.10);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
            speed = 100;
            player.setSpeed(0.30);
        }
        else {
            speed = kspeed;
            player.setSpeed(0.20);
        }
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            std::cout << "\t" << render->getFPS(FPS) << std::endl;
        }

		render->begin_scene();
		
		player.move(velocity.getX() * dtime, velocity.getY() * dtime);
        
		render->window.draw(player.getSprite());

		render->end_scene();
        
		gtt = gt.restart();
	}
	main_debug->log("\tMain loop has exited!");

	delete render;
	render = 0;

	main_debug->log("Renderer stopped and deallocated!");
	main_debug->log("Closing debug file, goodbye :)");
	
	main_debug->close();

	return 0;
}