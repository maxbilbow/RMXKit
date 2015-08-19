//
//  GameController.cpp
//  RMXKit
//
//  Created by Max Bilbow on 18/08/2015.
//  Copyright © 2015 Rattle Media Ltd. All rights reserved.
//

#include "GameController.hpp"


class GameController : public RMXObject,  RenderDelegate  {
    private GLView view;
    
    protected GameController() {
        this.setView(new GameView());
        
    }
    
    public static GameController getInstance() {
        if(singleton == null) {
            synchronized(GameController.class) {
                if(singleton == null) {
                    singleton = new GameController();
                    singleton.setView(new GameView());
                }
            }
        }
        return singleton;
    }
    
    private static GameController singleton = new GameController();
    
    private void initpov() {
        Node n = Node.getCurrent();
        n.setPhysicsBody(new PhysicsBody());
        n.physicsBody().setMass(0.5f);
        n.addBehaviour(new SpriteBehaviour());
        n.transform.setScale(2f, 0.1f, 2f);
        Scene.getCurrent().rootNode.addChild(n);
    }
    public void setup() {
        Scene scene = Scene.getCurrent();
        initpov();
        
        
        Node cube = Node.makeCube(0.5f, true, new Behaviour() {
            
            @Override
            public void update() {
                this.getNode().transform.move("forward:0.1");
                
            }
            
        });
        cube.transform.setPosition(0,0,5);
        
        
        Node cube2 = Node.makeCube(0.2f, false, new Behaviour() {
            @Override
            public void update() {
                this.getNode().transform.move("yaw:0.1");
                this.getNode().transform.move("pitch:0.1");
                this.getNode().transform.move("roll:0.1");
            }
            
        });
        
        
        Node cube3 = Node.makeCube(0.5f, true, new Behaviour() {
            @Override
            public void update() {
                this.getNode().transform.move("forward:0.5");
                this.getNode().transform.move("yaw:0.1");
            }
            
        });
        cube3.transform.setPosition(-10,0,10);
        cube3.addChild(cube2);
        cube2.transform.setPosition(0f,1f,0f);
        
        Node floor = new Node();
        floor.transform.setPosition(0,0,0);
        scene.rootNode.addChild(floor);
        
        floor.setGeometry(new Geometry(4*3){
            
            @Override
            protected void drawWithScale(float x, float y, float z) {
                float inf = 99999;//Float.POSITIVE_INFINITY;
                GL11.glBegin(GL11.GL_POLYGON);
                GL11.glColor3f(0.8f,0.8f,0.8f);
                GL11.glVertex3f( inf, -y,-inf);
                GL11.glVertex3f(-inf, -y,-inf);
                GL11.glVertex3f(-inf, -y, inf);
                GL11.glVertex3f( inf, -y, inf);
                GL11.glEnd();
            }
            
        });
        
    }
    
    @Override
    public void run() {
        //
        //       System.out.println("Hello LWJGL " + Sys.getVersion() + "!");
        try {
            
            this.setup();
            SharedLibraryLoader.load();
            
            this.view.initGL();
            this.view.enterGameLoop();
            
            // Release window and window callbacks
            glfwDestroyWindow(view.window());
            view.keyCallback().release();
        } catch (Exception e){
            e.printStackTrace();
        } finally {
            // Terminate GLFW and release the GLFWerrorfun
            glfwTerminate();
            view.errorCallback().release();
        }
    }
    
    @Override
    public void updateBeforeScene() {
        this.repeatedKeys();
    }
    
    @Override
    public void updateAfterScene() {
        
    }
    
    public final KeyStates keys = new KeyStates();
    
    private void repeatedKeys() {
        Node player = Node.getCurrent();
        
        if (this.keys.getOrDefault(GLFW_KEY_W, false)) {
            player.broadcastMessage("move","forward:1");
        }
        
        if (this.keys.getOrDefault(GLFW_KEY_S, false)) {
            player.broadcastMessage("move","forward:-1");
        }
        
        if (this.keys.getOrDefault(GLFW_KEY_A, false)) {
            player.broadcastMessage("move","left:1");
        }
        
        if (this.keys.getOrDefault(GLFW_KEY_D, false)) {
            player.broadcastMessage("move","left:-1");
        }
        
        if (this.keys.getOrDefault(GLFW_KEY_Q, false)) {
            player.broadcastMessage("move","up:-1");
        }
        
        if (this.keys.getOrDefault(GLFW_KEY_E, false)) {
            player.broadcastMessage("move","up:1");
        }
        if (this.keys.getOrDefault(GLFW_KEY_SPACE, false)) {
            player.broadcastMessage("jump");
        }
        
        if (this.keys.getOrDefault(GLFW_KEY_RIGHT, false)) {
            player.broadcastMessage("move","yaw:1");
        }
        
        if (this.keys.getOrDefault(GLFW_KEY_LEFT, false)) {
            player.broadcastMessage("move","yaw:-1");
        }
        
        if (this.keys.getOrDefault(GLFW_KEY_UP, false)) {
            player.broadcastMessage("move","pitch:-1");
        }
        
        if (this.keys.getOrDefault(GLFW_KEY_DOWN, false)) {
            player.broadcastMessage("move","pitch:1");
        }
        
        if (this.keys.getOrDefault(GLFW_KEY_X, false)) {
            player.broadcastMessage("move","roll:1");
        }
        
        if (this.keys.getOrDefault(GLFW_KEY_Z, false)) {
            player.broadcastMessage("move","roll:-1");
        }
    }
    
    
    public void setView(GLView view) {
        this.view = view;
        this.view.setDelegate(this);
    }
    //	private Thread thread;
    public void Start() {
        //			thread = new Thread(this,"Game");
        //			thread.start();
        this.run();
    }
    
    
}