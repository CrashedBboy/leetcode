/*******************************************************************************************
Rick is a fan of logic-based games. However, he is bored of the classic ones, like Sudoku and 
astermind, since he has solved so many of them. 

Recently he found a new game in which one is iven a string with some question marks in it.
The objective is to replace all of the question marks ith letters (one letter per question mark) 
in such a way that no letter appears next to another letter of the same kind.

Write a function:

    string solution(string &riddle);
    
That, given a string riddle, returns a copy of the string with all of the question marks replaced 
by owercase letters (a-z) in such a way that the same letters do not occur next to each other. 

The result can be any of the possible answers as long as it fulfils the above requirements.

Examples: 

1. Given riddle = "ab?ac?", your function might retun "abcaca". Some other possible results are 
abzacd', "abfacf". 

2. Given riddle = "rd?e?wg??", your function might return "rdveawgab".

3. Given riddle = "????????", your function might retun "codility".

Write an efficient algorithm for the following assumptions: 

• the length of the string is within the range [1 ..1OO,OOO];
• string riddle consists only of lowercases letters (a - z) or '?'
• it is always possible to turn string 'riddle' into a string without two identical consecutive letters.
*******************************************************************************************/
#include <vector>
#include <iostream>

using namespace std;

void resetLetterUsed(vector<bool>& used) {
    
    for (unsigned int i = 0; i < used.size(); i++) {
        used[i] = false;
    }
}

string solution(string &riddle) {
    
    if (riddle.size() == 0) {
        return "";
    }
    
    if (riddle.size() == 1) {
        
        if (riddle == "?") {
            return "a";
        } else {
            return riddle;
        }
    }
    
    vector<bool> used(26, false);
    
    for (unsigned int i = 0; i < riddle.size(); i++) {
        
        if (riddle[i] == '?') {
            
            resetLetterUsed(used);
            
            if (i == 0) {
            
                // only consider right neighbor
                if (riddle[i+1] != '?') {
                    used[ (int)(riddle[i+1] - 'a') ] = true;
                }
        
            } else if (i == (riddle.size() - 1)) {
                
                // only consider left neighbor
                used[ (int)(riddle[i-1] - 'a') ] = true;
                
            } else {
                
                // consider both side
                used[ (int)(riddle[i-1] - 'a') ] = true;
                if (riddle[i+1] != '?') {
                    used[ (int)(riddle[i+1] - 'a') ] = true;
                }
            }
            
            // find an unused letter
            char replace = 'a';
            for (unsigned int j = 0; j < used.size(); j++) {
                
                if (used[j] == false) {
                    replace = (char)('a' + j);
                    break;
                }
            }
            
            // replace '?' with the letter
            riddle[i] = replace;
        }
    }
    
    return riddle;
}