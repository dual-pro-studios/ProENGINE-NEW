#include "pro_event.hpp"

namespace pro {
    
    int getEvent(pro::renderer* render) {
        int event;
        while(render->window.pollEvent(evt)) {
            if(evt.type == sf::Event::Closed) {
                event = EVENT_EXIT;
            }
        }
        return event;
    }
    
}