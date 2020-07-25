

#include <iostream>
using namespace std;

template<class T, class U, class V=double>
class A
{
    T a;
    U b;
    V c;
    static int d;
};

int main()
{
    A<int, int> a;
    A<double, double> b;
    cout << sizeof(a) << endl;
    cout << sizeof(b) << endl;
}
