#include <iostream>
using namespace std;

int main()
{
	int m, n;
	cin >> m >> n;
	int **a;
	a = new int*[m];
	for(int i=0; i<m; i++) 
		a[i] = new int[n];

	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			a[i][j] = j;

	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++)
			cout << a[i][j] << " " ;
		cout << endl;
	}

	int *b = new int[m*n];
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			*(b+i*n+j) = j;


	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++)
			//cout << b[i*n+j] << " ";
			cout << *(b+i*n+j) << " ";
		cout << endl;
	}
}
