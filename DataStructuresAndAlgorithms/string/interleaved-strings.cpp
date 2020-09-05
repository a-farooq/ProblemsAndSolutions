/****
Given three strings A, B and C your task is to complete the function isInterleave which returns true if C is an interleaving of A and B else returns false. C is said to be interleaving A and B, if it contains all characters of A and B and order of all characters in individual strings is preserved.

Example 1:

Input:
A = YX, B = X, C = XXY
Output: 0
Explanation: XXY is not interleaving
of YX and X
Example 2:

Input:
A = XY, B = X, C = XXY
Output: 1
Explanation: XXY is interleaving of
XY and X.
Your Task:
Complete the function isInterleave() which takes three strings A, B and C as input and returns true if C is an interleaving of A and B else returns false. (1 is printed by the driver code if the returned value is true, otherwise 0.)

Expected Time Complexity: O(N * M)
Expected Auxiliary Space: O(N * M)
here, N = length of A, and M = length of B

Constraints:
1<=length of A, B, C <=100

The strings can be interleaved non-consecutively and both must exist completely
  ****/

bool isInterleaveUtil(int i, int j, int k, string A, string B, string C)
{
    bool ret=false;
    int lenA = A.length();
    int lenB = B.length();
    int lenC = C.length();

    if(k==lenC && (i!=lenA || j!=lenB)) return false;

    if(i==lenA && j==lenB) return true;

    if(k<lenC) {
        if(i < lenA && j<lenB && A[i]==C[k] && B[j]==C[k]) {
            ret = isInterleaveUtil(i+1, j, k+1,A,B,C);
            if(ret) return true;
            ret = isInterleaveUtil(i, j+1, k+1,A,B,C);
        }
        else if(i < lenA && A[i]==C[k]) {
            ret = isInterleaveUtil(i+1, j, k+1,A,B,C);
        }
        else if(j<lenB && B[j]==C[k]) {
            ret = isInterleaveUtil(i, j+1, k+1,A,B,C);
        }
        else {
            ret = isInterleaveUtil(i, j, k+1,A,B,C);
        }
    }
    return ret;
}

/*You are required to complete this method */
bool isInterleave(string A, string B, string C)
{
    int lenA = A.length();
    int lenB = B.length();
    int lenC = C.length();

    return isInterleaveUtil(0,0,0,A,B,C);
    /*
    bool flagA = false;
    int i=0,k = 0;
    while(k<lenC) {
        if(A[i]==C[k++]) {
            flagA = true;
            break;
        }
    }
    while(i<lenA && k<lenC) {
        if(A[i++]!=C[k++]) {
            flagA = false;
            break;
        }
    }

    bool flagB = false;
    int j=0;
    k = 0;
    while(k<lenC) {
        if(B[j]==C[k++]) {
            flagB = true;
            break;
        }
    }
    while(j<lenA && k<lenC) {
        if(A[j++]!=C[k++]) {
            flagB = false;
            break;
        }
    }
    if(flagA && flagB) return true;
    return false;*/
}
