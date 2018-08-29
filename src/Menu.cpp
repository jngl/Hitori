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
 * File:   Menu.cpp
 * Author: jeannoel
 * 
 * Created on 28 octobre 2011, 14:04
 */

#include "Menu.h"
#include "Button.h"

scene::Scene Menu::run(sf::RenderWindow& window)
{
    //fond
    sf::Texture fond;
    if(!fond.loadFromFile(MENU_FOND))
    {
        return scene::Close;
    }
    fond.setSmooth(false);
    sf::Sprite fondsprite;
    fondsprite.setTexture(fond);
    
    //comment jouer
    Button commetJouer;
    sf::Image commentJouerI;
    if(!commetJouer.texture.loadFromFile(MENU_COMMENT_JOUER))
    {
        return scene::Close;
    }
    commetJouer.texture.setSmooth(false);
    commetJouer.sprite.setTexture(commetJouer.texture);
    commetJouer.sprite.setPosition(218, 280);
    
    //jouer en facile
    Button facile;
    if(!facile.texture.loadFromFile(MENU_JOUER_FACILE))
    {
        return scene::Close;
    }
    facile.texture.setSmooth(false);
    facile.sprite.setTexture(facile.texture);
    facile.sprite.setPosition(253, 346);
    
    //jouer en normal
    Button normal;
    if(!normal.texture.loadFromFile(MENU_JOUER_NORMAL))
    {
        return scene::Close;
    }
    normal.texture.setSmooth(false);
    normal.sprite.setTexture(normal.texture);
    normal.sprite.setPosition(243, 407);
    
    //jouer en diffcile
    Button difficile;
    if(!difficile.texture.loadFromFile(MENU_JOUER_DIFFICILE))
    {
        return scene::Close;
    }
    difficile.texture.setSmooth(false);
    difficile.sprite.setTexture(difficile.texture);
    difficile.sprite.setPosition(233, 464);
    
    // Exécution de la boucle principale
    while (window.isOpen())
    {
        // Traitement des évènements
        sf::Event Event;
        while (window.pollEvent(Event))
        {
            // Fenêtre fermée : on quitte
            if (Event.type == sf::Event::Closed)
            {
                return scene::Close;
            }
            else if(commetJouer.isCliced(Event))
            {
                return scene::Tutorial;
            }
            else if(facile.isCliced(Event))
            {
                return scene::GameFacile;
            }
            else if(normal.isCliced(Event))
            {
                return scene::GameNormal;
            }
            else if(difficile.isCliced(Event))
            {
                return scene::GameDifficile;
            }
        }

        // Efface l'écran (remplissage avec du noir)
        window.clear();
        
        window.draw(fondsprite);
        commetJouer.draw(window);
        facile.draw(window);
        normal.draw(window);
        difficile.draw(window);
        
        // Affichage du contenu de la fenêtre à l'écran
        window.display();
    }
    
    return scene::Close;
}
