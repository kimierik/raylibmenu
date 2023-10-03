#pragma once



#include "../ui/button.h"
#include "../ui/view.h"
#include <map>
#include <raylib.h>
#include <utility>
#include <stdio.h>
#include <vector>
#include <tuple>


//null is invalid action
//this should not be given to any pawns
enum InputAction{
    NullAction,

    MoveUpAction,
    MoveDownAction,
    MoveLeftAction,
    MoveRightAction,
    InteractAction,
    ChangeMenuAction,
};










// inputs are redirected to this
class InputPawn {
    public:
    virtual void handleInput(InputAction action) {}
};




class InputController{ 
    //takes inputs and does magic
    InputPawn* _pawn;
    //also has the keymap
    //key and action
    std::map<int, int> keyMap;
    

    public:

    void InitialiseMap(){
        keyMap.insert(std::pair<int, int>(KEY_A,MoveLeftAction));
        keyMap.insert(std::pair<int, int>(KEY_D,MoveRightAction));
        keyMap.insert(std::pair<int, int>(KEY_W,MoveUpAction));
        keyMap.insert(std::pair<int, int>(KEY_S,MoveDownAction));
        keyMap.insert(std::pair<int, int>(KEY_E,InteractAction));
        keyMap.insert(std::pair<int, int>(KEY_X,ChangeMenuAction));
    }

    void HandleInputs(){
        int key= GetKeyPressed();
        if (key!=0){
            InputAction action = static_cast<InputAction>(keyMap.find(key)->second);
            printf("%i:%i\n",key,action);
            if (action!=0){
                _pawn->handleInput(action);
            }
        }
    }

    //sets pawn does not take controll of pawn
    void SetPawn(InputPawn* pawn){
        _pawn=pawn;
    }

    //take inputs make them into actions
    //send actions to pawn
};










