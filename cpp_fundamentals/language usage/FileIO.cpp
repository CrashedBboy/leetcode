#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    // write file
    ofstream writeOut("test.txt", ios::out);
    if (writeOut) {
        
        writeOut << "This is line one" << endl << "This is line two";
        writeOut.close();
    }

    // read file line by line
    ifstream readIn("test.txt", ios::in);
    if (readIn) {
        string buf;

        while (getline(readIn, buf)) {
            cout << buf << endl;
        }
        readIn.close();
    }

    // read file char by char
    ifstream readIn2("test.txt", ios::in);
    if (readIn2) {

        char c;
        while (readIn2.get(c)) {
        
            cout << c << " ";
        }
        readIn2.close();
    }

    return 0;
}
