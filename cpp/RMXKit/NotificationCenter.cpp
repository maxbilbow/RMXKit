//
//  RMXNotificationCenter.cpp
//  RMXKit
//
//  Created by Max Bilbow on 28/07/2015.
//  Copyright © 2015 Rattle Media Ltd. All rights reserved.
//


#import <iostream>
//#import "EventListener.hpp"
//#import "LinkedList.hpp"
//#import "Dictionary.hpp"
#import "NotificationCenter.hpp"


using namespace rmx;

typedef NotificationCenter::EventArgs EventArgs;
typedef NotificationCenter::EventType EventType;
typedef NotificationCenter::EventStatus EventStatus;




using namespace std;

NotificationCenter::NotificationCenter() {
    listeners = new LinkedList<EventListener>();
    events = new Dictionary<EventType, EventStatus>();
}

static bool _init;
static NotificationCenter * _current;

NotificationCenter * NotificationCenter::current() {
    if (!_init) {
        _current = new NotificationCenter();
        _init = true;
    }
    return _current;
}
    
bool NotificationCenter::hasListener(EventListener * listener) {
     return current()->listeners->contains(listener);// Listeners.Contains (listener);
}

void NotificationCenter::reset(EventType theEvent) {
//    theEvent->status = Idle;
    current()->events->setValueForKey(theEvent, EVENT_STATUS_IDLE);
}
    
void NotificationCenter::addListener(EventListener * listener) {
    if (!current()->listeners->contains (listener)) {
        current()->listeners->append(listener);
//        cout << "\nAdded to Listeners: " << *listener << endl;
    } else {
        cout << "\n !! Not Adding => Listeners already contain: " << *listener << endl;
    }
}

EventListener * NotificationCenter::removeListener(EventListener * listener) {
    return current()->listeners->removeValue(listener);
}

EventStatus NotificationCenter::statusOf(EventType theEvent) {
    try {
        return *current()->events->getValueForKey(theEvent);
    } catch (exception e) {
        cout << e.what() << ": setting new event as Idle" << endl;
        current()->events->setValueForKey(theEvent, EVENT_STATUS_IDLE);
        return EVENT_STATUS_IDLE;
    }
}

bool NotificationCenter::isIdle(EventType theEvent) {
    return statusOf(theEvent) == EVENT_STATUS_IDLE;
}

 bool NotificationCenter::isActive(EventType theEvent) {
    return statusOf(theEvent) == EVENT_STATUS_ACTIVE;
}


void NotificationCenter::eventDidOccur(EventType theEvent, EventArgs o) {
    eventWillStart(theEvent,o);
    eventDidEnd(theEvent,o);
}


bool NotificationCenter::isComplete(EventType theEvent) {
    return statusOf(theEvent) == EVENT_STATUS_COMPLETE;
}

bool NotificationCenter::didFail(EventType theEvent) {
    return statusOf(theEvent) == EVENT_STATUS_FAILURE;
}


void NotificationCenter::eventWillStart(EventType theEvent, EventArgs o) {
    LinkedList<EventListener>::Node * node = current()->listeners->firstNode();
    if (node->value == nullptr)
        return;
    else {
        while (node != nullptr) {
            node->value->OnEventDidStart(theEvent,o);
            node = node->next;
        }
    }
}

void NotificationCenter::eventDidEnd(EventType theEvent, EventArgs o) {
    LinkedList<EventListener>::Node * node = current()->listeners->firstNode();
    if (node->value == nullptr)
        return;
    else {
        while (node != nullptr) {
            node->value->OnEventDidEnd(theEvent, o);
            node = node->next;
        }
    }
}

 void NotificationCenter::notifyListeners(string message) {
     LinkedList<EventListener>::Node * node = current()->listeners->firstNode();
     if (node->value == nullptr)
         return;
     else {
         while (node != nullptr) {
             node->value->SendMessage(message);
             node = node->next;
         }
     }
}

void NotificationCenter::Test() {
    (new EventListener())->SendMessage("Yo!");
    NotificationCenter::eventWillStart("Hello, world!");
    NotificationCenter::eventDidEnd("Googbye, world!");
}
    
