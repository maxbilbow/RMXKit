//
//  RMXMath.hpp
//  RMXKit
//
//  Created by Max Bilbow on 19/08/2015.
//  Copyright © 2015 Rattle Media Ltd. All rights reserved.
//

#ifndef RMXMath_hpp
#define RMXMath_hpp

#include <stdio.h>

#endif /* RMXMath_hpp */

#define PI 3.147f
#define PI_OVER_180 (PI/180)

Vector3 RMXMatrix4Position(Matrix4 m);
Vector3 operator+(Vector3 lhs,  Vector3 rhs);
Vector3 operator-(Vector3 lhs,  Vector3 rhs);
Vector3 operator*(Vector3 lhs,  Vector3 rhs);
Vector3 operator/(Vector3 lhs,  Vector3 rhs);

Vector3 operator*(Vector3 lhs,  float rhs);
Vector3 operator/(Vector3 lhs,  float rhs);


void operator+=(Vector3& lhs,  Vector3 rhs);
void operator-=(Vector3& lhs,  Vector3 rhs);
void operator*=(Vector3& lhs,  Vector3 rhs);
void operator/=(Vector3& lhs,  Vector3 rhs);

void operator*=(Vector3& lhs,  float rhs);
void operator/=(Vector3& lhs,  float rhs);