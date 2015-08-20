//
//  NodeComponent.hpp
//  RMXKit
//
//  Created by Max Bilbow on 18/08/2015.
//  Copyright © 2015 Rattle Media Ltd. All rights reserved.
//

#ifndef NodeComponent_hpp
#define NodeComponent_hpp

#include <stdio.h>

#endif /* NodeComponent_hpp */

#import "Node.hpp"
namespace rmx {
    
    class NodeComponent : public Object {
        Node * node;
       
        bool enabled;
    public:
        
        virtual Node * setNode(Node * node);
        Node * getNode();
        
        bool isEnabled();
        void setEnabled(bool);
        
        Transform * getTransform();
    };

}