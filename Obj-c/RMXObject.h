//
//  Object.hpp
//  RMXKit
//
//  Created by Max Bilbow on 30/07/2015.
//  Copyright © 2015 Rattle Media Ltd. All rights reserved.
//

#ifndef Object_hpp
#define Object_hpp

//#include <stdio.h>



#endif /* Object_hpp */


//#import "RMXEventListener.h"

    enum SendMessageOptions {
        RequiresReceiver, DoesNotRequireReceiver
    };

/*!
 *   @author Max Bilbow, 15-08-04 16:08:04
 *
 *   A simple interface that allows any object to be printed using std::cout << theObject or std::cout << *theObject.
 *   node the difference between theObject and *theObject; the former gives the pointer's location in memory and more detailed description.
 *   @code
 *   Printable * theObject = new Printable();
 *   theObject->setDescription("Hello, World!");
 *   cout << theObject << endl;
 *   cout << *theObject << endl;
 *   @endcode
 *
 *   rmx::ptr:  0x7fff5fbff798 >> N3rmx9PrintableE, info: Hello, World!
 *
 *   Hello, World!
 *
 *   @since 0.1
 */
@protocol RMXPrintable

- (NSString *)description;

@end

//*!
// *  @author Max Bilbow, 15-08-04 17:08:53
// *  @param strm proceeding output
// *  @param a    the Printable object
// *  @return Prints the object's details, including location in memory, along with it's ToString() method
// *  @since 0.1
// */
//std::ostream& operator<<(std::ostream &strm,  rmx::Printable &a);
//
//*!
// *  @author Max Bilbow, 15-08-04 17:08:54
// *  @param strm proceeding output
// *  @param a    the Printable object pointer
// *  @return Prints the object's ToString() method
// *  @since 0.1
// */
//std::ostream& operator<<(std::ostream &strm,  rmx::Printable * a);



    
/*!
 *  @author Max Bilbow, 15-08-04 17:08:49
 *
 *  Base object for all standart event listening and notification tools.
 *  @since 0.1
 */
@interface RMXObject : NSObject  <RMXPrintable, RMXEventListener, RMXBehaviour>
        

/*!
 *  @author Max Bilbow, 15-08-06 17:08:33
 *
 *  A static collection of all active Object instances.
 *  @see LinkedList<Value>
 *  @since 0.1
 */
+ (NSMutableArray<RMXObject*>*) AllObjects;
        
/*!
 *  @author Max Bilbow, 15-08-06 17:08:13
 *
 *  The unique id of the instance as an unsigned int.
 *  @since 0.1
 */
@property (readonly) unsigned int uniqueID;

///@see RMXBehaviour
@property BOOL enabled;
       
/*!
 *  @author Max Bilbow, 15-08-06 17:08:27
 *
 *  The given name of the instance.
 *  @since 0.1
 */
@property NSString* name;

/*!
 *  @author Max Bilbow, 15-08-06 16:08:50
 *
 *  Returns the name with the uniqueID in brackets
 *  For name without id, use Name();
 *  @return the name with the uniqueID
 *  @since 0.1
 *  @see Name()
 */
- (NSString*)uniqueName;

/*!
 *  @author Max Bilbow, 15-08-06 17:08:50
 *
 *  @return The total number of rmx::Objects that currently exist in the system.
 *  @since 0.1
 */
- (int)Count;


/*!
 *  @author Max Bilbow, 15-08-06 16:08:41
 *
 *  Initiates with default name "Unnamed Object"
 *  @since 0.1
 */
- (id)initWithName:(NSString*)name;

- (id)init;

/*!
 *  @author Max Bilbow, 15-08-06 17:08:14
 *
 *  Deconstructor: removes the object from the list of active objects.
 *  @since 0.1
 */
- (void)dealloc;

/*!
 *  @author Max Bilbow, 15-08-06 16:08:40
 *
 *  Clones the object and makes sure that the name and ID are updated accordingly.
 *  This should be overridden, with inherited mathods invoked first, to include custom modifiers on any decendants.
 *  @return a clone of the object
 *  @since 0.1
 */
- (id)clone;


/*!
 *  @author Max Bilbow, 15-08-06 16:08:42
 *
 *  @discussion Does not currently work as desired. Not sure if messages sending,
 *  in this mannor is possible in c++ without excessive overhead.
 *  It might be possible to externally reference Objective-C but 
 *  probably not an ideal solution.
 *
 *  @param message the name of the method to call
 *  @param args    any value
 *  @param options e.g. should an error be thrown if no receiver present?
 *  @since 0.1
 *  @TODO: find a way of making this work...
 */
- (void) sendMessage:(NSString*)message;
- (void) sendMessage:(NSString*)message withArgs:(id)args;


/*!
 *  @author Max Bilbow, 15-08-06 16:08:43
 *
 *
 *  @return A LinkedList<Object>:Iterator containing all available Objects in the system.
 *  @since 0.1
 */
- (void*) /*LinkedList<Object>::Iterator*/ ObjectIterator;


@end











