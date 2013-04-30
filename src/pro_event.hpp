#ifndef PRO_EVENT_HPP
#define PRO_EVENT_HPP

#include <SFML/Graphics.hpp>

#define EVENT_EXIT 0

namespace pro {
    sf::Event evt;
    int getEvent(sf::RenderWindow &window);
}

#endif