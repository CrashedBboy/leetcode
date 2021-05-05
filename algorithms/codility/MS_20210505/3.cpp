// Question
/*

Given string S consists of 'a', 'b' and '?'. Fill the '?' with either 'a' or 'b' under 
the following constraints:

* No three identical consecutive letters (e.g. "aaa" or "bbb" is not permitted)

*/


#include <vector>
#include <unordered_set>

// Determin the given position is available to fill 'a' or 'b' or both
// Returns:
// 0 - indicates only 'a' is available to fill this position
// 1 - indicates only 'b' is available to fill this position
// 2 - both 'a' and 'b' are available
int available(string& S, int pos) {

    if ((pos-2) >= 0) {
        int aNumber = 0;
        int bNumber = 0;
        for (int i = pos-2; i <= pos; i++) {
            if (S[i] == 'a') { aNumber += 1; }
            else if (S[i] == 'b') { bNumber += 1; }
        }

        if (aNumber >= 2) { return 1; }
        if (bNumber >= 2) { return 0; }
    }

    if ((pos-1) >= 0 && (pos+1) < S.size()) {
        int aNumber = 0;
        int bNumber = 0;
        for (int i = pos-1; i <= pos+1; i++) {
            if (S[i] == 'a') { aNumber += 1; }
            else if (S[i] == 'b') { bNumber += 1; }
        }

        if (aNumber >= 2) { return 1; }
        if (bNumber >= 2) { return 0; }
    }

    if ((pos+2) < S.size()) {
        int aNumber = 0;
        int bNumber = 0;
        for (int i = pos; i <= pos+2; i++) {
            if (S[i] == 'a') { aNumber += 1; }
            else if (S[i] == 'b') { bNumber += 1; }
        }

        if (aNumber >= 2) { return 1; }
        if (bNumber >= 2) { return 0; }
    }

    return 2; // both 'a' and 'b' are available for this position
}

string solution(string &S) {

    // find all positions of '?' & use set to store them
    unordered_set<int> slots;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '?') {
            slots.insert(i);
        }
    }

    // Idea:
    // Phase1. First, we fill all '?' which can be filled by ONLY one type
    // Phase2. Next, from the remaining '?' (slots which can be filled with both types),
    //          pick random one and fill it with random type.
    //          Then loop back to Phase 1

    // Time complexity should be O(K), where K is the number of '?' slots.
    while (slots.size() > 0) {
        
        bool updated = false;

        // Phase1. First, we fill all '?' which can be filled by ONLY one type
        for (auto& pos : slots) {
            int availability = available(S, pos);
            if (availability == 0) {
                updated = true;
                S[pos] = 'a';
                slots.erase(pos);
            }
            else if (availability == 1) {
                updated = true;
                S[pos] = 'b';
                slots.erase(pos);
            }
        }

        // Phase 2. pick random one and fill it with random type
        if (!updated) {
            unordered_set<int>::iterator it = slots.begin();
            int firstSlot = *it;
            S[firstSlot] = 'a';
            slots.erase(it);
        }
    }

    return S;
}
