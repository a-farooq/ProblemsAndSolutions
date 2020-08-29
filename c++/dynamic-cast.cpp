#include <iostream>
using namespace std;

class Base
{
public:
	void fun() { cout << "Base::fun()\n"; }

	//virtual void fun() { cout << "Base::fun()\n"; }
	virtual ~Base() {}
};

class Derived : public Base
{
public:
	void fun() { cout << "Derived::fun()\n"; }
};

int main()
{
	Base* bd = new Derived;

	//with only Base class pointer avbl, even if pointing to Derived, fun will call Base::fun()
	//there are two ways to call Derived::fun() through same object pointer...
	//1. use RTTI through dynamic_cast. Downcast the Base pointer to Derived.
	//2. make fun() virtual in Base. Then same pointer can be used. But this is not always possible to modify Base class.
	bd->fun();

	Derived* d;
	d = dynamic_cast<Derived*>(bd);
	d->fun();
}
