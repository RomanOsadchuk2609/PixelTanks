#include "Game.h"

Game::Game()
{
    tank1.setX(850);
    tank1.setY(300);

    tank2.setX(100);
    tank2.setY(300);

    Shot s1(tank1.getX(),tank1.getY(),2);
    Shot s2(tank2.getX(),tank2.getY(),4);
    shot1 = s1;
    shot2 = s2;
    shot1.setPicture("res/snariad2.png");
    shot2.setPicture("res/snariad2.png");
}

Game::~Game()
{
    //dtor
}
