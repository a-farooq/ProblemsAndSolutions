

#include <iostream>
#include <limits>
#include <cmath>
using namespace std;

int main()
{
	double val = numeric_limits<double>::min();

	if(fabs(val-numeric_limits<double>::max()) < numeric_limits<double>::epsilon())
		cout << true << endl;

	else cout << false << endl;
}
