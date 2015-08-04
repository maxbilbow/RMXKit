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
#import "Dictionary.hpp"

//#define string std::string

namespace rmx {
    enum SendMessageOptions {
        RequiresReceiver, DoesNotRequireReceiver
    };
    #define quote(x) #x
    class Printable {
        
    protected:
        std::string description = "";
    public:
        virtual std::string ToString() {
            return this->description;
        }
        
        virtual void setDescription(std::string description) {
            this->description = description;
        }
    };
    #undef quote
}

///Prints the class' details, including location in memory, along with it's ToString() method
std::ostream& operator<<(std::ostream &strm,  rmx::Printable &a);

///Prints the class' details, including pointer address, along with it's ToString() method
std::ostream& operator<<(std::ostream &strm,  rmx::Printable * a);

namespace rmx {
    typedef void* Any;
    
    

    class Object : public Printable {
        static unsigned int _count;
        static LinkedList<Object> _allObjects;
        
        typedef void (*Receiver)(Object *, Any);
        unsigned int _id;

        Dictionary<std::string, Receiver> * _receivers = new Dictionary<std::string, Receiver>();
       
        void _updateID() {
            this->_id = _count++;
        }
        void _init(std::string name) {
            Object::_allObjects.append(this);
            this->_id = this->IncrementCount();
            this->name = !name.empty() ? name : "Unnamed Object";// + std::to_string(this->getID());
        }
        unsigned int IncrementCount() {
//            std::cout << "\nTOTAL OBJECTS: " << _count << std::endl;
            return _count++;
        }
    protected:
        void addReceiver(std::string name, Receiver receiver) {
            this->_receivers->setValueForKey(name, receiver);
        }
        std::string name;


    public:
        
        static unsigned int Count();
//        Object() {
//            this->_init("");
//        }
        
        Object(std::string name = ""){
            this->_init(name);
        }
//        ~Object(){
// //            this->SendMessage("OnDestroy", nullptr ,DoesNotRequireReceiver);
//        }
        /// The name of the object.
        std::string Name() {
            return this->name + " (" + std::to_string(this->_id) + ")";
        }
        ///	Should the object be hidden, saved with the scene or modifiable by the user?
        bool hideFlags = false;
        
        std::string ToString() override {
            return "Name: " + this->Name() + ", Description: " + Printable::ToString();
        }
        
        void setName(std::string name) {
             this->name = name;
        }
        
        virtual Object * clone(){
            void * ptr = malloc(sizeof(*this));//&o;
            memcpy(ptr, (void*)this, sizeof(*this));
            Object * o = (Object *) ptr;
            o->_updateID();
            if (o->name.find("CLONE of \"") == std::string::npos)
                o->setName("CLONE of \"" + this->name + "\"");// + std::to_string(this->getID()) + ")");
            return (Object*) ptr;
        }
        
        int getID() {
            return this->_id;
        }
       
        ///@TODO: convert message into function call.
        void SendMessage(std::string message, void * args = nullptr, SendMessageOptions options = DoesNotRequireReceiver) {
            Receiver receiver = *this->_receivers->getValueForKey(message);
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
        
        /// Removes a gameobject, component or asset.
        template <class T>
        static void Destroy(T * object) {
            delete object;
//            free(object);
        }
        
        /// Destroys the object obj immediately. You are strongly recommended to use Destroy instead.
        static void DestroyImmediate(Object * object) {
            delete object;
        }
        
        /// Makes the object target not be destroyed automatically when loading a new scene.
        static void DontDestroyOnLoad(Object * object){
            //TODO
        }
        
        /// Returns the first active loaded object of Type type.
        static Object * FindObjectOfType(typeof(Object) object){
            //TODO
            return nullptr;
        }
        
        /// Returns a list of all active loaded objects of Type type.
        static Object ** FindObjectsOfType(typeof(Object) object){
            //TODO
            return nullptr;
        }
        
        /// Clones the object original and returns the clone.
        template<class T>
        static T * Instantiate(T * object) {
//            if( Object * o = dynamic_cast< Object* >( object ) )
            if (std::is_base_of<Object,T>::value)
                return (T*) ((Object*) object)->clone();
            else {
                void * ptr = malloc(sizeof(*object));//&o;
                memcpy(ptr, (void*)object, sizeof(*object));
                return (T*) ptr;
            }
           
        }
        
        static LinkedList<Object>::Iterator ObjectIterator() {
            return Object::_allObjects.getIterator();
        }
    };
    
   

}








void RMXObjectCloneTest();



