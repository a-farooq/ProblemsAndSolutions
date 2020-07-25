

#include <iostream>
using namespace std;
  
template<int n> struct funStruct
{
    static const int val = 2*funStruct<n-1>::val;
};
  
template<> struct funStruct<0>
{
    static const int val = 1 ;
};
  
int main()
{
    cout << funStruct<10>::val << endl;
    return 0;
}
