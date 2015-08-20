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

#ifndef GameNode_hpp
#import "GameNode.hpp"
#endif

#ifndef NodeComponent_hpp
#import "NodeComponent.hpp"
#endif

#ifndef Transform_hpp
#import "Transform.hpp"
#endif

namespace rmx {
    class PhysicsBody : public NodeComponent {
        float mass = 0;
    public:
        PhysicsBody();
        void setMass(float mass);

        float getMass();
        
        float TotalMass();
    

    };
}