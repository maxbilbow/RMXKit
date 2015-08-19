//
//  RMXEngine.h
//  RMXKit
//
//  Created by Max Bilbow on 18/08/2015.
//  Copyright © 2015 Rattle Media Ltd. All rights reserved.
//

#ifndef RMXEngine_h
#define RMXEngine_h


#endif /* RMXEngine_h */

#import <GLUT/GLUT.h>

#import "RMXKit.h"
#import "NodeComponent.hpp"
namespace rmx {
    
    class Geometry{};// : public NodeComponent {};
    class Scene {};
    class Behaviour : public NodeComponent {};
    class Camera : public NodeComponent{};
    class PhysicsBody : public NodeComponent{};
    class KeyCallback : public Object {};

    class  RenderDelegate {
        virtual void updateBeforeScene(){};
        
        virtual void updateAfterScene(){};
        
    };
}

#import "Node.hpp"
#import "Transform.hpp"

#import "Transform.hpp"
#import "GameView.hpp"
#import "GameController.hpp"

