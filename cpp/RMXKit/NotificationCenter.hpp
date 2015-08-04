//
//  RMXNotificationCenter.hpp
//  RMXKit
//
//  Created by Max Bilbow on 28/07/2015.
//  Copyright © 2015 Rattle Media Ltd. All rights reserved.
//

#ifndef RMXNotificationCenter_cpp
#define RMXNotificationCenter_cpp

//#include <stdio.h>
//#import <list>
//#import <vector>



#endif /* RMXNotificationCenter_cpp */

#define EVENT_STATUS_IDLE       0ui
#define EVENT_STATUS_ACTIVE     1ui
#define EVENT_STATUS_COMPLETE   2ui
#define EVENT_STATUS_FAILURE    3ui


#import "LinkedList.hpp"
#import "Dictionary.hpp"
#import "EventListener.hpp"
namespace rmx {
    
    ///static class for handling global notifications throughout a system.
    class NotificationCenter {
    public:
        typedef void * EventArgs;
        typedef std::string EventType;
        typedef unsigned short EventStatus;
    private:
        ///List of all active EventListeners, assuming they were added to the list.
        ///@see EventListener::EventListener(std::string name, bool add);
        static LinkedList<EventListener> * listeners;
        
        ///Dictionaty containing all events, that have been activated at least once, and their statuses.
        static Dictionary<EventType, EventStatus> * events;

    public:
        
//        static NotificationCenter * current();
        ///Returns true if the listener exists withing listeners
        ///i.e. The given listener is listening.
        static bool hasListener(EventListener * listener);
        
        ///If the given EventType exists and is not Idle, the event's status is set to EVENT_STATUS_IDLE.
        static void reset(EventType theEvent);
        
        ///Adds the given listerner to listenrers iff it does not already exist (i.e. is already listening)
        static void addListener(EventListener * listener);
        
        ///Removes the given listener from the list (i.e. it stops listening)
        static EventListener * removeListener(EventListener * listener);
        
        ///Returns the status of a given EventType or the default 'Idle' if the EventType was never started.
        static EventStatus statusOf(EventType theEvent);
        
        ///Returns true iff an event is EVENT_STATUS_IDLE or non-existent
        static bool isIdle(EventType theEvent);
        
        ///Returns true iff an event is EVENT_STATUS_ACTIVE
        static bool isActive(EventType theEvent) ;
        
        
        ///Use this when you merely wish to notify of an events occurrance and do not have any actions to perform between eventWillStart() and eventDidEnd()
        ///@code
        ///if (check that something happenned) {
        ///   NotificationCenter::eventDidOccur("Something Happened", Args);
        ///}
        ///@endcode
        ///@see Calls eventWillStart(EventType theEvent, EventArgs o), @see eventDidEnd(EventType theEvent, EventArgs o)
        static void eventDidOccur(EventType theEvent, EventArgs o = nullptr);
        
        ///Returns true iff an event exists and has the status EVENT_STATUS_COMPLETE.
        ///@see eventDidEnd(EventType theEvent, EventArgs o);
        ///@code
        ///NotificationCenter::eventDidEnd("Something finished happening", EVENT_STATUS_COMPLETE);
        ///@endcode
        static bool isComplete(EventType theEvent);
        
        ///Returns true iff an event exists and has the status EVENT_STATUS_FAILURE.
        ///@see eventDidEnd(EventType theEvent, EventArgs o);
        ///@code
        ///NotificationCenter::eventDidEnd("Something finished happening", EVENT_STATUS_FAILURE);
        ///@endcode
        static bool didFail(EventType theEvent);
        
        ///Call this method before performing an event.
        ///@code
        ///NotificationCenter::eventWillStart("Something id happening", Args);
        ///PerformAnEvent();
        ///NotificationCenter::eventDidEnd("Something id happening", Args);
        ///@endcode
        ///@see Calls eventWillStart(EventType theEvent, EventArgs o)
        ///@see eventDidEnd(EventType theEvent, EventArgs o)
        static void eventWillStart(EventType theEvent, EventArgs o = nullptr);

        ///Call this method once an event has finished.
        ///@code
        ///NotificationCenter::eventWillStart("Something id happening", Args);
        ///PerformAnEvent();
        ///NotificationCenter::eventDidEnd("Something id happening", Args);
        ///@endcode
        ///@see Calls eventWillStart(EventType theEvent, EventArgs o)
        ///@see eventDidEnd(EventType theEvent, EventArgs o)
        static void eventDidEnd(EventType theEvent, EventArgs o = nullptr);
        
        ///Ideally this should invoke custom methods that are present.
        ///However it is not currently possible to convert strings to method names so the Object::SendMessage(message,args) method will have to be overridden to implement the desired behaviour.
        ///see EventListener::SendMessage(message,args);
        static void notifyListeners(std::string message, EventArgs args = nullptr);
        
    };
}

