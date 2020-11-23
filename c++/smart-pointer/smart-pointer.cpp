

#include <iostream>
using namespace std;

class Student
{
public:
	string getName()
	{
		return "abc";
	}
};

template<typename T>
class SmartPtr
{
	T* m_ptr;
public:
	SmartPtr(T* a_ptr=nullptr) : m_ptr(a_ptr)
	{
	}

	T* operator->()
	{
		return m_ptr;
	}

	T& operator*()
	{
		return *m_ptr;
	}

	~SmartPtr()
	{
		delete m_ptr;
	}

};

//void fun(SmartPtr<Student> sp) //crash
void fun(SmartPtr<Student>& sp)
{
	cout << sp->getName() << endl;
}

int main()
{
	SmartPtr<Student> sp(new Student());
	cout << sp->getName() << endl;
	cout << (*sp).getName() << endl;
	
	fun(sp);
}
