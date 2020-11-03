

#include <iostream>
#include <vector>
#include <exception>
using namespace std;

template<typename T>
class Minheap
{
	vector<T> m_heap;
	//int m_size;

	void bubbleUp()
	{
		int i = m_heap.size()-1;
		T element = m_heap[i];
		while(i>0)
		{
			//parent index
			int pi = (i-1)/2;

			if(element < m_heap[pi])
			{
				m_heap[i] = m_heap[pi];
				i = pi;
			}
			else break;
		}
		//found the position for element
		m_heap[i] = element;
	}

	void bubbleDown()
	{
		int size = m_heap.size();

		T element = top();

		int i=0;
		int child_pos = i*2+1;

		while(child_pos < size)
		{
			int rc = i*2+2;

			if(rc<size && m_heap[rc]<m_heap[child_pos]) {
				child_pos = rc;
			}

			if(m_heap[child_pos] < element) {
				m_heap[i]=m_heap[child_pos];
				i = child_pos;
			}
			else break;
			
			child_pos = i*2+1;
		}

		//found the position for element
		m_heap[i] = element;
	}


	void print()
	{
		for(auto val : m_heap)
			cout << val << " ";
		cout << endl;
	}

	public:

	Minheap()
	{
	}

	Minheap(vector<T> vec)
	{
		for(auto k : vec) {
			push(k);
			//print();
		}
	}

	void push(T item)
	{
		m_heap.push_back(item);
		if(m_heap.size() > 1)
			bubbleUp();
	}

	void pop()
	{
		if(m_heap.size() <= 0)
			throw string("Heap Empty!");

		int size = m_heap.size();

		m_heap[0] = m_heap[size-1];
		m_heap.pop_back();

		if(m_heap.size() > 1)
			bubbleDown();
	}

	T& top()
	{
		if(m_heap.size()<0)
			throw string("Heap Empty");
		return m_heap[0];
	}

	int size()
	{
		return m_heap.size();
	}

	void sort()
	{
		cout << "Heap sort: " << endl;
		while(m_heap.size()>0)
		{
			cout << top() << " ";
			pop();
			//print();
		}
		cout << endl;
	}
};

int main()
{
	try {
		vector<int> vec = {70, 54, 89, 73, 90, 21};
		Minheap<int> heap(vec);
		heap.sort();

		vector<string> stvec = { "where", "have", "you", "gone", "today"};
		Minheap<string> stheap(stvec);
		stheap.sort();
	}
	catch(exception& e)
	{
		cout << e.what() << endl;
	}
	catch(string& exc)
	{
		cout << "Exception: " << exc << endl;
	}
}
