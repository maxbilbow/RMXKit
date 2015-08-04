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
#import <iostream>
#import "Object.hpp"
//#import "NotificationCenter.hpp"


namespace rmx {
    
    class EventListener : public Object {
        ///Private initilization adds this object to NotificationCenter::listeners iff add == true;
        ///@see NotificationCenter::listeners
        void init(bool add = true);
    public:
        typedef std::string AnEvent;
        typedef void * EventArgs;
        
        ///Initializes and adds the object to the list of active event listeners.
        EventListener(std::string name = "", bool add = true):Object(name) {
            this->init(add);
        }
        
        ~EventListener();
        
        ///Notify's all active listeners that an event is about to start
        virtual void OnEventDidStart(AnEvent theEvent, EventArgs args) {
            std::cout << *this << "\n       Event Started: " << theEvent << ", with args: " << args << std::endl << std::endl;
        }
        
        ///Notify's all active listeners that an event did start
        virtual void OnEventDidEnd(AnEvent theEvent, EventArgs args) {
            std::cout << *this << "\n         Event Ended: " << theEvent << ", with args: " << args << std::endl << std::endl;
        }

        
        ///Receives a message
        /// Has to be overridden for to add specific method handing
        /// as it is currently not automatic to call a method this way
        virtual void SendMessage(AnEvent message, EventArgs args = nullptr){
            std::cout << *this << "\n    Message Received: " << message << std::endl << std::endl;
        }

       
        
        void StartListening();
        
        void StopListening();

        
        ///Extends the Object::clone() method so that the listening status of the object is also copied.
        ///@see NotificationCenter::addListener(listener);
        EventListener * clone() override;

    };

}


///Successfull test of
/// • Object::clone()
/// • Object::Instantiate(Object inheritance)
/// • Event Listening with cloned objects
void RMXEventListenerTest();

