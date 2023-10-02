#pragma once

#include "./drawable.h"
#include <vector>



using namespace std;

// contains all the things we want to draw on the screen
class View{
    protected:
    vector<Drawable*> drawableList;

    public:

    //adds drawable to drawables list
    //View takes controll of the drawable and will destroy it when deconstructed
    void AddDrawable(Drawable* drawable);

    //draws all drawables
    virtual void DrawDrawables();

    //delete all drawables
    ~View();

};




