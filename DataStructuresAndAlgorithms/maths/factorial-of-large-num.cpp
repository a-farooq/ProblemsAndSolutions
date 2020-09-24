/****
Given an integer, the task is to find factorial of the number.
 
Input:
The first line of input contains an integer T denoting the number of test cases.  
The first line of each test case is N,the number whose factorial is to be found
 
Output:
Print the factorial of the number in separate line.
 
Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 1000
 
Example:
Input
3
5
10
2
 
Output
120
3628800
2

Algorithm:
Multiply all digits of a given number from 2 till itself
and save in a big array in reverse
  ****/

#include <iostream>
using namespace std;

#define MAX 100000000
int res[MAX];

int multiply(int res[], int k, int size)
{
    int carry=0;
    int i=0;
    for(; i< size; i++) {
        int t = res[i]*k + carry;
        res[i] = t%10;
        carry = t/10;
    }
    while(carry) {
        res[size]=carry%10;
        carry/=10;
        size++;
    }
    return size;
}
void factorial(int n)
{
    //int res[MAX]; //causes seg fault
    res[0]=1;
    int res_size=1;
    for(int k=2; k<=n; k++)
        res_size = multiply(res, k, res_size);

    for(int i=res_size-1; i>=0; i--)
        cout << res[i];
    cout << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    factorial(n);
	}
	return 0;
}
