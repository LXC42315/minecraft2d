#include <iostream>
#include <vector>  
#include <string>  
#include <chrono>  
#include <thread> 
#include<fstream>
#include <cstdlib>
#include <ncurses.h> // input output
#include <unistd.h>  // sleep functi
#include"Mct_zmzs.hpp"
#define BLUE "\033[35m"
using namespace std;
using namespace this_thread;
using namespace chrono;


void zmzs::exec()
{
    ifstream is("Minecraft_zmzs");
    string s("\033[34m");  
    int n;
    is>>n;
    for(int i=1;i<=220;i++)
    {
        getline(is,s);
        cout<<BLUE<<s<<endl;
        sleep_for(microseconds(450000));
    }
    is.close();
}


zmzs::zmzs(/* args */)
{
}

zmzs::~zmzs()
{
}