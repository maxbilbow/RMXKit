//
//  RMXNotificationCenter.m
//  RMXKit
//
//  Created by Max Bilbow on 06/08/2015.
//  Copyright © 2015 Max Bilbow. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "RMXKit.h"


@implementation RMXEvent
- (id)init {
    _status = EVENT_STATUS_IDLE;
    return self;
}
@end


@implementation RMXNotificationCenter  {
    /*!
     *  @author Max Bilbow, 15-08-04 17:08:42
     *  List of all active EventListeners, assuming they were added to the list.
     *  @see EventListener::EventListener(std::string name, bool add);
     *  @since 0.1
     */
     NSMutableArray<EventListener> * listeners;
    /*!
     *
     *  @author Max Bilbow, 15-08-04 17:08:42
     *  Dictionaty containing all events, that have been activated at least once, and their statuses.
     *  @since 0.1
     */
     NSMutableDictionary<EventType, RMXEvent*> * events;
}


static RMXNotificationCenter* _current;

+ (void)setCurrent:(id)singleton {
    _current = singleton;
}

//static BOOL _init = false;
+ (void)Start {
//    if (!_init) {
//        _listeners = [NSMutableArray<RMXEventListener> new];
//        _events = [NSMutableDictionary<EventType, RMXEvent*> new];
//        _init = YES;
//        [self new];
//        
//    }
}

- (void)doOnInit {
    NSLog(@"doOnInit!");
    self._listeners = [NSMutableArray<RMXEventListener> new];
    self._events = [NSMutableDictionary<EventType, RMXEvent*> new];
//    _init = YES;

}

/*!
 *  @author Max Bilbow, 15-08-04 17:08:42
 *  Returns true if the listener exists withing listeners
 *  i.e. The given listener is listening.
 *  @since 0.1
 */
+ (BOOL)hasListener:(EventListener)listener {
    return [[RMXNotificationCenter current]._listeners containsObject: listener];
}

/*!
 *  @author Max Bilbow, 15-08-04 17:08:42
 *  If the given EventType exists and is not Idle, the event's status is set to EVENT_STATUS_IDLE.
 *  @since 0.1
 */
+ (void)reset:(EventType)theEvent {
    if ([RMXNotificationCenter current]._events[theEvent] != NULL) {
        [RMXNotificationCenter current]._events[theEvent].status = EVENT_STATUS_IDLE;
    }
}

/*!
 *  @author Max Bilbow, 15-08-04 17:08:42
 *  Adds the given listerner to listenrers iff it does not already exist (i.e. is already listening)
 *  @since 0.1
 */
+ (void)addListener:(EventListener)listener{
    [[RMXNotificationCenter current]._listeners addObject:listener];
}

/*!
 *  @author Max Bilbow, 15-08-04 17:08:42
 *  Removes the given listener from the list (i.e. it stops listening)
 *  @since 0.1
 */
+ (EventListener)removeListener:(EventListener)listener{
    if ([[RMXNotificationCenter current]._listeners containsObject:listener]) {
        [[RMXNotificationCenter current]._listeners removeObject:listener];
        return listener;
    } else {
        return NULL;
    }
}

/*!
 *  @author Max Bilbow, 15-08-04 17:08:42
 *  Returns the status of a given EventType or the default 'Idle' if the EventType was never started.
 *  @since 0.1
 */
+ (EventStatus)statusOf:(EventType)theEvent{
    RMXEvent * e = [RMXNotificationCenter current]._events[theEvent];
    if (e != NULL) {
        return  e.status;
    } else {
        return EVENT_STATUS_IDLE;
    }
}

/*!
 *  @author Max Bilbow, 15-08-04 17:08:42
 *  Returns true iff an event is EVENT_STATUS_IDLE or non-existent
 *  @since 0.1
 */
+ (BOOL)isIdle:(EventType)theEvent{
    return [self statusOf:theEvent] == EVENT_STATUS_IDLE;
}

/*!
 *  @author Max Bilbow, 15-08-04 17:08:42
 *
 *  Returns true iff an event is EVENT_STATUS_ACTIVE
 *  @since 0.1
 */
+ (BOOL)isActive:(EventType)theEvent{
    return [self statusOf:theEvent] == EVENT_STATUS_ACTIVE;
}

/*!
 *  @author Max Bilbow, 15-08-04 17:08:42
 
 *  Returns true iff an event exists and has the status EVENT_STATUS_COMPLETE.
 *  @see eventDidEnd(EventType theEvent, EventArgs o);
 *  @code
 *  NotificationCenter::eventDidEnd("Something finished happening", EVENT_STATUS_COMPLETE);
 *  @endcode
 *  @since 0.1
 */
+ (BOOL)isComplete:(EventType)theEvent{
    return [self statusOf:theEvent] == EVENT_STATUS_COMPLETE;
}

/*!
 *  @author Max Bilbow, 15-08-04 17:08:42
 
 *  Returns true iff an event exists and has the status EVENT_STATUS_FAILURE.
 *  @see eventDidEnd(EventType theEvent, EventArgs o);
 *  @code
 *  NotificationCenter::eventDidEnd("Something finished happening", EVENT_STATUS_FAILURE);
 *  @endcode
 *  @since 0.1
 */
+ (BOOL)didFail:(EventType)theEvent{
    return [self statusOf:theEvent] == EVENT_STATUS_FAILURE;
}

/*!
 *  @author Max Bilbow, 15-08-04 17:08:42
 *  Use this when you merely wish to notify of an events occurrance and do not have any actions to perform between eventWillStart() and eventDidEnd()
 *  @code
 *  if (check that something happenned) {
 *     NotificationCenter::eventDidOccur("Something Happened", Args);
 *  }
 *  @endcode
 *  @see Calls eventWillStart(EventType theEvent, EventArgs o), @see eventDidEnd(EventType theEvent, EventArgs o)
 *  @since 0.1
 */
+ (void)eventDidOccur:(EventType)theEvent {
    [RMXNotificationCenter eventDidOccur:theEvent withArgs:NULL];
}

+ (void)eventDidOccur:(EventType)theEvent withArgs:(EventArgs)args{
    [RMXNotificationCenter eventWillStart:theEvent withArgs:args];
    [RMXNotificationCenter eventDidEnd:theEvent withArgs:args];
}



/*!
 *  @author Max Bilbow, 15-08-04 17:08:42
 
 *  Call this method before performing an event.
 *  @code
 *  NotificationCenter::eventWillStart("Something id happening", Args);
 *  PerformAnEvent();
 *  NotificationCenter::eventDidEnd("Something id happening", Args);
 *  @endcode
 *  @see Calls eventWillStart(EventType theEvent, EventArgs o)
 *  @see eventDidEnd(EventType theEvent, EventArgs o)
 *  @since 0.1
 */
+ (void)eventWillStart:(EventType)theEvent{
    [RMXNotificationCenter eventWillStart:theEvent withArgs:NULL];
}

+ (void)eventWillStart:(EventType)theEvent withArgs:(EventArgs)args{
    if ([RMXNotificationCenter current]._events[theEvent] == NULL) {
        [RMXNotificationCenter current]._events[theEvent] = [RMXEvent new];
    }
    for (EventListener listener in [RMXNotificationCenter current]._listeners) {
        if ([listener respondsToSelector:@selector(onEventDidEnd:withArgs:)])
            [listener onEventDidStart:theEvent withArgs:args];
    }
    [RMXNotificationCenter current]._events[theEvent].status = EVENT_STATUS_ACTIVE;
}

/*!
 *  @author Max Bilbow, 15-08-04 17:08:17
 *
 *  Call this method once an event has finished.
 *  @code
 *  NotificationCenter::eventWillStart("Something id happening", Args);
 *  PerformAnEvent();
 *  NotificationCenter::eventDidEnd("Something id happening", Args);
 *  @endcode
 *  @see Calls eventWillStart(EventType theEvent, EventArgs o)
 *  @see eventDidEnd(EventType theEvent, EventArgs o)
 *  @param theEvent string
 *  @param o       anything
 *  @since 0.1
 */
+ (void)eventDidEnd:(EventType)theEvent {
    [RMXNotificationCenter eventDidEnd:theEvent withArgs:NULL];
}

+ (void)eventDidEnd:(EventType)theEvent withArgs:(EventArgs)args{
//    if (args is EventStatus && (EventStatus) args == EVENT_STATUS_COMPLETE)
    for (EventListener listener in [RMXNotificationCenter current]._listeners) {
        if ([listener respondsToSelector:@selector(onEventDidStart:withArgs:)])
            [listener onEventDidEnd:theEvent withArgs:args];
    }
    [self reset:theEvent];

}

/*!
 *  @author Max Bilbow, 15-08-04 17:08:52
 *
 *  Ideally this should invoke custom methods that are present.
 *  However it is not currently possible to convert strings to method names so the Object::SendMessage(message,args) method will have to be overridden to implement the desired behaviour.
 *  @see EventListener::SendMessage(message,args);
 *  @param message string
 *  @param args    anything
 *  @since 0.1
 */
+ (void)notifyListeners:(NSString*)message {
    [RMXNotificationCenter notifyListeners:message withArgs:NULL];
}

+ (void)notifyListeners:(NSString*)message withArgs:(EventArgs)args {
    for (EventListener listener in [RMXNotificationCenter current]._listeners) {
        if ([listener respondsToSelector:@selector(sendMessage:withArgs:)])
            [listener sendMessage:message withArgs:args];
    }
}

@end