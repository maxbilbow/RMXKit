//
//  PhysicsBody.hpp
//  RMXKit
//
//  Created by Max Bilbow on 20/08/2015.
//  Copyright © 2015 Rattle Media Ltd. All rights reserved.
//

#ifndef PhysicsBody_hpp
#define PhysicsBody_hpp

#include <stdio.h>

#endif /* PhysicsBody_hpp */


namespace rmx {
    class PhysicsBody : public NodeComponent{
        float mass = 0;
    public:
        void setMass(float mass) {
            this->mass = mass;
        }
        float getMass() {
            return this->mass;
        }
        
        float TotalMass() {
            return this->getNode()->getTransform()->mass();
        }
        
    

    };
}