#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

const int THREAD_NUMBER = 10;

class Counter {

private:
	int _count;
	mutex mu;

public:
	Counter() : _count(0) {}

	void increaseTen() {

		mu.lock(); // waiting until it get the lock

		for (int i = 0; i < 10; i++) { _count += 1; }
		
		mu.unlock(); // release lock

        // [what problem might happen?]
        // if a exception thorwn between mutex.lock() and mutex.unlock()
        // unlock() won't be called, thus other thread will not get the lock
        // solution: use lock_guard<mutex> instead
	}

	void printCount() {

		cout << "count: " << _count << endl;
	}
};

void visit(Counter& c) {

	c.increaseTen();
}

int main() {

	Counter c;

	thread t1(visit, ref(c));
	thread t2(visit, ref(c));

	t1.join();
	t2.join();

	c.printCount();

	return 0;
}