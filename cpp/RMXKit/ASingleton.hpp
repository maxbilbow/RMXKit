//
//  ASingleton.hpp
//  RMXKit
//
//  Created by Max Bilbow on 30/07/2015.
//  Copyright © 2015 Rattle Media Ltd. All rights reserved.
//

#ifndef ASingleton_hpp
#define ASingleton_hpp

#include <stdio.h>

#endif /* ASingleton_hpp */

#import <iostream>
#import "Object.hpp"

namespace rmx {
    ///Not a true singleton as additional objects can be created through decendants.
    ///However current() is a simple way of having one main statically available instance.
    ///Useuful for switching between camera objects, for example.
    ///setCurrent(T) returns the value that was replaced.
    template <class T>
    class ASingleton {
        static T * _current;
    public:
        static T * current() {
            if (_current != nullptr)
                return _current;
            else
                _current = new T();
            return _current;
        }
        
        ///Sets the current static "Singleton" and returns the old
        static T * setCurrent(T * t) {
            T * old = _current;
            _current = t;
            return old;
        }
    };
    
}