

#include <iostream>
#include <thread>
#include <memory>

using namespace std;

std::thread observer;

void observe(weak_ptr<int> wp)
{
	observer = std::thread([wp](){
		while(true)
		{
			this_thread::sleep_for(std::chrono::seconds(1));
			if(shared_ptr<int> sp = wp.lock()) 
			{
				cout << "Observing: "<<*sp<<endl;
			}
			else 
			{
				cout << "Stop\n";
				break;
			}
		}
	});
}

int main()
{
	{
		auto sp = shared_ptr<int>(new int());

		observe(sp);
		this_thread::sleep_for(std::chrono::seconds(5));
	}
	observer.join();
}
