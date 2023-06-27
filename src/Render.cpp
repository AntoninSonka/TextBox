#include "Render.h"

Render::Render(){
    this->window.create(sf::VideoMode(this->width, this->height), "Okno");
    this->window.setFramerateLimit(240);
}

void Render::update(){
    if(this->event.type == sf::Event::Closed){
        this->window.close();
    }
}
