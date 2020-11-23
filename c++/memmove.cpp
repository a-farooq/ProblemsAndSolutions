

#include <iostream>
#include <vector>
using namespace std;

void mem_move(void* dest, void* src, int bytes)
{
	//char takes 1 byte
	//have to copy byte by byte
	char* dest_t = (char*)dest;
	char* src_t = (char*)src;

	char* temp = new char[bytes];

	for(int i=0; i<bytes; i++)
		temp[i]=src_t[i];

	for(int i=0; i<bytes; i++)
		dest_t[i]=temp[i];

	delete [] temp;
}

int main()
{
	char name1[20] = "aamil-farooq";
	char name2[30];

	mem_move(name2, name1, strlen(name1)+1);
	cout << name2 << endl;

	int u=3999;
	int v;
	mem_move(&v, &u, sizeof(u));
	cout << v << endl;

	//vector<int> vec1 = {87, 453, 890, 73123};
	//vector<int> vec2(vec1.size());
	int vec1[] = {87, 453, 890, 73123};
	int vec2[4];
	//memcopy(&vec2, &vec1, sizeof(vec1));
	mem_move(vec2, vec1, sizeof(vec1));
	cout << sizeof(vec1) << endl;
	for(auto val:vec2) cout << val <<" "; cout << endl;
}
