#ifndef PRO_EVENT_HPP
#define PRO_EVENT_HPP

#include "pro_renderer.hpp"

#define EVENT_EXIT 0

namespace pro {
    sf::Event evt;
    int getEvent(pro::renderer* render);
}

#endif