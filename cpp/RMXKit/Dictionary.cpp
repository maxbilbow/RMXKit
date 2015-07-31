//
//  Dictionary.cpp
//  RMXKit
//
//  Created by Max Bilbow on 29/07/2015.
//  Copyright © 2015 Rattle Media Ltd. All rights reserved.
//



//#import <iostream>
//
//
//#import "LinkedList.hpp"
#import "Dictionary.hpp"
#import "Object.hpp"
using namespace std;
using namespace rmx;



typedef Object Thing;

//using namespace rmx;
void RMXDictionaryTest() {
    // insert code here...
    std::cout << "\nDICTIONARY START>>>>\n\n";
        //Lets start by adding a "Thing" to a linked list
    LinkedList<Thing> * things = new LinkedList<Thing>();
    things->append(new Thing());
    cout << "Added a Thing to the list: " << things->first() << endl;
    
    //Create a dictionary with a string key.
    Dictionary<string, Thing> * dict = new Dictionary<string, Thing>();
    
    //Set the first THING to the Thing we have in our list
    dict->setValueForKey("THING", things->getValue(0));
    dict->setValueForKey("THING2", new Thing());
//    things->getValue(0)->name = "World!";
    cout << endl;
    cout << "  Printing thing 2: " << dict->getValueForKey("THING2")->ToString() << endl;
    cout << "  Printing thing 1: " << dict->getValueForKey("THING")->ToString() << endl;
    
    things->first()->setName("World!");
    dict->getValueForKey("THING2")->setName("Hello!");
    //Check the name change in the list.
    cout << "Thing 1 is now: " << things->first() << endl;
    
    //Check the name was changed in the dictionary also.
    cout << endl;
    cout << "  Printing thing 2: " << dict->getValueForKey("THING2")->ToString() << endl;
    cout << "  Printing thing 1: " << dict->getValueForKey("THING")->ToString() << endl;
    
    //Create a new thing
    Thing * aThing = new Thing();
    aThing->setName("Monty");
    
    //Replace the thing at key "THING"
    Thing* oldThing = dict->setValueForKey("THING", aThing);
    
    //Do we still have the old Thing? I.e. was it actually replaced?
    cout << endl;
    cout << "  We Repleced (and removed) thing 1: " << oldThing << endl;
    
    //What remains in out dictionary?
    cout << "                   Printing thing 2: " << dict->getValueForKey("THING2") << endl;
    cout << "               Printing new thing 1: " << dict->getValueForKey("THING") << endl;
    
    
}