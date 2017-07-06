#include "Tank2.h"
#include "Tank.h"
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <ctime>
#include <Windows.h>
#include "Shot.h"
using namespace std;
Tank2::Tank2()
{
    Tank();
}

Tank2::~Tank2()
{
    //dtor
}
void Tank2::Move(float t, string Map[11])
{
    if(Keyboard::isKeyPressed(Keyboard::D))
    {
        MoveRight(t,Map);
    }
    else if(Keyboard::isKeyPressed(Keyboard::A))
    {
        MoveLeft(t,Map);
    }
    else if(Keyboard::isKeyPressed(Keyboard::W))
    {
        MoveUP(t,Map);
    }
    else if(Keyboard::isKeyPressed(Keyboard::S))
    {
        MoveDown(t,Map);
    }
}
