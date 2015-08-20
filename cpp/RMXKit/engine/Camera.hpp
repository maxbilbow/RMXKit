//
//  Camera.hpp
//  RMXKit
//
//  Created by Max Bilbow on 20/08/2015.
//  Copyright © 2015 Rattle Media Ltd. All rights reserved.
//

#ifndef Camera_hpp
#define Camera_hpp

#include <stdio.h>

#endif /* Camera_hpp */
//#import "GameView.hpp"
namespace rmx {
    
    class Camera : public NodeComponent {
        float fovX, fovY, nearZ, farZ, aspect;
        Matrix4 _projectionMatrix;
    public:
        Camera();
        void makePerspective(GameView * view);
        Matrix4 modelViewMatrix();
        
        float getFarZ();
        void setFarZ(float farZ);
        float getFovX();
        void setFovX(float fovX);
        float getNearZ();
        void setNearZ(float nearZ);
        
        Matrix4 projectionMatrix();

    };
    
    
}