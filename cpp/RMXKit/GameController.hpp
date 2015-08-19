//
//  GameController.hpp
//  RMXKit
//
//  Created by Max Bilbow on 18/08/2015.
//  Copyright © 2015 Rattle Media Ltd. All rights reserved.
//

#ifndef GameController_hpp
#define GameController_hpp

#include <stdio.h>

#endif /* GameController_hpp */

namespace rmx {

class KeyStates {};

class GameController : public Object,  RenderDelegate  {
    GameView * view;
    static GameController * singleton;
    
    void initpov();
    void setup();

    GameController();
    
    
public:
    static GameController * getInstance();
    
    void run();
    
    const KeyStates keys;
    
    void repeatedKeys();
    
    void setView(GameView * view);
    
};

}