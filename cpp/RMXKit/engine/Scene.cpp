//
//  Scene.cpp
//  RMXKit
//
//  Created by Max Bilbow on 19/08/2015.
//  Copyright © 2015 Rattle Media Ltd. All rights reserved.
//

#import "RMXEngine.hpp"
//#import "Scene.hpp"


using namespace rmx;
using namespace std;




//	private static Scene current;
Scene * Scene::getCurrent() {
    if (Scene::_current == nullptr)
        _current = new Scene();
    return _current;
}

Scene * Scene::setCurrent(Scene * scene) {
    Scene * old = _current;
    _current = scene;
    return old;
}

void Scene::setAsCurrent() {
    setCurrent(this);
}



void Scene::renderScene(Camera * cam) {
    //		cam.look();
    Matrix4 modelMatrix = cam->modelViewMatrix();
    //modelMatrix.negate();
    Node::NodeList::Iterator i = this->_rootNode->getChildren()->getIterator();
    while (i.hasNext()) {
        (*i.next())->draw(modelMatrix);
    }
}


void Scene::updateSceneLogic() {
    this->_physicsWorld->updatePhysics(this->_rootNode);
    this->_rootNode->updateLogic();
}