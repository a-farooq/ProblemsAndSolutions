// condition_variable example
#include <iostream>           // std::cout
#include <thread>             // std::thread
#include <mutex>              // std::mutex, std::unique_lock
#include <unistd.h>           // sleep
#include <condition_variable> // std::condition_variable

std::mutex mtx;
std::condition_variable cv;
volatile int param = 1;

void run (int id, int MAX) {
	while (param<MAX) {
		sleep(1);
  		std::unique_lock<std::mutex> lck(mtx);

		//if(param%2 != id) {
			cv.wait(lck, [&](){ return param%2==id; });
		//}
  		std::cout << "thread-" << id << ": " << param << '\n';
		param++;


		cv.notify_all();
		mtx.unlock();
  	}
}

int main ()
{
  std::thread threads[2];
  // spawn 2 threads:
  for (int i=0; i<2; ++i)
    threads[i] = std::thread(run,i, 100);

  std::cout << "2 threads ready to race...\n";

  for (auto& th : threads) th.join();

  return 0;
}
