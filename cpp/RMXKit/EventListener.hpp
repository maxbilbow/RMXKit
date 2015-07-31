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
//    protected:
        void init(bool add = true);
    public:
        typedef std::string AnEvent;
        typedef void * EventArgs;
        EventListener(std::string name = "", bool add = true):Object(name) {
            this->init(add);
        }
        //    virtual void OnEvent(String theEvent, EventArgs args){}
        virtual void OnEventDidStart(AnEvent theEvent, EventArgs args) {
            std::cout << *this << "\n       Event Started: " << theEvent << ", with args: " << args << std::endl << std::endl;
        }
        
        virtual void OnEventDidEnd(AnEvent theEvent, EventArgs args) {
            std::cout << *this << "\n         Event Ended: " << theEvent << ", with args: " << args << std::endl << std::endl;
        }
        virtual void SendMessage(AnEvent message){
            std::cout << *this << "\n    Message Received: " << message << std::endl << std::endl;
        }
        
        EventListener * clone() override;
//        {
//            EventListener * clone =  (EventListener*) Object::clone();
//            if (NotificationCenter::hasListener(this)) {
//                NotificationCenter::addListener(clone);
//            }
//        }
    };

}



void RMXEventListenerTest();

