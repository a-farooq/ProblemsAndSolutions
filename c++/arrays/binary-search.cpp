



#include<iostream>
using namespace std;

/*You need to complete this function */
int bin_search(int A[], int left, int right, int k)
{
    int mid;
    while(left <= right) {
        mid = left+(right-left)/2;
        if(A[mid]==k) break;

        if(k < A[mid]) right = mid-1;
        else left = mid+1;
    }
    if(A[mid]==k) return mid;
    return -1;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, k;
		cin >> n;
		int a[n];
		for(auto i = 0; i < n; i++)
			cin >> a[i];

		cin >> k;
		cout << bin_search(a, 0, n-1, k) << endl;
	}
}
