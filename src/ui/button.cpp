

#include "./button.h"
#include <cstdio>
#include <raylib.h>
#include <string>
#include "../utils/macros.h"


using namespace std;


    //construct button
Button::Button(u32 x,u32 y, u32 w, u32 h, string label, void(*function)()){

    //casting hell
    _cordinate=Vector2{ static_cast<float>(x),static_cast<float>(y)};
    _size=Vector2{ static_cast<float>(w),static_cast<float>(h)};
    _label=label;
    func=function;
}

Button::Button(Vector2 cords, Vector2 size, string label, void(*function)()){
    _cordinate=cords;
    _size=size;
    _label=label;
    func=function;
}

Button::Button(Vector2 cords, u32 w, u32 h, string label, void(*function)()){
    _cordinate=cords;
    _size=Vector2{ static_cast<float>(w),static_cast<float>(h)};
    _label=label;
    func=function;
}



//draw button
void Button::draw() {
    Color c =GetColor(0x7a7a7a);
    DrawRectangleV(_cordinate,  _size, c);
    //label centre - half of font widht
    float textw = MeasureText(_label.c_str(), labelFontSize);
    DrawText(_label.c_str(), GetCenter().x-(textw/2), GetCenter().y-( static_cast<float>(labelFontSize)/2), labelFontSize, BLACK); //6 is fontsize/2
}


//button has been clicked
//how fuck do we do this one
//do we have function pointer to what we want to happen
void Button::ClickEvent(){
    func();
}



