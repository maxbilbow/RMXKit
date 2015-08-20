//
//  RMXMath.cpp
//  RMXKit
//
//  Created by Max Bilbow on 19/08/2015.
//  Copyright © 2015 Rattle Media Ltd. All rights reserved.
//

//#import "RMXEngine.hpp"
//#import "RMXMath.hpp"
//#import <GLKit/GLKVector3.h>
#include "Includes.h"
using namespace std;
Vector3 RMXMatrix4Position(Matrix4 m) {
    return GLKVector3Make(m.m30, m.m31, m.m32);
}

Vector3 operator+(Vector3 lhs,  Vector3 rhs) {
    return GLKVector3Add(lhs, rhs);
}

Vector3 operator-(Vector3 lhs,  Vector3 rhs) {
    return GLKVector3Subtract(lhs, rhs);
}

Vector3 operator*(Vector3 lhs,  Vector3 rhs) {
    return GLKVector3Multiply(lhs, rhs);
}

Vector3 operator/(Vector3 lhs,  Vector3 rhs) {
    return GLKVector3Divide(lhs, rhs);
}

Vector3 operator*(Vector3 lhs,  float rhs) {
    return GLKVector3MultiplyScalar(lhs, rhs);
}

Vector3 operator/(Vector3 lhs,  float rhs) {
    return GLKVector3DivideScalar(lhs, rhs);
}

void operator+=(Vector3& lhs,  Vector3 rhs){
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    lhs.z += rhs.z;
}

void operator-=(Vector3& lhs,  Vector3 rhs) {
    lhs.x -= rhs.x;
    lhs.y -= rhs.y;
    lhs.z -= rhs.z;
}

void operator*=(Vector3& lhs,  Vector3 rhs){
    lhs.x *= rhs.x;
    lhs.y *= rhs.y;
    lhs.z *= rhs.z;
}

void operator/=(Vector3& lhs,  Vector3 rhs) {
    lhs.x /= rhs.x;
    lhs.y /= rhs.y;
    lhs.z /= rhs.z;
}

void operator*=(Vector3& lhs,  float rhs) {
    lhs.x *= rhs;
    lhs.y *= rhs;
    lhs.z *= rhs;
}

void operator/=(Vector3& lhs,  float rhs) {
    lhs.x /= rhs;
    lhs.y /= rhs;
    lhs.z /= rhs;
}

string operator+(string lhs, float rhs) {
    return lhs + to_string(rhs);
}

string operator+(float lhs, string rhs) {
    return to_string(lhs) + rhs;
}

string& operator+=(string& lhs, float rhs) {
    return lhs += to_string(rhs);
}

string S(float f) {
    return to_string(f);
}

std::ostream& operator<<(std::ostream& in,  Matrix4 m) {
    string s = "Matrix:\n";
    s += S(m.m00) + ", " + m.m01 + ", " + m.m02 + ", " + m.m03 + "\n";
    s += S(m.m10) + ", " + m.m11 + ", " + m.m12 + ", " + m.m13 + "\n";
    s += S(m.m20) + ", " + m.m21 + ", " + m.m22 + ", " + m.m23 + "\n";
    s += S(m.m30) + ", " + m.m31 + ", " + m.m32 + ", " + m.m33 + "\n";
    return in << s;
}

