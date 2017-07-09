#include "Tank.h"
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <ctime>
#include <Windows.h>
#include "Shot.h"
using namespace sf;
using namespace std;
Tank::Tank()
{
    speed = 0.3;
    texture.loadFromFile("res/Tank1.png");
    sprite.setTexture(texture);
    x=485;
    y=275;
    sprite.setPosition(x,y);
    tankPosition = 1;
    time = clock();
    readyToShot = false;
    hp = 50;
    Damaged = false;
}

Tank::~Tank()
{
    //dtor
}
double Tank::getSpeed() const {
    return speed;
}

double Tank::getX() const {
    return x;
}

void Tank::setX(int x) {
    this-> x = x;
    sprite.setPosition(this->x,this->y);
}

double Tank::getY() const {
    return y;
}

void Tank::setY(int y) {
    this-> y = y;
    sprite.setPosition(this->x,this->y);
}


void Tank::setSpeed(int speed) {
    Tank::speed = speed;
}
void Tank::setPicture(string file)
{
    Texture texture2;
    Sprite sprite2;
    texture2.loadFromFile(file);
    sprite2.setTexture(texture);
    sprite2.setPosition(x,y);
    texture = texture2;
    sprite = sprite2;
}

Sprite Tank::getSprite()
{
    return sprite;
}

void Tank::setPosition(int tankPosition)
{
    this->tankPosition = tankPosition;
}

int Tank::getPosition()
{
    return tankPosition;
}

void Tank::MoveUP(float t,string Map[11], Tank tank2)
{
    bool f=true;
    for(int i=0; i<11; i++)
    {
        for(int j=0; j<20; j++)
        {
            if(Map[i][j]=='K'||Map[i][j]=='Z')
            {
                int a=j*50, b=i*50+50;
               if(y<b+50-2 && y>b+2 && x>(a-40+2) && x<(a+50-2))
               {
                   y=b+51;
                   f=false;
                   break;
               }
            }
        }
        if(!f) break;
    }
    if(y<tank2.y+40-2 && y>tank2.y+2 && x>tank2.x-40+2 && x<tank2.x+40-2)
    {
        f=false;
        y=tank2.y+41;
    }
    if(!Damaged&&f)
    {
        if(y>50)
        {
            if(tankPosition==1)
            {
                sprite.move(0, -speed*t);
                y-=speed;
                setPicture("res/Tank1.png");
                tankPosition=1;
            }
            else
            {
                setPicture("res/Tank1.png");
                tankPosition=1;
            }
        }
    }
    else return;
}

void Tank::MoveDown(float t,string Map[11], Tank tank2)
{
    bool f=true;
    for(int i=0; i<11; i++)
    {
        for(int j=0; j<20; j++)
        {
            if(Map[i][j]=='K'||Map[i][j]=='Z')
            {
                int a=j*50, b=i*50+50;
                if(y<b-2 && y>b-40+2 && x>(a-40+2) && x<(a+50-2))
                {
                    y=b-41;
                    f=false;
                    break;
                }
            }
        }
        if(!f) break;
    }
    if(y<(tank2.y-2) && y>(tank2.y-40+2) && x>tank2.x-40+2 && x<(tank2.x+40-2) )
    {
        f=false;
        y=tank2.y-41;
    }
    if(!Damaged && f)
    {
        if(y<560)
        {
            if(tankPosition==3)
            {
                sprite.move(0, speed*t);
                y+=speed;
                setPicture("res/Tank3.png");
                tankPosition=3;
            }
            {
                setPicture("res/Tank3.png");
                tankPosition=3;
            }
        }
    }
    else return;

}

void Tank::MoveRight(float t,string Map[11], Tank tank2)
{
    bool f=true;
    for(int i=0; i<11; i++)
    {
        for(int j=0; j<20; j++)
        {
            if(Map[i][j]=='K'||Map[i][j]=='Z')
            {
                int a=j*50, b=i*50+50;
               if(y<b+50-2 && y>b-40+2 && x>(a-40+2) && x<a-2)
               {
                   x=a-41;
                   f=false;
                   break;
               }
            }
        }
        if(!f) break;
    }
    if(y<tank2.y+40-2 && y>tank2.y-40+2 && x>tank2.x-40+2 && x<tank2.x-2)
    {
        f=false;
        x=tank2.x-41;
    }
    if(!Damaged && f)
    {
        if(x<960)
        {
            if(tankPosition==2)
            {
                sprite.move(speed*t, 0);
                x+=speed;
                setPicture("res/Tank2.png");
                tankPosition=2;
            }
            else
            {
                setPicture("res/Tank2.png");
                tankPosition=2;
            }
        }
    }
    else return;
}

void Tank::MoveLeft(float t,string Map[11], Tank tank2)
{
    bool f=true;
    for(int i=0; i<11; i++)
    {
        for(int j=0; j<20; j++)
        {
            if(Map[i][j]=='K'||Map[i][j]=='Z')
            {
                int a=j*50, b=i*50+50;
               if(y<b+50-2 && y>b-40+2 && x>a+2 && x<(a+50-2))
               {
                   x=a+51;
                   f=false;
                   break;
               }
            }
        }
        if(!f) break;
    }
    if(y<tank2.y+40-2 && y>tank2.y-40+2 && x>tank2.x+2 && x<tank2.x+40-2)
    {
        f=false;
        x=tank2.x+41;
    }
    if(!Damaged && f)
    {
        if(x>0)
        {

            if(tankPosition==4)
            {
                sprite.move(-speed*t, 0);
                x-=speed;
                setPicture("res/Tank4.png");
                tankPosition=4;
            }
            else
            {
                setPicture("res/Tank4.png");
                tankPosition=4;
            }
        }
    }
    else return;
}

void Tank::Move(float t,string Map[11], Tank tank2)
{
    if(Keyboard::isKeyPressed(Keyboard::Right)||Keyboard::isKeyPressed(Keyboard::D))
    {
        MoveRight(t,Map,tank2);
    }
    else if(Keyboard::isKeyPressed(Keyboard::Left)||Keyboard::isKeyPressed(Keyboard::A))
    {
        MoveLeft(t,Map,tank2);
    }
    else if(Keyboard::isKeyPressed(Keyboard::Up)||Keyboard::isKeyPressed(Keyboard::W))
    {
        MoveUP(t,Map,tank2);
    }
    else if(Keyboard::isKeyPressed(Keyboard::Down)||Keyboard::isKeyPressed(Keyboard::S))
    {
        MoveDown(t,Map,tank2);
    }
}

bool Tank::isReadyToShot()
{
    return readyToShot;
}

void Tank::setReadyToShot(bool value)
{
    readyToShot = value;
}

void Tank::setTime(float time)
{
    this->time = time;
}
float Tank::getTime()
{
    return time;
}

int Tank::getHP()
{
    return hp;
}
void Tank::downgradeHP()
{
    if(hp>0)
        hp-=10;
    if(hp<=0) Damaged = true;
}

bool Tank::isDamaged()
{
    return Damaged;
}
