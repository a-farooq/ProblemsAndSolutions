#include <iostream>

using namespace std;

class Test
{
private:
	string m_name;
public:
    Test() {}

    friend ostream& operator << (ostream& out, const Test& obj);

	friend istream& operator >> (istream& in, Test& obj);
};

ostream& operator << (ostream& out, const Test& obj)
{
    out << obj.m_name;
    return out;
}

istream& operator >> (istream& in, Test& obj)
{
	in >> obj.m_name;
	return in;
}

int main()
{
	Test test;
	cin >> test;
	cout << test << endl;
}
