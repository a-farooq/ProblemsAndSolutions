


#include <iostream>
using namespace std;

void reverse_rec(const string st, int i=0)
{
	if(i==st.length()) return;

	reverse_rec(st, i+1);
	cout << st[i];
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string st;
		cin >> st;
		reverse_rec(st);
		cout << endl;
	}
}

