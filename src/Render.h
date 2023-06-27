#pragma once

#include <SFML/Graphics.hpp>

class Render {
private:
    
    const unsigned int height = 750;
    const unsigned int width = 1200;

public:

    sf::Event event;

    sf::RenderWindow window;

    Render();
    void update();

};
