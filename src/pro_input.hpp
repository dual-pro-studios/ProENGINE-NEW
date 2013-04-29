#ifndef PRO_INPUT_HPP
#define PRO_INPUT_HPP

#include <SFML/Graphics.hpp>
#define LEFT 1
#define RIGHT 2
#define UP 3
#define DOWN 4
#define LEFTRIGHT 5
#define UPDOWN 6
#define LEFTUP 7
#define LEFTDOWN 8
#define RIGHTUP 9
#define RIGHTDOWN 10
#define ESC 11
#define q 12
#define SPACE 13

namespace pro {

int getInput();

}

#endif