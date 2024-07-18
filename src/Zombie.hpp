#ifndef ZOMBIE
#define ZOMBIE
#include"player.hpp"
#include<ctime>
#include<fstream>
#include<iostream>
#include<cstring>
#include"Hostile_organisms.hpp"
using namespace std;
class Zombie : public Hostile_organisms
{
private:
    time_t zombie_starttime;
    time_t zombie_nowtime;
public:
    void Init(Player *player);
    void Render(Player *player);
    void update(Player *player);
    void save(ofstream& os);
    void read(std::ifstream &is);
};
#endif