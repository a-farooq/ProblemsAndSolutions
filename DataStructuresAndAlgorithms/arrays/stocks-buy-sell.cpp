/****
The cost of stock on each day is given in an array A[] of size N. Find all the days on which you buy and sell the stock so that in between those days your profit is maximum.

Input: 
First line contains number of test cases T. First line of each test case contains an integer value N denoting the number of days, followed by an array of stock prices of N days. 

Output:
For each testcase, output all the days with profit in a single line. And if there is no profit then print "No Profit".

Constraints:
1 <= T <= 100
2 <= N <= 103
0 <= Ai <= 104

Example
Input:
3
7
100 180 260 310 40 535 695
4
100 50 30 20
10
23 13 25 29 33 19 34 45 65 67
Output:
(0 3) (4 6)
No Profit
(1 4) (5 9)

Explanation:
Testcase 1: We can buy stock on day 0, and sell it on 3rd day, which will give us maximum profit.

Note: Output format is as follows - (buy_day sell_day) (buy_day sell_day)
For each input, output should be in a single line.
  ****/

#include <iostream>
using namespace std;

// User function template for C++

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int price[], int n)
{

    int start=-1;
    int end = -1;
    bool profit=false;
    for(int i=0; i<n;i++) {
        //dont change start if already set i.e. start >=0
        //set local minima as start
        if(start<0 && price[i]<price[i+1])
            if(i==0 || price[i-1]>=price[i] ) {
                start = i;
                //reset end
                end = -1;
            }

        //set end only if not set
        //set local maxima as end
        if(end<0 && price[i]>=price[i-1])
            if(i==n-1 || price[i]>price[i+1] ) {
                end=i;
                if(start>=0 && end>start) {
                    cout << "("<<start<<" "<<end<<") ";
                    profit=true;
                }
                //reset start
                start=-1;
            }
        //cout << "i:"<<i<<",start:"<<start<<",end:"<<end<<endl;
    }

    if(!profit) cout << "No Profit";
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        bool profit = false;
        cin >> n;
        int i = 0, j = 1;
        int x, y;
        cin >> x;
        //find all the increasing subsequences and print
        for(; j < n; j++) {
            cin >> y;
            if(x > y) {
                if(j-i > 1) {
                    cout << "("<< i << " "<< j-1 << ") ";
                    profit = true;
                }
                i = j;
            }
            else if(j==n-1) {
                if(j-i>0) {
                    cout << "("<< i << " " << j << ") ";
                    profit = true;
                }
            }
            x = y;
        }
        if(!profit) cout << "No Profit";
        cout << endl;
    }
	return 0;
}
