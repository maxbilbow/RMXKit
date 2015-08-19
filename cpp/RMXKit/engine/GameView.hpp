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



namespace rmx {
    
    class GLView {};
    
    class GLFWErrorCallback {};
  

class GameView : public GLView {
    Node * _pointOfView;

    int _height = 720, _width = 1280;
    
    
    // We need to strongly reference callback instances.
    GLFWErrorCallback * _errorCallback;
    KeyCallback   * _keyCallback;
    
    // The window handle
    long _window;
    
    
    RenderDelegate * delegate = NULL;
    
public:
    void initGL();
    
    void enterGameLoop();
    
    
    
    
    bool setPointOfView(Node * pointOfView);
    RenderDelegate getDelegate();
   
    
    void setDelegate(RenderDelegate delegate);
    
    
    
    long window();
    
    GLFWErrorCallback * errorCallback();
    
    KeyCallback * keyCallback();
    
    int width();
    void setWidth(int width);
    
    int height();
    
    void setHeight(int height);
    
    Node * pointOfView();
};

}