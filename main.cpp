#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include <ctime>
#include "Tank1.h"
#include "Tank2.h"
#include "Tank.h"
#include "Shot.h"

using namespace sf;
using namespace std;

int main()
{
    string Map[11]
    {
        "ZZZZZZZZZZZZZZZZZZZZ",
        "Z KK KZKK  KKZK KK Z",
        "ZZZK K  KZZK  K KZZZ",
        "ZKKKKKKKKKKKKKKKKKKZ",
        "Z   K   ZKKZ   K   Z",
        "Z   KZKKZZZZKKZK   Z",
        "Z   K   ZKKZ   K   Z",
        "ZKKKKKKKKKKKKKKKKKKZ",
        "ZZZK K  KZZK  K KZZZ",
        "Z KK KZKK  KKZK KK Z",
        "ZZZZZZZZZZZZZZZZZZZZ"
    };
    /*string Map[11]
    {
        "ZZZZZZZZZZZZZZZZZZZZ",
        "Z        KK        Z",
        "Z        KK        Z",
        "Z      K KK K      Z",
        "Z        ZZ        Z",
        "Z        ZZ        Z",
        "Z        ZZ        Z",
        "Z   K    KK    K   Z",
        "Z        KK        Z",
        "Z        KK        Z",
        "ZZZZZZZZZZZZZZZZZZZZ"
    };*/
    Texture textureK;
    textureK.loadFromFile("res/K.png");
    Texture textureZ;
    textureZ.loadFromFile("res/Z.png");

    Sprite spriteK;
    spriteK.setTexture(textureK);
    Sprite spriteZ;
    spriteZ.setTexture(textureZ);

    RenderWindow window(VideoMode(1000, 600), "Pixel Tanks");
    Image image;
    image.loadFromFile("res/Tank1.png");
    window.setIcon(50,50,image.getPixelsPtr());
    Texture infoTexture;
    infoTexture.loadFromFile("res/info.png");
    Sprite infoSprite;
    infoSprite.setTexture(infoTexture);
    infoSprite.setPosition(0,0);

    RectangleShape reload1(Vector2f(60,10));
    reload1.setPosition(723,35);
    reload1.setFillColor(Color::Red);

    RectangleShape reload2(Vector2f(60,10));
    reload2.setPosition(225,35);
    reload2.setFillColor(Color::Red);

    Tank1 tank1;
    Tank2 tank2;
    tank1.setX(850);
    tank1.setY(300);

    tank2.setX(100);
    tank2.setY(300);

    tank1.setPosition(2);
    tank2.setPosition(4);
    vector<Shot> shot;
    Shot shot1(tank1.getX(),tank1.getY(),tank1.getPosition());
    Shot shot2(tank2.getX(),tank2.getY(),tank2.getPosition());
    shot1.setPicture("res/snariad2.png");
    shot2.setPicture("res/snariad2.png");
    Clock clock;
    Clock clock1;
    Clock clock2;
    tank1.setTime(clock1.getElapsedTime().asSeconds());
    tank2.setTime(clock2.getElapsedTime().asSeconds());
    float time;
    while (window.isOpen())
    {
        /*if(clock1.getElapsedTime().asSeconds()>=3)
        {
            shot1.setCanDoDamage(true);
            shot2.setCanDoDamage(true);
        }*/
        float t = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        t/=600;
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        tank1.Move(t, Map);
        tank2.Move(t, Map);

        //if(Mouse::isButtonPressed(Mouse::Left))
        if(Keyboard::isKeyPressed(Keyboard::P))
        {
            if(tank1.isReadyToShot() && !tank1.isDamaged())
            {
                Shot temp1(tank1.getX(),tank1.getY(),tank1.getPosition());
                shot1 = temp1;
                shot1.setPicture("res/snariad.png");
                tank1.setReadyToShot(false);
                tank1.setTime(clock1.getElapsedTime().asSeconds());
            }
        }
        if(tank1.isReadyToShot())
        {
            RectangleShape temp(Vector2f(60,10));
            temp.setPosition(723,35);
            temp.setFillColor(Color::Red);
            reload1 = temp;
        }
        else if((clock1.getElapsedTime().asSeconds()-tank1.getTime())>=3 )
        {
            tank1.setTime(clock1.getElapsedTime().asSeconds());
            tank1.setReadyToShot(true);
        }
        else
        {
           float a = (clock1.getElapsedTime().asSeconds()-tank1.getTime())*20;
            RectangleShape temp(Vector2f(a,10));
            temp.setPosition(723+60-a,35);
            temp.setFillColor(Color::Red);
            reload1 = temp;
        }
        if(Keyboard::isKeyPressed(Keyboard::Space))
        {
            if(tank2.isReadyToShot() && !tank2.isDamaged())
            {
                Shot temp2(tank2.getX(),tank2.getY(),tank2.getPosition());
                shot2 = temp2;
                shot2.setPicture("res/snariad.png");
                tank2.setReadyToShot(false);
                tank2.setTime(clock2.getElapsedTime().asSeconds());
            }
        }
        if((clock2.getElapsedTime().asSeconds()-tank2.getTime())>=3 )
        {
            tank2.setTime(clock2.getElapsedTime().asSeconds());
            tank2.setReadyToShot(true);
        }
        if(tank2.isReadyToShot())
        {
            RectangleShape temp(Vector2f(60,10));
            temp.setPosition(225,35);
            temp.setFillColor(Color::Red);
            reload2 = temp;
        }
        else
        {
            float a = (clock2.getElapsedTime().asSeconds()-tank2.getTime())*20;
            RectangleShape temp(Vector2f(a,10));
            temp.setPosition(225,35);
            temp.setFillColor(Color::Red);
            reload2 = temp;
        }

        shot1.isOnBlock(Map);
        shot2.isOnBlock(Map);
        if(shot1.isOnTank(tank2))
        {
            tank2.downgradeHP();
        }
        if(shot2.isOnTank(tank1))
        {
            tank1.downgradeHP();
        }
        if(shot1.isCanMove())
            shot1.Move(t);

        if(shot2.isCanMove())
            shot2.Move(t);
        window.clear(Color::Black);
        window.draw(shot1.getSprite());
        window.draw(shot2.getSprite());
        for(int i=0; i<11; i++)
        {
            for(int j=0; j<20; j++)
            {
                if(Map[i][j]=='Z')
                {
                    spriteZ.setPosition(j*50,i*50+50);
                    window.draw(spriteZ);
                }
                else if(Map[i][j]=='K')
                {
                    spriteK.setPosition(j*50,i*50+50);
                    window.draw(spriteK);
                }
                else continue;
            }
        }
        RectangleShape hp1(Vector2f(tank1.getHP(),10));
        hp1.setPosition(802+50-tank1.getHP(),35);
        hp1.setFillColor(Color::Green);

        RectangleShape hp2(Vector2f(tank2.getHP(),10));
        hp2.setPosition(156,35);
        hp2.setFillColor(Color::Green);

        window.draw(infoSprite);
        window.draw(reload1);
        window.draw(reload2);
        window.draw(hp1);
        window.draw(hp2);
        window.draw(tank1.getSprite());
        window.draw(tank2.getSprite());

        window.display();
    }

    return 0;
}

