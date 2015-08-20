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
    public:
        typedef Dictionary<std::string, NodeComponent> Components;
        typedef LinkedList<Behaviour*> Behaviours;
        typedef LinkedList<Node*> NodeList;
    private:
        static Node * _current;
        
        Node * parent;
        
        Transform * _transform;
        
        Geometry * _geometry;
        
        NodeList * children = new NodeList();
        
        Components * components = new Components();
        
        Behaviours * behaviours = new Behaviours();
        
    public:
        
        void setTransform(Transform * transform);
        
        Transform * getTransform();
        
        static void setCurrent(Node * node);
        
        static Node * getCurrent();
        
        
        
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
        
        void draw(Matrix4 modelViewMatrix);
        
        
        
        
        
        Node * getParent();
        
        void setParent(Node * parent);
        
        static Node * makeCube(float s,bool body, Behaviour * b);
        
        void addToCurrentScene();

        void SendMessage(std::string message, void * args = nullptr, SendMessageOptions options = DoesNotRequireReceiver) override;
        void BroadcastMessage(std::string message, void * args = nullptr, SendMessageOptions options = DoesNotRequireReceiver) override;
        
        static void test();
    };

}