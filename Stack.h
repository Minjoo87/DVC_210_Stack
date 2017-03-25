// Programmer: Minjoo Kim
// Programmer's ID: 1581736

#ifndef STACK_H
#define STACK_H

#include <algorithm>
using namespace std;

template <typename V>
class Stack
{
    V* values;
    int cap;
    int staekSize; // track size
    void capacity(int);
    
public:
    Stack(int = 2);
    void push(const V&);
    V& peek();
    void pop() {if (staekSize > 0) --staekSize;}
    int size() const {return staekSize;}
    int capacity() const {return cap;}
    bool empty() const {return staekSize==0;}
    void clear() {staekSize = 0;}
    ~Stack(){delete [] values;}
    Stack<V>& operator=(const Stack<V>&);
    Stack(const Stack<V>&);
};

template <typename V>
Stack<V>::Stack(int cap)
{
    this->cap = cap;
    values = new V[cap];
    
    for (int index = 0; index < cap; index++){
        values[index] = V();
    }
    staekSize = 0;
}

template <typename V>
Stack<V>& Stack<V>::operator=(const Stack<V>& original)
{
    if (this != &original) //check if copy or not, better not be tho
    {
        // same as destructor
        delete [] values;
        
        // same as copy constructor
        cap = original.cap;
        staekSize = original.staekSize;
        values = new V[cap]; // not copy, is new
        for (int i = 0; i < cap; i++){ // contents copy original to new
            values[i] = original.values[i];
        }
    }
    return *this; // return self reference
}

template <typename V>
Stack<V>::Stack(const Stack<V>& original)
{
    staekSize = original.staekSize; //still copy
    cap = original.cap; // still copy
    values = new V[cap]; // not copy, is new
    for (int i = 0; i < cap; i++){ // contents copy original to new
        values[i] = original.values[i];
    }
}

template <typename V>
void Stack<V>::push(const V& value)
{
    if (staekSize == cap) capacity(2 * cap); // double the capacity if full
    values[staekSize] = value;
    ++staekSize;
}

template <typename V>
V& Stack<V>::peek()
{
    if (staekSize < 0){
        return values[0]; // a copy
    }
    else if (staekSize >= cap){
        capacity(2 * staekSize);
    }
    return values[staekSize-1]; // a copy
}

template <typename V>
void Stack<V>::capacity(int newCap)
{
    V* temp = new V[newCap];
    
    // get the lesser of the new and old capacities
    int limit = min(newCap,cap);
    
    // copy the contents
    for (int i = 0; i < limit; i++){
        temp[i] = values[i];
    }
    
    // set added values to their defaults
    for (int i = limit; i < cap; i++){
        temp[i] = V();
    }
    
    // deallocate original array
    delete [] values;
    
    // switch newly allocated array into the object
    values = temp;
    
    // update the capacity
    cap = newCap;
}

#endif
