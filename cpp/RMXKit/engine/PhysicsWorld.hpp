//
//  PhysicsWorld.hpp
//  RMXKit
//
//  Created by Max Bilbow on 19/08/2015.
//  Copyright © 2015 Rattle Media Ltd. All rights reserved.
//

#ifndef PhysicsWorld_hpp
#define PhysicsWorld_hpp

#include <stdio.h>

#endif /* PhysicsWorld_hpp */

namespace rmx {
    class PhysicsWorld : public Object , public Unfinised {
        Vector3 gravity = GLKVector3Make(0.0f,-9.8f,0.0f);
//        Scene * scene;
    public:
//        PhysicsWorld():Object(scene->getName());
        Vector3 getGravity();
        
        void setGravity(Vector3 gravity);
        
        void setGravity(float x, float y, float z);
        
        void updatePhysics(Node * rootNode);
        
        void applyGravityTo(Node * node);
        
    };

}