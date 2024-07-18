#ifndef HOSTILE_ORGANIS
#define HOSTILE_ORGANIS
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
class Hostile_organisms
{
protected:
    int xx;
    int yy;
    int lifez;
public:
    Hostile_organisms(/* args */);
    ~Hostile_organisms();
    virtual void Init(Player *player);
    virtual void Render(Player *player);
    virtual void update(Player *player);
    virtual void save(ofstream& os);
    virtual void read(std::ifstream &is);
    virtual void attack(Player *player);
};


#endif