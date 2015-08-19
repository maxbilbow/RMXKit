//
//  Node.h
//  RMXKit
//
//  Created by Max Bilbow on 18/08/2015.
//  Copyright © 2015 Rattle Media Ltd. All rights reserved.
//

#ifndef Node_h
#define Node_h

#include <stdio.h>
#import <iostream>
#endif /* Node_h */

//#include <iostream>
//#import "Transform.hpp"


namespace rmx {
    class Geometry;
    class Transform;
    class NodeComponent;
    class Behaviour;
    class Camera;
    class PhysicsBody;
    
    class Node : public Object {
    
        static Node * _current;
        
        Node * parent;
        
        rmx::Transform * transform;
        
        Geometry * _geometry;
        
        LinkedList<Node*> * children = new LinkedList<Node*>();
        
        Dictionary<std::string, NodeComponent> * components = new Dictionary<std::string, NodeComponent>();
        
        LinkedList<Behaviour*> * behaviours = new LinkedList<Behaviour*>();
        
    public:
        static void setCurrent(Node * node);
        
        static Node * current();
        
        
        
    //    template <class T = NodeComponent>
        NodeComponent * setComponent(NodeComponent * component);
        
        void addBehaviour(Behaviour * behaviour);
        
        NodeComponent * getComponent(std::string className);
        

        
        
        LinkedList<Node*> * getChildren();
        
        void addChild(Node * child);
        bool removeChildNode(Node * node);
        
        Node * getChildWithName(std::string name);
        
        
        Node();
        
        
        Node(std::string name);
        
        Camera * camera();
        
        void setCamera(Camera * camera);
        
        static Node * newCameraNode();
        
        
        Geometry * geometry();
        

        void setGeometry(Geometry * geometry);
        
        PhysicsBody * physicsBody();
        
        void setPhysicsBody(PhysicsBody * body);
        
        void updateLogic();
        
        void draw(Transform * transform);
        
        
        static void test();
        
        
        Node * getParent();
        
        void setParent(Node * parent);
        
        static Node * makeCube(float s,bool body, Behaviour * b);
        
        void addToCurrentScene();

    };

}