//
//  LinkedList.hpp
//  JustForFun
//
//  Created by Max Bilbow on 09/07/2015.
//  Copyright © 2015 Rattle Media. All rights reserved.
//

#ifndef LinkedList_cpp
#define LinkedList_cpp

#endif /* LinkedList_cpp */

#import <iostream>
namespace rmx {


    template <typename Value> class LinkedList {
        typedef LinkedList<Value> List;
    public:
        typedef struct _Node {
        public:
            Value * value;
            _Node * next;
        } Node;
    private:
        int _count;
        Node * _head;

    public:
        LinkedList();
        ~LinkedList();
        
        int count();
        
        Node * lastNode();
        
        Value * first();
        
        Node * firstNode();
        
        Value * last();
        
        bool isEmpty();
        
    //    ///Removes and returns the mathcing node
    //    Node * removeNode(Node * node);
       
        ///removes and returns value at index
        Value * removeValueAtIndex(int index);

        ///Removes and returns the node at index
        Node * removeNodeAtIndex(int index);

    //     Node * insertValueAtIndex(int index);
        
        ///Necessary for reversing a list
        Node * asNodeArray();
        
        ///Copy of list as an array
        Value * asArray();
        
        ///Removes all elements, beginnig with the first.
        void removeAll();
        
        ///Appends and returns appended value
        Value * append(Value * value);
        
        ///Appends and returns appended value
        Value append(Value value);
        
        ///appends an array of given size (sizeof(array))
        void append(Value array[], __SIZE_TYPE__ size);
        
        ///Removes and returns the node containing the corresponding value
        Node * removeNodeWithValue(Value * value);
        
        ///Removes and returns the node containing the corresponding value
        Node * removeNodeWithValue(Value value);
        
        ///Removes and returns the first matching value;
        Value * removeValue(Value * value);
        
        ///Removes and returns the first matching value;
        Value removeValue(Value value);
        
        Value * getValue(int index);
        
        Node * getNodeWithValue(Value * value);
        
        Node * getNode(int index);
        
        ///TODO: Test this method with primitives and pointers.
        bool contains(Value * value);
        
        ///Returns previous value or throws error if out of range
        Value * setValue(int index);

        void print(void);
        
        Value * pop(Node ** head);
       
        
        
        LinkedList<Value> * reverse();
        
    //    template <class Value>
    };

    template <typename Value>
    inline LinkedList<Value>::LinkedList() {
        this->_head = new Node();
    }

    template <typename Value>
    inline LinkedList<Value>::~LinkedList() {
        std::cout << "Deleting!" << std::endl;
        this->removeAll();
        //    free(this);
        
    }

    template <typename Value>
    inline Value * LinkedList<Value>::append(Value * value) {
        if (_count == 0 || this->_head == NULL) {
            if (_count != 0)
                throw std::invalid_argument("Why is count not zero when _head == NULL?!");
            this->_head = new Node();
            this->_head->value = value;
        } else {
            Node * last = lastNode(); //!= NULL ? _head : new Node();//this is -1 (holds no value)
            last->next = new Node();
            last->next->value = value;
        }
        ++this->_count;
#if RMX_DEBUG
        try {
            std::cout << "appending " << value << " at " << value << ", SIZE is now: " << _count << std::endl;
        } catch (std::exception e) {
            std::cout << "appending " << value << " at " << value << ", SIZE is now: " << _count << e.what() << std::endl;
        }
#endif
        return value;
    };

    template <typename Value>
    bool LinkedList<Value>::isEmpty() {
        return this->_count == 0;
    }



    template <typename Value> int LinkedList<Value>::count() {
        return this->_count;
    }

    template <typename Value> Value * LinkedList<Value>::first() {
        return this->_head->value;
    }

    template <typename Value> typename LinkedList<Value>::Node * LinkedList<Value>::firstNode() {
        return this->_head;
    }

    template <typename Value> Value * LinkedList<Value>::last() {
        return this->lastNode()->value;
    };

    template <typename Value> typename LinkedList<Value>::Node * LinkedList<Value>::lastNode() {
        if (this->_head == NULL) {
            return NULL;
        }
        Node * last = this->_head;
        while (last->next != NULL) {
            last = last->next;
        }
        return last;
    };




    template <typename Value> Value LinkedList<Value>::append(Value value) {
        return *this->append(&value);
    };

    template <typename Value> Value * LinkedList<Value>::pop(Node ** head) {
        int retval = -1;
        Node * next_node = NULL;
        
        if (*head == NULL) {
            return -1;
        }
        
        next_node = (*head)->next;
        retval = (*head)->value;
        //    free(*head);
        *head = next_node;
        
        return retval;
    };

    template <typename Value> typename LinkedList<Value>::Node * LinkedList<Value>::removeNodeWithValue(Value * value) {
        if (this->_head->value == value) {
            Node * result = this->_head;
            this->_head = this->_head->next;
            --_count;
            return result;
        } else {
            Node * previous = this->_head;
            Node * current = this->_head->next;
            
            while (current->next != nullptr) {
                if (current->value == value) {
                    previous->next = current->next;
                    --_count;
                    return current;
                } else {
                    previous = current;
                    current = current->next;
                }
            }
            return nullptr;
        }
    }

    template <typename Value> typename LinkedList<Value>::Node * LinkedList<Value>::removeNodeWithValue(Value value) {
        if (*this->_head->value == value) {
            Node * result = this->_head;
            this->_head = this->_head->next;
            --_count;
            return result;
        } else {
            Node * previous = this->_head;
            Node * current = this->_head->next;
            
            while (current->next != nullptr) {
                if (*current->value == value) {
                    previous->next = current->next;
                    --_count;
                    return current;
                } else {
                    previous = current;
                    current = current->next;
                }
            }
            return nullptr;
        }
    }

    template <typename Value> Value * LinkedList<Value>::removeValue(Value * value) {
        Node * result = this->removeNodeWithValue(value);
        return result == nullptr ? nullptr : result->value;
    };

    template <typename Value> Value LinkedList<Value>::removeValue(Value value) {
        Node * result = this->removeNodeWithValue(value);
        return result == nullptr ? nullptr : *result->value;
    };

    template <typename Value> Value * LinkedList<Value>::removeValueAtIndex(int index) {
        try {
            Node * node = (Node*) removeNodeAtIndex(index);
            return node->value;
        } catch (std::invalid_argument e) {
            std::cout << e.what() << std::endl;
        }
        return NULL;
    }
    template <typename Value> typename LinkedList<Value>::Node * LinkedList<Value>::removeNodeAtIndex(int index) {
        if (index < 0 || index > this->_count - 1) {
            throw std::invalid_argument("index " + std::to_string(index) + " is out of range: " + std::to_string(_count));
        }
        int i = 0;
        //	Node * spare = this->_head;
        Node * current = this->_head;
        Node * previous = NULL;
        //	Node * next = this->head->next;
        //	Node * result;
        while (i <= index) {
            if (i++ == index) {
                //			result = current;
                if (previous == NULL) {
                    this->_head = current->next;
                } else {
                    previous->next = current->next;
                }
                this->_count--;
                return current;
            } else {
                previous = current;
                current = current->next;
            }
        }
        throw std::invalid_argument("Unknown index exception - index: " + std::to_string(index) + ", range: " + std::to_string(_count));
    };


    template <typename Value> void LinkedList<Value>::removeAll() {
        while (_count > 0) {
            removeNodeAtIndex(0);
        }
    }



    template <typename Value> typename LinkedList<Value>::Node * LinkedList<Value>::getNode(int index) {
        Node * result = this->_head;
        for (int i = 0; i < index; ++i) {
            result = result->next;
        }
        return result;
    }


    template <typename Value> Value * LinkedList<Value>::getValue(int index) {
        Node * result = this->_head;
        for (int i = 0; i < index; ++i) {
            result = result->next;
        }
        return result->value;
    }

    ///May cause error with result->next == null.
    template <typename Value> typename LinkedList<Value>::Node * LinkedList<Value>::getNodeWithValue(Value * value) {
        Node * result = this->_head;
        for (int i = 0; i < _count; ++i) {
            if (value == result->value)
                return result;
            else
                result = result->next;
        }
        return nullptr;
    }


    ///Returns previous value or throws error if out of range
    template <typename Value> Value * LinkedList<Value>::setValue(int index) {
        return this->_head->value;
    }



    template <typename Value> LinkedList<Value> * LinkedList<Value>::reverse() {
        Node * array = this->asNodeArray();
        int i = _count - 1;
        
        
        this->_head = &array[i];
        Node * current = &array[i];// = this->_head;
        while ( i > 0) {
            --i;
            current->next = &array[i];
            current = current->next;
        }
        current->next = NULL;
        
        return this;
    }



    template <typename Value> typename LinkedList<Value>::Node * LinkedList<Value>::asNodeArray() {
        Node * nodes = new Node[_count];
        Node * current = this->_head;
        for (int i = 0; i < _count; ++i) {
            nodes[i] = *current;
            current = current->next;
        }
        
        return nodes;
    }

    template <typename Value> Value * LinkedList<Value>::asArray() {
        int count = this->count();
        Value (* values) = new Value[count];
        Node * nodes = this->asNodeArray();
        for (int i = 0; i < count; ++i) {
            values[i] = *nodes[i].value;//this->getValue(i);
        }
        
        return values;
    }


    template <typename Value> void LinkedList<Value>::append(Value array[], size_t size) {
        for (int i = 0; i < size / sizeof(array[0]); ++i) {
            this->append(&array[i]);
        }
    };

    ///TODO: Test this method
    template <typename Value> bool LinkedList<Value>::contains(Value * value) {
        Node * current = this->_head;
        
        while (current->next != nullptr) {
            if (current->value == value)
                return true;
            current = current->next;
        }
        return false;
        
    };


    template <typename Value>
    inline void LinkedList<Value>::print()
    {
        std::cout << std::endl;
        try {
            if (this->isEmpty()) {
                std::cout << "Empty" << std::endl;
            } else {
                try {
                    std::cout << _count << " items: " << *_head->value;
                } catch (std::exception e) {
                    std::cout << ", " << e.what();
                }
                Node * current = _head;
                while (current->next != NULL) {
                    try {
                        std::cout << ", " << *current->next->value;
                        current = current->next;
                    } catch (std::exception e) {
                        std::cout << ", " << e.what();
                    }
                }
                std::cout << std::endl;
            }
        } catch (std::exception e) {
            
            std::cout << e.what() << std::endl;;
        }
        
    }
}
    void RMXLinkedListTest(void);