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
 * File:   Tutorial.cpp
 * Author: jeannoel
 * 
 * Created on 27 octobre 2011, 18:42
 */

#include "Tutorial.h"

scene::Scene Tutorial::run(sf::RenderWindow& App)
{
    sf::Texture fondI;
    if(!fondI.loadFromFile(TUTORIAL_1))
    {
        return scene::Close;
    }
    fondI.setSmooth(false);
    sf::Sprite fondS;
    fondS.setTexture(fondI);
    
    int n=1;
    
    // Exécution de la boucle principale
    while (App.isOpen())
    {
        // Traitement des évènements
        sf::Event Event;
        while (App.pollEvent(Event))
        {
            // Fenêtre fermée : on quitte
            if (Event.type == sf::Event::Closed)
            {
                return scene::Close;
            }

            if(Event.type == sf::Event::MouseButtonReleased)
            {
                switch(n)
                {
                    case 1:
                        if(!fondI.loadFromFile(TUTORIAL_2))
                        {
                            return scene::Close;
                        }
                        break;
                    case 2:
                        if(!fondI.loadFromFile(TUTORIAL_3))
                        {
                            return scene::Close;
                        }
                        break;
                    case 3:
                        if(!fondI.loadFromFile(TUTORIAL_4))
                        {
                            return scene::Close;
                        }
                        break;
                    case 4:
                        if(!fondI.loadFromFile(TUTORIAL_5))
                        {
                            return scene::Close;
                        }
                        break;
                    case 5:
                        if(!fondI.loadFromFile(TUTORIAL_6))
                        {
                            return scene::Close;
                        }
                        break;
                    default:
                        return scene::Menu;
                }
                n++;
            }
        }

        // Efface l'écran (remplissage avec du noir)
        App.clear(sf::Color::White);
        
        App.draw(fondS);

        // Affichage du contenu de la fenêtre à l'écran
        App.display();
    }
    
    return scene::Menu;
}

