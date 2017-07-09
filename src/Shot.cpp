#include "Shot.h"
#include "Tank1.h"
#include "Tank2.h"
#include "Tank.h"
#include <SFML/Graphics.hpp>
#include <Windows.h>
using namespace sf;
using namespace std;
Shot::Shot()
{
    texture.loadFromFile("res/snariad.png");
    sprite.setTexture(texture);
    //speed = 0.7;
    speed = 0.05;
}

Shot::Shot(double x, double y, int course)
{

    this->course=course;

    if(course == 1)
    {
        this->x=x+15;
        this->y=y;
    }
    if(course == 2)
    {
        this->x=x+40;
        this->y=y+15;
    }
    if(course == 3)
    {
        this->x=x+15;
        this->y=y+40;
    }
    if(course ==4)
    {
        this->x=x;
        this->y=y+15;
    }
    texture.loadFromFile("res/snariad.png");
    sprite.setTexture(texture);
    sprite.setPosition(this->x,this->y);
    rect=RectangleShape(Vector2f(10,10));
    rect.setPosition(this->x,this->y);
    rect.setFillColor(Color::Red);
    canDoDamage = true;
    canMove = true;
    speed = 0.7;
    //speed = 0.05;
}

Shot::~Shot()
{
    //dtor
}


double Shot::getX() const {
    return x;
}

void Shot::setX(int x) {
    Shot::x = x;
}

double Shot::getY() const {
    return y;
}

void Shot::setY(int y) {
    Shot::y = y;
}

void Shot::setPicture(string file)
{
    texture.loadFromFile(file);
    sprite.setTexture(texture);
}
Sprite Shot::getSprite()
{
    return sprite;
}
RectangleShape Shot::getRect()
{
    return rect;
}
void Shot::Move(float t)
{
    if(canMove)
    {
        switch(course)
        {
            case 1:
                {

                    rect.move(0,-speed*2*t);
                    sprite.move(0,-speed*t);
                    y-=speed;
                    break;
                }
            case 2:
                {
                    sprite.move(speed*t,0);
                    rect.move(speed*t,0);
                    x+=speed;
                    break;

                }
            case 3:
                {
                    sprite.move(0,speed*t);
                    rect.move(0,speed*t);
                    y+=speed;
                    break;
                }
            case 4:
                {
                    sprite.move(-speed*t,0);
                    rect.move(-speed*t,0);
                    x-=speed;
                    break;
                }
        }
    }
    else return;
}
bool Shot::isCanDoDamage()
{
    return canDoDamage;
}

void Shot::setCanDoDamage(bool value)
{
    canDoDamage = value;
}

bool Shot::isOnTank(Tank tank)
{
    if(y+5>=(tank.getY()) && y+5<=(tank.getY()+50) && x+5>=tank.getX() && x+5<=(tank.getX()+50) && isCanDoDamage())
    {
        speed = 0;
        canMove=false;
        setPicture("res/snariad3.png");
        canDoDamage = false;
        return true;
    }
    else return false;
}

void Shot::setCanMove(bool value)
{
    canMove=value;
}
bool Shot::isCanMove()
{
    return canMove;
}
void Shot::isOnBlock(string Map[11])
{
    for(int i=0; i<11; i++)
        {
            for(int j=0; j<20; j++)
            {
                if(Map[i][j]=='K')
                {
                    if(x+5>j*50 && x+5<(j*50+50) && y +5>(i*50+50) && y+5<(i*50+50+50) && isCanDoDamage())
                    {
                        Map[i][j]=' ';
                        speed = 0;
                        canMove=false;
                        setPicture("res/snariad3.png");
                        canDoDamage = false;
                        return ;
                    }
                }
                else if(Map[i][j]=='Z')
                {
                    if(x+5>j*50 && x+5<(j*50+50) && y+5 >(i*50+50) && y+5<(i*50+50+50) && isCanDoDamage())
                    {
                        speed = 0;
                        canMove=false;
                        setPicture("res/snariad3.png");
                        canDoDamage = false;
                        return;
                    }
                }
            }
        }
        return;
}
