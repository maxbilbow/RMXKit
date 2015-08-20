//
//  Geometry.hpp
//  RMXKit
//
//  Created by Max Bilbow on 19/08/2015.
//  Copyright © 2015 Rattle Media Ltd. All rights reserved.
//

#ifndef Geometry_hpp
#define Geometry_hpp

#include <stdio.h>

#endif /* Geometry_hpp */


namespace rmx {
    class Geometry{
        static Geometry _cube;
        int * _vertexData, * _indexData;
        int _e = 0;

    public:
        
        virtual void drawWithScale(float x, float y, float z) {}
        void render(Node * node, Matrix4 modelViewMatrix);
        static Geometry * Cube();
        
        
        
        Geometry(int size);
        void addVertex(Vector3 v);
        
        void addVertex(float x, float y, float z);
        void prepare();
        
        void pushMatrx(Node * node, Matrix4 base);
      
        void popMatrix();     
    
    };
    
    class Cube : public Geometry {
    public:
         void drawWithScale(float x, float y, float z) override;
    };

    class Floor : public Geometry {
        
    protected:
        void drawWithScale(float x, float y, float z) override;
    public:
        Floor():Geometry(4*9) {}
        
    };

}