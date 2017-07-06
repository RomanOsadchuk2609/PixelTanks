#ifndef TANK2_H
#define TANK2_H
#include "Tank.h"
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <ctime>
#include <Windows.h>
#include "Shot.h"
class Tank2: public Tank
{
    public:
        Tank2();
        virtual ~Tank2();
        void Move(float t, string Map[11], Tank tank2);

    protected:

    private:
};

#endif // TANK2_H
