// Programmer: Minjoo Kim
// Programmer's ID: 1581736

#include <iostream>
using namespace std;

#include<cassert>

#include "Stack.h"
#include "Stack.h"

int main(){
    cout << "Programmer: Minjoo Kim\n";
    cout << "Programmer's ID: 1581736\n";
    cout << "File: " << __FILE__ << endl;
    cout << endl;
    
    cout << "Stack Test :" << endl;
    cout << "--------------------" << endl;
    Stack<int> a;
    cout << "Testing Stack::size" << endl;
    cout << "EXPECTED: 0" << endl;
    cout << "ACTUAL: " << a.size() << endl;
    assert(0 == a.size());
    cout << "Pass!" << endl;
    
    cout << "Testing Stack::push & Stack::peek" << endl;
    a.push(111);
    a.push(222);
    cout << "EXPECTED: 222" << endl;
    cout << "ACTUAL: " << a.peek() << endl
    ;
    assert(222 == a.peek());
    cout << "Pass!" << endl;
    
    cout << "Testing Stack::pop" << endl;
    cout << "Befor pop: " << a.peek() << endl;
    a.pop();
    cout << "After pop: " << a.peek() << endl;
    assert(111 == a.peek());
    cout << "Pass!" << endl;
    
    cout << "Testing assignment operator" << endl;
    Stack<int> b;
    b = a;
    assert(a.size() == b.size());
    for (int i = 0; i < b.size(); i++) {
        assert(a.peek() == b.peek());
        a.pop();
        b.pop();
    }
    cout << "Pass!" << endl;
    
    cout << "Testing copy operator" << endl;
    
    a.push(111);
    a.push(222);
    
    Stack<int> c(a);
    
    assert(a.size() == c.size());
    for (int i = 0; i < c.size(); i++) {
        assert(a.peek() == c.peek());
        a.pop();
        c.pop();
    }
    cout << "Pass!" << endl;
    
    Stack<int> d;
    cout << "Testing Stack::capacity" << endl;
    cout << "Defalut capacity: " << d.capacity() << endl;
    assert(2 == d.capacity());
    d.push(111);
    d.push(222);
    d.push(333);
    d.push(444);
    d.push(555);
    cout << "After pushing 5 element, size is: " << d.size() << endl;
    cout << "Capacity had doubled twice!" << endl;
    assert(8 == d.capacity());
    cout << "Pass!" << endl;
    
    cout << "Testing Stack::clear & empty" << endl;
    d.clear();
    assert(0 == d.size());
    assert(d.empty());
    cout << "Pass!" << endl;
    
    d.push(111);
    d.push(222);
    d.push(333);
    
    cout << "Constant object test" << endl;
    const Stack<int> e(d);
    cout << "size: " << e.size();
    assert(e.size() == 3);
    cout << "It's not empty!" << endl;
    assert(!e.empty());
    cout << "Pass!" << endl;
}
