//
//  ASingleton.hpp
//  RMXKit
//
//  Created by Max Bilbow on 30/07/2015.
//  Copyright © 2015 Rattle Media Ltd. All rights reserved.
//

#ifndef ASingleton_hpp
#define ASingleton_hpp


#endif /* ASingleton_hpp */


//#import "RMXObject.h"

@protocol RMXSingleton

///Return the current singleton or initialize a new one
+ (instancetype)current;

- (void)setCurrent:(id)singleton;

+ (BOOL)isInitialized;

///null the current singleton
- (void)dealloc;

@optional
- (void)doOnInit;

@end

/*!
 *   Not a true singleton as additional objects can be created through decendants.
 *   However current() is a simple way of having one main statically available instance.
 *   Useuful for switching between camera objects, for example.
 *   setCurrent(T) returns the value that was replaced.
 *
 *   @since <#0.1#>
 */
@interface RMXSingleton : RMXObject


+ (instancetype)current;
+ (BOOL)isInitialized;


@end
    
