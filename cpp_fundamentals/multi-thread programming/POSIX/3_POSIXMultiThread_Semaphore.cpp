#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <queue>
#include <iostream>

using namespace std;

#define BUF_SIZE 10

std::queue<int> buffer;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

sem_t empty_slots;
sem_t filled_slots;

void* producer(void* data) {

    for (int i = 0; i < 10; i++) {
        sem_wait(&empty_slots); // decrease the semaphore by 1 or block the below code if semaphore is alread 0
        pthread_mutex_lock(&lock);

        buffer.push(i);
        cout << "produced: " << i << endl;

        pthread_mutex_unlock(&lock);
        sem_post(&filled_slots);

        sleep(1);
    }

    pthread_exit(nullptr);
}

void* consumer(void* data) {

    for (int i = 0; i < 10; i++) {
        sem_wait(&filled_slots);
        pthread_mutex_lock(&lock);

        cout << "consumed: " << buffer.front() << endl;
        buffer.pop();

        pthread_mutex_unlock(&lock);
        sem_post(&empty_slots);
        sleep(1);
    }

    pthread_exit(nullptr);
}

int main(void) {

    pthread_t prod_thread, cons_thread;

    sem_init(&empty_slots, 0 /* pshared: if shared between processes */, BUF_SIZE /* init val */);
    sem_init(&filled_slots, 0, 0);

    pthread_create(&prod_thread, nullptr /* attr*/, producer, nullptr /* data*/);
    pthread_create(&cons_thread, nullptr /* attr*/, consumer, nullptr /* data*/);

    // synchronization: wait for both threads finish
    pthread_join(prod_thread, nullptr);
    pthread_join(cons_thread, nullptr);

    // destroy mutex and semaphore
    pthread_mutex_destroy(&lock);
    sem_destroy(&empty_slots);
    sem_destroy(&filled_slots);

    return 0;
}