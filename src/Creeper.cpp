#include"Creeper.hpp"
#include"player.hpp"
#include<ctime>
#include<fstream>
#include<iostream>
#include<cstring>
#include <cstdlib>
#include <ncurses.h> // input output
#include <unistd.h>  // sleep function
#include <iostream>
#include <time.h>
Creeper::Creeper(/* args */)
{
}

Creeper::~Creeper()
{
}
void Creeper::Render(Player *player)
{
    if(this->lifez<=0) return;
    attron(COLOR_PAIR(7));
    mvprintw(yy, xx, "o");
    attroff(COLOR_PAIR(7));
    mvprintw(this->yy + 1, this->xx, "%d", this->lifez);
}

void Creeper::update(Player *player)
{
    if(player->nearby(this->xx,this->yy,50)==0) return;
    Hostile_organisms::update(player);
    if(player->nearby(xx,yy,5)==1)
    {
        //this->lifez=0;
        player->life-=10;
        this->Init(player);
    }
    this->attack(player);
}