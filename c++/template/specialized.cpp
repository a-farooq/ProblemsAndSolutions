



#include <iostream>
using namespace std;
 
template <class T>
T max (T &a, T &b)
{
    return (a > b)? a : b;
}
 
template <>
int max <int> (int &a, int &b)
{
    cout << "Called ";
    return (a > b)? a : b;
}
 
int main ()
{
    int a = 10, b = 20;
    cout << max <int> (a, b) << endl;
}
