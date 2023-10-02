#pragma once

#include "drawable.h"
#include <cstdio>
#include <raylib.h>
#include "input.h"


class FakeGame : public Drawable, public  InputPawn{

    public:

    void draw() override{
        ClearBackground(RAYWHITE);
        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
    }

    void handleInput(InputAction action)override{
        switch (action) {

            case MoveDownAction:
                printf("down\n");
                break;

            case MoveUpAction:
                printf("up\n");
                break;
                
            case MoveLeftAction:
                printf("left\n");
                break;

            case MoveRightAction:
                printf("rihg\n");
                break;

            default:
                printf("unknown action playercontroller \n");
                break;
        }

    }


};
