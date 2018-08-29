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
 * File:   Cellule.cpp
 * Author: jeannoel
 * 
 * Created on 22 octobre 2011, 22:28
 */

#include "Cellule.h"

#include "Hitori.h"
#include "define.h"

#include <climits>
#include <sstream>

using namespace std;

Cellule::Cellule() {
    number=UINT_MAX;
    setColor(Gray);
    str.setFillColor(sf::Color(125,125,125));
}
unsigned int Cellule::getNumber()
{
    return number;
}
void Cellule::setNumber(unsigned int n)
{
    number=n;
    str.setString(std::to_string(n));
    
}
void Cellule::setFont(sf::Font& font){
    str.setFont(font);
}
void Cellule::setColor(CelluleColor c)
{
    color=c;
    switch(c)
    {
        case White:
            sprite.setTexture(getCellule2());
            break;
        case Black:
            sprite.setTexture(getCellule3());
            break;
        default:
            sprite.setTexture(getCellule1());
            break;
    }
}
Cellule::CelluleColor Cellule::getColor()
{
    return color;
}
void Cellule::draw(sf::RenderWindow& win)
{
    win.draw(sprite);
    
    win.draw(str);
}
void Cellule::setPosition(unsigned int x, unsigned int y)
{
    sf::Vector2f pos;
    pos.x=x*Hitori::TileSize;
    pos.y=y*Hitori::TileSize;
    sprite.setPosition(pos);
    
    
    pos.x+=Hitori::TileSize/3;
    pos.y+=Hitori::TileSize/6;
    str.setPosition(pos);
    
}
sf::Texture& Cellule::getCellule1()
{
    static sf::Texture img;
    static bool b=true;
    if(b)
    {
        b=false;
        img.loadFromFile(GAME_CELLULE_1);
    }
    
    return img;
}
sf::Texture& Cellule::getCellule2()
{
    static sf::Texture img;
    static bool b=true;
    if(b)
    {
        b=false;
        img.loadFromFile(GAME_CELLULE_2);
    }
    
    return img;
}
sf::Texture& Cellule::getCellule3()
{
    static sf::Texture img;
    static bool b=true;
    if(b)
    {
        b=false;
        img.loadFromFile(GAME_CELLULE_3);
    }
    
    return img;
}
void Cellule::scale(float s)
{
    sprite.scale(s,s);
    sprite.setPosition(sprite.getPosition()*s);
    
    sf::Vector2f pos;
    float ts=(float)Hitori::TileSize*s;
    pos.x=sprite.getPosition().x+ts/3;
    pos.y=sprite.getPosition().y+ts/6;
    str.setPosition(pos);
    str.scale(s,s);
}