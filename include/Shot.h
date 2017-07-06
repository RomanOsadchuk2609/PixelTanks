#ifndef SHOT_H
#define SHOT_H
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "Tank.h"
#include "Tank1.h"
#include "Tank2.h"
using namespace sf;
using namespace std;

class Shot
{
    public:
        Shot();
        Shot(double x, double y, int course);
        virtual ~Shot();
        void setPicture(string file);
        double getX() const;
        void setX(int x);
        double getY() const;
        void setY(int y);
        void Move(float t);
        Sprite getSprite();
        RectangleShape getRect();
        bool isOnTank(Tank tank);
        void isOnBlock(string Map[11]);
        bool isCanDoDamage();
        void setCanDoDamage(bool value);
        bool isCanMove();
        void setCanMove(bool value);

    protected:

    private:
        RectangleShape rect;
        Texture texture;
        Sprite sprite;
        bool isShot;
        double speed;
        double x;
        double y;
        int course;
        bool canDoDamage;
        bool canMove;
};

#endif // SHOT_H
