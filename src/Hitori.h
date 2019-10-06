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
 * File:   Hitori.h
 * Author: jeannoel
 *
 * Created on 22 octobre 2011, 22:25
 */

#ifndef HITORI_H
#define	HITORI_H

#include <string>
#include <SFML/Graphics.hpp>
#include <random>

#include  "Cellule.h"
#include "define.h"

#include <core/Vector2D.hpp>

using namespace std;

class Hitori {
public:
    
    static scene::Scene facile(sf::RenderWindow& App, unsigned int n);
    
    static const unsigned int TileSize=56;
    
protected:    
    Hitori();
    
    void generateBase(unsigned s);
    
    unsigned int getSize();
    
    void draw(sf::RenderWindow& win);
    
    void setCelluleColor(unsigned int x, unsigned int y, Cellule::CelluleColor c);
    
    bool check();
    
    void print();
    
    scene::Scene gameRun(sf::RenderWindow& App);
    
private:
    bool checkCellule(unsigned int x, unsigned int y);
    
    void scale(float s);

    sf::Font font;
    
    core::Vector2D<Cellule> m_cells;
    //Cellule** array;
    
    unsigned int size;

    std::default_random_engine rng;
    
    unsigned int* randArray(unsigned int s);

};

#endif	/* HITORI_H */

