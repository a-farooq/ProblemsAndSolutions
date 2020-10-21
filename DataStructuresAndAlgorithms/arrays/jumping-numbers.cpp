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
using namespace std;

int main() {
	//code
	int t;
	cin >> t;

	set<int> jump = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12};

	int max = 12;

	while(t--)
	{
	    int n;
	    cin >> n;

	    int tens_place = max/10;

	    while(max < n)
	    {
	        tens_place++;

	        //removing unwanted numbers e.g 110, 132 etc.
	        if(jump.find(tens_place)==jump.end())
	            continue;

	        int rem = tens_place%10;

	        if(rem == 0) {
	            max = tens_place*10 + 1;
	        }
	        else if(rem == 9) {
	            max = tens_place*10 + 8;
	        }
	        else {
	            jump.insert(tens_place*10 + rem-1);
	            max = tens_place*10 + rem+1;
	        }
	        jump.insert(max);
	    }
	    for(auto val : jump) {
	        if(val > n) break;
	        cout << val << " ";
	    }

	    cout << endl;
	}
	return 0;
}
