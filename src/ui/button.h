#pragma once


#include "./drawable.h"
#include <raylib.h>
#include <string>
#include "../utils/macros.h"
using namespace std;




class Button : public Drawable{

    //_ only so we can use same name in constructor
    Vector2 _cordinate;
    Vector2 _size;
    std::string _label;
    int labelFontSize=12;
    void (*func)();

    public:
    //construct button
    Button(u32 x,u32 y, u32 w, u32 h, string label, void(*function)());

    Button(Vector2 cords, Vector2 size, string label, void(*function)());

    Button(Vector2 cords, u32 w, u32 h, string label, void(*function)());



    //draw button
    void draw() override;

    Vector2 GetPosition(){
        return _cordinate;
    };

    //get centerpoint of rect
    Vector2 GetCenter(){
        return Vector2{_cordinate.x+(_size.x/2),_cordinate.y+(_size.y/2)};
    }


    //button has been clicked
    //how fuck do we do this one
    //do we have function pointer to what we want to happen
    void ClickEvent();


};



