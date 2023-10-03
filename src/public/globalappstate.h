#pragma once


#include "../ui/button.h"
#include "../input/input.h"
#include "../input/menu.h"
#include "fakegame.h"






enum AppContext{
    MainMenuContext,
    GameContext,
};



class GlobalAppState{



    



    private:
    FakeGame *game;
    View * gameview;

    Menu* mainMeny;

    public:
    View* currentlyDrawnView;
    InputController inputController;




    //singelton logic
    private:
    static GlobalAppState * instance;
    GlobalAppState(){
        game = new FakeGame;
        gameview= new View;
        mainMeny=new Menu;
        initInputController();

        InitMainMeny();
        gameview->AddDrawable(game);
        currentlyDrawnView=mainMeny;
    }

    public:
    GlobalAppState(const GlobalAppState&ob)=delete;
    static GlobalAppState * getGlobalAppState();
    // end of singelton logic
    
    
    

    private:
    void InitMainMeny(){ //this function should probably be moved out of the GlobalAppState
        mainMeny->AddButton(new Button(50,50,100,100,"thing",nullptr),0,0);
        mainMeny->AddButton(new Button(50,160,100,100,"thing",nullptr),0,1);
        mainMeny->AddButton(new Button(160,50,100,100,"thing",nullptr),1,0);
        mainMeny->AddButton(new Button(160,160,100,100,"thing",nullptr),1,1);
        mainMeny->MoveCursor(0, 0); //when all buttons are added (or atleas 0,0) we need to move cursor to 0,0 so we dont have any nullptr's
    }

    void initInputController(){
        inputController= InputController();
        inputController.InitialiseMap();
        inputController.SetPawn(mainMeny);
    }

    public:


    void SetView(AppContext view){
        switch (view) {
            case MainMenuContext:
                currentlyDrawnView=mainMeny;
                inputController.SetPawn(mainMeny);
                break;

            case GameContext:
                currentlyDrawnView = gameview;
                inputController.SetPawn(game);
                break;
        
        }
    }



};
