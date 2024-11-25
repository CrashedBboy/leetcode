#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <string>

using namespace std;

#define N_THREAD 5

class RoutineContext {
public:
    string* sharedDocument;
    pthread_mutex_t* lock;
    char identifier;
};

// each thread are trying to log on a shared documents (represented by vector<char>)
void* threadRoutine(void* arg) {

    RoutineContext* context = ((RoutineContext*)arg);
    char id = context->identifier;

    // note: even printing (stdout) is a critical region, because internally the stdout is a shared buffer
    pthread_mutex_lock(context->lock);
    cout << "   [Thread] thread " << id << " is executed" << endl;
    pthread_mutex_unlock(context->lock);

    for (int i = 0; i < 3; i++) {
        pthread_mutex_lock(context->lock);
        context->sharedDocument->push_back(id);

        sleep(1);
        pthread_mutex_unlock(context->lock);
    }

    pthread_exit(nullptr);
}

int main(void) {

    // shared document to be edited collaboratively
    string sharedDoc = "";

    // create multiple thread
    pthread_t threads[N_THREAD];
    int resultCode; // used for store return values of pthread_create(): 0, EAGAIN, EINVAL, or EPERM
    pthread_mutex_t lock;

    pthread_mutex_init(&lock, nullptr /* attr */ );

    RoutineContext context[N_THREAD];
    for (int i = 0; i < N_THREAD; i++) {
        context[i].sharedDocument = &sharedDoc;
        context[i].lock = &lock;
        context[i].identifier = (char)('A' + i);
    }

    for (int i = 0; i < N_THREAD; i++) {
        cout << "[Main] creating a new thread (" << (char)('A'+i) << ")" << endl;
        resultCode = pthread_create(&threads[i], nullptr, threadRoutine, (void*)&context[i]);

        /**
        Q. what would be the problem of following code, where every thread accesses the same position for context?
            for (...) {
                RoutineContext context (...);
                pthread_create(&threads[i], nullptr, threadRoutine, (void*)&context);
            }
        
        A. each thread might get the wrong context content,
            because all thread are not executed in the same order of the loop.
         */
        
        // todo: make this a error handler and let the EAGAIN able to retry
        if (resultCode != 0) {
            switch (resultCode) {
                case EAGAIN:
                    cout << "   Not enough of resource" << endl;
                    break;
                case EINVAL:
                    cout << "   Invalid thread attributes" << endl;
                    break;
                case EPERM:
                    cout << "   Permission denied" << endl;
                    break;
                default:
                    cout << "   failed" << endl;
                    break;
            }
        }
    }

    /*
    [Concept of detached thread vs. joining thread]
    detaching:
    detaching marks the child thread to run independently, the resources after finish will be cleaned up by OS automatically

    joining a child thread:
    the calling thread waits for child thread to finish.

    Important note: 
    the created thread without explicit detaching or joining are JOINABLE thread.
    If you don't join or detach them, these threads remain in a "zombie" state after termination, 
    holding resources until they are explicitly joined. => that would be a resource leak.

    Why do them become zombie:
    all joinable (non-detached) child wait for a parent to reclaim their resource, but the parent is gone.
    => The process is still up.These zombie threads don't perform any work.
    They simply occupy resources until they are joined (or the process terminates).
    */
    void* returnedData[N_THREAD];
    for (int i = 0; i < N_THREAD; i++) {
        int joinStatusCode = pthread_join(threads[i], &returnedData[i]);
        if (joinStatusCode != 0) {
            cout << "Unable to join thread " << i << endl;
            exit(1);
        }
    }
    cout << "All threads are finished" << endl;
    cout << "Shared Doc: " << sharedDoc << endl;

    pthread_mutex_destroy(&lock); // always remember to uninitialize the lock

    /*
    Don't use exit() or return in main program to prevent premature:
        Otherwise, it may happesn that the child thread is still running but 
        the parent thread closes the whole process
    */
    pthread_exit(nullptr);
}