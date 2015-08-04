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
     *   @since <#0.1#>
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
        static unsigned int _count;
        static unsigned int _deleted;
        static LinkedList<Object> _allObjects;
        unsigned int _id;
        
        
        
        void _updateID() {
            this->_id = _count++;
        }
        
        static void _RemoveObject(Object * obj) {
            Object::_allObjects.removeValue(obj);
        }
        

        
    protected:
       
        
        std::string name;


    public:
        ///The total number of rmx::Objects that exist.
        static unsigned int Count() {
            return Object::_allObjects.count(); //_count - Object::_deleted;
        }
        
        static void DeleteAllObjects();
        
        /*!
         *  @author Max Bilbow, 15-08-04 17:08:40
         *
         *  @return A LinkedList containing all available Objects.
         *  @since 0.1
         */
        static LinkedList<Object> * AllObjects() {
            return &Object::_allObjects;
        }
        
        ///Initiates with default name "Unnamed Object"
        Object(std::string name = "Unnamed Object");
       
        ~Object();
        
        ///Returns the name with the uniqueID in brackets
        ///For name without id, use getName();
        std::string Name() {
            return this->name + " (" + std::to_string(this->_id) + ")";
        }
        
        ///Returns the text name of the object
        std::string getName() {
            return this->name;
        }
        
        ///	Should the object be hidden, saved with the scene or modifiable by the user?
        bool hideFlags = false;
        
        
        ///Prints the unique name and description
        std::string ToString() override {
            return "Name: " + this->Name() + ", Description: " + Printable::ToString();
        }
        
        ///Sets the name
        void setName(std::string name) {
             this->name = name;
        }
        
        ///Clones the object and makes sure that the name and ID are updated accordingly.
        ///This should be overridden, with inherited mathods invoked first, to include custom modifiers on any decendants.
        virtual Object * clone();
        
        ///Returns the uniqueID
        int getID() {
            return this->_id;
        }
       
        ///@TODO: convert message into function call.
        virtual void SendMessage(std::string message, void * args = nullptr, SendMessageOptions options = DoesNotRequireReceiver) {}
        
        
        /// Removes a gameobject, component or asset by calling delete.
        /// TODO: Additonal functionality may be needed later
        template <class T>
        static void Destroy(T * object) {
            delete object;
//            free(object);
        }
        
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
        
        /// Clones the object original and returns the clone.
        /// If the object is of type rmx::Object, then it's clone() method is called
        /// Otherwise the instance is cloned in memory and may need additional modification (i.e. uniqueID, pointers, etc... that should not match that of the original.
        template<class T>
        static T * Instantiate(T * object) {
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
        
        static LinkedList<Object>::Iterator ObjectIterator() {
            return Object::_allObjects.getIterator();
        }
    };
    
   

}











