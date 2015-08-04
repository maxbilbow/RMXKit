//
//  Object.cpp
//  RMXKit
//
//  Created by Max Bilbow on 30/07/2015.
//  Copyright © 2015 Rattle Media Ltd. All rights reserved.
//

#import "RMXKit.h"
//#import "Object.hpp"
//#import <iostream>
using namespace std;
using namespace rmx;


std::ostream& operator<<(std::ostream &strm,  rmx::Printable &a) {
    return strm /* << "rms::inst: " << &a << " >> " << typeid(a).name() << ", info: \n   ==> " */ <<  a.ToString();
}

std::ostream& operator<<(std::ostream &strm,  rmx::Printable * a) {
    return strm << "rmx::ptr:  " << &a /* << ", rms::inst: " << *a */<< " >> " << typeid(*a).name() << ", info: " << a->ToString();
}

unsigned int Object::_count = 0;
unsigned int Object::_deleted = 0;
LinkedList<Object> * _allObjects = new LinkedList<Object>();

class Thing {
public:
    std::string name = "Hello, I'm Barry!";
};

void RMXObjectCloneTest(){
    Object * o = new Object();
    
    Object * o2 = o;
    Object * clone = o->clone();
    Object * clone2 = Object::Instantiate(clone);
    clone2->setName("clone2");
    clone2->setDescription("AND IM A CLONE OF A CLONE!");
    
    o->setName("o1");
    o->setDescription("I am the first object");
    
    clone->setName("Clone1");
    clone->setDescription("I am a clone of the first object");
    
    Thing barry = Thing();
    Thing * baz = Object::Instantiate(&barry);
    baz->name = "And I'm his bloody clone!";
    
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
    //    cout << o->clone() << endl;
    
    //    OpenGLView::Run(argc, argv);
    
    //    NotificationCenter::Test();
}


void RMXPrintableTest() {
    Printable * theObject = new Printable();
    theObject->setDescription("Hello, World!");
    cout << theObject << endl;
    cout << *theObject << endl;
}

class AnObject : public Object {
    
};

void RMXObjectCountInitAndDeinitTest() {
//    LinkedList<Object>::
    AnObject * thing = new AnObject();
    cout << "++Objects: " << Object::Count() << endl;
    AnObject * thing2 = new AnObject();
    cout << "++Objects: " << Object::Count() << endl;
    AnObject * thing3 = (AnObject*) thing->clone();
    cout << "++Objects: " << Object::Count() << endl;
    delete thing;
    cout << "--Objects: " << Object::Count() << endl;
    delete thing2;
    cout << "--Objects: " << Object::Count() << endl;
    delete thing3;
    cout << "--Objects: " << Object::Count() << endl;
    
}