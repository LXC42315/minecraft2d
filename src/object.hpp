
#ifndef MCT_OBJECT_H
#define MCT_OBJECT_H

#include <time.h>
#include "player.hpp"
#include<fstream>
#include<iostream>
#include<cstring>
using namespace std;
class Object
{
protected:
    time_t start_time;
    time_t now_time;
    int x;
    int y;
    Player *player;
public:
    virtual void update();
    virtual void Render();
    virtual void Init(Player *player);
    virtual void save(ofstream& os);
    virtual void read(std::ifstream& is);
    virtual bool is_tree_at(int x,int y);
};

#endif