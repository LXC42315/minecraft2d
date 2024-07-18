#include "player.hpp"
#include "object.hpp"
#include <cstdlib>
#include <ncurses.h> // input output
#include <unistd.h>  // sleep function
#include <iostream>
#include <time.h>
#include <algorithm>
#include<fstream>
#include<iostream>
#include<cstring>
using namespace std;

void Player::update()
{

    time(&now_time);
    if ((now_time - start_time) % 100 == 0)
    {
        this->s--;
    }
}

bool Player::bump(int x, int y)
{
    if (this->x == x && this->y == y)
    {
        this->x=this->last_x;
        this->y=this->last_y;
        return true;
    }
    return false;
}
bool Player::nearby(int xx, int yy, int mange)
{
    if (abs(this->x - xx) <= mange && abs(this->y - yy) <= mange)
        return true;
    else
        return false;
}
bool Player::zombie_nearby(int xa, int ya)
{
    if (this->nearby(xa, ya, 0) == 1)
    {
        if (this->life > 0)
        {
            this->life -= 1;
            s -= 1;
            if (level > 3)
                level -= 3;
            return true;
        }
        else
        {
            this->gameover = true;
            return false;
        }
    }
    return false;
}
void Player::Increase_satiety(int satiety)
{
    if (s < 20)
    {
        s += satiety;
    }
    if (s > 20)
        s = 20;
}
void Player::Increase_life()
{
    if (s == 20 && life < 20)
    {
        life++;
    }
}
void Player::Increase_life_value(int value)
{
    this->life = value;
}
void Player::Init_equip()
{
    equip.insert(make_pair("WU",1));
    equip.insert(make_pair("WOOD",4));
    equip.insert(make_pair("STONE",5));
    equip.insert(make_pair("IRON",6));
    equip.insert(make_pair("DIAMOND",7));
    equip.insert(make_pair("NETHERITE_INGOT",8));
    equip.insert(make_pair("IRON_NETHERITE_INGOT",9));
    equip.insert(make_pair("GOLDEN_NETHERITE_INGOT",10));
    equip.insert(make_pair("DIAMOND_NETHERITE_INGOT",4));
    equip.insert(make_pair("ENDLESS",1E18));
}
void Player::Render()
{
    attron(COLOR_PAIR(10));
    mvprintw(y , x, "o");
    //dir = STOP;
    attroff(COLOR_PAIR(10));
    mvprintw(0, 45, "x %d", x);
    mvprintw(0, 50, "y %d", y);
    //mvprintw(0,200,"ch:%d",this->c);
    
}
void Player::Render_life()
{
    int length = life <= 20 ? life * 2 : 40;
    int H=1;
    for (int i = 0; i < length; i += 2)
    {
        attron(COLOR_PAIR(8));
        mvprintw(0, i, "* ");
        attroff(COLOR_PAIR(8));
    }
    if (life > 20)
    {
        for (int i = 42; i <= life * 2; i += 2)
        {
            attron(COLOR_PAIR(4));
            mvprintw(H, i - (H - 1) * 40 - 42, "* ");
            attroff(COLOR_PAIR(4));
            if (i % 40 == 0)
            {
                H++;
            }
        }
    }
    for (int i = 0; i <= s * 2; i += 2)
    {

        attron(COLOR_PAIR(1));
        mvprintw(H + 1, i, "* ");
        attroff(COLOR_PAIR(1));
    }
    for (int i = 0; i <= w * 2; i += 2)
    {

        attron(COLOR_PAIR(5));
        mvprintw(H + 2, i, "* ");
        attroff(COLOR_PAIR(5));
    }
    H=1;
}
bool Player::life_big()
{
    if(this->life>0)return true;
    return false;
}
void Player::Init()
{
    //life = 20;
    s = 20;
    w = 20;
    level = 0;
    dir = STOP;
    x = (rand() % 256) + 1;
    y = (rand() % 100) + 1;
    attack=0;
    this->damage=1;
    //this->Init_equip();
}
int Player::XX()
{
    return this->x;
}
int Player::YY()
{
    return this->y;
}
void Player::save(std::ofstream& os)
{
    os<<this->x<<endl<<this->y<<endl<<this->life<<endl;
}

void Player::read(std::ifstream& is)
{
    string n;
    getline(is,n);
    this->x=stoi(n);
    getline(is,n);
    this->y=stoi(n);
    getline(is,n);
    this->life=stoi(n);
}
void Player::move(int x,int y)
{
    this->x+=x;
    this->y+=y;
}
void Player::Render_Inventory()
{
    for(int i=100;i<=200;i++) mvprintw(70,i,"=");
    for(int j=71;j<=76;j++)
    {
        for(int i=100;i<=200;i+=10) mvprintw(j,i,"|");
    }
    for(int i=100;i<=200;i++) mvprintw(77,i,"=");
}