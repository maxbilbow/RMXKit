//
//  GameController.cpp
//  RMXKit
//
//  Created by Max Bilbow on 18/08/2015.
//  Copyright © 2015 Rattle Media Ltd. All rights reserved.
//

#import "RMXEngine.hpp"
#import "GameController.hpp"

using namespace std;
using namespace rmx;

GameController::GameController() {
    this->setView(new GameView());
}

GameController * GameController::getInstance() {
    if(_singleton == nullptr) {
        _singleton = new GameController();
    }
    return _singleton;
}


void GameController::initpov() {
    Node * n = Node::getCurrent();
    n->setPhysicsBody(new PhysicsBody());
    n->physicsBody()->setMass(0.5f);
//    n->addBehaviour(new SpriteBehaviour());
    n->getTransform()->setScale(2.0f, 0.1f, 2.0f);
    Scene::getCurrent()->rootNode()->addChild(n);
}

class BehaviourA : public Behaviour {
public:
    void update() override {
        this->getNode()->getTransform()->move(Forward,"0.1");
    }
};

class BehaviourB : public Behaviour {
public:
    void update() override {
        this->getNode()->getTransform()->move(Yaw,   "0.1");
        this->getNode()->getTransform()->move(Pitch, "0.1");
        this->getNode()->getTransform()->move(Roll,  "0.1");
    }
    
};

class BehaviourC : public Behaviour {
public:
    void update() override {
        this->getNode()->getTransform()->move(Forward,"0.5");
        this->getNode()->getTransform()->move(Yaw,  "0.1");
    }
    
};

void GameController::setup() {
    Scene * scene = Scene::getCurrent();
    initpov();
    
    Node * cube = Node::makeCube(0.5f, true, new BehaviourA());
    cube->getTransform()->setPosition(0.0f,0.0f,5.0f);
        
        
    Node * cube2 = Node::makeCube(0.2f, false, new BehaviourB());
        
    Node * cube3 = Node::makeCube(0.5f, true, new BehaviourC());
    cube3->getTransform()->setPosition(-10.0f,0.0f,10.0f);
    cube3->addChild(cube2);
    cube2->getTransform()->setPosition(0.0f,1.0f,0.0f);
        
    Node * floor = new Node();
    floor->getTransform()->setPosition(0,0,0);
    scene->rootNode()->addChild(floor);
        
    floor->setGeometry(new Floor());
    
}

void GameController::run() {
        //
        //       System.out.println("Hello LWJGL " + Sys.getVersion() + "!");
        try {
            
            this->setup();
//            SharedLibraryLoader::load();
            
            this->view->initGL();
            this->view->enterGameLoop();
            
            // Release window and window callbacks
            glfwDestroyWindow(view->window());
//            view->keyCallback().release();
        } catch (exception e){
//            e.printStackTrace();
        }
    // Terminate GLFW and release the GLFWerrorfun
            glfwTerminate();
//            view.errorCallback().release();
    
}
    

void GameController::updateBeforeScene() {
    this->repeatedKeys();
}


void GameController::updateAfterScene() {
    
}

void GameController::repeatedKeys() {
    Node * player = Node::getCurrent();
    
    if (this->keys[GLFW_KEY_W]) {
        player->getTransform()->move(Forward,"1");
    }
    
    if (this->keys[GLFW_KEY_S]) {
        player->getTransform()->move(Forward,"-1");
    }
    
    if (this->keys[GLFW_KEY_A]) {
        player->getTransform()->move(Left,"1");
    }
    
    if (this->keys[GLFW_KEY_D]) {
        player->getTransform()->move(Left, "-1");
    }
    
    if (this->keys[GLFW_KEY_Q]) {
        player->getTransform()->move(Up,"-1");
    }
    
    if (this->keys[GLFW_KEY_E]) {
        player->getTransform()->move(Up,"1");
    }
    if (this->keys[GLFW_KEY_SPACE]) {
        player->getTransform()->move(Jump);
    }
    
    if (this->keys[GLFW_KEY_RIGHT]) {
        player->getTransform()->move(Yaw,"1");
    }
    
    if (this->keys[GLFW_KEY_LEFT]) {
        player->getTransform()->move(Yaw,"-1");
    }
    
    if (this->keys[GLFW_KEY_UP]) {
        player->getTransform()->move(Pitch,"-1");
    }
    
    if (this->keys[GLFW_KEY_DOWN]) {
        player->getTransform()->move(Pitch,"1");
    }
    
    if (this->keys[GLFW_KEY_X]) {
        player->getTransform()->move(Roll,"1");
    }
    
    if (this->keys[GLFW_KEY_Z]) {
        player->getTransform()->move(Roll,"-1");
    }
}


void GameController::setView(GameView * view) {
    this->view = view;
    this->view->setDelegate(this);
}
