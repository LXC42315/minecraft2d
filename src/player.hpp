#ifndef MCT_PLAYER
#define MCT_PLAYER
#include"wait.hpp"
#include <ctime>
#include<iostream>
#include<cstring>
#include<map>
using namespace std;
typedef enum DIRECTION
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN,
    K,
    A,
} Dir;


class Player
{
private:
    int z;
    int s;
    int w;
    bool gameover;
    Dir dir;
    time_t start_time;
    time_t now_time;
public:
    void save(ofstream& os);
    void update();
    bool bump(int x, int y);
    bool nearby(int x, int y, int range);
    bool zombie_nearby(int x,int y);
    void Init();
    void Increase_satiety(int satiety);
    void Increase_life();
    void Increase_life_value(int value);
    void Render();
    void Render_life();
    void Init_equip();
    bool life_big();
    void poll_input();
    void Render_Inventory();
    void read(std::ifstream &is);
    void move(int x, int y);
    int XX();
    int YY();
    int c;
    bool attack;
    int level;
    multimap<string,long long> equip;
    int life;
    int x,last_x;
    int y,last_y;
    int damage;
    map<string,int> backpack;
};

#endif