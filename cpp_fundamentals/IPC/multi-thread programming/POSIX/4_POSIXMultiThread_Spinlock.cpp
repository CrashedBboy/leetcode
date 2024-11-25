#include <pthread.h>
#include <iostream>
#include <unistd.h>

using namespace std;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
bool ready = false;

void* worker(void* data) {

    while (true) {
        pthread_mutex_lock(&lock); // get the lock in order to access the critical region
        if (ready) {
            // do the job
            cout << "   Got it!!!" << endl;
            pthread_mutex_unlock(&lock);
            break;
        }
        else {
            cout << "   Not yet" << endl;
        }
        pthread_mutex_unlock(&lock);
    }

    pthread_exit(nullptr);
}

void* signaler(void* data) {

    sleep(1);
    pthread_mutex_lock(&lock);
    ready = true;
    cout << "Signal sent!" << endl;
    pthread_mutex_unlock(&lock);

    pthread_exit(nullptr);
}

int main(void) {

    pthread_t worker_thread, signaler_thread;

    pthread_create(&worker_thread, nullptr, worker, nullptr);
    pthread_create(&signaler_thread, nullptr, signaler, nullptr);

    pthread_join(worker_thread, nullptr);
    pthread_join(signaler_thread, nullptr);

    return 0;
}