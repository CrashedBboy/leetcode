#include <iostream>
#include <limits>

using namespace std;

int main() {

    cout << "Integer (4 bytes) limitation: " << numeric_limits<int>::min()
        << " ~ " << numeric_limits<int>::max() << endl;

    cout << "Unsigned integer (4 bytes) limitation: " << numeric_limits<unsigned int>::min()
        << " ~ " << numeric_limits<unsigned int>::max() << endl;

    cout << "Long Long (8 bytes) limitation: " << numeric_limits<long long>::min()
        << " ~ " << numeric_limits<long long>::max() << endl;

    cout << "Char (1 byte) limitation: " << int(numeric_limits<unsigned char>::min())
        << " ~ " << int(numeric_limits<unsigned char>::max()) << endl;

    cout << "Float (4 bytes) limitaion: " << numeric_limits<float>::min()
        << " ~ " << numeric_limits<float>::max() << endl;

    cout << "Double (8 bytes) limitation: " << numeric_limits<double>::min()
        << " ~ " << numeric_limits<double>::max() << endl;

    return 0;
}
