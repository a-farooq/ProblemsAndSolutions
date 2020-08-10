/***************
Given a positive number X. Find all Jumping Numbers smaller than or equal to X. 
Jumping Number: A number is called Jumping Number if all adjacent digits in it differ by only 1. All single digit numbers are considered as Jumping Numbers. For example 7, 8987 and 4343456 are Jumping numbers but 796 and 89098 are not.

Input:
The first line of the input contains T denoting the number of testcases. Each testcase contain a positive number X.

Output:
Output all the jumping numbers less than X in sorted order. Jump to example for better understanding.

Constraints:
1 <= T <= 100
1 <= N <= 10^9

Example:
Input:
2
10
50
Output:
0 1 2 3 4 5 6 7 8 9 10
0 1 2 3 4 5 6 7 8 9 10 12 21 23 32 34 43 45

Explanation:
Testcase 2: Here, the most significant digits of each jumping number is following increasing order, i.e., jumping numbers starting from 0, followed by 1, then 2 and so on, themselves being in increasing order 2, 21, 23.
****************/
#include <iostream>
#include <set>
#include <unordered_set>
#include <queue>
using namespace std;

set<int> b;

int main()
{
    int t, n;
    int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12 };
    set<int> a (arr, arr+sizeof(arr)/sizeof(arr[0]));
    cin >> t;

    int max = *a.rbegin();
    int n1 = max/10;
        
    while(t--)
    {
        cin >> n;

        while(max < n)
        {
            ++n1;
            
            if(a.find(n1)==a.end()) continue;
            
            int last2 = n1%10;
            switch(last2) {
                case 0:
                    max = n1*10+1;
                    a.insert(max);
                    break;
                case 1:
                    a.insert(n1*10);
                    max = n1*10+2;
                    a.insert(max);
                    break;
                case 2:
                    a.insert(n1*10+1);
                    max = n1*10+3;
                    a.insert(max);
                    break;
                case 3:
                    a.insert(n1*10+2);
                    max = n1*10+4;
                    a.insert(max);
                    break;
                case 4:
                    a.insert(n1*10+3);
                    max = n1*10+5;
                    a.insert(max);
                    break;
                case 5:
                    a.insert(n1*10+4);
                    max = n1*10+6;
                    a.insert(max);
                    break;
                case 6:
                    a.insert(n1*10+5);
                    max = n1*10+7;
                    a.insert(max);
                    break;
                case 7:
                    a.insert(n1*10+6);
                    max = n1*10+8;
                    a.insert(max);
                    break;
                case 8:
                    a.insert(n1*10+7);
                    max = n1*10+9;
                    a.insert(max);
                    break;
                case 9:
                    max = n1*10+8;
                    a.insert(max);
                    break;
            }
        }
        
        for(auto i:a) {
            if(i > n) break;
            cout << i << " ";
        }
        
        cout << endl;
    }
}
/*
bool jumping(int n)
{
    if(b.find(n)!=b.end())
        return false;
        
    if(a.find(n)!=a.end())
        return true;
        
    if(n <= 10) 
    {
        a.insert(n);
        return true;
    }
    
    int m = n/10;
    if(a.find(m)!=a.end())
    {
        short last1 = n%10;
        short last2 = m%10;
        
        if(abs(last1-last2)==1)
        {
            a.insert(n);
            return true;
        }
    }
    else
    {
        jumping(m);
    }
    
    b.insert(n);
    return false;
}

int main2() {
	//code
	int T;
	long n;
	    
	cin >> T;
	while(T--)
	{
	    cin >> n;
        
        for(auto i=0; i <= 9 && i <= n; ++i)
            a.insert(i);
            
        for(auto i=10; i <= n; i+=10)
        {
            int j = i/10;   //e.g. i = 125; j = 12
            if(a.find(j)!=a.end()) //found
            {
                int last = j%10;    //last = 2
                
                if(last>0) {
                    int n1 = last-1;    //n1 = 1
                    int t1 = j*10+n1;
                    if(t1 <= n) 
                        a.insert(t1);  //insert 121
                }
                   
                if(last<9) { 
                    int n2 = last+1;    //n2 = 3
                    int t2 = j*10+n2;
                    if(t2 <= n)
                        a.insert(t2);  //insert 123
                }
            }
        }
        
        //for(auto i=0; i <= n; ++i)
        //    jumping(i);

        
	    for(auto i: a)
	        cout << i << " ";
	    cout << endl;
	        
	    for(auto i: b)
	        cout << i << " ";
	    cout << endl;
	}
	return 0;
}
*/
