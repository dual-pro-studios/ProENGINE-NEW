#include "pro_input.hpp"

namespace pro {
    int getInput() {
        int result;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            result = LEFTRIGHT;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            result = UPDOWN;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            result = LEFTUP;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            result = LEFTDOWN;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            result = RIGHTUP;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            result = RIGHTDOWN;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            result = LEFT;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            result = RIGHT;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            result = UP;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            result = DOWN;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            result = ESC;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
            result = q;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            result = SPACE;
        }
        
        return result;
    }
}