//
//  Object.cpp
//  RMXKit
//
//  Created by Max Bilbow on 30/07/2015.
//  Copyright © 2015 Rattle Media Ltd. All rights reserved.
//

#import "RMXKit.h"
#define DEBUG_THIS  (DEBUG_INCLUDE_TEST_OUTPUT || DEBUG_RMX_OBJECT)
//#import "Object.h"
//#import <iostream>
using namespace std;
using namespace rmx;


LinkedList<Object> Object::_allObjects = LinkedList<Object>();

std::ostream& operator<<(std::ostream &strm,  rmx::Printable * a) {
    if (a == nullptr)
        return strm << "WARNING: Object was deleted!";
    else
        return strm << a->ToString();
}

std::ostream& operator<<(std::ostream &strm,  rmx::Printable & a) {
    return strm << typeid(a).name() <<  " @ " << static_cast<void *>(&a) << " >> " << &a;//.ToString();
}

unsigned int Object::_count = 0;
unsigned int Object::_deleted = 0;
LinkedList<Object> * _allObjects = new LinkedList<Object>();

class Thing {
public:
    std::string name = "Hello, I'm Barry!";
};



void RMXObjectCloneTest(){
    std::cout << "\n\n******** BEGIN TEST: Object Cloning ********\n" << std::endl;
    Object * o = new Object();
    
#if DEBUG_THIS
    Object * o2 = o;
#endif
    Object * clone = o->clone();
    Object * clone2 = Object::Instantiate(clone);
    
    
    o->setName("o1");
    o->setDescription("I am the first object");
    
    clone->setName("Clone1");
    clone->setDescription("I am a clone of the first object");
    
    clone2->setName("clone2");
    clone2->setDescription("AND IM A CLONE OF A CLONE!");
    
    Thing barry = Thing();
    Thing * baz = Object::Instantiate(&barry);
    baz->name = "And I'm his bloody clone!";
#if DEBUG_THIS
    cout << "\nto_string:       " << o->ToString() << endl;
    cout << "\npointer o:       " << o << endl;
    cout << "\npointer2 o2:     " << o2 << endl;
    cout << "\nclone pointer:   " << clone << endl;
    cout << "\nclone2 pointer:  " << clone2 << endl;
    
    
    
    cout << "\ninstance *o:     " << *o << endl;
    cout << "\ninstance2 *o2:   " << *o2 << endl;
    cout << "\nclone instance:  " << *clone << endl;
    cout << "\nclone2 instance: " << *clone2 << endl;
    
    cout << "\n         Barry:  " << barry.name << endl;
    cout << "\n           Baz:  " << baz->name << endl;
#endif
    //    cout << o->clone() << endl;
    
    //    OpenGLView::Run(argc, argv);
    
    //    NotificationCenter::Test();
    std::cout <<   "\n********   END TEST: Object Cloning ********\n" << std::endl;
}


void RMXPrintableTest() {
    std::cout <<   "\n******** BEGIN TEST: PRINTABLE ********\n" << std::endl;
    Printable * theObject = new Printable();
    theObject->setDescription("Hello, World!");
#if DEBUG_THIS || DEBUG_RMX_PRINTABLE
    cout << theObject << endl;
    cout << *theObject << endl;
#endif
    std::cout <<   "\n********   END TEST: PRINTABLE ********\n" << std::endl;
}

class AnObject : public Object {
    
};


void RMXObjectCountInitAndDeinitTest() {
    std::cout << "\n\n******** BEGIN TEST: Objec Count & Deinint ********\n" << std::endl;
#if DEBUG_THIS || D_ObjectCountInitAndDeinitTest
    cout << "List Count: " << Object::AllObjects()->count() << ", Object count: " << Object::Count() << endl;
#endif
    Object::AllObjects()->deleteAll();
#if DEBUG_THIS || D_ObjectCountInitAndDeinitTest
    cout << "List Count: " << Object::AllObjects()->count() << ", Object count: " << Object::Count() << endl;
#endif

    
    AnObject * thing = new AnObject();
#if DEBUG_THIS || D_ObjectCountInitAndDeinitTest
    cout << "++Objects: " << Object::Count() << endl;
#endif
    AnObject * thing2 = new AnObject();
#if DEBUG_THIS || D_ObjectCountInitAndDeinitTest
    cout << "++Objects: " << Object::Count() << endl;
#endif
    AnObject * thing3 = (AnObject*) thing->clone();
#if DEBUG_THIS || D_ObjectCountInitAndDeinitTest
    cout << "++Objects: " << Object::Count() << endl;
#endif
    EventListener * thing4 = new EventListener();
#if DEBUG_THIS || D_ObjectCountInitAndDeinitTest
    cout << "++Objects: " << Object::Count() << endl;
#endif

    delete thing;
#if DEBUG_THIS || D_ObjectCountInitAndDeinitTest
    cout << "--Objects: " << Object::Count() << endl;
#endif
    delete thing2;
#if DEBUG_THIS || D_ObjectCountInitAndDeinitTest
    cout << "--Objects: " << Object::Count() << endl;
#endif
    delete thing3;
#if DEBUG_THIS || D_ObjectCountInitAndDeinitTest
    cout << "--Objects: " << Object::Count() << endl;
#endif
    delete thing4;
#if DEBUG_THIS || D_ObjectCountInitAndDeinitTest
    cout << "--Objects: " << Object::Count() << endl;
#endif
    
    std::cout <<   "\n********   END TEST: Objec Count & Deinint ********\n" << std::endl;
    
}