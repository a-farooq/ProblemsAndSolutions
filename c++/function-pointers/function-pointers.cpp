
#include <iostream>
using namespace std;

typedef int (*op_fptr)(int, int);

int add(int a, int b)
{
	return a+b;
}

int mult(int a, int b)
{
	return a*b;
}

int sub(int a, int b) 
{
	return a-b;
}

void operate2(op_fptr op, int x, int y)
{
	cout << op(x, y) << endl;
}

void operate(int (*op)(int, int), int x, int y)
{
	cout << op(x, y) << endl;
}

int main()
{
	int(*fptr)(int, int) = &sub;

	operate(add, 5, 4); //usage1
	operate2(mult, 5, 4); //usage2
	cout << fptr(5, 4) << endl; //usage3
}
