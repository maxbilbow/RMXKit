//
//  RMXMath.cpp
//  RMXKit
//
//  Created by Max Bilbow on 19/08/2015.
//  Copyright © 2015 Rattle Media Ltd. All rights reserved.
//

#import "RMXEngine.hpp"
#import "RMXMath.hpp"
//#import <GLKit/GLKVector3.h>


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
