//
//  Geometry.cpp
//  RMXKit
//
//  Created by Max Bilbow on 19/08/2015.
//  Copyright © 2015 Rattle Media Ltd. All rights reserved.
//

#import "Includes.h"
#import "Node.hpp"
#import "NodeComponent.hpp"
#import "Transform.hpp"
#import "Geometry.hpp"
//#import <GLFW/glfw3.h>

using namespace rmx;
using namespace std;

void Floor::drawWithScale(float x, float y, float z) {
    float inf = 99999;//Float.POSITIVE_INFINITY;
    glBegin(GL_POLYGON);
    glColor3f(0.8f,0.8f,0.8f);
    glVertex3f( inf, -y,-inf);
    glVertex3f(-inf, -y,-inf);
    glVertex3f(-inf, -y, inf);
    glVertex3f( inf, -y, inf);
    glEnd();
}

//private ByteBuffer _elements;
//private ShortBuffer _indexData;
//private int _e = 0;
Geometry::Geometry(int size) {
    _vertexData = new int[sizeof(int) * size];
    _indexData = new int[sizeof(int) * size / 3];
}

int * Geometry::vertexData() {
    return _vertexData;
}

int * Geometry::indexData() {
    return _indexData;
}
void Geometry::addVertex(Vector3 v) {
    this->addVertex(v.x, v.y, v.z);
}

void Geometry::addVertex(float x, float y, float z)  {
    if (_count >= _size)
        throw new invalid_argument("ERROR: TOO MANY VERTICES");
    _vertexData[_count++] = x;
    _vertexData[_count++] = y;
    _vertexData[_count++] = z;
    
}
void Geometry::prepare() {
   
}

void Geometry::pushMatrx(Node * node, Transform * base) {
    //		Matrix4 m = (Matrix4) modelViewMatrix.clone();
//    Matrix4 m = node->getTransform()->worldMatrix();
    //		AxisAngle4f baseA = new AxisAngle4f();
    //		baseA.set(base);
    //		AxisAngle4f modelA = new AxisAngle4f();
    //		modelA.set(_modelView);
    
//    EulerAngles baseA = base->eulerAngles();// / PI_OVER_180;
    EulerAngles modelA = node->getTransform()->eulerAngles() / PI_OVER_180;
    
//    modelA /= PI_OVER_180;
    glPushMatrix();
    
    
    //		glRotatef(baseA.angle, baseA.x, baseA.y, baseA.z);
    //		glRotatef(modelA.angle, modelA.x, modelA.y, modelA.z);
    
    //		glRotatef(baseA.x, 1,0,0);
    //        glRotatef(baseA.y, 0,1,0);
    //        glRotatef(baseA.z, 0,0,1);
    
    
    
    
    //		 glMultMatrixf(_modelView.buffer())
    Vector3 translation = base->getTransform()->position();
    glTranslatef(
                 translation.z,
                 translation.y,
                 translation.z
                 );
    
    Vector3 m_translation = node->getTransform()->getTransform()->position();
    glTranslatef(
                 m_translation.z,
                 m_translation.y,
                 m_translation.z
                 );
    glRotatef(modelA.x, 1,0,0);
    glRotatef(modelA.y, 0,1,0);
    glRotatef(modelA.z, 0,0,1);
    
    
    
    //		Bugger.logAndPrint("\n BASEA: "+ baseA, false);
    //		Bugger.logAndPrint("\nMODELA: "+ modelA, false);
    
    
    
    
    
}

//	private void enableTexture() {
//		 glEnable(GL_TEXTURE_2D); //Enable texture
////         glBindTexture(GL_TEXTURE_2D,text2D);//Binding texture
//	}
void Geometry::popMatrix() {
    //		 glDisable(GL_TEXTURE_2D);//TODO perhaps?
    
    glPopMatrix();
}
void Geometry::render(Node * node, Transform * rootTransform) {
    if (vertexMode) {
        cout << "WARNING: Vertex Mode enabled but may not be fully implemented yet." << endl;
        return;
    }
    //		 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //		         glLoadIdentity();
    
    this->pushMatrx(node, rootTransform);
    float X = node->getTransform()->scale().x;
    float Y = node->getTransform()->scale().y;
    float Z = node->getTransform()->scale().z;
    drawWithScale(X, Y, Z);
    
    this->popMatrix();
}

void _render() {
    //this.pushMatrx();
    //		glVertex3dv(_elements);
    //glColor3f(0.0f,0.0f,1.0f);
    //glDrawElements(GL_QUADS, _elements);
    //this.popMatrix();
}



    /*Bugger.logAndPrint("Cube with " + 6*3*4 + " elements", true);
     _cube = new Geometry(6 * 3 * 4);
     _cube.addVertex( 1.0f, 1.0f,-1.0f);
     _cube.addVertex(-1.0f, 1.0f,-1.0f);
     _cube.addVertex(-1.0f, 1.0f, 1.0f);
     _cube.addVertex( 1.0f, 1.0f, 1.0f);
     //            glColor3f(1.0f,0.5f,0.0f);
     _cube.addVertex( 1.0f,-1.0f, 1.0f);
     _cube.addVertex(-1.0f,-1.0f, 1.0f);
     _cube.addVertex(-1.0f,-1.0f,-1.0f);
     _cube.addVertex( 1.0f,-1.0f,-1.0f);
     //            glColor3f(1.0f,0.0f,0.0f);
     _cube.addVertex( 1.0f, 1.0f, 1.0f);
     _cube.addVertex(-1.0f, 1.0f, 1.0f);
     _cube.addVertex(-1.0f,-1.0f, 1.0f);
     _cube.addVertex( 1.0f,-1.0f, 1.0f);
     //            glColor3f(1.0f,1.0f,0.0f);
     _cube.addVertex( 1.0f,-1.0f,-1.0f);
     _cube.addVertex(-1.0f,-1.0f,-1.0f);
     _cube.addVertex(-1.0f, 1.0f,-1.0f);
     _cube.addVertex( 1.0f, 1.0f,-1.0f);
     //            glColor3f(0.0f,0.0f,1.0f);
     _cube.addVertex(-1.0f, 1.0f, 1.0f);
     _cube.addVertex(-1.0f, 1.0f,-1.0f);
     _cube.addVertex(-1.0f,-1.0f,-1.0f);
     _cube.addVertex(-1.0f,-1.0f, 1.0f);
     //            glColor3f(1.0f,0.0f,1.0f);
     _cube.addVertex( 1.0f, 1.0f,-1.0f);
     _cube.addVertex( 1.0f, 1.0f, 1.0f);
     _cube.addVertex( 1.0f,-1.0f, 1.0f);
     _cube.addVertex( 1.0f,-1.0f,-1.0f);
     _cube.prepare();
     }*/
//    return _cube;
//}


Geometry * Geometry::Cube() {
    if (_cube == nullptr)
        _cube = new rmx::Cube();
    return _cube;
}


void Cube::drawWithScale(float X, float Y, float Z) {
        glBegin(GL_QUADS);
        glColor3f(1.0f,1.0f,0.0f);
        glVertex3f( X, Y,-Z);
        glVertex3f(-X, Y,-Z);
        glVertex3f(-X, Y, Z);
        glVertex3f( X, Y, Z);
        glColor3f(1.0f,0.5f,0.0f);
        glVertex3f( X,-Y, Z);
        glVertex3f(-X,-Y, Z);
        glVertex3f(-X,-Y,-Z);
        glVertex3f( X,-Y,-Z);
        glColor3f(1.0f,0.0f,0.0f);
        glVertex3f( X, Y, Z);
        glVertex3f(-X, Y, Z);
        glVertex3f(-X,-Y, Z);
        glVertex3f( X,-Y, Z);
        glColor3f(1.0f,1.0f,0.0f);
        glVertex3f( X,-Y,-Z);
        glVertex3f(-X,-Y,-Z);
        glVertex3f(-X, Y,-Z);
        glVertex3f( X, Y,-Z);
        glColor3f(0.0f,0.0f,1.0f);
        glVertex3f(-X, Y, Z);
        glVertex3f(-X, Y,-Z);
        glVertex3f(-X,-Y,-Z);
        glVertex3f(-X,-Y, Z);
        glColor3f(1.0f,0.0f,1.0f);
        glVertex3f( X, Y,-Z);
        glVertex3f( X, Y, Z);
        glVertex3f( X,-Y, Z);
        glVertex3f( X,-Y,-Z);
        glEnd();
}

