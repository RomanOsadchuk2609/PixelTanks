#include "Tank.h"
#include "Tank1.h"
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <ctime>
#include <Windows.h>

Tank1::Tank1()
{
    Tank();
    //ctor
}

Tank1::~Tank1()
{

}
void Tank1::Move(float t, string Map[11])
{
    if(Keyboard::isKeyPressed(Keyboard::Right))
    {
        MoveRight(t,Map);
    }
    else if(Keyboard::isKeyPressed(Keyboard::Left))
    {
        MoveLeft(t,Map);
    }
    else if(Keyboard::isKeyPressed(Keyboard::Up))
    {
        MoveUP(t,Map);
    }
    else if(Keyboard::isKeyPressed(Keyboard::Down))
    {
        MoveDown(t,Map);
    }
}
