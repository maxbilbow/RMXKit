//
//  RMXEngine.h
//  RMXKit
//
//  Created by Max Bilbow on 18/08/2015.
//  Copyright © 2015 Rattle Media Ltd. All rights reserved.
//

#ifndef RMXEngine_h
#define RMXEngine_h


#endif /* RMXEngine_h */

#define _GLFW_COCOA         1
#define _GLFW_USE_OPENGL    1




#import "RMXKit.h"

#import <GLKit/GLKMatrix4.h>
#import <GLKit/GLKVector3.h>
#import <GLKit/GLKVector4.h>

typedef GLKMatrix4 Matrix4;
typedef GLKVector3 Vector3;
typedef GLKVector4 Vector4;
typedef GLKQuaternion Quaternion;
#import "RMXMath.hpp"
#import "NodeComponent.hpp"
#import "PhysicsWorld.hpp"
#import "Geometry.hpp"
#import "Node.hpp"
#import "Transform.hpp"
#import "PhysicsBody.hpp"
#import "Camera.hpp"
#import "Behaviour.hpp"
#import "Scene.hpp"
#import "GameView.hpp"
#import "GameController.hpp"


