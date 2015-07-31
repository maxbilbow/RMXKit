//
//  LIntList.hpp
//  JustForFun
//
//  Created by Max Bilbow on 09/07/2015.
//  Copyright © 2015 Rattle Media. All rights reserved.
//

#ifndef LIntedList_cpp
#define LIntedList_cpp

#include <stdio.h>

#endif /* LIntList_cpp */

//template <class Value>
//class Node {
//
//
//public:
//
//};


//class Node {
//public:
//    int value;
//    Node * next;
//};


typedef struct _Node {
    void * value;
    _Node * next;
} Node;

class LIntList {
    int _count = 0;
    Node * _head = new Node();
    Node * _last(void);
    
public:
    const int (^count)(void) = ^(void) {
        return _count;
    };
    
    LIntList();
    
//    const void*(^first)(void) = ^(void) {
//        return this->_head->next->value;
//    };

    int first();
    
    int last();
    
//    const int(^last)(void) = ^(void) {
//        return this->_last()->value;
//    };
    
    int append(int value);
    
    //    static void print_list(Node<Value> * head);
    void print(void);
    
    //    static int pop(Node<Value> ** head);
    int pop(Node ** head);
    
    //    static int remove_by_value(Node<Value> ** head, int val);
    int remove_by_value(int val);
    
    
    
    //    template <class Value>
};


void LIntListTest(void);


