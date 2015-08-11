//
//  RMXObject.m
//  RMXKit
//
//  Created by Max Bilbow on 06/08/2015.
//  Copyright © 2015 Max Bilbow. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RMXBehaviour.h"
#import "RMXEventListener.h"
#import "RMXObject.h"
#import "RMXSingleton.h"
#import "RMXNotificationCenter.h"


@implementation RMXObject {
    @private unsigned int _id;
}

- (void)startListening {
    [RMXNotificationCenter addListener:self];
}

- (void)stopListening {
    [RMXNotificationCenter removeListener:self];
}

- (void)dealloc {
    [RMXNotificationCenter removeListener:self];
    [_allObjects removeObject:self];
    NSLog(@"deleting %@", [self uniqueName]);
}

/*!
 *  @author Max Bilbow, 15-08-06 17:08:35
 *
 *  The number of instances created; used to assign the the unique _id on initialization.
 *  @since 0.1
 */
static unsigned int _count = 0;
static NSMutableArray<RMXObject*> * _allObjects;



/*!
 *  @author Max Bilbow, 15-08-06 17:08:33
 *
 *  A static collection of all active Object instances.
 *  @see LinkedList<Value>
 *  @since 0.1
 */
+ (NSMutableArray<RMXObject*>*)AllObjects {
    return _allObjects;
}

/*!
 *  @author Max Bilbow, 15-08-06 17:08:13
 *
 *  The unique id of the instance as an unsigned int.
 *  @since 0.1
 */
- (unsigned int)uniqueID {
    return _id;
}


/*!
 *  @author Max Bilbow, 15-08-06 16:08:50
 *
 *  Returns the name with the uniqueID in brackets
 *  For name without id, use Name();
 *  @return the name with the uniqueID
 *  @since 0.1
 *  @see Name()
 */
- (NSString*)uniqueName {
    return [NSString stringWithFormat:@"%@ (%u)", _name, _id];
}

/*!
 *  @author Max Bilbow, 15-08-06 17:08:50
 *
 *  @return The total number of rmx::Objects that currently exist in the system.
 *  @since 0.1
 */
- (int)Count {
    return (int) [_allObjects count];
}


/*!
 *  @author Max Bilbow, 15-08-06 16:08:41
 *
 *  Initiates with default name "Unnamed Object"
 *  @since 0.1
 */
- (id)initWithName:(NSString*)name {
    _name = name;
    _id = _count++;
    [_allObjects addObject:self];
    return self;
}

- (id)init {
    _name = @"Unnamed Object";
    return self;
}

- (id)clone {
    void * ptr = malloc(sizeof(self));
    memcpy(ptr, (void*)CFBridgingRetain(self), sizeof(self));
    RMXObject * o = (RMXObject *) CFBridgingRelease(ptr);
    o->_id = _count++;
    if (![o.name containsString:@"CLONE of \""]) {
        [o setName: [NSString stringWithFormat:@"CLONE of \"%@\" (%ui)", _name, _id ]];
    }
    [_allObjects addObject:o];
#if DEBUG_MALLOC
    NSLog(@"~INITIALIZING CLONE: %@", [o uniqueName]);
#endif
    return o;
}


/*!
 *  @author Max Bilbow, 15-08-06 16:08:42
 *
 *  @discussion Does not currently work as desired. Not sure if messages sending,
 *  in this mannor is possible in c++ without excessive overhead.
 *  It might be possible to externally reference Objective-C but
 *  probably not an ideal solution.
 *
 *  @param message the name of the method to call
 *  @param args    any value
 *  @param options e.g. should an error be thrown if no receiver present?
 *  @since 0.1
 *  @TODO: find a way of making this work...
 */
- (void) sendMessage:(NSString*)message {
    SEL selector = NSSelectorFromString(message);
    if ([self respondsToSelector:selector])
        [self performSelector:selector];
    else 
        NSLog(@"Received Message: %@, but selector not found.", message);
}
- (void) sendMessage:(NSString*)message withArgs:(id)args {
    SEL selector = NSSelectorFromString(message);
    if ([self respondsToSelector:selector]) {
        [self performSelector:selector withObject:args];
    } else {
        NSLog(@"Received Message: %@, but selector not found.", message);
    }
    
}

/*!
 *  @author Max Bilbow, 15-08-06 16:08:43
 *
 *
 *  @return A LinkedList<Object>:Iterator containing all available Objects in the system.
 *  @since 0.1
 */
- (void*) /*LinkedList<Object>::Iterator*/ ObjectIterator {
    return NULL;
}

- (NSString*)description {
    return [self uniqueName];
}

@end