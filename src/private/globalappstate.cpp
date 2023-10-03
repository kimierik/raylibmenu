
#include "../public/globalappstate.h"


GlobalAppState* GlobalAppState::instance=nullptr;

GlobalAppState * GlobalAppState::getGlobalAppState(){
    if (instance==nullptr) {
        instance= new GlobalAppState;
        return instance;
    }else{
        return instance;
    }
}

