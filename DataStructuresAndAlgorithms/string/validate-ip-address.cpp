/****
Write a program to Validate an IPv4 Address. According to Wikipedia, IPv4 addresses are canonically represented in dot-decimal notation, which consists of four decimal numbers, each ranging from 0 to 255, separated by dots, e.g., 172.16.254.1 . The generalized form of an IPv4 address is (0-255).(0-255).(0-255).(0-255). Here we are considering numbers only from 0 to 255 and any additional leading zeroes will be considered invalid.

Your task is  to complete the function isValid which returns 1 if the ip address is valid else returns 0. The function takes a string ip as its only argument .

Example 1:

Input:
ip = 222.111.111.111
Output: 1
Example 2:

Input:
ip = 5555..555
Output: 0
Explanation: 5555..555 is not a valid
ip address, as the middle two portions
are missing.
Your Task:
Complete the function isValid() which takes a character array as input parameter and returns 1 if this is a valid ip address otherwise returns 0.

Expected Time Complexity: O(N), N = length of string.
Expected Auxiliary Space: O(1)

Constraints:
1<=length of string <=50

Note:The Input/Ouput format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only. As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.
  ****/

#include <iostream>
using namespace std;
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
int isValid(char *ip)
{
    int len = strlen(ip);
    if(len < 7 || len > 15) return 0;
    int dotcnt = 0;
    int digitcnt = 0;

    char* octet = new char[4];
    memset(octet, '\0', 4);
    char* tmp = octet;
    //cout << ip << endl;
    while(1)
    {
        //cout << *ip << endl;

        if(*ip == '.' || *ip == '\0') {
            //cout << "@@@" << octet << endl;

            if(*octet == '\0') return 0;
            //if(*octet == '0' && *(octet+1) == '0') return 0;
            //if(*octet == '0' && *(octet+1) == '0' && *(octet+2)=='0') return 0;
            //if(digitcnt == 3 && (*octet > '2' || *(octet+1) > '5' || *(octet+2) > '5'))
            //    return 0;
            int num = atoi(octet);
            if(digitcnt == 3 && num > 255) return 0;
            if(digitcnt > 1 && num == 0) return 0;
            if(digitcnt > 1 && (*octet == '0')) return 0;

            if(*ip == '\0') break;

            if(++dotcnt > 3) return 0;

            memset(octet, '\0', 4);
            tmp = octet;
            digitcnt = 0;
        }
        else {
            if(!(*ip >= '0' && *ip <= '9')) return 0;
            *tmp = *ip;
            tmp++;
            //cout << "===" << octet << endl;
            //digitcnt++;
            if(++digitcnt > 3) return 0;
        }
        ip++;
    }
    if(dotcnt != 3) return 0;
    return 1;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		char s[10000];
		cin >> s;
		cout << isValid(s) << endl;
	}
}
