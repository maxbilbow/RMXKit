//
//  NodeComponent.cpp
//  RMXKit
//
//  Created by Max Bilbow on 18/08/2015.
//  Copyright © 2015 Rattle Media Ltd. All rights reserved.
//

//#import "RMXKit.h"
#import "RMXEngine.hpp"
//#import "Object.h"
//#import "Node.h"
//#include "NodeComponent.hpp"

using namespace rmx;
using namespace std;

bool NodeComponent::isEnabled() {
    return this->enabled;
}

void NodeComponent::setEnabled(bool enabled) {
    this->enabled = enabled;
}

Node * NodeComponent::setNode(Node * node) {
    Node * oldNode = this->node;
    this->node = node;
    return oldNode;
}

Node * NodeComponent::getNode() {
    return this->node;
}

Transform * NodeComponent::getTransform() {
    return this->node->getTransform();
}