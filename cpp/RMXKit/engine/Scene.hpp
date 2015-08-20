//
//  Scene.hpp
//  RMXKit
//
//  Created by Max Bilbow on 19/08/2015.
//  Copyright © 2015 Rattle Media Ltd. All rights reserved.
//

#ifndef Scene_hpp
#define Scene_hpp

#include <stdio.h>

#endif /* Scene_hpp */

namespace rmx {

    class Scene : public Object, public Unfinised {
        static Scene * _current;
        Node * _rootNode = new Node("rootNode");
        PhysicsWorld * _physicsWorld = new PhysicsWorld();

    public:
        
        Node * rootNode();
        static Scene * getCurrent();
        static Scene * setCurrent(Scene * scene);
        void updateSceneLogic();
        void renderScene(Camera * camera);
        
        void setAsCurrent();
    };

}