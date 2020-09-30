/****

  ****/

#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    int m, n;
	    cin >> m >> n;
	    string st1, st2;
	    cin >> st1 >> st2;

	    int lcs[m+1][n+1];
	    for(int i=0; i<= m; i++) {
	        for(int j=0; j<=n; j++) {
	            if(i==0 || j==0)
					lcs[i][j]=0;
				//note the subscripts of strings
	            else if(st1[i-1]==st2[j-1]) {
	                lcs[i][j]=1+lcs[i-1][j-1];
	            }
	            else {
	                lcs[i][j]=max(lcs[i-1][j], lcs[i][j-1]);
	            }
	        }
	    }
	    cout << lcs[m][n] << endl;
	}
	return 0;
}
