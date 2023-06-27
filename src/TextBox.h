#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>

class TextBox {
private:

    std::ostringstream textL;
    std::ostringstream textR;

    void inputLogic(int chtyped){
        if(chtyped == 8){
            if(this->textL.str().length() > 0){
                dLastCh();
            }
        }
        else if(chtyped == 13){
            this->textL << '\n';
        }
        else{
            std::string TtextL = this->textL.str();
            this->textL.str("");
            this->textL << TtextL <<static_cast<char>(chtyped);
        }
        this->textbox.setString(textL.str() + "_" + textR.str());
    }

    void dLastCh(){
        std::string t = this->textL.str();
        std::string newT = "";
        for(int i = 0; i < t.length() - 1; i++){
            newT += t[i];
        }
        this->textL.str("");
        this->textL << newT;
        this->textbox.setString(this->textL.str() + this->textR.str());
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

    void navInText(sf::Event input){
        if(input.key.code == sf::Keyboard::Left){
            if(!this->textL.str().empty()){
                std::string textRstr = this->textR.str();
                std::string textLstr = this->textL.str();
                char lastChar = textLstr.back();
                textLstr.pop_back();
                textRstr = lastChar + textRstr;
                this->textR.str(textRstr);
                this->textL.str(textLstr);
            }
        }
        else if(input.key.code == sf::Keyboard::Right){
            if(!this->textR.str().empty()){
                std::string textRstr = this->textR.str();
                std::string textLstr = this->textL.str();
                char firstChar = textRstr.front();
                textRstr.erase(0, 1);
                textLstr += firstChar;
                this->textR.str(textRstr);
                this->textL.str(textLstr);
            }
        }
        this->textbox.setString(this->textL.str() + "_" + this->textR.str());
    }
};
