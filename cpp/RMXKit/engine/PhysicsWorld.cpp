//
//  PhysicsWorld.cpp
//  RMXKit
//
//  Created by Max Bilbow on 19/08/2015.
//  Copyright © 2015 Rattle Media Ltd. All rights reserved.
//

#import "RMXEngine.hpp"
//#import "PhysicsWorld.hpp"

using namespace std;
using namespace rmx;



Vector3 PhysicsWorld::getGravity() {
    return this->gravity;
}
    
void PhysicsWorld::setGravity(Vector3 gravity) {
    this->gravity = gravity;
}

void PhysicsWorld::setGravity(float x, float y, float z) {
        this->gravity.x = x;
        this->gravity.y = y;
        this->gravity.z = z;
}
    
void PhysicsWorld::updatePhysics(Node * rootNode) {
    Node::NodeList::Iterator i = rootNode->getChildren()->getIterator();
    while (i.hasNext()) {
        Node * node = *i.next();
        if (node->physicsBody() != nullptr) {
            this->applyGravityTo(node);
        }
    }
}

float getCurrentFramerate() {
    return 0.1667;
}
    
void PhysicsWorld::applyGravityTo(Node * node) {
        Transform * t = node->getTransform();
        float g = 0;
        float mass = node->getTransform()->mass();
        float framerate = getCurrentFramerate();
        //		System.out.println(node.getName() + " >> BEFORE: " + m.position());t.
    t->setPosition(t->position() + this->gravity * framerate * mass);
        //		System.out.println(node.getName() + " >>  AFTER: " + m.position());
        //		m.translate(x, y, z);
        if (t->position().y < g)
            t->setM(3 * 4 + 1 - 1, g);
}