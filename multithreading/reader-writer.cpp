#include <iostream>           // std::cout
#include <thread>             // std::thread
//#include <pthread.h>             // std::thread
#include <mutex>              // std::mutex, std::unique_lock
#include <semaphore.h>              // std::mutex, std::unique_lock
#include <unistd.h>           // sleep
using namespace std;

sem_t wrt;
std::mutex mtx;
//pthread_mutex_t mtx;
int bal = 1;
int reader_cnt = 0;
#define READERS_COUNT 2
#define WRITERS_COUNT 2

void writer(int idx)
{
	sem_wait(&wrt);
	//sleep(1);
	bal *= 2;
	cout << "writer "<<idx << " updates the value "<<bal<<endl;
	sem_post(&wrt);
}

void reader(int idx)
{
	{
	lock_guard<mutex> lck(mtx);
	//pthread_mutex_lock(&mtx);
	reader_cnt++;
	if(reader_cnt==1)
		sem_wait(&wrt);
	//pthread_mutex_unlock(&mtx);
	//lck.unlock();
	}

	cout << "Reader "<<idx<<" reads the value "<< bal<<endl;
	
	//pthread_mutex_lock(&mtx);
	
	{
	lock_guard<mutex> lck(mtx);
	reader_cnt--;
	if(reader_cnt==0)
		sem_post(&wrt);
	//lck.unlock();
	}
}

int main ()
{
	sem_init(&wrt, 0, 1);
	//pthread_mutex_init(&mtx, NULL);

	//srand(time(NULL));
	int a[10] = {1,2,3,4,5,6,7,8,9,10};

  	//pthread_t readers[READERS_COUNT];
  	//pthread_t writers[WRITERS_COUNT];
  	thread readers[READERS_COUNT];
  	thread writers[WRITERS_COUNT];
  	// spawn threads
  	for (int i=0; i<READERS_COUNT; ++i) {
  		//pthread_create(&readers[i], NULL, (void*)reader, (void*)&a[i]);
		readers[i] = thread(reader, i+1);
	}
  	for (int i=0; i<WRITERS_COUNT; ++i) {
  		//pthread_create(&writers[i], NULL, (void*)writer, (void*)&a[i]);
		writers[i] = thread(writer, i+1);
	}
  	for (int i=0; i<READERS_COUNT; ++i) {
  		//pthread_join(readers[i], NULL);
		readers[i].join();
	}

  	for (int i=0; i<WRITERS_COUNT; ++i) {
  		//pthread_join(writers[i], NULL);
  		writers[i].join();
	}

	//pthread_mutex_destroy(&mtx);
	sem_destroy(&wrt);
  	return 0;
}
