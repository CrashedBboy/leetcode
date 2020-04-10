// Source : https://leetcode.com/problems/queue-reconstruction-by-height/
// Author : CrashedBboy
// Date   : 2020-04-09

// Questions
/********************************************************************************** 
Suppose you have a random list of people standing in a queue.
Each person is described by a pair of integers (h, k), 
where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h.
Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.

 
Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
**********************************************************************************/

// [idea]
// sort the list based on K, if more than one element have same K, sort them using H

// (7,0) (4,4) (7,1) (5,0) (6,1) (5,2)
// sorted:
// (5,0) (7,0) (6,1) (7,1) (5,2) (4,4)

// check every node whether its position meet the node description

// (5,0) (7,0) (6,1) (7,1) (5,2) (4,4)
// _____________________________
//                           X           too much #front! we have to move it closer to head

// (5,0) (7,0) (5,2) (6,1) (7,1) (4,4)
// ___________________________________
//                                  X    too much #front! we have to move it closer to head

// (5,0) (7,0) (5,2) (6,1) (4,4) (7,1)
// ____________________________________  return


// (8,0) (1,1) (4,1) (3,2) (3,3) (17,0) (3,5) (6,2) (7,2) (7,3) (2,9)

// sorted:
// (8,0) (17,0) (1,1) (4,1) (3,2) (6,2) (7,2) (3,3) (7,3) (3,5) (2,9)
// _______________V___

// (8,0) (1,1) (17,0) (4,1) (3,2) (6,2) (7,2) (3,3) (7,3) (3,5) (2,9)
// _____________________V__

// (8,0) (1,1) (4,1) (17,0) (3,2) (6,2) (7,2) (3,3) (7,3) (3,5) (2,9)
// ___________________________V__

// (8,0) (1,1) (4,1) (3,2) (17,0) (6,2) (7,2) (3,3) (7,3) (3,5) (2,9)
// _____________________________________________V__

// (8,0) (1,1) (4,1) (3,2) (3,3) (17,0) (6,2) (7,2) (7,3) (3,5) (2,9)
// _________________________________________________________V___

// (8,0) (1,1) (4,1) (3,2) (3,3) (17,0) (3,5) (6,2) (7,2) (7,3) (2,9)
// __________________________________________________________________  // return

bool sortByFrontThenHeight(vector<int> v1, vector<int> v2) {

    if (v1[1] != v2[1]) {
        return v1[1] < v2[1];
    } else {
        return v1[0] < v2[0];
    }
}

class Solution {

public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {

        // check input
        if (people.size() == 0) {
            return people;
        }
        
        // sort the list first
        std::sort(people.begin(), people.end(), sortByFrontThenHeight);

        // fix the list
        for (int i = 0; i < people.size(); i++) {

            int height = people[i][0];
            int maxFrontGreater = people[i][1];

            int frontGreater = 0;
            for (int j = 0; j < i; j++) {

                if (people[j][0] >= height) {

                    frontGreater += 1;
                }

                if (frontGreater > maxFrontGreater) {

                    // move element to position 'j', not 'j - 1'
                    vector<int> tmp = {height, maxFrontGreater};

                    people.erase(people.begin() + i); // O(N)
                    people.insert(people.begin() + j, tmp); // O(N)
                
                    break;
                }
            }
        }

        return people;
    }
};