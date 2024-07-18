#ifndef MCT7_HPP
#define MCT7_HPP
#include "Zombie.hpp"
#include "Tree.hpp"
#include "player.hpp"
#include "object.hpp"
#include "wait.hpp"
#include"Creeper.hpp"
#include"Warden.hpp"
#include <iostream>
#include<vector>
using namespace std;
typedef enum EQUIP
{
    WU,
    WOOD,
    STONE,
    IRON,
    DIAMOND,
    NETHERITE_INGOT,
    IRON_NETHERITE_INGOT,
    GOLDEN_NETHERITE_INGOT,
    emerald_NETHERITE_INGOT,
    DIMMAND_NETHERITE_INGOT,
    ENDLESS
} E;
class Mct7
{
private:
public:
    Mct7(/* args */);
    ~Mct7();

    void read(string name);

    void color_attron();

    void color_attroff();

    bool die();

    void update();

    bool pass_word();

    void save(string name);

    bool is_read();

    int execute(void);

    void poll_input();

    void Render();

    void init_color();
    void open_backpack();
    void Initialize();
    void draw_home_page();
    bool home_page();
    E Equip;
    vector <Zombie*> zombie;
    Player *player;
    vector <Object*> object;
    vector <Hostile_organisms*> hostile_organisms;
    bool gameover;
    int WIDTH;
    int HEIGHT;
    time_t starttime;
    time_t nowtime;
    string password;
    string acc;
};
#endif