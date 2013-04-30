#include "pro_event.hpp"

namespace pro {
    
    int getEvent(sf::RenderWindow &window) {
        int event;
        while(window.pollEvent(evt)) {
            if(evt.type == sf::Event::Closed) {
                event = EVENT_EXIT;
            }
        }
        return event;
    }
    
}