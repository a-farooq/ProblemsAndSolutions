

#include <iostream>
#include <vector>
using namespace std;

void memcopy(void* dest, void* src, int size)
{
	char* dest_t = (char*)dest;
	char* src_t = (char*)src;

	for(int i=0; i<size; i++)
		dest_t[i]=src_t[i];
}

int main()
{
	char name1[20] = "aamil-farooq";
	char name2[30];

	memcopy(name2, name1, strlen(name1)+1);
	cout << name2 << endl;

	int u=3999;
	int v;
	memcopy(&v, &u, sizeof(u));
	cout << v << endl;

	//vector<int> vec1 = {87, 453, 890, 73123};
	//vector<int> vec2(vec1.size());
	int vec1[] = {87, 453, 890, 73123};
	int vec2[4];
	memcopy(&vec2, &vec1, sizeof(vec1));
	cout << sizeof(vec1) << endl;
	for(auto val:vec2) cout << val <<" "; cout << endl;
}
