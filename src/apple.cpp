#include"apple.hpp"
#include <algorithm>
#include <cstdlib>
#include <ncurses.h> // input output
#include <unistd.h>  // sleep function
#include <iostream>
#include <time.h>
#include "player.hpp"
void Apple::Render()
{
    attron(COLOR_PAIR(8));
    mvprintw(x,y, "@");
    attroff(COLOR_PAIR(8));
}
void Apple::update()
{
    if(player->nearby(x,y,5))
    {
        player->backpack["apple"]++;
        this->Init(player);
    }
}