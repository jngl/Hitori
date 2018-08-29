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
 * File:   Cellule.h
 * Author: jeannoel
 *
 * Created on 22 octobre 2011, 22:28
 */

#ifndef CELLULE_H
#define	CELLULE_H

#include <SFML/Graphics.hpp>

class Cellule {
public:
    Cellule();
    
    unsigned int getNumber();
    void setNumber(unsigned int n);

    void setFont(sf::Font& font);
    
    enum CelluleColor
    {
        White,
        Black,
        Gray
    };
    
    void setColor(CelluleColor c);
    
    void setPosition(unsigned int x, unsigned int y);
    
    CelluleColor getColor();
    
    void scale(float s);
    
    void draw(sf::RenderWindow& win);
    
private:
    unsigned int number;
    CelluleColor color;
    
    sf::Sprite sprite;
    sf::Text str;
    
    static sf::Texture& getCellule1();
    static sf::Texture& getCellule2();
    static sf::Texture& getCellule3();
};

#endif	/* CELLULE_H */

