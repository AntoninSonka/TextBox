#include <SFML/Graphics.hpp>
#include "Render.h"
#include "TextBox.h"

int main()
{
    Render render;
    sf::Font font;
    font.loadFromFile("ARIAL.TTF");
    TextBox textBox(font);
    while (render.window.isOpen())
    {
        while (render.window.pollEvent(render.event)){
            render.update();
            if(render.event.type == sf::Event::TextEntered){
                textBox.typedOn(render.event);
            }
            if(render.event.type == sf::Event::KeyPressed){
                textBox.navInText(render.event);
            }
        }
        render.window.clear(sf::Color::Black);
        render.window.draw(textBox.textbox);
        render.window.display();
    }

    return 0;
}
