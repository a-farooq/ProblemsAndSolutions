



#include<iostream>
using namespace std;

/*You need to complete this function */
int bin_search_rec(int A[], int left, int right, int k)
{
    int mid;
    if(left <= right) {
        mid = left+(right-left)/2;
        if(A[mid]==k) return mid;

        if(k < A[mid]) return bin_search_rec(A, left, mid-1, k); //right = mid-1;
        else return bin_search_rec(A, mid+1, right, k); //left = mid+1;
    }
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
		cout << bin_search_rec(a, 0, n-1, k) << endl;
	}
}
