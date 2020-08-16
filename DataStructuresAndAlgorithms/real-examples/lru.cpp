/****
In operating systems that use paging for memory management, page replacement algorithm are needed to decide which page needs to be replaced when the new page comes in. Whenever a new page is referred and is not present in memory, the page fault occurs and Operating System replaces one of the existing pages with a newly needed page. Given a sequence of pages and memory capacity, your task is to find the number of page faults using Least Recently Used (LRU) Algorithm.

Input:
The first line of input contains an integer T denoting the number of test cases. Each test case contains n number of pages and next line contains space seaprated sequence of pages. The following line consist of the capacity of the memory.
Note: Pages are referred in the order left to right from the array (i.e index 0 page is referred first then index 1 and so on). Memory is empty at the start.

Output:
Output the number of page faults.

Constraints:
1<=T<=100
1<=n<=1000
4<=capacity<=100

Example:
Input:
2
9
5 0 1 3 2 4 1 0 5
4
8
3 1 0 2 5 4 1 2
4

Output:
8
7

Explanation:
Testcase 1:
memory allocated with 4 pages 5, 0, 1, 3: page fault = 4
page number 2 is required, replaces LRU 5: page fault = 4+1 = 5
page number 4 is required, replaces LRU 0: page fault = 5 + 1 = 6
page number 1 is required which is already present: page fault = 6 + 0 = 6
page number 0 is required which replaces LRU 1: page fault = 6 + 1 = 7
page number 5 is required which replaces LRU 3: page fault = 7 + 1  =8.
****/
#include <iostream>
#include <array>
#include <list>
#include <set>
#include <algorithm>
#include <unordered_map>
using namespace std;

class LRU
{
public:
};

int main() {
	int t;
	array<int, 1005> arr;
	cin >> t;
	while(t--)
	{
	    int n, cap;
	    cin >> n;
	    int i = 0;
	    while(i<n)
	        cin >> arr[i++];

	    cin >> cap;

	    list<int> pagelist;
	    unordered_map<int, list<int>::iterator> pagemap;

	    int pagefault = 0;
	    for(int i = 0; i < n; i++)
	    {
	        int page = arr[i];
	        auto mapiter = pagemap.find(page);
	        if(mapiter == pagemap.end()) { //page not found in map
    	        if(pagelist.size() < cap) { //list is not full
    	            pagelist.push_front(page);
    	            pagemap[page] = pagelist.begin();
    	        }
    	        else { //list is full
    	            int lru = pagelist.back();
    	            pagelist.pop_back();
    	            pagelist.push_front(page);
    	            pagemap.erase(lru);
    	            pagemap[page] = pagelist.begin();
    	        }
    	        pagefault++;
	        }
	        else { //page found in map
	            auto iter = pagemap[page];
	            pagelist.erase(iter);
	            pagelist.push_front(page);
	        }
	    }

	    cout << pagefault << endl;
	}
	return 0;
}
