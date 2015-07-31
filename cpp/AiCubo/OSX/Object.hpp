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

//#define string std::string

namespace rmx {
   
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
    static unsigned int _count;
    class Object : public Printable {
        
        unsigned int _id;
        void _updateID() {
            this->_id = _count++;
        }
        void _init(std::string name) {
            this->_id = this->IncrementCount();
            this->name = !name.empty() ? name : "Unnamed Object";// + std::to_string(this->getID());
        }
        unsigned int IncrementCount() {
//            std::cout << "\nTOTAL OBJECTS: " << _count << std::endl;
            return _count++;
        }
    protected:
        std::string name;
    public:
        static unsigned int Count();
        Object() {
            this->_init("");
        }
        
        Object(std::string name){
            this->_init(name);
        }
        ~Object(){ }
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
        
        /// Removes a gameobject, component or asset.
        static void Destroy(Object * object) {
            delete object; //should happen at end of cycle
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
    };
    
   

}



///Prints the class' details, including location in memory, along with it's ToString() method
std::ostream& operator<<(std::ostream &strm,  rmx::Printable &a);

///Prints the class' details, including pointer address, along with it's ToString() method
std::ostream& operator<<(std::ostream &strm,  rmx::Printable * a);




void RMXObjectCloneTest();



