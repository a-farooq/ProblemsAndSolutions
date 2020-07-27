/*****
If a derived class writes its own method, then all functions of base class with same name become hidden, even if signaures of base class functions are different. In the above question, when fun() is rewritten in Derived, it hides both fun() and fun(int) of base class.
*****/

#include <iostream>
using namespace std;

class Base
{
    public:
        void fun() { cout << "Base::fun() called" << endl; }
        void fun(int i) { cout << "Base::fun(int i) called" << endl; }
};

class Derived : public Base
{
    public:
        void fun() { cout << "Derived::fun() called" << endl; }
};

int main()
{
    Derived d;
    d.fun(5); //compiler error
    d.Base::fun(5); 
}
