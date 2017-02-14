/*
 * ZipSFML - example
 * Copyright (C) 2016 Matadini (matadini@hotmail.com)
 *
 * This software is provided 'as-is', without any express
 * or implied warranty. In no event will the authors be
 * held liable for any damages arising from the use of this software.
 *
 * Permission is granted to anyone to use this software
 * for any purpose, including commercial applications, and
 * to alter it and redistribute it freely, subject to the
 * following restrictions:
 *
 * 1. The origin of this software must not be misrepresented;
 * you must not claim that you wrote the original software.
 * If you use this software in a product, an acknowledgment
 * in the product documentation would be appreciated but is not required.
 *
 * 2. Altered source versions must be plainly marked as such,
 * and must not be misrepresented as being the original software.
 *
 * 3. This notice may not be removed or altered from any source distribution.
 *
 */

#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "zip_sfml/zip_sfml.h"


int main(int argc, char *argv[])
{
    sf::RenderWindow window(
                sf::VideoMode(400, 400, 32),
                std::string("ZipSFML - test"),
                sf::Style::Default);

    ZipSFML loader(std::string("data.zip"));


    std::shared_ptr<sf::Texture> texture (loader.getTextureFromZip("image.png"));
    std::shared_ptr<sf::Font> font (loader.getFontFromZip("font.ttf"));

    sf::RectangleShape shape;
    shape.setFillColor(sf::Color::Blue);
    shape.setSize(sf::Vector2f(150.f, 150.f));
    shape.setPosition(sf::Vector2f(50.f, 50.f));
    shape.setTexture(texture.get());

    sf::Text text;
    text.setString(std::string("Hello"));
    text.setPosition(sf::Vector2f(200.f, 300.f));
    text.setCharacterSize(75);
    text.setFont(*font);
    text.setColor(sf::Color::Green);

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }

        window.clear(sf::Color::White);

        window.draw(shape);
        window.draw(text);

        window.display();
    }

    return 0;
}
