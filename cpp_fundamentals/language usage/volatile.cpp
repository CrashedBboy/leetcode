/**  

    In this file, we will learn the difference b/t having volatile keywords or not.

    In short, volatile keywords tell the compiler that this variable's value may be changed by code out of current thread.
    
    So:
        1. It forces the compiler to reload the value from memory every time the variable is used,even if the register already have it.
        2. The compiler must not reorder instructions in a way that changes the access order of the volatile variable.
 */

#include <pthread.h>
#include <iostream>

using namespace std;

volatile int sharedData = 0; // the global variable to be updated

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* incValue(void* arg) {

    for (int i = 0; i < 10; i++) {
        pthread_mutex_lock(&mutex);
        cout << "Increase from " << sharedData << " to " << (sharedData + 1) << endl;
        sharedData += 1;
        pthread_mutex_unlock(&mutex);
    }

    return nullptr;
}

int main(void) {
    pthread_t t1, t2;

    pthread_create(&t1, nullptr, &incValue, nullptr);
    pthread_create(&t2, nullptr, &incValue, nullptr);

    pthread_join(t1, nullptr);
    pthread_join(t2, nullptr);

    cout << "Final value: " << sharedData << endl;

    pthread_exit(nullptr);
}