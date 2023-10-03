

#include "./ui/view.h"

#include "./ui/button.h"
#include "./public/globalappstate.h"

#include "input/input.h"
#include "input/menu.h"
#include "raylib.h"
#include "./public/fakegame.h"
#include <cstdio>
#include <streambuf>





int main(void) {

    InitWindow(800, 450, "raylib [core] example - basic window");

    GlobalAppState * globalAppState = GlobalAppState::getGlobalAppState();


    while (!WindowShouldClose()) {

        //handles inputs and gives them to the propper controller
        globalAppState->inputController.HandleInputs();


        BeginDrawing();

        globalAppState->currentlyDrawnView->DrawDrawables();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
