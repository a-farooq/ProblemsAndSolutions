#include <iostream>
using namespace std;

class Test
{
	public:
	int static inst_cnt;

	Test()
	{ 
		cout << "Test()" << endl;
		//inst_cnt++;
	}
	~Test()
	{
		cout << "~Test()" << endl;
		//inst_cnt--;
	}

	void* operator new(size_t tmp)
	{
		cout << "operator new()" << endl;
		inst_cnt++;
		void* p=::new Test;
		return p;
	}
	void operator delete(void* tmp)
	{
		cout << "operator delete()" << endl;
		inst_cnt--;
	}
};

int Test::inst_cnt=0;

int main()
{
	//Test t1, t2;
	
	Test* t3 = new Test;
	cout << Test::inst_cnt << endl;
	delete t3;
}
