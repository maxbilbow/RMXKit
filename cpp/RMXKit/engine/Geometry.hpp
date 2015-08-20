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
        static Geometry * _cube;
        int * _vertexData, * _indexData;
        int _size = 0, _count = 0;
        bool vertexMode;
        void pushMatrx(Node * node, Transform * base);
        void popMatrix();
    protected:
        virtual void drawWithScale(float x, float y, float z) {}
    public:
        bool isVertexMode();
        void setVertexMode(bool vertexMode);
        void render(Node * node, Transform * root);
        
        static Geometry * Cube();
        
        int * vertexData();
        int * indexData();
        
        Geometry(int size);
        void addVertex(Vector3 v);
        
        void addVertex(float x, float y, float z);
        void prepare();
        
        
    
    };
    
    class Cube : public Geometry {
    protected:
         void drawWithScale(float x, float y, float z) override;
    public:
        Cube():Geometry(6*3*4){}
    };

    class Floor : public Geometry {
        
    protected:
        void drawWithScale(float x, float y, float z) override;
    public:
        Floor():Geometry(4*9) {}
        
    };

}