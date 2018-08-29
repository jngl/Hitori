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
 * File:   main.cpp
 * Author: jeannoel
 *
 * Created on 22 octobre 2011, 22:24
 */

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Hitori.h"
#include "define.h"
#include "Tutorial.h"
#include "Menu.h"

using namespace std;


/*
 * 
 */

int main()
{
    scene::Scene s=scene::Menu;
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "Hitori");
    
    while(true)
    {
        switch(s)
        {
            case scene::Menu:
                s=Menu::run(window);
                break;
            case scene::Close:
                return 0;
                break;
            case scene::Tutorial:
                s=Tutorial::run(window);
                break;
            case scene::GameFacile:
                s=Hitori::facile(window,5);
                break;
            case scene::GameNormal:
                s=Hitori::facile(window,8);
                break;
            case scene::GameDifficile :
                s=Hitori::facile(window,12);
                break;
            default:
                cout<<"scene inconnue"<<endl;
                return 1;
        }
    }
    
    return 0;
}
