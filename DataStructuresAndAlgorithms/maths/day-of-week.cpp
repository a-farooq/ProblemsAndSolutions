/****
Write a program that calculates the day of the week for any particular date in the past or future.

Input:
The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow. Each test case consist of one line. The first line of each test case consists of an integer d,m and y, d is day, m is month and y is the year.

Output:
Print day of given date.

Constraints:
1 <= T <= 100
1 <= d <= 31
1 <= m <= 12
1990 <= Y <= 2100

Example:
Input:
2
28 12 1995
30 8 2010
Output:
Thursday
Monday

https://stackoverflow.com/questions/6385190/correctness-of-sakamotos-algorithm-to-find-the-day-of-week/6385934#6385934
  ****/

#include <iostream>
using namespace std;

string getday(int d)
{
    switch(d) {
        case 0: return "Sunday";
        case 1: return "Monday";
        case 2: return "Tuesday";
        case 3: return "Wednesday";
        case 4: return "Thursday";
        case 5: return "Friday";
        case 6: return "Saturday";
    }
}
int findday(int d, int m, int y)
{
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    y -= m<3;
    return (y+y/4-y/100+y/400+t[m-1]+d)%7;
}
int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    int d, m, y;
	    cin >> d >> m >> y;
	    cout << getday(findday(d,m,y)) << endl;
	}
	return 0;
}
