//
//  RMXNotificationCenter.h
//  RMXKit
//
//  Created by Max Bilbow on 28/07/2015.
//  Copyright © 2015 Rattle Media Ltd. All rights reserved.
//

#ifndef RMXNotificationCenter_m
#define RMXNotificationCenter_m


#endif /* RMXNotificationCenter_m */

#define EVENT_STATUS_IDLE       0ui
#define EVENT_STATUS_ACTIVE     1ui
#define EVENT_STATUS_COMPLETE   2ui
#define EVENT_STATUS_FAILURE    3ui


//#import "LinkedList.h"
//#import "Dictionary.h"
//#import "EventListener.h"

//typedef struct _RMXEvent {
//    unsigned short status;
//} RMXEvent;



/*!
 *   @author Max Bilbow, 15-08-04 16:08:21
 *
 *   @brief  static class for handling global notifications throughout a system.
 *
 *   @since 0.1
 */
@interface RMXNotificationCenter : NSNotificationCenter

typedef id<RMXEventListener> EventListener;
typedef NSString * EventType;
typedef void * EventArgs;
typedef unsigned short EventStatus;

/*!
 *  @author Max Bilbow, 15-08-06 20:08:21
 *
 *  Activate the NotificationCenter. Must be called once.
 *  @since 0.1
 */
+ (void)Start;

/*!
 *  @author Max Bilbow, 15-08-04 17:08:42
 *  Returns true if the listener exists withing listeners
 *  i.e. The given listener is listening.
 *  @since 0.1
 */
+ (BOOL)hasListener:(EventListener)listener;

/*!
 *  @author Max Bilbow, 15-08-04 17:08:42
 *  If the given EventType exists and is not Idle, the event's status is set to EVENT_STATUS_IDLE.
 *  @since 0.1
 */
+ (void)reset:(EventType)theEvent;

/*!
 *  @author Max Bilbow, 15-08-04 17:08:42
 *  Adds the given listerner to listenrers iff it does not already exist (i.e. is already listening)
 *  @since 0.1
 */
+ (void)addListener:(EventListener)listener;

/*!
 *  @author Max Bilbow, 15-08-04 17:08:42
 *  Removes the given listener from the list (i.e. it stops listening)
 *  @since 0.1
 */
+ (EventListener)removeListener:(EventListener)listener;

/*!
 *  @author Max Bilbow, 15-08-04 17:08:42
 *  Returns the status of a given EventType or the default 'Idle' if the EventType was never started.
 *  @since 0.1
 */
+ (EventStatus)statusOf:(EventType)theEvent;

/*!
 *  @author Max Bilbow, 15-08-04 17:08:42
 *  Returns true iff an event is EVENT_STATUS_IDLE or non-existent
 *  @since 0.1
 */
+ (BOOL)isIdle:(EventType)theEvent;

/*!
 *  @author Max Bilbow, 15-08-04 17:08:42
 *
 *  Returns true iff an event is EVENT_STATUS_ACTIVE
 *  @since 0.1
 */
+ (BOOL)isActive:(EventType)theEvent;

/*!
 *  @author Max Bilbow, 15-08-04 17:08:42
 
 *  Returns true iff an event exists and has the status EVENT_STATUS_COMPLETE.
 *  @see eventDidEnd(EventType theEvent, EventArgs o);
 *  @code
 *  NotificationCenter::eventDidEnd("Something finished happening", EVENT_STATUS_COMPLETE);
 *  @endcode
 *  @since 0.1
 */
+ (BOOL)isComplete:(EventType)theEvent;

/*!
 *  @author Max Bilbow, 15-08-04 17:08:42
 
 *  Returns true iff an event exists and has the status EVENT_STATUS_FAILURE.
 *  @see eventDidEnd(EventType theEvent, EventArgs o);
 *  @code
 *  NotificationCenter::eventDidEnd("Something finished happening", EVENT_STATUS_FAILURE);
 *  @endcode
 *  @since 0.1
 */
+ (BOOL)didFail:(EventType)theEvent;

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
+ (void)eventDidOccur:(EventType)theEvent;
+ (void)eventDidOccur:(EventType)theEvent withArgs:(EventArgs)args;

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
+ (void)eventWillStart:(EventType)theEvent;
+ (void)eventWillStart:(EventType)theEvent withArgs:(EventArgs)args;

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
+ (void)eventDidEnd:(EventType)theEvent;
+ (void)eventDidEnd:(EventType)theEvent withArgs:(EventArgs)args;

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
+ (void)notifyListeners:(NSString*)message;
+ (void)notifyListeners:(NSString*)message withArgs:(EventArgs)args;

@end;
