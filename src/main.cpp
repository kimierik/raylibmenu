

#include "./public/view.h"

#include "./public/button.h"

#include "public/input.h"
#include "raylib.h"
#include "./public/fakegame.h"
#include <cstdio>
#include <streambuf>

enum GameState{
    MainMenu,
    Game,
    SettingsMenu,
    PauseMenu,
};




void callthing(){
    printf("budd\n");
}



int main(void) {

    InitWindow(800, 450, "raylib [core] example - basic window");

    FakeGame *game=new FakeGame;

    View * gameview= new View;
    gameview->AddDrawable(game);

    //View * mainmenu= new View;
    Menu* mainMeny=new Menu;
    //mainmenu->AddDrawable(new Button(50,50,100,100,"thing",nullptr));
    mainMeny->AddButton(new Button(50,50,100,100,"thing",&callthing),0,0);
    mainMeny->AddButton(new Button(50,160,100,100,"thing",&callthing),0,1);
    mainMeny->AddButton(new Button(160,50,100,100,"thing",&callthing),1,0);
    mainMeny->AddButton(new Button(160,160,100,100,"thing",&callthing),1,1);

    mainMeny->MoveCursor(0, 0); //when all buttons are added (or atleas 0,0) we need to move cursor to 0,0 so we dont have any nullptr's

    //View* currentlyDrawnView=mainmenu;
    View* currentlyDrawnView=mainMeny;


    
    InputController inputController= InputController();
    inputController.InitialiseMap();
    inputController.SetPawn(mainMeny);



    while (!WindowShouldClose()) {

        //handles inputs and gives them to the propper controller
        inputController.HandleInputs();

        //handle inputs and convert them into input actions
        //move this to input controller but where do we get acces to mainMeny and gameview
        if (IsKeyPressed(KEY_X)) {
            currentlyDrawnView=mainMeny;
            inputController.SetPawn(mainMeny);
            printf("menu\n");
        }

        if (IsKeyPressed(KEY_Z)) {
            currentlyDrawnView = gameview;
            inputController.SetPawn(game);
            printf("game\n");
        }



        BeginDrawing();

        currentlyDrawnView->DrawDrawables();


        EndDrawing();
    }

    CloseWindow();

    return 0;
}
