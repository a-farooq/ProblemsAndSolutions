
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>
using namespace std;

volatile bool done = false;

void* func(void* arg)
{
	sleep(3);
	done = true;
	return NULL;
}

int main()
{
	pthread_t t1;
	pthread_create(&t1, NULL, func, NULL);

	cout << "Waiting..." << endl;
	while(!done) {}
	cout << "Exiting..." << endl;
}
