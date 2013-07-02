//
//  main.cpp
//  PROENGINE[1.5]
//
//  Created by Altan Haan on 4/30/13.
//  Copyright (c) 2013 Dual-Pro Studios. All rights reserved.
//

#include <SFML/Window.hpp>

int main()
{
    sf::Window window(sf::VideoMode(800, 600), "My window");
    
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
    
    return 0;
}
