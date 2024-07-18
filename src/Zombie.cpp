#include <cstdlib>
#include <ncurses.h> // input output
#include <unistd.h>  // sleep function
#include <iostream>
#include <time.h>
#include"player.hpp"
#include"Zombie.hpp"
using namespace std;
void Zombie::Init(Player *player)
{
    Hostile_organisms::Init(player);
    time(&zombie_starttime);
}
void Zombie::Render(Player *player)
{
    if(this->lifez<=0) return;
    time(&zombie_nowtime);
    if(((zombie_nowtime-zombie_starttime)/600)%2!=0) return;
    for (int k = 1; k <= 5; k++)
    {
        attron(COLOR_PAIR(7));
        mvprintw(yy, xx, "*");
        attroff(COLOR_PAIR(7));
        mvprintw(this->yy + 1, this->xx, "%d", this->lifez);
    }
}
void Zombie::update(Player *player)
{
    time(&zombie_nowtime);
    if(this->lifez<=0) return;
    if(((zombie_nowtime-zombie_starttime)/600)%2!=0) return;
    if(player->nearby(this->xx,this->yy,50)==0) return;
    if(this->lifez==0) return;
    int xxxx=xx,yyyy=yy;
    Hostile_organisms::update(player);
    player->zombie_nearby(xxxx,yyyy);
    this->attack(player);
}
void Zombie::save(ofstream& os)
{
    os<<this->xx<<endl<<this->yy<<endl<<this->lifez<<endl;
}
void Zombie::read(std::ifstream& is)
{
    string n;
    getline(is,n);
    this->xx=stoi(n);
    getline(is,n);
    this->yy=stoi(n);
    getline(is,n);
    this->lifez=stoi(n);
}