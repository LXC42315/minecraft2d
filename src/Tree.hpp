#ifndef MCT_TREE_
#define MCT_TREE_
#include"object.hpp"
#include"player.hpp"
#include<iostream>
#include<cstring>
using namespace std;
class Tree : public Object
{
private:
    int tree;
    bool is_l;
public:
    Tree();
    ~Tree();
    void Render();
    void Update();
    void save(ofstream& os);
    void read(std::ifstream &is);
    void broke(Player *player);
    void Init(Player* player);
    bool is_tree_at(int x,int y);
};
#endif