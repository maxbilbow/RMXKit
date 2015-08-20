//
//  PhysicsBody.cpp
//  RMXKit
//
//  Created by Max Bilbow on 20/08/2015.
//  Copyright © 2015 Rattle Media Ltd. All rights reserved.
//
//#import "RMXEngine.hpp"
//#import "PhysicsBody.hpp"


#import "Includes.h"


//#import "GameNode.hpp"
//
//#import "NodeComponent.hpp"
//#import "Transform.hpp"
#import "PhysicsBody.hpp"


using namespace rmx;

PhysicsBody::PhysicsBody() {
    this->mass = 0;
    this->setName("PhysicsBody");
}

void PhysicsBody::setMass(float mass) {
    this->mass = mass;
}
float PhysicsBody::getMass() {
    return this->mass;
}

float PhysicsBody::TotalMass() {
    return this->getNode()->getTransform()->mass();
}
