//
//  Interfaces.h
//  RMXKit
//
//  Created by Max Bilbow on 28/07/2015.
//  Copyright © 2015 Rattle Media Ltd. All rights reserved.
//

#ifndef EventListener_h
#define EventListener_h


#endif /* EventListener */
//#import <iostream>

typedef NSString* AnEvent;
typedef void * EventArgs;

/*!
 * 
 *   @author Max Bilbow, 15-08-04 16:08:32
 *
 *   @brief  abstract class for EventListeners
 *   @see NotificationCenter
 *   @since 0.1
 */
@protocol RMXEventListener <NSObject>

/*!
 *  @author Max Bilbow, 15-08-04 16:08:01
 *
 *  Initializes and adds the object to the list of active event listeners.
 *  @param name (default: "") inherited from rmx::Object
 *  @param add (default: true) whether to add this listener on initialization
 *  @see Object
 *  @since <#0.1#>
 */
@optional
- (id)initWithName:(NSString *)name andAddToListeners:(BOOL)add;



/*!
 *  @author Max Bilbow, 15-08-04 16:08:30
 *
 *  Notify's all active listeners that an event is about to start
 *  @param theEvent as string
 *  @param args     anything
 *  @since 0.1
 */
- (void)onEventDidStart:(AnEvent)theEvent withArgs:(EventArgs)args;

/*!
 *  @author Max Bilbow, 15-08-04 16:08:53
 *
 *  Notify's all active listeners that an event did start
 *  @param theEvent string identifier
 *  @param args     anything
 *  @since 0.1
 */
- (void)onEventDidEnd:(AnEvent)theEvent withArgs:(EventArgs)args;

/*!
 *   @author Max Bilbow, 15-08-04 16:08:55
 *
 *   Receives a message
 *   Has to be overridden for to add specific method handing
 *   as it is currently not automatic to call a method this way
 *   @param message Name of selector or any other message
 *   @param args    any object.
 *   @since 0.1
 */
- (void)sendMessage:(NSString*)message withArgs:(EventArgs)args;

@required
/*!
 *   @author Max Bilbow, 15-08-04 16:08:22
 *
 *   @brief  Inserts the object into Notification::listeners, if it isn't already inserted.
 *
 *   @see NotificationCenter::addListener(listener)
 *   @since 0.1
 */
- (void)startListening;

/*!
 *   @author Max Bilbow, 15-08-04 16:08:22
 *
 *   @brief  Removes the object from Notification::listeners, if it exists in the list.
 *   @see NotificationCenter::removeListener(listener)
 *   @since 0.1
 */
- (void)stopListening;

/*!
 *  @author Max Bilbow, 15-08-06 18:08:25
 *
 *  Removes the listener from notification center otherwise memory leaks may occur later
 *  @since 0.1
 */
- (void)dealloc;

@end




