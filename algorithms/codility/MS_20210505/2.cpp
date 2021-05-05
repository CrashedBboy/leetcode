// Question
/*
Given a list of string CARS, each string consists of '0' or '1'.
Return a list X, where X[i] indicates how many others are "similar" to CARS[i]

Definition of similar:
There're only one mismatch bit between two strings. e.g. "001" and "101" are similar

*/


#include <string>
#include <vector>

// Helper function: transform car's string feature into binary integer
unsigned int str2int(string& str) {

    unsigned int number = 0;
    for (auto& c : str) {
        number = number << 1;
        unsigned int digit = c - '0';
        number += digit;
    }

    return number;
}

// Bit-operation: using shift and AND to count '1' bits
int countOnes(unsigned int x) {

    int num = 0;
    while (x > 0) {
        num += (x & 1);
        x = x >> 1;
    }

    return num;
}

vector<int> solution(vector<string> &cars) {
    
    // Transform each car's string feature into binary integer
    // in order to perform Bit-operation(XOR)
    vector<unsigned int> features (cars.size(), 0); // space complexity O(MN)
    for (int i = 0; i < cars.size(); i++) { // time complexity: O(MN)
        features[i] = str2int(cars[i]);
    }

    // Calculate the number of similar car for each given car
    // Time complexity is O(N^2)
    // However, I eliminate the time by avoiding calculating duplicatd pairs
    vector<int> related (features.size(), 0);
    for (int i = 0; i < features.size(); i++) {
        for (int j = (i + 1); j < features.size(); j++) {

            // Utilize XOR bit-operation to check similarity
            if (countOnes(features[i]^features[j]) <= 1) {
                related[i] += 1;
                related[j] += 1;
            }
        }
    }

    return related;
}
