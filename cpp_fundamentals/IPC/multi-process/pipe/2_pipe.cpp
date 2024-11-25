#include <iostream>
#include <unistd.h>
#include <cstring>

using namespace std;

/*
Goal: using pipe to do one-way communication between the parent and the child

Communication: parent writes and child reads
*/

int main(void) {

    int pipefd[2]; // pipe read/write file descriptors
    if (pipe(pipefd) == -1) {
        cerr << "pipe creation failed" << endl;
    }


    pid_t pid = fork();
    if (pid < 0) {
        cerr << "fork failed" << endl;
        return 1;
    }

    if (pid == 0) { // child(forked) process
        close(pipefd[1]); // close unused read end
        char buffer[100];

        // When the writer closes the pipe, read() returns 0, indicating the end of the stream.
        while (true) {
            if (read(pipefd[0], buffer, sizeof(buffer)) != 0) {
                cout << "received: " << buffer << endl;
            }
            else {
                break;
            }
        }
        close(pipefd[0]);
    }
    else { // parent process
        close(pipefd[0]); // close unused write end
        const char* message = "Hey kid!";
        write(pipefd[1], message, strlen(message)+1);
        for (int i = 0; i < 3; i++) {
            const char* code = ("WAKE UP");
            write(pipefd[1], code, strlen(code)+1);
            sleep(1); // Simulate some delay
        }
        close(pipefd[1]); // singals the reader that no more data will be written
    }

    return 0;
}