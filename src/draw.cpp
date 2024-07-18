
/*#include"draw.hpp"
using namespace std;
void draw_creapaa(int x,int y)
{
    init_pair(9, COLOR_GREEN, COLOR_GREEN);
    init_pair(13,COLOR_BLACK,COLOR_BLACK);
    srand(time(0));
    // Shell Screen Init, functions from ncurses.h
    initscr();
    start_color();
    clear();
    noecho();
    cbreak();
    curs_set(0);
    clear();
    for(int i=0;i<=6;i++)
    {
        for(int j=0;j<=16;j++)
        {
            if(draw_creapa[i][j]==1) attron(COLOR_PAIR(9));
            else attron(COLOR_PAIR(13));
            mvprintw(i+y,j+x," ");
            if(draw_creapa[i][j]==1) attroff(COLOR_PAIR(9));
            else attroff(COLOR_PAIR(13));
        }
    }
    refresh();
}*/