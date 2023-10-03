

#include "menu.h"
#include "../public/globalappstate.h"


void Menu::handleInput(InputAction action){
        printf("menucontroller action %i\n",action);
        switch (action) {

            case MoveUpAction:
                MoveCursor(0, -1);
                break;

            case MoveDownAction:
                MoveCursor(0, 1);
                break;

            case MoveLeftAction:
                MoveCursor(-1, 0);
                break;

            case MoveRightAction:
                MoveCursor(1, 0);
                break;

            case InteractAction:
                Interact();
                break;

            case ChangeMenuAction:
                GlobalAppState::getGlobalAppState()->SetView(GameContext);
                break;

            default:
                printf("unknown key from menucontroller \n");
                break;
        
        }

    }
