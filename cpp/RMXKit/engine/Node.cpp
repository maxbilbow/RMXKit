//
//  Node.c
//  RMXKit
//
//  Created by Max Bilbow on 18/08/2015.
//  Copyright © 2015 Rattle Media Ltd. All rights reserved.
//
#include <iostream>

#include "RMXEngine.hpp"



using namespace rmx;
using namespace std;
    
//Node * Node::_current = Node::newCameraNode();

Node::Node() {
    this->children = new LinkedList<Node*>();
    this->transform = new Transform(this);
}

void Node::setCurrent(Node * node) {
        _current = node;
}
    

Node * Node::current() {
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
    if (!this->children->contains(child)) {
        this->children->append(child);
        child->setParent(this);
    }
}
    
    public boolean removeChildNode(Node node) {
        return this.children.remove(node);
    }
    
    public Node getChildWithName(String name) {
        for (Node child : this.children) {
            if (child.getName() == name)
                return child;
        }
        return null;
    }
    
    public Node(){
        this.transform = new Transform(this);
        
    }
    
    
    public Node(String name) {
        this.transform = new Transform(this);
        this.setName(name);
    }
    
    public Camera camera() {
        return (Camera) this.getComponent(Camera.class);
    }
    
    public void setCamera(Camera camera) {
        this.setComponent(Camera.class, camera);
    }
    
    public static Node newCameraNode() {
        Node cameraNode = new Node("CameraNode");
        cameraNode.setCamera(new Camera());
        return cameraNode;
    }
    
    
    
    public Geometry geometry() {
        return _geometry;// (Geometry) this.getComponent(Geometry.class);
    }
    
    private Geometry _geometry;
    public void setGeometry(Geometry geometry) {
        _geometry = geometry;
        //		this.setComponent(Geometry.class, geometry);
    }
    
    public PhysicsBody physicsBody(){
        return (PhysicsBody) this.getComponent(PhysicsBody.class);
    }
    
    public void setPhysicsBody(PhysicsBody body) {
        this.setComponent(PhysicsBody.class, body);
    }
    
    public void updateLogic() {
        for (Behaviour behaviour : this.behaviours) {
            if (behaviour.isEnabled())
                behaviour.update();
        }
        for (Node child : this.children)
            child.updateLogic();
        for (Behaviour behaviour : this.behaviours) {
            if (behaviour.isEnabled())
                behaviour.lateUpdate();
        }
    }
    
    public void draw(Matrix4 modelMatrix) {
        if (this.geometry() != null) {
            this.geometry().render(this, modelMatrix);
        }
        for (Node child : this.children) {
            child.draw(modelMatrix);
        }
    }
    
    
    
    public static void test(String[] args) {
        RMXObject o = new RMXObject();
        o.setName("Parent");
        Node o2 = Node.newCameraNode();
        
        try {
            o.sendMessage("getCamera",null);
            
            o2.sendMessage("getCamera",null);
            o.sendMessage("getCamera","Balls");
            o2.sendMessage("getCamera","Balls");
        }catch (SecurityException | IllegalAccessException | IllegalArgumentException
                | InvocationTargetException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
        if (o2.geometry() == null)
            Bugger.log("That's OK then");
        if (o2.camera() != null)
            Bugger.log("That's OK then");
        
        //		o2.addBehaviour(new ABehaviour());
        
        o2.updateLogic();
    }
    
    
    public Node getParent() {
        return parent;
    }
    
    public void setParent(Node parent) {
        if (this.parent != null && parent != this.parent) {
            this.parent.removeChildNode(this);
            ;		}
        this.parent = parent;
    }
    
    @Override
    public void broadcastMessage(String message) {
        super.broadcastMessage(message);
        for (NodeComponent c : this.components.values()) {
            c.broadcastMessage(message);
        }
        for (Behaviour b : this.behaviours) {
            b.broadcastMessage(message);
        }
    }
    
    @Override
    public void broadcastMessage(String message, Object args) {
        super.broadcastMessage(message, args);
        for (NodeComponent c : this.components.values()) {
            c.broadcastMessage(message, args);
        }
        for (Behaviour b : this.behaviours) {
            b.broadcastMessage(message,args);
        }
        
    }
    
    public static Node makeCube(float s,boolean body, Behaviour b) {
        Node n = new Node("Cube");
        n.setGeometry(Geometry.cube());
        if (body)
            n.setPhysicsBody(new PhysicsBody());
        n.transform.setScale(s, s, s);
        n.addBehaviour(b);
        n.addToCurrentScene();
        return n;
    }
    
    private void addToCurrentScene() {
        Scene.getCurrent().rootNode.addChild(this);
    }
}