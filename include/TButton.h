#ifndef TBUTTON_H
#define TBUTTON_H
#include <SFML/Graphics.hpp>
#include <string>
using namespace sf;
using namespace std;

class TButton
{
    public:
        TButton(string file);
        virtual ~TButton();
        bool isMouseOnButton();
        void MouseOnButton();
        Sprite getSprite();
    protected:

    private:
        Texture texture;
        Sprite sprite;
        int x, y;
        int w,h;
        string file;
};

#endif // TBUTTON_H
