#include"Hostile_organisms.hpp"
using namespace std;

Hostile_organisms::Hostile_organisms(/* args */)
{
}

Hostile_organisms::~Hostile_organisms()
{
}

void Hostile_organisms::Init(Player *player)
{
    this->xx =(rand() % 256) + 1;
    this->yy = (rand() % 100) + 1;
    this->lifez = 20;
}
void Hostile_organisms::Render(Player *player)
{
    
}
void Hostile_organisms::update(Player *player)
{
    if (this->lifez > 0)
    {
        if (this->xx < player->XX())
        {
            this->xx++;
        }
        else if (this->xx > player->XX())
        {
            this->xx--;
        }
        else if (this->yy < player->YY())
        {
            this->yy++;
        }   
        else if (this->yy > player->YY())
        {
            this->yy--;
        }
    }
}
void Hostile_organisms::save(ofstream& os)
{

}

void Hostile_organisms::read(std::ifstream &is)
{

}

void Hostile_organisms::attack(Player *player)
{
    if(player->nearby(this->xx,this->yy,10)==1) this->lifez-=player->damage;
    player->attack=0;
}