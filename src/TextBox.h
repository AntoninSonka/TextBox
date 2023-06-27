#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>

class TextBox {
private:

    std::ostringstream text;

    void inputLogic(int chtyped){
        if(chtyped == 8){
            if(this->text.str().length() > 0){
                dLastCh();
            }
        }
        else if(chtyped == 13){
            this->text << '\n';
        }
        else{
            this->text << static_cast<char>(chtyped);
        }
        this->textbox.setString(text.str() + "_");
    }

    void dLastCh(){
        std::string t = this->text.str();
        std::string newT = "";
        for(int i = 0; i < t.length() - 1; i++){
            newT += t[i];
        }
        this->text.str("");
        this->text << newT;
        this->textbox.setString(this->text.str());
    }

public:

    sf::Text textbox;

    TextBox(sf::Font& font, int charSize = 20, sf::Color color = sf::Color::White){
        this->textbox.setFont(font);
        this->textbox.setCharacterSize(charSize);
        this->textbox.setFillColor(color);
    }

    void typedOn(sf::Event input){
        int charTyped = input.text.unicode;
        if(charTyped < 128){
            inputLogic(charTyped);
        }
    }
};
