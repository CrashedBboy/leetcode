#include <pthread.h>
#include <unistd.h>
#include <iostream>
#include <queue>

#define BUF_SIZE 5

using namespace std;

queue<int> buffer;

// use the marco INITIALIZER for statically created mutex / cond
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_non_full = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond_non_empty = PTHREAD_COND_INITIALIZER;

void* consumer(void* args) {

    while (true) {
        pthread_mutex_lock(&lock);
        // check the condition: the buffer has something to be processed
        while (buffer.empty()) {
            pthread_cond_wait(&cond_non_empty, &lock); // this will yield the holding lock until get notified
        }

        int item = buffer.front();
        buffer.pop();
        cout << "consumed: " << item << endl;

        pthread_cond_signal(&cond_non_full);
        pthread_mutex_unlock(&lock);
        
        sleep(1.5);
    }

    pthread_exit(nullptr);
}


void* producer(void* args) {
    int item = 0;
    while (true) {
        pthread_mutex_lock(&lock);

        while (buffer.size() == BUF_SIZE) {
            pthread_cond_wait(&cond_non_full, &lock);
        }

        buffer.push(++item);

        cout << "Produced: " << item << endl;

        pthread_cond_signal(&cond_non_empty);
        pthread_mutex_unlock(&lock);

        sleep(0.5);
    }

    pthread_exit(nullptr);
}

int main(void) {
    pthread_t prod_thread, cons_thread;

    pthread_create(&prod_thread, nullptr, producer, nullptr);
    pthread_create(&cons_thread, nullptr, consumer, nullptr);

    pthread_detach(prod_thread);
    pthread_detach(cons_thread);

    cout << "The process will be closed after 20s." << endl;
    sleep(20);

    return 0;

}