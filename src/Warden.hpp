#ifndef WARDEN
#define WARDEN
#include"Hostile_organisms.hpp"
#include"player.hpp"
#include<ctime>
#include<fstream>
#include<iostream>
#include<cstring>
using namespace std;
class Warden : public Hostile_organisms
{
private:
    time_t now_time;
    time_t start_time;
public:
    Warden(/* args */);
    ~Warden();
    void Init(Player *player);
    void Render(Player *player);
    void update(Player *player);
    int damage;
};



#endif