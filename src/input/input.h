#pragma once



#include "../ui/button.h"
#include "../ui/view.h"
#include "../utils/debug.c"
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










// we need to be able to draw the cursor itself so we can see anything
// rn we can have it as rec rect that is at the same  position as button
// 
// idk if we can add the rect in the View as last
// or we can if we have the position as pointers not real values
// but that is cringe
// if we render it here then where do we render it
// when do we call the render function
// do we make the DrawDrawables into a virtual and then just rewrite it
// that also sounds cringe
// but probably better?




//does not belong in this file idk where else to put it rn
class Menu : public InputPawn, public View{

    //map with buttons
    map<tuple<int,int>, Button*> buttonmap;

    //legit maybe change to vec2 touples are hard to work with and look really ugly
    tuple<int,int> cursor;

    Button* hoveredButton;

    public:

    Menu(){
        cursor=tuple<int,int>(0,0);
    }


    virtual void Interact(){
        hoveredButton->ClickEvent();
    }// when press interract on button 
                             // virtual so we can do something else in inv then just call function that is on button

    //adds button to the menu. x and y are cordinates to the button in the keymap
    //so if we press down the 
    void AddButton(Button* button,int x,int y){
        //add button to the matrix
        buttonmap[tuple<int,int>(x,y)]=button;
        drawableList.push_back(button);
    }


    void MoveCursor(int x, int y){
        /*
        printf("move cursor %i %i\n",x,y);
        printf("cursor was %i : %i\n",get<0>(cursor),get<1>(cursor));
        printf("cursor would be %i : %i\n",get<0>(cursor)+x,get<1>(cursor)+y);
        */
        
        
        //find returns iterator so we need to see if the iterator is end()
        map<tuple<int,int>,Button*>::iterator ite=buttonmap.find(tuple<int,int>(get<0>(cursor)+x,get<1>(cursor)+y));
        Button* hov=ite->second;

        //past end pointer why not 0 
        if (ite != buttonmap.end() ) {
            hoveredButton=hov;
            cursor=tuple<int,int>(get<0>(cursor)+x,get<1>(cursor)+y);
        }else{
            if (x==0 && y==0) {
                printf("did not move curor but did not find button\n");
                PrintStackTrace();
                //this is a bug and for now will crash the entire game
                exit(1);
            }
            //no button found

            //x is positive
            if (x>0) {
                //we moved too mutch to the right wrap to 0
                cursor=make_tuple(0,get<1>(cursor));
            }else if (x<0) {
                //no wrap to max
                cursor=make_tuple(0,get<1>(cursor));
            }
            
            //y is pos
            if (y>0) {
                cursor=make_tuple(get<0>(cursor),0);
            }else if (y<0) {
                cursor=make_tuple(get<0>(cursor),0);
            }
            
            //update what we set the cursor to
            MoveCursor(0,0);// this is breaking things we need to split this functon it has too many things that it is doing
                            // for now lets not have menues that break 
        }
    }



    void DrawDrawables()override{

        for (Drawable* i:drawableList){
            i->draw();
        }

        Vector2 cursorScreenPos =hoveredButton->GetCenter();
        //draw cursor
        //nullprt
        DrawCircle(cursorScreenPos.x ,cursorScreenPos.y  , 20, RED);
    }


    //when we move, we move the cursor
    void handleInput(InputAction action)override{
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

            default:
                printf("unknown key from menucontroller \n");
                break;
        
        }

    }


};




