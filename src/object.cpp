#include "object.hpp"
#include <algorithm>
#include <cstdlib>
#include <ncurses.h> // input output
#include <unistd.h>  // sleep function
#include <iostream>
#include <time.h>
#include<fstream>

using namespace std;
void Object::update()
{
   
}
void Object::Render()
{
    
}
void Object::Init(Player *player)
{
    this->player=player;
    this->x = (rand() % 256) + 1;
    this->y = (rand() % 100) + 1;
}
void Object::save(ofstream& os)
{
    os<<this->x<<endl<<this->y<<endl;
}
void Object::read(std::ifstream& is)
{
    string n;
    getline(is,n);
    this->x=stoi(n);
    getline(is,n);
    this->y=stoi(n);
}
bool Object::is_tree_at(int x,int y)
{
    
}