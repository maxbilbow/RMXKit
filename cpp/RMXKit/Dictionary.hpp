//
//  Dictionary.hpp
//  RMXKit
//
//  Created by Max Bilbow on 29/07/2015.
//  Copyright © 2015 Rattle Media Ltd. All rights reserved.
//

#ifndef Dictionary_cpp
#define Dictionary_cpp

//#include <stdio.h>
//#import <list>
//#import "LinkedList.hpp"

#endif /* Dictionary_cpp */

#import <iostream>
#import "LinkedList.hpp"


namespace rmx {
    

    template <typename Key, typename Value>
    class KeyValuePair {
    public:
        Key key;
        Value * value;
    };


    //typedef struct _KeyValuePair KeValuePair;

    template <typename Key, typename Value>
    class Dictionary : public LinkedList<KeyValuePair<Key,Value> > {
        
    public:
        typedef KeyValuePair<Key, Value> Pair;
        typedef typename LinkedList<KeyValuePair<Key,Value> >::Node Node;
//        Dictionary() {
// //            super::LinkedList();
//        }
//        ~Dictionary() {
//            this->removeAll();//TODO: More here
//        }
        
        ///Returns the KeyValuePair that points to the entry
        Pair * getKeyValuePair(Key key) {
            Node * node = this->firstNode();
            while (node != nullptr && node->value != nullptr) {
                if (node->value->key == key)
                    return node->value;
                else {
                    node = node->next;
                }
            }
            return nullptr;
        }
        
        ///Looks OK
        Value * getValueForKey(Key key){
            Pair * node = this->getKeyValuePair(key);
            if (node != nullptr)
                return node->value;
            else
                return nullptr;
        }
        
        ///This looks OK.
        Value * setValueForKey(Key key, Value * value) {
            Pair * pair = this->getKeyValuePair(key);
            if (pair != nullptr) {
                Value * old = pair->value;
                pair->value = value;
                return old;
            } else {
                KeyValuePair<Key,Value> * newPair = new KeyValuePair<Key,Value>();
                newPair->key = key;
                newPair->value = value;
                this->append(newPair);
                return nullptr;
            }
        }
        
        Value setValueForKey(Key key, Value  value) {
            return *this->setValueForKey(key, &value);
        }

    };
   
}

void RMXDictionaryTest();


