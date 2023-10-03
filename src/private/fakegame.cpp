
#include "../public/fakegame.h"
#include "../public/globalappstate.h"



void FakeGame::handleInput(InputAction action){
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
            case ChangeMenuAction:
                GlobalAppState::getGlobalAppState()->SetView(MainMenuContext);
                break;

            default:
                printf("unknown action playercontroller \n");
                break;
        }

    }

