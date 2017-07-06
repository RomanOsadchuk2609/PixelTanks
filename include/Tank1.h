#ifndef TANK1_H
#define TANK1_H
#include "Tank.h"
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <ctime>
#include <Windows.h>

class Tank1: public Tank
{
    public:
        Tank1();
        virtual ~Tank1();
        void Move(float t, string Map[11]);

    protected:

    private:
};

#endif // TANK1_H
