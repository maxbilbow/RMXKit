//
//  main.cpp
//  AiCubo
//
//  Created by Max Bilbow on 28/07/2015.
//  Copyright © 2015 Rattle Media Ltd. All rights reserved.
//

#import <iostream>


#import "RMXKit.h"

//#import "LinkedList.hpp"
//#import "Dictionary.hpp"
//#import "ASingleton.hpp"
//#import "Object.hpp"


#define quote(x) #x

//#import "OpenGLView.hpp"

using namespace std;
using namespace rmx;






int main(int argc, char * argv[]) {
    RMXLinkedListTest();
    RMXDictionaryTest();
    RMXObjectCloneTest();
    RMXEventListenerTest();
    return 0;
}
