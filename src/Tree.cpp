#include"Tree.hpp"
#include <cstdlib>
#include <ncurses.h> // input output
#include <unistd.h>  // sleep function
#include <iostream>
#include <time.h>
#include<fstream>
#include<iostream>
#include<cstring>
using namespace std;
Tree::Tree()
{
}

Tree::~Tree()
{

}
void Tree::Init(Player* player)
{
    Object::Init(player);
    is_l=1;
}
void Tree::Render()
{
    if(!is_l) return;
    attron(COLOR_PAIR(1));
    mvprintw(x, y, "o");
    attroff(COLOR_PAIR(1));
}
void Tree::Update()
{
    if(!is_l) return;
    player->bump(x , y);
    /*if(player->nearby(x,y,2))
    {
        this->is_l=0;
        player->backpack["oak"]++;
    }*/
}
void Tree::save(ofstream& os)
{
    os<<x<<endl<<y<<endl;
}
void Tree::read(std::ifstream& is)
{
    if(!is_l) return;
    string n;
    getline(is,n);
    x=stoi(n);
    getline(is,n);
    y=stoi(n);
}
bool Tree::is_tree_at(int x,int y)
{
    return x==this->x&&y==this->y;
}