#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>
using namespace std;

std::mutex mtx;
condition_variable cv;

int threads;
volatile int param = 1;

void* threadfunc(void *arg)
{
	int turn = *(int*)arg;

	while(1)
	{
		mtx.lock();


		if(param%2 != turn)
			cv.wait(mtx);

		cout << "thread-" << turn << ": " << param << endl;
		param++;

		cv.notify_all();
		mtx.unlock();
	}
	return NULL;
}


int main()
{
	thread tid[threads];

	cout << "Number of threads: ";
	cin >> threads;

	for(int i= 1; i <= threads; i++)
		tid[i] = thread(threadfunc, i);

	for(auto th : tid)
		th.join();
}
