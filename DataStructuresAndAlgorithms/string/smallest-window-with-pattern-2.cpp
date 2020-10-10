/****
Given two strings. Find the smallest window in the first string consisting of all the characters of the second string.

Example 1:

Input:
S = timetopractice
P = toc
Output: toprac
Explanation: toprac is the smallest
subset in which toc can be found.
Example 2:

Input:
S = zoomlazapzo
P = oza
Output: apzo
Explanation: To find oza in the
zoomlazapzo the smallest subset is
apzo.
Your Task:
You don't need to read input or print anything. Your task is to complete the function smallestWindow() which takes two string S and P as inputs and returns the smallest window in string S having all the characters of the string P. In case there are multiple such windows of same length, return the one with the least starting index. Return "-1" in case there's no such window present. 

Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(1)

Constraints: 
1 <= |S|, |P| <= 1000
  ****/

// return the smallest window in S with all the characters of P
// if no such window exists, return "-1"
string smallestWindow (string str, string pat){
    // Your code here
    if(pat.length() > str.length()) {
        return "-1";
    }

    int hash_str[256]={0};
    int hash_pat[256]={0};

    for(auto ch:pat)
        hash_pat[ch]++;

    int cnt=0;
    int start=0;
    int minlen=INT_MAX;
    int start_index=0;
    for(int i=0; i<str.length(); i++) {
        char ch=str[i];
        hash_str[ch]++;

        if(hash_str[ch]<=hash_pat[ch]) {
            if(cnt==0) {
                start = i;
                start_index=i;
            }
            cnt++;
        }

        if(cnt == pat.length())
        {
            while(hash_str[str[start]]>hash_pat[str[start]]) {
                hash_str[str[start]]--;
                start++;
            }
            if(minlen > i-start+1) {
                minlen = i-start+1;
                start_index=start;
            }
        }
    }

    if(minlen>str.length()) return "-1";

    return str.substr(start_index, minlen);
}
