#include <iostream>
using namespace std;

class Point
{
	int m_x, m_y;
public:
	Point(int x, int y) : m_x(x), m_y(y)
	{
	}

	Point& operator()(int dx, int dy)
	{
		m_x += dx;
		m_y += dy;
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Point& pt);
};

	ostream& operator<<(ostream& out, const Point& pt)
	{
		out << pt.m_x << ", "<< pt.m_y;
		return out;
	}
int main()
{
	Point pt(0, 0);
	
	cout << pt << endl;
	//adding offset to point object
	pt(3,2);
	cout << pt << endl;
}
