#pragma once

#include "input.h"

#include "../utils/debug.h"



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
    void handleInput(InputAction action)override;


};
