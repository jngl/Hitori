/*Copyright (C) 2011 Glesser Jean-noël

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.*/

/* 
 * File:   Button.cpp
 * Author: jeannoel
 * 
 * Created on 28 octobre 2011, 19:45
 */

#include "Button.h"

void Button::draw(sf::RenderWindow& window)
{
    sf::Vector2i tmp = sf::Mouse::getPosition(window);
   /* tmp.x -= sprite.getPosition().x;
    tmp.y -= sprite.getPosition().y;*/

    if(sprite.getGlobalBounds().contains(tmp.x,tmp.y))
    {
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sprite.setColor(sf::Color(255,255,255,100));
        }
        else
        {
            sprite.setColor(sf::Color(255,255,255,170));
        }
    }
    else
    {
        sprite.setColor(sf::Color::White);
    }
    
    window.draw(sprite);
}
bool Button::isCliced(sf::Event& e)
{
    return e.type==sf::Event::MouseButtonReleased &&
            e.mouseButton.button==sf::Mouse::Left &&
            sprite.getGlobalBounds().contains(e.mouseButton.x,e.mouseButton.y);
}

