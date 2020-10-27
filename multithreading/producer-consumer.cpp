#include <iostream>           // std::cout
#include <thread>             // std::thread
//#include <pthread.h>             // std::thread
#include <mutex>              // std::mutex, std::unique_lock
#include <semaphore.h>              // std::mutex, std::unique_lock
#include <unistd.h>           // sleep
using namespace std;

sem_t empty;
sem_t full;
std::mutex mtx;
//pthread_mutex_t mtx;
//volatile int param = 1;
#define SIZE 5
int buffer[SIZE];
int buf_idx=0;
#define PROD_COUNT 4
#define CONS_COUNT 3

void producer(int idx)
{
	sem_wait(&empty);
	lock_guard<mutex> lck(mtx);
	//pthread_mutex_lock(&mtx);
	//sleep(1);
	cout << "Producer "<<idx<<endl;
	int item = rand()%100;
	cout << item << endl;

	buffer[buf_idx++]=item;
	//pthread_mutex_unlock(&mtx);
	sem_post(&full);
}

void consumer(int idx)
{
	sem_wait(&full);
	lock_guard<mutex> lck(mtx);
	//pthread_mutex_lock(&mtx);
	//sleep(1);
	int item = buffer[--buf_idx];
	cout << "Consumer "<<idx<<endl;
	cout << item << endl;
	//pthread_mutex_unlock(&mtx);
	sem_post(&empty);
}

int main ()
{
	sem_init(&empty, 0, SIZE);
	sem_init(&full, 0, 0);

	srand(time(NULL));

  	std::thread producers[PROD_COUNT];
  	std::thread consumers[CONS_COUNT];
  	//pthread_t producers[PROD_COUNT];
  	//pthread_t consumers[CONS_COUNT];
  	// spawn threads
  	for (int i=0; i<PROD_COUNT; ++i)
  		producers[i] = std::thread(producer, i);

  	for (int i=0; i<CONS_COUNT; ++i)
  		consumers[i] = std::thread(consumer, i);

  	for (auto& th : producers) th.join();
  	for (auto& th : consumers) th.join();

	sem_destroy(&empty);
	sem_destroy(&full);
  	return 0;
}
