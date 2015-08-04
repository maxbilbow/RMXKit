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
#import "LinkedList.hpp"


//#define string std::string

namespace rmx {

    enum SendMessageOptions {
        RequiresReceiver, DoesNotRequireReceiver
    };

    ///A simple interface that allows any object to be printed using std::cout << theObject or std::cout << *theObject.
    ///node the difference between theObject and *theObject; the former gives the pointer's location in memory and more detailed description.
    ///@code
    ///Printable * theObject = new Printable();
    ///theObject->setDescription("Hello, World!");
    ///cout << theObject << endl;
    ///cout << *theObject << endl;
    ///@endcode
    ///
    ///rmx::ptr:  0x7fff5fbff798 >> N3rmx9PrintableE, info: Hello, World!
    ///
    ///Hello, World!
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

///Prints the object's details, including location in memory, along with it's ToString() method
std::ostream& operator<<(std::ostream &strm,  rmx::Printable &a);

///Prints the object's ToString() method
std::ostream& operator<<(std::ostream &strm,  rmx::Printable * a);

namespace rmx {
    typedef void* Any;
    
    class Object : public Printable {
        static unsigned int _count;
        static unsigned int _deleted;
        static LinkedList<Object> _allObjects;
        unsigned int _id;
        
        typedef void (*Receiver)(Object *, Any);

//        Dictionary<std::string, Receiver> * _receivers = new Dictionary<std::string, Receiver>();
       
        void _updateID() {
            this->_id = _count++;
        }
        
        static void _RemoveObject(Object * obj) {
            Object::_allObjects.removeValue(obj);
        }
        

        
    protected:
        void addReceiver(std::string name, Receiver receiver) {
            throw std::invalid_argument("Not implemented");
//              this->_receivers->setValueForKey(name, receiver);
        }
        
        std::string name;


    public:
        ///The total number of rmx::Objects that exist.
        static unsigned int Count() {
            return Object::_allObjects.count(); //_count - Object::_deleted;
        }
        
        static void DeleteAllObjects();
        static LinkedList<Object> * AllObjects() {
            return &Object::_allObjects;
        }
        
        ///Initiates with default name "Unnamed Object"
        Object(std::string name = "Unnamed Object"){
            this->_id = Object::_count++; //this->IncrementCount();
            this->name = !name.empty() ? name : "Unnamed Object";
            Object::_allObjects.append(this);
#if DEBUG_MALLOC
            std::cout << "~INITIALIZING Object: " << *this << std::endl;
#endif
        }
       
        ~Object() {
#if DEBUG_MALLOC
            std::cout << "~DELETING Object: " << *this;
#endif
            Object::_deleted++;
            Object::_RemoveObject(this);
#if DEBUG_MALLOC
            std::cout << ", Remainig: " << Object::Count() << std::endl;
#endif
        }
        
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
        virtual Object * clone(){
            void * ptr = malloc(sizeof(*this));//&o;
            memcpy(ptr, (void*)this, sizeof(*this));
            Object * o = (Object *) ptr;
            o->_updateID();
            if (o->name.find("CLONE of \"") == std::string::npos)
                o->setName("CLONE of \"" + this->name + "\"");// + std::to_string(this->getID()) + ")");
            Object::_allObjects.append(o);
#if DEBUG_MALLOC
            std::cout << "~INITIALIZING CLONE: " << *o << std::endl;
#endif
            return o;
        }
        
        ///Returns the uniqueID
        int getID() {
            return this->_id;
        }
       
        ///@TODO: convert message into function call.
        void SendMessage(std::string message, void * args = nullptr, SendMessageOptions options = DoesNotRequireReceiver) {
            Receiver receiver = nullptr; //*this->_receivers->getValueForKey(message);
            if (receiver != nullptr) {
                try {
                    receiver(this, args);
                } catch (std::exception e) {
                    std::cout << "Receiver Error: "<< message << ", for: " << *this << "\n ==> ERROR: " << e.what() << std::endl;
                }
            } else if (options == RequiresReceiver)
                throw std::invalid_argument("Receiver was not available: " + message);
#if DEBUG_BEHAVIOURS
            else
                std::cout << "Receiver was not available: "<< message << ", for: " << *this << std::endl;
#endif
        }
        
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











