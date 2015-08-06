//
//  Object.hpp
//  RMXKit
//
//  Created by Max Bilbow on 30/07/2015.
//  Copyright © 2015 Rattle Media Ltd. All rights reserved.
//

#ifndef Object_hpp
#define Object_hpp

#include <stdio.h>



#endif /* Object_hpp */

#import <iostream>
#import <type_traits>
#import "LinkedList.h"


namespace rmx {

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
    class Printable {
        
    protected:
        std::string description = "";
    public:
        virtual std::string ToString() {
            return this->description.empty() ? "N/A" : this->description;
        }
        
        virtual void setDescription(std::string description) {
            this->description = description;
        }
    };
}

/*!
 *  @author Max Bilbow, 15-08-04 17:08:53
 *  @param strm proceeding output
 *  @param a    the Printable object
 *  @return Prints the object's details, including location in memory, along with it's ToString() method
 *  @since 0.1
 */
std::ostream& operator<<(std::ostream &strm,  rmx::Printable &a);

/*!
 *  @author Max Bilbow, 15-08-04 17:08:54
 *  @param strm proceeding output
 *  @param a    the Printable object pointer
 *  @return Prints the object's ToString() method
 *  @since 0.1
 */
std::ostream& operator<<(std::ostream &strm,  rmx::Printable * a);

namespace rmx {

    typedef void* Any;
    
    /*!
     *  @author Max Bilbow, 15-08-04 17:08:49
     *
     *  Base object for all standart event listening and notification tools.
     *  @since 0.1
     */
    class Object : public Printable {
        
        /*!
         *  @author Max Bilbow, 15-08-06 17:08:35
         *
         *  The number of instances created; used to assign the the unique _id on initialization.
         *  @since 0.1
         */
        static unsigned int _count;

        /*!
         *  @author Max Bilbow, 15-08-06 17:08:33
         *
         *  A static collection of all active Object instances.
         *  @see LinkedList<Value>
         *  @since 0.1
         */
        static LinkedList<Object> _allObjects;
        
        /*!
         *  @author Max Bilbow, 15-08-06 17:08:13
         *
         *  The unique id of the instance as an unsigned int.
         *  @since 0.1
         */
        unsigned int _id;

        
    protected:
       
        /*!
         *  @author Max Bilbow, 15-08-06 17:08:27
         *
         *  The given name of the instance.
         *  @since 0.1
         */
        std::string name;

    public:
        
        /*!
         *  @author Max Bilbow, 15-08-06 17:08:50
         *
         *  @return The total number of rmx::Objects that currently exist in the system.
         *  @since 0.1
         */
        static unsigned int Count();
        
        /*!
         *  @author Max Bilbow, 15-08-04 17:08:40
         *
         *  @return A LinkedList containing all available Objects.
         *  @since 0.1
         */
        static LinkedList<Object> * AllObjects() {
            return &Object::_allObjects;
        }
        
        /*!
         *  @author Max Bilbow, 15-08-06 16:08:41
         *
         *  Initiates with default name "Unnamed Object"
         *  @since 0.1
         */
        Object(std::string name = "Unnamed Object");
       
        /*!
         *  @author Max Bilbow, 15-08-06 17:08:14
         *
         *  Deconstructor: removes the object from the list of active objects.
         *  @since 0.1
         */
        ~Object();
        
        /*!
         *  @author Max Bilbow, 15-08-06 16:08:50
         *
         *  Returns the name with the uniqueID in brackets
         *  For name without id, use Name();
         *  @return the name with the uniqueID
         *  @since 0.1
         *  @see Name()
         */
        std::string uniqueName();
        
        /*!
         *  @author Max Bilbow, 15-08-06 16:08:14
         *
         *  @return the given name of the object
         *  @since 0.1
         *  @see uniqueName()
         */
        std::string Name();
        
        /*!
         *  @author Max Bilbow, 15-08-06 16:08:25
         *
         *  Can be overriden as required.
         *  @return the unique name and description
         *  @since 0.1
         *  @see Printable
         */
        virtual std::string ToString() override;
        
        /*!
         *  @author Max Bilbow, 15-08-06 16:08:12
         *
         *  Setter for the name
         *  @param name any string
         *  @since 0.1
         *  @see uniqueName()
         */
        void setName(std::string name);
        
        /*!
         *  @author Max Bilbow, 15-08-06 16:08:40
         *
         *  Clones the object and makes sure that the name and ID are updated accordingly.
         *  This should be overridden, with inherited mathods invoked first, to include custom modifiers on any decendants.
         *  @return a clone of the object
         *  @since 0.1
         */
        virtual Object * clone();
        
        /*!
         *  @author Max Bilbow, 15-08-06 16:08:21
         *
         *  @return the uniqueID assigned at initialization
         *  @since 0.1
         */
        int getID();
       
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
        virtual void SendMessage(std::string message, void * args = nullptr, SendMessageOptions options = DoesNotRequireReceiver) { }
        

        /*!
         *  @author Max Bilbow, 15-08-06 16:08:43
         *
         *
         *  @return A LinkedList<Object>:Iterator containing all available Objects in the system.
         *  @since 0.1
         */
        static LinkedList<Object>::Iterator ObjectIterator() {
            return Object::_allObjects.getIterator();
        }
        
        
        /*!
         *  @author Max Bilbow, 15-08-06 17:08:26
         *
         *  Clones the object original and returns the clone.
            If the object is of type rmx::Object, then it's clone() method is called
            Otherwise the instance is cloned in memory and may need additional modification 
            (i.e. uniqueID, pointers, etc... that should not match that of the original.
         *
         *  @param object anything
         *  @return a unique copy of the input or the instance's Object::clone result.
         *  @since 0.1
         *  @see clone()
         */
        template<class T> static T * Instantiate(T * object) {
            //            if( Object * o = dynamic_cast< Object* >( object ) )
            if (std::is_base_of<Object,T>::value) {
                #if DEBUG_MALLOC
                std::cout << "Object::";
                #endif
                return (T*) ((Object*) object)->clone();
            } else {
                void * ptr = malloc(sizeof(*object));//&o;
                memcpy(ptr, (void*)object, sizeof(*object));
                #if DEBUG_MALLOC
                std::cout << "~UNKNOWN CLONE: " << ptr << std::endl;
                #endif
                return (T*) ptr;
            }

        }
        
        
        /*!
         *  @author Max Bilbow, 15-08-06 17:08:58
         *
         *  Removes a gameobject, component or asset by calling delete.
         *  @TODO: Make destruction safe as with Unity's GameObject.Destroy function.
         *  @param object Anything
         *  @since 0.1
         */
        template <class T> static void Destroy(T * object) {
            delete object; //TODO Dont destroy immediately.
        }
        
        /* More unimplemented Unity GameObject based functions:
         
        ///	Should the object be hidden, saved with the scene or modifiable by the user?
        bool hideFlags = false;
         
        /// Destroys the object obj immediately. You are strongly recommended to use Destroy instead.
        /// TODO: Additonal functionality may be needed later
        static void DestroyImmediate(Object * object) {
            delete object;
        }
        
        /// TODO: Makes the object target not be destroyed automatically when loading a new scene.
        static void DontDestroyOnLoad(Object * object){
            //TODO
        }
        
        /// TODO: Returns the first active loaded object of Type type.
        static Object * FindObjectOfType(typeof(Object) object){
            //TODO
            return nullptr;
        }
        
        /// TODO: Returns a list of all active loaded objects of Type type.
        static Object ** FindObjectsOfType(typeof(Object) object){
            //TODO
            return nullptr;
        }
        */
        
    };
    
}











