#ifndef APPLE_OBJECT_H
#define APPLE_OBJECT_H
#include"player.hpp"
#include"object.hpp"

class Apple : public Object
{
private:
    
public:
    void Render();
    void update();
};
#endif