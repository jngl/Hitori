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
 * Created on 24 octobre 2011, 17:30
 */

#ifndef DEFINE_H
#define	DEFINE_H

#define MENU_FOND "data/menu.png"
#define MENU_COMMENT_JOUER "data/menu comment jouer.png"
#define MENU_JOUER_FACILE "data/jouerFacile.png"
#define MENU_JOUER_NORMAL "data/jouerNormal.png"
#define MENU_JOUER_DIFFICILE "data/jouerDifficile.png"

#define TUTORIAL_1 "data/tuto1.png"
#define TUTORIAL_2 "data/tuto2.png"
#define TUTORIAL_3 "data/tuto3.png"
#define TUTORIAL_4 "data/tuto4.png"
#define TUTORIAL_5 "data/tuto5.png"
#define TUTORIAL_6 "data/tuto6.png"

#define GAME_CELLULE_1 "data/Cellule1.png"
#define GAME_CELLULE_2 "data/Cellule2.png"
#define GAME_CELLULE_3 "data/Cellule3.png"

#define GAME_SIDE "data/side.png"
#define GAME_MENU "data/gameMenu.png"
#define GAME_VERIFIER "data/gameVerifier.png"
#define GAME_GAGNER "data/gameGagner.png"
#define GAME_PERDU "data/gamePerdu.png"

namespace scene
{
    enum Scene
    {
        Close,
        Menu,
        GameFacile,
        GameNormal,
        GameDifficile,
        Tutorial
    };    
}

#endif	/* DEFINE_H */
