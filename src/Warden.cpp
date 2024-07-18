#include"Warden.hpp"
Warden::Warden(/* args */)
{
}

Warden::~Warden()
{
}
void Warden::Init(Player *player)
{
    Hostile_organisms::Init(player);
    this->lifez=1000;
    this->damage=45;
    time(&this->start_time);
}

void Warden::Render(Player *player)
{
    if(this->lifez<=0) return;
    attron(COLOR_PAIR(5));
    mvprintw(yy, xx, "o");
    attroff(COLOR_PAIR(5));
    mvprintw(this->yy + 1, this->xx, "%d", this->lifez);
}

void Warden::update(Player *player)
{
    if(this->lifez<=0) return;
    Hostile_organisms::update(player);
    time(&this->now_time);
    if(player->nearby(this->xx,this->yy,20)&&this->now_time-this->start_time>=5)
    {
        player->life-=damage;
    }
    this->attack(player);
}