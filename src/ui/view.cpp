
#include "./view.h"
#include <stdio.h>



void View::AddDrawable(Drawable* drawable){
    drawableList.push_back(drawable);
}

//draws all drawables
void View::DrawDrawables(){
    for (Drawable* i:drawableList){
        i->draw();
    }
}

View::~View(){
    //idk if this works
    for (Drawable* i:drawableList){
        delete i;
    }
}
