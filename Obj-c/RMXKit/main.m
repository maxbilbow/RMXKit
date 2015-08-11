//
//  main.m
//  RMXKit
//
//  Created by Max Bilbow on 06/08/2015.
//  Copyright © 2015 Max Bilbow. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "Tests.h"
#import "RMXKit.h"

@interface Listener : RMXSingleton
- (void)print;
- (void)printWithArgs:(void*)args;
@end

@implementation Listener
- (void)onEventDidStart:(AnEvent)theEvent withArgs:(EventArgs)args {
    NSLog(@"EVENT STARTS: %@, withArgs: %@", theEvent, args);
}

- (void)onEventDidEnd:(AnEvent)theEvent withArgs:(EventArgs)args {
    NSLog(@"  EVENT ENDS: %@, withArgs: %@", theEvent, args);
}
- (void)print {
    NSLog(@"Winner!");
}
- (void)printWithArgs:(void*)args {
    NSLog(@"Winner! Args: %@", args);
}

@end


int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
//        RMXLinkedListTest();
//        RMXDictionaryTest();
//        RMXObjectCloneTest();
//        RMXEventListenerTest();
//        RMXPrintableTest();
//        RMXObjectCountInitAndDeinitTest();
        //    RMXBehaviourTest();
        [RMXNotificationCenter Start];
        Listener * l = [Listener new];
        [l startListening];
        [RMXNotificationCenter notifyListeners:@"[RMXNotificationCenter notifyListeners: \"Hello, World!\"]"];
        [RMXNotificationCenter eventDidOccur:@"[RMXNotificationCenter eventDidOccur:\"An Event\"]" withArgs:@"An Argument"];
        
        [l sendMessage:@"print"]; //Works
        [l sendMessage:@"print" withArgs: @"Hello, World!"]; //Doesnt work but doesnt break either
        [l sendMessage:@"printWithArgs:" withArgs: @"Hello, World!"]; //Success!
        [l setName:@"A Supposed Singleton"];
        NSLog(@" First instance: %@", l.name);
        NSLog(@"Second instance: %@", [Listener current].name);
        NSLog(@" Third instance: %@", [Listener new].name);
        NSLog(@"Fourth instance: %@", [[Listener alloc]init].name);
        
        
    }
    return 0;
}
