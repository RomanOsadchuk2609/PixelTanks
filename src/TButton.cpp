#include "TButton.h"
#include <SFML/Graphics.hpp>
#include <string>
using namespace sf;
using namespace std;

TButton::TButton(string file)
{

    //texture.loadFromFile("res/map1.png");
    this->file=file;
    texture.loadFromFile(file);
    sprite.setTexture(texture);
    x=0;
    y=0;
    w=270;
    h=158;
    sprite.setTextureRect(IntRect(x,y,w,h));
    sprite.setPosition(50,100);
}

TButton::~TButton()
{
    //dtor
}

Sprite TButton::getSprite()
{
    return sprite;
}

bool TButton::isMouseOnButton()
{

    if(Mouse::getPosition().x>=sprite.getPosition().x+10+200 && Mouse::getPosition().x<=sprite.getPosition().x+w-10+200 &&
       Mouse::getPosition().y>=sprite.getPosition().y+80+10 &&Mouse::getPosition().y<=sprite.getPosition().y+h+80-10)
        return true;
    else return false;
}

void TButton::MouseOnButton()
{
    if(isMouseOnButton())
    {
        x=270;
        sprite.setTextureRect(IntRect(x,y,w,h));
    }
    else
    {
        x=0;
        sprite.setTextureRect(IntRect(x,y,w,h));
    }
}
