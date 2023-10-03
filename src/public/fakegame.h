#pragma once

#include "../ui/drawable.h"
#include <cstdio>
#include <raylib.h>
#include "../input/input.h"

class FakeGame : public Drawable, public  InputPawn{

    public:

    void draw() override{
        ClearBackground(RAYWHITE);
        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
    }

    void handleInput(InputAction action)override;


};
