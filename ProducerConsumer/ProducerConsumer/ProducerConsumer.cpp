#include <queue>
#include <thread>
#include <iostream>
#include <mutex>

int counter = 0;
bool done = false;

std::queue<int> goods;
std::mutex queueMutex;
std::condition_variable condition;

void producer()
{
	std::cout << "Starting producer..." << std::endl;

	for (int i = 0; i < 500; ++i)
	{
		{
			std::unique_lock<std::mutex> lock(queueMutex);
			condition.wait(lock, [] {return counter == 0; });
			goods.push(i);
			counter++;
		}
		condition.notify_one();
	}
	done = true;

	std::cout << "Finished producer..." << std::endl;
}

void consumer()
{
	std::cout << "Starting consumer..." << std::endl;

	while (!done)
	{
		{
			std::unique_lock<std::mutex> lock(queueMutex);
			condition.wait(lock, [] {return counter != 0; });
			goods.pop();
			counter--;
		}
		condition.notify_one();
	}

	std::cout << "Finished consumer..." << std::endl;
}

int main()
{
	counter = 0;

	std::thread producerThread(producer);
	std::thread consumerThread(consumer);

	producerThread.join();
	consumerThread.join();

	std::cout << "Net: " << counter << " " << goods.size() << std::endl;
}