#ifndef TANK_H
#define TANK_H
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <ctime>
using namespace sf;
using namespace std;

class Tank
{
    public:
        Tank();
        virtual ~Tank();
        double getSpeed() const;
        void setSpeed(int speed);
        void setPicture(string file);
        virtual void Move(float t, string Map[11]);
        void MoveUP(float t, string Map[11]);
        void MoveDown(float t, string Map[11]);
        void MoveLeft(float t, string Map[11]);
        void MoveRight(float t, string Map[11]);
        Sprite getSprite();
        void shot();
        double getX() const;
        void setX(int x);
        double getY() const;
        void setY(int y);
        int getPosition();
        void setPosition(int tankPosition);
        bool isReadyToShot();
        void setReadyToShot(bool value);
        float getTime();
        void setTime(float time);
        int getHP();
        void downgradeHP();
        bool isDamaged();
    protected:

    private:
        Texture texture;
        Texture snariad1;
        Sprite snariad2;
        Sprite sprite;
        float time;
        bool readyToShot;
        int tankPosition;
        double speed;
        double x;
        double y;
        int hp;
        //Shot shot;
        bool Damaged;
};

#endif // TANK_H
