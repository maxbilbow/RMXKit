//
//  Node.c
//  RMXKit
//
//  Created by Max Bilbow on 18/08/2015.
//  Copyright © 2015 Rattle Media Ltd. All rights reserved.
//
#import <iostream>

#import "Includes.h"
#import "Transform.hpp"
#import "NodeComponent.hpp"

#import "Geometry.hpp"
#import "Node.hpp"



using namespace rmx;
using namespace std;
    
//Node * Node::_current = Node::newCameraNode();

Node::Node() {
    this->children = new LinkedList<Node*>();
    this->_transform = new Transform(this);
}

void Node::setCurrent(Node * node) {
        _current = node;
}
    

Node * Node::getCurrent() {
        if (_current == NULL)
            _current = newCameraNode();
        return _current;
}
    
NodeComponent * Node::setComponent(NodeComponent * component) {
    string key = typeid(component).name();
//    NodeComponent * result = this->components->getValueForKey(key);
    
    return this->components->setValueForKey(key,component);
}

void Node::addBehaviour(Behaviour * behaviour) {
    if (behaviour != NULL) {
        this->behaviours->append(behaviour);
        behaviour->setNode(this);
    }
}
    
NodeComponent * Node::getComponent(string className) {
    return this->components->getValueForKey(className);
}


LinkedList<Node*> * Node::getChildren() {
    return this->children;
}
    
void Node::addChild(Node * child) {
    if (!this->children->contains(&child)) {
        this->children->append(child);
        child->setParent(this);
    }
}
    
bool Node::removeChildNode(Node * node) {
    return this->children->removeValue(node);
}

Node * Node::getChildWithName(string name) {
    NodeList::Iterator i = this->children->getIterator();
    while (i.hasNext()) {
        Node * n = *i.next();
        if (n->Name() == name)
            return n;
    }
    return NULL;
}

    
    
Node::Node(string name) {
    this->_transform = new Transform(this);
    this->setName(name);
}

Camera * Node::camera() {
    return (Camera*) this->getComponent(typeid(Camera).name());
}
    
void Node::setCamera(Camera * camera) {
    this->setComponent(camera);
}
    
Node * Node::newCameraNode() {
    Node * cameraNode = new Node("CameraNode");
    cameraNode->setCamera(new Camera());
    return cameraNode;
}
    
    
    
Geometry * Node::geometry() {
    return _geometry;// (Geometry) this.getComponent(Geometry.class);
}
    

void Node::setGeometry(Geometry * geometry) {
    _geometry = geometry;
}
    
PhysicsBody * Node::physicsBody(){
    return (PhysicsBody*) this->getComponent(typeid(PhysicsBody).name());
}
    
void Node::setPhysicsBody(PhysicsBody * body) {
    this->setComponent(body);
}
    
void Node::updateLogic() {
    Behaviours::Iterator bi = this->behaviours->getIterator();
    while (bi.hasNext()) {
        Behaviour * b = *bi.next();
        if (b->isEnabled())
            b->update();
    }
    NodeList::Iterator ci = this->children->getIterator();
    while (ci.hasNext()) {
        Node * n = *ci.next();
        n->updateLogic();
    }
    
    bi = this->behaviours->getIterator();
    while (bi.hasNext()) {
        Behaviour * b = *bi.next();
        if (b->isEnabled())
            b->lateUpdate();
    }
}

void Node::draw(Matrix4 modelViewMatrix) {
    if (this->_geometry != nullptr) {
        this->_geometry->render(this, modelViewMatrix);
    }
    NodeList::Iterator ci = this->children->getIterator();
    while (ci.hasNext()) {
        Node * n = *ci.next();
        n->draw(modelViewMatrix);
    }
}

    
    

    
Node * Node::getParent() {
    return this->parent;
}
    
void Node::setParent(Node * parent) {
    if (this->parent != nullptr && parent != this->parent) {
        this->parent->removeChildNode(this);
        this->parent = parent;
    }
}

///TODO
void Node::SendMessage(std::string message, void * args, SendMessageOptions options) {
    //TODO
}

void Node::BroadcastMessage(std::string message, void * args, SendMessageOptions options) {
    Object::BroadcastMessage(message, args, options);
    Components::Iterator ci = this->components->getIterator();
    while (ci.hasNext())
        ci.next()->value->BroadcastMessage(message,args,options);
    
    Behaviours::Iterator bi = this->behaviours->getIterator();
    while (bi.hasNext())
        (*bi.next())->BroadcastMessage(message,args,options);
}
    
Node * Node::makeCube(float s,bool body, Behaviour * b) {
    Node * n = new Node("Cube");
    n->setGeometry(Geometry::Cube());
        if (body)
            n->setPhysicsBody(new PhysicsBody());
        n->getTransform()->setScale(s, s, s);
        n->addBehaviour(b);
        n->addToCurrentScene();
        return n;
    }
    
void Node::addToCurrentScene() {
    Scene::getCurrent()->rootNode()->addChild(this);
}

void Node::setTransform(Transform *transform) {
    if (_transform != nullptr)
        throw invalid_argument("Transform can only be set once! " + this->ToString());
    else
        _transform = transform;
}

void Node::test() {
    Object * o = new Object();
    o->setName("Parent");
    Node * o2 = Node::newCameraNode();
    
    try {
        o->SendMessage("getCamera",nullptr);
        
        o2->SendMessage("getCamera",nullptr);
        o->SendMessage("getCamera",new string("Hello 1"));
        o2->SendMessage("getCamera",new string("Hello Node"));
    } catch (exception e) {
        // TODO Auto-generated catch block
        cout << "ERROR: " << e.what() << endl;
    }
    o2->updateLogic();
}
