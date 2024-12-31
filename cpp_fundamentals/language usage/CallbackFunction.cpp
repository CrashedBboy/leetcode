#include <iostream>



using namespace std;

void requestData(int key, void (*analyzeData)(int data)) {

    cout << "Request data via key: " << key << endl;

    // simulated: we get the data back
    int data = 12;
    (*analyzeData)(data);
}

void analysisMode1(int data) {
    cout << "Data is being processed by method 1" << endl;
}

void analysisMode2(int data) {
    cout << "Data is being processed by method 2" << endl;
}

int main(void) {

    int key = 3;
    requestData(key, &analysisMode1);
    requestData(key, &analysisMode2);

    return 0;
}