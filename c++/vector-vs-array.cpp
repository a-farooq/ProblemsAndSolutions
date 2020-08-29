#include <iostream>
#include <vector>
using namespace std;

//void fun(int *a, vector<int> b)
void fun(int a[], vector<int> b) //same as above
{
	a[0] = 1;
	b[0] = 2;
}
int main()
{
	int a[10] = {0};
	vector<int> b(10, 0);

	fun(a, b);
	for(auto val : a) cout << val << " "; cout << endl;
	for(auto val : b) cout << val << " "; cout << endl;
}
