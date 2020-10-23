



#include <iostream>
using namespace std;
 
template <class T>
T max (T &a, T &b)
{
    cout << "general Called ";
    return (a > b)? a : b;
}
 
template <>
int max <int> (int &a, int &b)
{
    cout << "int Called ";
    return (a > b)? a : b;
}
 
int main ()
{
    float a = 10, b = 20;
    cout << max <float> (a, b) << endl;
}
