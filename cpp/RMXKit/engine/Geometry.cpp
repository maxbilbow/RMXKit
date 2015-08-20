//
//  Geometry.cpp
//  RMXKit
//
//  Created by Max Bilbow on 19/08/2015.
//  Copyright © 2015 Rattle Media Ltd. All rights reserved.
//

#import "RMXEngine.hpp"
#import "Geometry.hpp"
#import <GLFW/glfw3.h>

using namespace rmx;

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

int * Geometry::vertices() {
    return _vertexData;
}

int * Geometry::indexData() {
    return _indexData;
}
void Geometry::addVertex(Vector3 v) {
    _cube.addVertex(v.x, v.y, v.z);
}

void Geometry::addVertex(float x, float y, float z)  {
    if (_e >= _elements.capacity())
        System.out.println("ERROR: TOO MANY ELEMENTS");
    _elements.put((byte) x);
    _elements.put((byte) y);
    _elements.put((byte) z);
    //		_elements[_e++] = x;
    //		_elements[_e++] = y;
    //		_elements[_e++] = z;
    
}
void Geometry::prepare() {
    _elements.flip();
    _indexData.flip();
}

void Geometry::pushMatrx(Node node, Matrix4 base) {
    //		Matrix4 m = (Matrix4) modelViewMatrix.clone();
    _modelView.set(node.transform.worldMatrix());
    //		AxisAngle4f baseA = new AxisAngle4f();
    //		baseA.set(base);
    //		AxisAngle4f modelA = new AxisAngle4f();
    //		modelA.set(_modelView);
    
    EulerAngles baseA = base.eulerAngles();
    EulerAngles modelA = _modelView.eulerAngles();
    baseA.scale(1 / click.rmx.RMX.PI_OVER_180);
    modelA.scale(1 / click.rmx.RMX.PI_OVER_180);
    
    glPushMatrix();
    
    
    //		glRotatef(baseA.angle, baseA.x, baseA.y, baseA.z);
    //		glRotatef(modelA.angle, modelA.x, modelA.y, modelA.z);
    
    //		glRotatef(baseA.x, 1,0,0);
    //        glRotatef(baseA.y, 0,1,0);
    //        glRotatef(baseA.z, 0,0,1);
    
    
    
    
    //		 glMultMatrixf(_modelView.buffer())
    glTranslatef(
                 base.m30,
                 base.m31,
                 base.m32
                 );
    
    
    glTranslatef(
                 _modelView.m30,
                 _modelView.m31,
                 _modelView.m32
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
void Geometry::render(Node node, Matrix4 modelMatrix) {
    //		 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //		         glLoadIdentity();
    
    this.pushMatrx(node, modelMatrix);
    float
    X = node.transform.scale().x,
    Y = node.transform.scale().y,
    Z = node.transform.scale().z;
    drawWithScale(X, Y, Z);
    
    this.popMatrix();
}

void Geometry::_render() {
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
    return _cube;
}


Geometry::Cube() {
    if (_cube == nullptr)
        _cube = new Cube();
    return _cube;
}


Cube::drawWithScale(float X, float Y, float Z) {
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