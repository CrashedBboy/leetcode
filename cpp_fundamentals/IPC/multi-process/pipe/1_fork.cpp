#include <iostream>
#include <unistd.h>

using namespace std;

/*

Goal: fork a child process, and make child process executes different routine

Return Value(type: pid_t) of fork():
    For parent process, the returned pid is the pid of child process.
    The value is always greater than 0.

    For child process itself, the returned pid is 0.

    When error happens, the returned pid is -1
*/
// 


int main(void) {

    pid_t pid = fork();

    if (pid < 0) {
        cerr << "Fork failed" << endl;
        return 1;
    }

    // distinguish the parent and the child
    if (pid > 0) {
        cout << "This is the parent process, pid: " << getpid()
            << ", child pid: " << pid << endl;
        sleep(30);
    }
    else if (pid == 0) {
        cout << "This is the child process, pid: " << getpid() << endl; 
        sleep(30);
    }

    return 0;
}