//
//  RMXSingleton.m
//  RMXKit
//
//  Created by Max Bilbow on 08/08/2015.
//  Copyright © 2015 Max Bilbow. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RMXBehaviour.h"
#import "RMXEventListener.h"
#import "RMXObject.h"
#import "RMXSingleton.h"


@implementation RMXSingleton

//static RMXSingleton * _current;



- (instancetype)init {
    if ([[self class] isInitialized])
        return [self class].current;
    else {
        self = [super init];
        [[self class]setCurrent:self];
        [self sendMessage:@"doOnInit"];
//        [self sendMessage:@"setCurrent:" withArgs:self];
        return self;
    }
}

- (instancetype)initWithName:(NSString *)name {
    if ([[self class] isInitialized])
        return [self class].current;
    else {
        self = [super initWithName:name];
        [[self class]setCurrent:self];
        [self sendMessage:@"doOnInit"];
//        [self sendMessage:@"setCurrent:" withArgs:self];
        return self;
    }
}

+ (instancetype)current {
    if ([self isInitialized])
        return self.current;
    else
        
    return self.current;
}

//- (void)dealloc {
//    if (_current == self)
//        return
//    NSLog(@"Dealocaed a singleton!");
//}
@end

//
//static T * _current;
//public:
//static T * current() {
//    if (_current != nullptr)
//        return _current;
//    else
//        _current = new T();
//    return _current;
//}
//
//~ASingleton() {
//    _current = nullptr;
//    Object::~Object();
//}
//
/////Sets the current static "Singleton" and returns the old
//static T * setCurrent(T * t) {
//    T * old = _current;
//    _current = t;
//    return old;
//}