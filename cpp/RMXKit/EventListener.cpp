//
//  EventListener.cpp
//  RMXKit
//
//  Created by Max Bilbow on 30/07/2015.
//  Copyright © 2015 Rattle Media Ltd. All rights reserved.
//


#import "EventListener.hpp"
#import "NotificationCenter.hpp"

using namespace rmx;
using namespace std;

void EventListener::init(bool add) {
    if (add)
        NotificationCenter::addListener(this);
}

EventListener * EventListener::clone() {
    EventListener * clone =  (EventListener*) Object::clone();
    if (NotificationCenter::hasListener(this)) {
        cout << "\n *** Should Add the Clone: " << Name() << endl << endl;
        NotificationCenter::addListener(clone);
    } else {
        cout << "\n *** Diddn't Add the Clone: " << Name() << endl << endl;
    }
    
    return clone;
}

void RMXEventListenerTest(){
    EventListener * o = new EventListener(" O Will Listen");
    EventListener p = EventListener(" P Will Listen");
    EventListener p2 = EventListener("P2 Not Listening", false);
    p.setDescription("I am the second object! I SHOULD LISTEN");
    p2.setDescription("I am the third object and shaln't be listening!");
//    p2.clone();
//    o->setName("o1");
    EventListener * clone = o->clone();
    EventListener * clone2 = Object::Instantiate(clone);
    Object::Instantiate(&p);
    Object::Instantiate(&p2);
//    clone2->setName("clone2");
    clone2->setDescription("AND IM A CLONE OF A CLONE! I SHOULD LISTEN");
    

    o->setDescription("I am the first object: I SHOULD LISTEN");
    
//    clone->setName("Clone1");
    clone->setDescription("I am a clone of the first object: I SHOULD LISTEN");
    
//    cout << endl;
//    cout << *o << endl;
//    cout << *clone << endl;
//    cout << *clone2 << endl;
//    cout << p.ToString() << endl;
//    cout << p2.ToString() << endl;
//    cout << endl;
    
    NotificationCenter::eventDidOccur("Something's Happening!",  new string("Poof!"));
    NotificationCenter::notifyListeners("MESSAE RECEIVED!");

}