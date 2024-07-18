#include"golden_apple.hpp"
#include <algorithm>
#include <cstdlib>
#include <ncurses.h> // input output
#include <unistd.h>  // sleep function
#include <iostream>
#include <time.h>

void Golden_apple::update()
{
    if (player->nearby(x,y,5))
    {
        player->backpack["golden_apple"]++;
        x = (rand() % 256) + 1;
        y = (rand() % 100) + 1;
    }
}
void Golden_apple::Render()
{
    attron(COLOR_PAIR(6));
    mvprintw(y, x, "@");
    attroff(COLOR_PAIR(6));
    mvprintw(0, 55, "golden_appleX %d", x);
    mvprintw(0, 75, "golden_appleY %d", y);
}