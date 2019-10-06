/*Copyright (C) 2011 Glesser Jean-noël
 * 
 T his program is free software; you can redistribute it and/or* modify
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
 * File:   Button.h
 * Author: jeannoel
 *
 * Created on 28 octobre 2011, 19:45
 */

#ifndef BUTTON_H
#define	BUTTON_H

#include "data.h"

namespace button {
    enum class State{
        NORMAL,
        OVER,
        CLICKED
    };

    State StateUpdate(const Point2f& button_position, const Vector2f& button_size, const Point2f& mouse_position, bool mouse_pressed);

    ColorRGBA stateToColor(State state);
}

#include <SFML/Graphics.hpp>

class Button {
public:    
    void draw(sf::RenderWindow& App);
    bool isCliced(sf::Event& e);
    
    sf::Texture texture;
    sf::Sprite sprite;
};

#endif	/* BUTTON_H */

