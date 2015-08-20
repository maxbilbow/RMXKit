//
//  Node.c
//  RMXKit
//
//  Created by Max Bilbow on 18/08/2015.
//  Copyright © 2015 Rattle Media Ltd. All rights reserved.
//
//#import <iostream>

#import "Includes.h"

#import "NodeComponent.hpp"
#import "Transform.hpp"
#import "Geometry.hpp"
#import "Behaviour.hpp"
#import "Scene.hpp"
#import "Camera.hpp"
#import "PhysicsBody.hpp"
#import "GameNode.hpp"







using namespace rmx;
using namespace std;
    
GameNode * GameNode::_current = GameNode::newCameraNode();

GameNode::GameNode() {
    this->setName("GameNode");
    this->onLoad();
}

GameNode::GameNode(string name) {
    this->setName(name);
    this->onLoad();
}



void GameNode::onLoad() {
//    this->children = GameNodeList();
//    this->behaviours = GameNodeBehaviours();
//    this->components = GameNodeComponents();
//    this->camera = new Camera();
    this->_transform = new Transform(this);
    this->afterLoad();
}

void GameNode::setCurrent(GameNode * node) {
    _current = node;
}
    
Transform * GameNode::getTransform() {
    return _transform;
}

GameNode * GameNode::getCurrent() {
        if (_current == null)
            _current = newCameraNode();
        return _current;
}
    
NodeComponent * GameNode::setComponent(NodeComponent * component)  {
    string key = typeid(component).name();
//    NodeComponent * result = this->components->getValueForKey(key);
    cout << "Adding component: " << component << endl;
    return this->components.setValueForKey(key,component);
}

void GameNode::addBehaviour(Behaviour * behaviour) {
    if (behaviour != null) {
        this->behaviours.append(behaviour);
        behaviour->setNode(this);
    }
}
    
NodeComponent * GameNode::getComponent(string className) {
    return this->components.getValueForKey(className);
}


GameNodeList * GameNode::getChildren() {
    return &this->children;
}
    
void GameNode::addChild(GameNode * child) {
    if (!this->children.contains(&child)) {
        this->children.append(child);
        child->setParent(this);
    }
}
    
bool GameNode::removeChildNode(GameNode * node) {
    return this->children.removeValue(node);
}

GameNode * GameNode::getChildWithName(string name) {
    GameNodeList::Iterator i = this->children.getIterator();
    while (i.hasNext()) {
        GameNode * n = *i.next();
        if (n->Name() == name)
            return n;
    }
    return    null;
}
    

Camera * GameNode::getCamera() {
    cout << this << endl;
    return GameNode::getCurrent()->camera;// new Camera();// this->camera;
//    if (this->camera != null)
//        return this->camera;//(Camera*) this->getComponent(typeid(Camera).name());
//    else {
//        cout << "WARNING: Camera is null, generating new... " << this << endl;
//        this->camera = new Camera();
//        this->camera->setName("Spare Camera");
//        this->camera->setNode(this);
//    }
//    return this->camera;
}

void GameNode::setCamera(Camera * camera) {
//    this->setComponent(camera);
    camera->NodeComponent::setNode(this);
    this->camera = camera;
}
    
GameNode * GameNode::newCameraNode() {
    GameNode * cameraNode = new GameNode("CameraNode");
    cameraNode->setCamera(new Camera());
    return cameraNode;
}
    
Geometry * GameNode::geometry() {
    return _geometry;// (Geometry) this.getComponent(Geometry.class);
}
    

void GameNode::setGeometry(Geometry * geometry) {
    this->_geometry = geometry;
}
    
PhysicsBody * GameNode::physicsBody(){
//    PhysicsBody * body = (PhysicsBody*) this->getComponent(typeid(PhysicsBody).name());
//    if (body ==   null)
//        cout << "WARNING: null returned when requesting physicsBody in GameNode" << endl;
    if (this->_physicsBody != null)
        return this->_physicsBody;
    else
        return null;
}
    
void GameNode::setPhysicsBody(PhysicsBody * body) {
//    this->setComponent(body);
    this->_physicsBody = body;
    body->setNode(this);
}
    
void GameNode::updateLogic() {
    GameNodeBehaviours::Iterator bi = this->behaviours.getIterator();
    while (bi.hasNext()) {
        Behaviour * b = *bi.next();
        if (b->isEnabled())
            b->update();
    }
    GameNodeList::Iterator ci = this->children.getIterator();
    while (ci.hasNext()) {
        GameNode * n = *ci.next();
        n->updateLogic();
    }
    
    bi = this->behaviours.getIterator();
    while (bi.hasNext()) {
        Behaviour * b = *bi.next();
        if (b->isEnabled())
            b->lateUpdate();
    }
}

void GameNode::draw(Transform * rootTransform) {
    if (this->_geometry !=   null) {
        this->_geometry->render(this, rootTransform);
    }
    GameNodeList::Iterator ci = this->children.getIterator();
    while (ci.hasNext()) {
        GameNode * n = *ci.next();
        n->draw(rootTransform);
    }
}

    
    

    
GameNode * GameNode::getParent() {
    return this->parent;
}
    
void GameNode::setParent(GameNode * parent) {
    if (this->parent !=   null && parent != this->parent) {
        this->parent->removeChildNode(this);
        this->parent = parent;
    }
}

///TODO
void GameNode::SendMessage(std::string message, void * args, SendMessageOptions options) {
    //TODO
}

void GameNode::BroadcastMessage(std::string message, void * args, SendMessageOptions options) {
    Object::BroadcastMessage(message, args, options);
//    GameNodeComponents::Iterator ci = this->components->getIterator();
//    while (ci.hasNext())
//        ci.next()->value->BroadcastMessage(message,args,options);
    
    GameNodeBehaviours::Iterator bi = this->behaviours.getIterator();
    while (bi.hasNext())
        (*bi.next())->BroadcastMessage(message,args,options);
}
    
GameNode * GameNode::makeCube(float s,bool body, Behaviour * b) {
    GameNode * n = new GameNode("Cube");
    n->setGeometry(Geometry::Cube());
        if (body)
            n->setPhysicsBody(new PhysicsBody());
        n->getTransform()->setScale(s, s, s);
        n->addBehaviour(b);
        n->addToCurrentScene();
        return n;
    }
    
void GameNode::addToCurrentScene() {
    Scene::getCurrent()->rootNode()->addChild(this);
}

void GameNode::setTransform(Transform *transform) {
    if (this->_transform !=   null)
//        throw invalid_argument("Transform can only be set once! " + this->ToString());
        cout << "WARNING: Transform can only be set once! " << this << endl;
    else
        this->_transform = transform;
}

void GameNode::test() {
    Object * o = new Object();
    o->setName("Parent");
    GameNode * o2 = GameNode::newCameraNode();
    
    try {
        o->SendMessage("getCamera",  null);
        
        o2->SendMessage("getCamera",  null);
        o->SendMessage("getCamera",new string("Hello 1"));
        o2->SendMessage("getCamera",new string("Hello Node"));
    } catch (exception e) {
        // TODO Auto-generated catch block
        cout << typeid(GameNode).name() << " " << "ERROR: " << e.what() << endl;
    }
    o2->updateLogic();
}
