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
 * File:   Hitori.cpp
 * Author: jeannoel
 * 
 * Created on 22 octobre 2011, 22:25
 */

#include "Hitori.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

#include "define.h"
#include "Button.h"


class WhiteCheck
{
public:
    bool** array;
    size_t size;
    
    bool check()
    {
        if(array[0][0]==false)//la 1er case est blanche
        {
            checkpart1(0,0);
        }
        else
        {
            checkpart1(0,1);
        }
        
        for(size_t y=0;y<size;y++)
        {
            for(size_t x=0;x<size;x++)
            {
                if(!array[y][x])
                    return false;       
            }
            delete[] array[y];
        }
        delete[] array;
        return true;
    }
    
private:
    void checkpart1(unsigned int x, unsigned int y)
    {
        if(!array[y][x])
        {
            array[y][x]=true;
            if(x!=0)
            {
                checkpart1(x-1,y);
            }
            if(x<size-1)
            {
                checkpart1(x+1,y);
            }
            if(y!=0)
            {
                checkpart1(x,y-1);
            }
            if(y<size-1)
            {
                checkpart1(x,y+1);
            }
        }
    }
};


scene::Scene Hitori::facile(sf::RenderWindow& App, unsigned int n)
{
    Hitori mHitori;
    mHitori.generateBase(n);
    
    for(unsigned int i=0;i<mHitori.size;i++)
    {
        for(unsigned int j=0;j<mHitori.size;j++)
        {
            mHitori.array[i][j].setColor(Cellule::White);
        }
    }
    
    std::uniform_int_distribution<int> distribution(0,mHitori.size-1);

    for(unsigned int i=0;i<mHitori.size*mHitori.size/2;i++)
    {
        sf::Vector2i pos;
        pos.x=distribution(mHitori.rng);
        pos.y=distribution(mHitori.rng);
        mHitori.array[pos.x][pos.y].setColor(Cellule::Black);
        unsigned int n=mHitori.array[pos.x][pos.y].getNumber();
        mHitori.array[pos.x][pos.y].setNumber(distribution(mHitori.rng));
        if(!mHitori.check())
        {
            mHitori.array[pos.x][pos.y].setColor(Cellule::White);
            mHitori.array[pos.x][pos.y].setNumber(n);
        }
    }
    
    for(unsigned int i=0;i<mHitori.size;i++)
    {
        for(unsigned int j=0;j<mHitori.size;j++)
        {
            mHitori.array[i][j].setColor(Cellule::Gray);
        }
    }
    
    return mHitori.gameRun(App);
}
scene::Scene Hitori::gameRun(sf::RenderWindow& App)
{
    //taille d'une cellule
    float celluleSize=600.f/static_cast<float>(size);
    scale(celluleSize/56.f);
    
    //cotee
    sf::Texture sideI;
    if(!sideI.loadFromFile(GAME_SIDE))
    {
        return scene::Close;
    }
    sf::Sprite sideS;
    sideS.setTexture(sideI);
    sideS.setPosition(600,0);
    
    //men
    Button menuButton;
    if(!menuButton.texture.loadFromFile(GAME_MENU))
    {
        return scene::Close;
    }
    menuButton.texture.setSmooth(false);
    menuButton.sprite.setTexture(menuButton.texture);
    menuButton.sprite.setPosition(610, 10);
    
    //menu
    Button verrifier;
    if(!verrifier.texture.loadFromFile(GAME_VERIFIER))
    {
        return scene::Close;
    }
    verrifier.texture.setSmooth(false);
    verrifier.sprite.setTexture(verrifier.texture);
    verrifier.sprite.setPosition(610, 70);
    
    //gagner
    sf::Texture gagnerI;
    if(!gagnerI.loadFromFile(GAME_GAGNER)){
        return scene::Close;
    }
    gagnerI.setSmooth(false);
    sf::Sprite gagnerS;
    gagnerS.setTexture(gagnerI);
    gagnerS.setPosition(610, 130);
    
    //perdu
    sf::Texture perduI;
    if(!perduI.loadFromFile(GAME_PERDU))
    {
        return scene::Close;
    }
    perduI.setSmooth(false);
    sf::Sprite perduS;
    perduS.setTexture(perduI);
    perduS.setPosition(610, 130);
    
    int gagnerPerdu=2;
    
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

            if(Event.type == sf::Event::MouseButtonPressed)
            {
                if(Event.mouseButton.x<600)
                {
                    if(Event.mouseButton.button==sf::Mouse::Left)
                    {
                        setCelluleColor(Event.mouseButton.y/celluleSize,
                                Event.mouseButton.x/celluleSize,
                                Cellule::Black);
                    }
                    else if(Event.mouseButton.button==sf::Mouse::Right)
                    {
                        setCelluleColor(Event.mouseButton.y/celluleSize,
                                Event.mouseButton.x/celluleSize,
                                Cellule::White);
                    }
                    else
                    {
                        setCelluleColor(Event.mouseButton.y/celluleSize,
                                Event.mouseButton.x/celluleSize,
                                Cellule::Gray);
                    }
                }
            }
            else if(menuButton.isCliced(Event))
            {
                return scene::Menu;
            }
            else if(verrifier.isCliced(Event))
            {
                if(check())
                {
                    gagnerPerdu=0;
                }
                else
                {
                    gagnerPerdu=1;
                }
            }
        }

        // Efface l'écran (remplissage avec du noir)
        App.clear();
        
        draw(App);
        App.draw(sideS);
        menuButton.draw(App);
        verrifier.draw(App);
        if(gagnerPerdu==0)
            App.draw(gagnerS);
        else if(gagnerPerdu==1)
            App.draw(perduS);

        // Affichage du contenu de la fenêtre à l'écran
        App.display();
    }
    return scene::Menu;
}
void Hitori::generateBase(unsigned s)
{    
    size=s;
    
    unsigned int** t1=new unsigned int *[size];
    
    for(unsigned int i=0;i<size;i++)
    {
         t1[i]= new unsigned int[size];

        for(unsigned int j=0;j<i;j++)
        {
            t1[i][j]=j+(size-i);
        }

        for(unsigned int j=i;j<size;j++)
        {
            t1[i][j]=j-i;
        }
    }
    
    //on inverse les ligne
    unsigned int* a=randArray(size);
    unsigned int** t2=new unsigned int*[size];
    for(unsigned int i=0;i<size;i++)
    {        
        
        t2[i]=new unsigned int[size];
        
        for(unsigned int j=0;j<size;j++)
        {
            t2[i][j]=t1[a[i]][j];
        }
    }
    delete[] a;
    
    //on inverse le colone
    a=randArray(size);
    for(unsigned int i=0;i<size;i++)
    {        
        for(unsigned int j=0;j<size;j++)
        {
            t1[j][i]=t2[j][a[i]];
        }
    }
    delete[] a;
    
    array=new Cellule*[size];
    for(unsigned int i=0;i<size;i++)
    {
        array[i]=new Cellule[size];
        for(unsigned int j=0;j<size;j++)
        {
            array[i][j].setNumber(t1[i][j]);
            array[i][j].setPosition(j,i);
            array[i][j].setFont(font);
        }
    }
    
}

Hitori::Hitori()
{
    std::random_device seedGenerator;
    rng.seed(seedGenerator());

    font.loadFromFile("data/Vera.ttf");

    array=nullptr;
}
Hitori::~Hitori()
{
    if(array!=nullptr)
    {
        for(unsigned int i=0;i<size;i++)
        {
            delete[] array[i];
        }
        
        delete[] array;
    }
}
unsigned int Hitori::getSize()
{
    return size;
}
void Hitori::draw(sf::RenderWindow& win)
{
    for(unsigned int i=0;i<size;i++)
    {        
        for(unsigned int j=0;j<size;j++)
        {
            array[i][j].draw(win);
        }
    }
}
void Hitori::setCelluleColor(unsigned int x, unsigned int y, Cellule::CelluleColor c)
{
    array[x][y].setColor(c);
}
bool Hitori::check()
{    
    for(unsigned int i=0;i<size;i++)//pour chaque ligne
    {
        for(unsigned int j=0;j<size;j++)//pour chaque cellule
        {
            if(!checkCellule(i,j))
                return false;
        }
    }
    
    //toutles case blanche doive etre connecter
    WhiteCheck c;
    c.array=new bool*[size];
    for(unsigned int y=0;y<size;y++)
    {
        c.array[y]=new bool[size];
        for(unsigned int x=0;x<size;x++)
        {
            if(array[y][x].getColor()==Cellule::Black)
            {
                c.array[y][x]=true;
            }
            else
            {
                c.array[y][x]=false;
            }
        }
    }
    c.size=size;
    return c.check();
}
bool Hitori::checkCellule(unsigned int x, unsigned int y)
{
    Cellule c=array[y][x];
    
    if(c.getColor()==Cellule::Black)
    {
        //il ne faut pas que le cellule de gauche soit noir
        if(x<size-1)
        {
            if(array[y][x+1].getColor()==Cellule::Black)
            {
                return false;
            }
        }
        
        //cellule du bas pas noir
        if(y<size-1)
        {
            if(array[y+1][x].getColor()==Cellule::Black)
            {
                return false;
            }
        }
        
    }
    else if(c.getColor()==Cellule::White)
    {
        unsigned int tmp=c.getNumber();
        
        //une seul fois par ligne
        for(unsigned int k=0;k<size;k++)//le numero et t'il uplusieur fois
        {
            if(k!=x)//si c'est une autre
            {
                if(array[y][k].getColor()==Cellule::White)//s'il elle est blanche
                {
                    if(tmp==array[y][k].getNumber())
                    {
                        return false;
                    }
                }
            }
        }
        
        //une seul fois par colone
        for(unsigned int k=0;k<size;k++)
        {
            if(k!=y)//si c'est une autre
            {
                if(array[k][x].getColor()==Cellule::White)//s'il elle est blanche
                {
                    if(tmp==array[k][x].getNumber())
                    {
                        return false;
                    }
                }
            }
        }
    }
    else
    {
        return false;
    }
    
    return true;
}
void Hitori::print()
{    
    for(unsigned int i=0;i<size;i++)
    {
        for(unsigned int j=0;j<size;j++)
        {
            cout<<array[i][j].getNumber();
        }
        cout<<endl;
    }
}
void Hitori::scale(float s)
{
    for(unsigned int i=0;i<size;i++)
    {
        for(unsigned int j=0;j<size;j++)
        {
            array[i][j].scale(s);
        }
    }
}
unsigned int* Hitori::randArray(unsigned int s)
{
    vector<unsigned int> a1;
    for(unsigned int i=0;i<s;i++)
    {
        a1.push_back(i);
    }
    
    unsigned int* a2=new unsigned int[s];
    for(unsigned int i=0;i<s;i++)
    {
        std::uniform_int_distribution<int> distribution(0,s-i-1);
        unsigned int tmp=distribution(rng);
        a2[i]=a1[tmp];
        a1.erase(a1.begin()+tmp);
    }
    
    return a2;
}
