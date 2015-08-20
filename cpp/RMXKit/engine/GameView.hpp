//
//  GameView.h
//  RMXKit
//
//  Created by Max Bilbow on 18/08/2015.
//  Copyright © 2015 Rattle Media Ltd. All rights reserved.
//

#ifndef GameView_h
#define GameView_h

#include <stdio.h>

#endif /* GameView_h */


#define END_OF_GAMELOOP "END_OF_GAMELOOP"

#import <GLFW/glfw3.h>


namespace rmx {
    class RenderDelegate {
    public:
        virtual void updateBeforeScene(){};
        
        virtual void updateAfterScene(){};
        
    };
}


namespace rmx {
    
    

class GameView : public Object {
    Node * _pointOfView;

    int _height = 720, _width = 1280;
    
    void errorCallback(int i,const char* c);
    // We need to strongly reference callback instances.
   

    
    // The window handle
    GLFWwindow * _window;
    
    
    RenderDelegate * delegate;
    
public:
    void initGL();
    
    void enterGameLoop();
    
    
    
    
    bool setPointOfView(Node * pointOfView);
    RenderDelegate * getDelegate();
   
    
    void setDelegate(RenderDelegate * delegate);
    
    
    
    GLFWwindow * window();
    
    
    
    
    int width();
    void setWidth(int width);
    
    int height();
    
    void setHeight(int height);
    
    Node * pointOfView();
};

}