

#include <iostream>
using namespace std;

class Array
{
	int* m_ptr;
	int m_size;

	public:	
	Array(int*a_ptr, int a_size)
	{
		m_size = a_size;
		if(m_size > 0)
		{
			m_ptr = new int[m_size];
			for(int i=0; i<m_size; i++)
				m_ptr[i] = a_ptr[i];
		}
	}

	int& operator[](int idx)
	{
		if(idx<m_size) {
			return m_ptr[idx];
		}
		cout << "Index out of bound\n";
		exit(0);
		//return -1;
	}

	void print()
	{
		for(int i=0; i<m_size; i++)
			cout << m_ptr[i] << " ";
		cout << endl;
	}
};

int main()
{
	int a[5] = {5, 3, 9, 0, 2};
	Array arr(a, 5);
	arr.print();
	cout << "arr[3]: "<<arr[3] << endl;
	//arr[5] = 1; //Error: index out of bound
	arr[3] = 1;
	arr.print();
}
