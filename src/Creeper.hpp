#ifndef CREEPER
#define CREEPER
#include"player.hpp"
#include<ctime>
#include<fstream>
#include<iostream>
#include<cstring>
#include"Hostile_organisms.hpp"
using namespace std;
class Creeper : public Hostile_organisms
{
private:

public:
    Creeper(/* args */);
    ~Creeper();
    void Render(Player *player);
    void update(Player *player);
};

#endif