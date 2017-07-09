#ifndef GAME_H
#define GAME_H

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
#include "TButton.h"

using namespace sf;
using namespace std;


class Game
{
    public:
        Game();
        virtual ~Game();

///***************************************************************************
        Tank1 tank1;
        Tank2 tank2;
        Shot shot1;
        Shot shot2;
        /*TButton Map1;
        TButton Map2;
        TButton Map3;*/

    protected:

    private:
};

#endif // GAME_H
