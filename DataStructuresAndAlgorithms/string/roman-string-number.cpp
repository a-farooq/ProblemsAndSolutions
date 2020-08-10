/**********
Given an string in roman no format (s)  your task is to convert it to integer .

Input:
The first line of each test case contains the no of test cases T. Then T test cases follow. Each test case contains a string s denoting the roman no.

Output:
For each test case in a new line print the integer representation of roman number s. 

Constraints:
1<=T<=100
1<=roman no range<4000

Example:
Input
2
V
III 
Output
5
3
**********/
#include <iostream>
#include <map>
using namespace std;

map<char,int> roman;

int main() {
	//code
	roman.insert(pair<char, int>('I', 1));
	roman.insert(pair<char, int>('V', 5));
	roman.insert(pair<char, int>('X', 10));
	roman.insert(pair<char, int>('L', 50));
	roman.insert(pair<char, int>('C', 100));
	roman.insert(pair<char, int>('D', 500));
	roman.insert(pair<char, int>('M', 1000));

	int t;
	string str;
	cin >> t;
	while(t--)
	{
	    cin >> str;

	    int i = str.length()-1;
	    int num = roman[str[i]];
	    
	    for(--i; i>=0; i--)
	    {
	        if(roman[str[i]] < roman[str[i+1]])
	            num -= roman[str[i]];
	        else
	            num += roman[str[i]];
	    }
	    
	    cout << num << endl;
	}
	return 0;
}
