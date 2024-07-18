//  -> gcc -o Mct2 Mct2.cpp -lncurses
#include <cstdlib>
#include <ncurses.h> // input output
#include <unistd.h>  // sleep function
#include <iostream>
#include <time.h>
#include <fstream>
#include "Mct7.hpp"
#include "apple.hpp"
#include "golden_apple.hpp"
#include "draw.hpp"
#include"Mct_zmzs.hpp"
using namespace std;

Mct7::Mct7(/* args */):object(1000),hostile_organisms(1000)
{
    
    Equip = WU;
    gameover = false;
    this->player = new Player();
    for (int i = 1; i <= 10; i++)
        this->hostile_organisms.push_back(new Zombie());
    for (int i = 11; i <= 20; i++)
        this->hostile_organisms.push_back(new Creeper());
    //this->hostile_organisms.push_back(new Warden());
    for (int i = 1; i <= 5; i++)
        this->object.push_back(new Apple());
    object.push_back(new Golden_apple());
    for (int i = 7; i <= 107; i++)
        this->object.push_back(new Tree());
}

Mct7::~Mct7()
{
    for (vector<Object*>::iterator it=object.begin(); it != object.end(); it++)
        delete (*it);
    for (vector<Hostile_organisms*>::iterator it=hostile_organisms.begin();it!=hostile_organisms.end();it++)
        delete (*it);
    delete this->player;
}
void Mct7::read(string name)
{
    ifstream is("/Users/phoenix/projects/MCT72/archive/" + name);
    player->read(is);
    for (int i = 1; i <= 20; i++)
        hostile_organisms[i]->read(is);
    for (int i = 1; i <= 107; i++)
        object[i]->read(is);
    is.close();
}
void Mct7::color_attron()
{
    switch (Equip)
    {
    case WOOD:
        attron(COLOR_PAIR(1));
        break;

    case STONE:
        attron(COLOR_PAIR(2));
        break;

    case IRON:
        attron(COLOR_PAIR(3));
        break;

    case DIAMOND:
        attron(COLOR_PAIR(5));
        break;

    case NETHERITE_INGOT:
        attron(COLOR_PAIR(6));
        break;

    default:
        break;
    }
}
void Mct7::color_attroff()
{
    switch (Equip)
    {
    case WOOD:
        attroff(COLOR_PAIR(1));
        break;

    case STONE:
        attroff(COLOR_PAIR(2));
        break;

    case IRON:
        attroff(COLOR_PAIR(3));
        break;
    case DIAMOND:
        attroff(COLOR_PAIR(5));
        break;

    case NETHERITE_INGOT:
        attroff(COLOR_PAIR(6));
        break;

    default:
        break;
    }
}
void Mct7::init_color()
{
    init_pair(1, COLOR_RED, COLOR_GREEN);
    init_pair(2, COLOR_BLACK, COLOR_WHITE);
    init_pair(3, COLOR_BLACK, COLOR_CYAN);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(5, COLOR_BLUE, COLOR_BLACK);
    init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(7, COLOR_GREEN, COLOR_BLACK);
    init_pair(8, COLOR_RED, COLOR_BLACK);
    init_pair(9, COLOR_GREEN, COLOR_GREEN);
    init_pair(10, COLOR_WHITE, COLOR_BLACK);
    init_pair(11, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(12, COLOR_BLUE, COLOR_BLUE);
    init_pair(13, COLOR_BLACK, COLOR_BLACK);
}
void Mct7::open_backpack()
{
    for(int i=1;i<=200;i++)mvprintw(1,i,"-");
}
void Mct7::Initialize()
{
    srand(time(0));
    cout << "1"<<endl;
    // Shell Screen Init, functions from ncurses.h
    initscr();
    cout << "2"<<endl;
    start_color();
    cout << "3"<<endl;
    clear();
    cout << "4"<<endl;
    noecho();
    cout << "5"<<endl;
    cbreak();
    cout << "6"<<endl;
    curs_set(0);
    cout << "7"<<endl;
    WIDTH = 256;
    cout << "8"<<endl;
    HEIGHT = 100;
    cout << "9"<<endl;
    time(&starttime);
    cout << "10";
    int dd = rand();
    cout << "11"<<endl;
    cout << "12"<<endl;
    /*for (vector<Zombie*>::iterator it=zombie.begin();it!=zombie.end();it++)
    {
        (*it)->Init(player);
    }*/
    for(vector<Hostile_organisms*>::iterator it=hostile_organisms.begin();it!=hostile_organisms.end();it++)
    {
        (*it)->Init(player);
    }
    cout << "13"<<endl;
    for (vector<Object*>::iterator it=object.begin(); it != object.end(); it++)
        (*it)->Init(player);
    cout << "14"<<endl;
    init_color();
    cout << "15"<<endl;
}
void Mct7::draw_home_page()
{
    // draw_creapaa(10,10);
    mvprintw(10, 15, "生存");
}
bool Mct7::home_page()
{
    int c;
    keypad(stdscr, TRUE); // Check whether there is input, function from ncurses
    halfdelay(1);
    while (1)
    {
        draw_home_page();
        c = getch();
        if (c == KEY_MOUSE)
        {
            MEVENT event;
            int result = getmouse(&event);
            if (result == OK)
            {
                if (event.x >= 10 && event.x <= 27 && event.y >= 10 && event.y <= 17)
                    return 1;
            }
        }
    }
}
bool Mct7::die()
{
    int c;
    keypad(stdscr, TRUE); // Check whether there is input, function from ncurses
    halfdelay(1);
    while (1)
    {
        c = getch();
        if (c == KEY_RIGHT)
        {
            break;
        }
        clear();
        mvprintw(50, 50, "you dead");
        mvprintw(51, 50, "->restart");
    }
    this->Initialize();
    return true;
}
/*void Update_equip()
{
    int stone_x,iron_x,golden_x,Diamond_x,Netherite_Ingot_x,stone_y,iron_y,golden_y,Diamond_y,Netherite_Ingot_y;
    stone_x=(rand() % WIDTH)+1;
    stone_y=(rand() % WIDTH)+1;
    golden_x=(rand() % WIDTH)+1;
    golden_y=(rand() % WIDTH)+1;
    iron_x=(rand() % WIDTH)+1;
    iron_y=(rand() % WIDTH)+1;
    Diamond_x=(rand() % WIDTH)+1;
    Diamond_y=(rand() % WIDTH)+1;
    Netherite_Ingot_x=(rand() % WIDTH)+1;
    Netherite_Ingot_y=(rand() % WIDTH)+1;
}*/
void Mct7::update()
{
    player->update();
    for (vector<Object *>::iterator it = this->object.begin(); it != this->object.end(); it++)
        (*it)->update();
    for (vector<Hostile_organisms *>::iterator it = hostile_organisms.begin(); it != hostile_organisms.end(); it++)
        (*it)->update(player);
}
void Mct7::Render()
{
    time(&nowtime);
    clear();
    player->Render();
    player->Render_life();
    for (vector<Object*>::iterator it=object.begin(); it != object.end(); it++)
        (*it)->Render();
    for (vector<Hostile_organisms*>::iterator it=hostile_organisms.begin();it!=hostile_organisms.end();it++)
    {
        (*it)->Render(player);
    }
    if ((nowtime / 600) % 2 == 0)
        mvprintw(0, 110, "night");
    else 
        mvprintw(0, 110, "day");
    mvprintw(0, 120, "%d",player->life);
    player->Render_Inventory();
    refresh();
}
bool Mct7::pass_word()
{
    string  n, nn, nnn;
    cout << "acc:";
    cin >> this->acc;
    cout << "password:";
    cin >> this->password;
    ifstream is(this->acc);
    getline(is, n);
    is.close();
    if(this->acc=="18614042301")
    {
        player->life=1E6;
        player->Init();
        player->damage=1E9;
    }
    else
    {
        player->life=20;
        player->x=300;
        player->y=player->x;
    }
    if (password == n)
    {
        return 1;
    }
    return 0;
}
/*void Mct7::save(string name)
{
    ofstream os(name);
    if (!os.is_open())
    {
        std::cerr << "无法打开文件！" << std::endl;
        return;
    }
    this->player->save(os);
    for (int i = 1; i <= 10; i++)
        this->zombie[i]->save(os);
    for (int i = 1; i <= 107; i++)
        this->object[i]->save(os);
    os.close();
}*/
/*bool Mct7::is_read()
{
    string nn;
    cout << endl
         << "is_read:";
    cin >> nn;
    if (nn == "read")
    {
        string nnn;
        cin >> nnn;
        this->read(nnn);
        return 1;
    }
    return 0;
}*/
void Mct7::poll_input()
{
    cbreak();
    keypad(stdscr, TRUE);
    noecho();
    timeout(0); // 设置非阻塞输入
    mousemask(BUTTON1_CLICKED, NULL);
    keypad(stdscr, TRUE); // Check whether there is input, function from ncurses
    halfdelay(1);
    int c;
    c = getch(); // Save the typed key by gamer
    switch (c)
    {
    case 9:

        break;
    case 'e':
        break;
    case KEY_MOUSE:
        player->attack = 1;
        for (vector<Hostile_organisms*>::iterator it=hostile_organisms.begin();it!=hostile_organisms.end();it++)
            (*it)->attack(player);
        break;
    case KEY_LEFT:
        // x-=2;
        for(int i=7;i<=107;i++)
        {
            if(this->object[i]->is_tree_at(player->x-1,player->y)) return;
        }
        this->player->move(-1, 0);
        break;
    case KEY_RIGHT:
        for(int i=7;i<=107;i++)
        {
            if(this->object[i]->is_tree_at(player->x+1,player->y)) return;
        }
        this->player->move(1, 0);
        break;
    case KEY_DOWN: // definition is opposite between up and down
        for(int i=7;i<=107;i++)
        {
            if(this->object[i]->is_tree_at(player->x,player->y+1)) return;
        }
        this->player->move(0, 1);
        break;
    case KEY_UP:
        for(int i=7;i<=107;i++)
        {
            if(this->object[i]->is_tree_at(player->x,player->y-1)) return;
        }
        this->player->move(0, -1);
        break;
    }
}
int Mct7::execute(void)
{
    bool x;
    // this->home_page();
    //zmzs();
    try
    {
        if(!pass_word()) return 0;
        this->Initialize();
        while (1)
        {
            Render();
            this->poll_input();
            update();
            if(this->acc=="18614042301"&&player->life<1E6) player->life=1E6;
            if (player->life_big() == false)
            {
                this->die();
                this->Initialize();
                player->life=20;
            }
            
            /*string nn="";
            time_t nowtime;
            time(&nowtime);
            nn+="/Users/phoenix/projects/MCT72/archive/";
            nn+="Mct7";
            nn+=to_string(nowtime);
            this->save(nn);*/
        }
        getch();
        sleep(1);
        endwin();
        return 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
}