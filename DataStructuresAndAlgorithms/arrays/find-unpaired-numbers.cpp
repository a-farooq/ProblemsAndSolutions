/*************************
You are given an array A containing 2*N+2 positive numbers, out of which 2*N numbers exist in pairs whereas the other two number occur exactly once and are distinct. You need to find the other two numbers and print them in ascending order.
 

Input :
The first line contains a value T, which denotes the number of test cases. Then T test cases follow .The first line of each test case contains a value N. The next line contains 2*N+2 space separated integers.

Output :
Print in a new line the two numbers in ascending order.

Constraints :
1<=T<=100
1<=N<=10^6
1<=A[i]<=5*10^8

Example:
Input :
2
2
1 2 3 2 1 4
1
2 1 3 2

Output :
3 4
1 3
*************************/
#include <iostream>
#include <cstring>
#include <set>
using namespace std;
long a[1000005], t;
set<int> b;

int main()
{
    int t, n, k;
    cin >> t;
    while(t--)
    {
        cin >> n;
        b.clear();
        for (auto i = 0; i < 2*n+2; ++i)
        {
            cin >> k;
            if(b.find(k)!=b.end())
                b.erase(k);
            else b.insert(k);
        }
        for(auto i:b)
            cout << i << " ";
        cout << endl;
    }
}

int main2() {
	//code
	int T, n, max;
	cin >> T;
	while(T--)
	{
	    cin >> n;
	    max = 0;
	    memset(a, 0, sizeof(a));
	    for(auto i=1; i <= 2*n+2; ++i)
	    {
	        cin >> t;
	        ++a[t];
	        a[t] %= 2; 
	        max = t > max ? t : max;
	    }
	    
	    for(auto i = 1; i <= max; ++i)
	    {
	        if(a[i]==1)
	            cout << i << " ";
	    }
	    cout << endl;
	}
	return 0;
}
