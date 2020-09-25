/****
Given two numbers as stings s1 and s2 your task is to multiply them.

Example 1:

Input:
s1 = 33
s2 = 2
Output: 66
Example 2:

Input:
s1 = 11
s2 = 23
Output: 253
Your Task:

You are required to complete the function multiplyStrings() which takes two strings s1 and s2 as its only argument and returns their product as strings.

Constraints:
1 <= length of s1 and s2 <= 103

Expected time complexity: O( n1 * n2 )
Expected auxiliary space: O( n1 + n2 ) ; where n1 and n2 are sizes of strings s1 and s2 respectively.

Algorithm:
Reverse both strings and loop over second to multiple each digit with first string
  ****/

string multiply(string s, int k)
{
    int carry = 0;
    for(int i=0; i<s.length(); i++) {
        int p = (s[i]-'0')*k + carry;
        //cout << "p: "<<p << endl;
        //char t = p%10 + 48;//static_cast<char>(p%10);
        //cout << "t: "<<t << endl;
        s[i] = p%10 + 48;//static_cast<char>(t);
        carry = p/10;
        //cout << "s: " << s << endl;
    }

    if(carry) {
        s += to_string(carry);
    }
    //cout << "s: "<<s << endl;
    return s;
}

string add(string s3, string s4)
{
    string s = "";
    int carry=0;
    int i=0, j=0;
    while(i<s3.length() || j<s4.length()) {
        int a = 0;
        int b = 0;
        if(i<s3.length()) {
            a = s3[i]-'0';
            i++;
        }

        if(j<s4.length()) {
            b = s4[j]-'0';
            j++;
        }
        int sum = a+b+carry;
        carry = sum/10;
        //s += to_string(sum%10);
        s += sum%10 + 48;
    }
    if(carry) {
        //s += to_string(carry);
        s += carry+48;
    }
    return s;
}
/*You are required to complete below function */
string multiplyStrings(string s1, string s2)
{
    if(!s1.compare("0") || !s2.compare("0"))
        return "0";

    bool neg=false;
    if(s1[0]=='-')
    {
        neg=!neg;
        s1=s1.substr(1);
    }
    if(s2[0]=='-')
    {
        neg=!neg;
        s2=s2.substr(1);
    }
   //Your code here
    reverse(s1.begin(), s1.end());
    //cout << s1 << endl;
    //cout << s2 << endl;
    string s3="";
    int c=0;
    for(int i=s2.length()-1; i>=0; i--) {
        string s4 = multiply(s1, s2[i]-'0');
        //cout << "s4: "<<s4 << endl;
        if(s3=="")
            s3 = s4;
        else {
            int k=c;
            while(k--)
                s4 = "0"+s4;
            s3 = add(s3, s4);
        }
        c++;
        //cout << "s3: "<<s3 << endl;
    }
    reverse(s3.begin(), s3.end());
    while(s3[0]=='0')
        s3=s3.substr(1);
    if(neg) s3="-"+s3;
    return s3;
}
