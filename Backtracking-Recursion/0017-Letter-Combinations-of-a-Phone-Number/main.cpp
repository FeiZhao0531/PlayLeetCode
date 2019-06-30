/// Source : https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
/// Author : Fei
/// Time   : Jun-27-2019

#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

/// Backtracking
/// Time Complexity: O(2^len(s))
/// Space Complexity: O(len(s))
class Solution {
public:
    vector<string> letterCombinations(string digits) {

        if( digits.size() == 0)
            return res;
        string s = "";
        findCombination( digits, 0, s);

        return res;
    }
private:
    string dict[10] = { "", // 0
                        "", // 1
                        "abc", // 2
                        "def", // 3
                        "ghi", // 4
                        "jkl", // 5
                        "mno", // 6
                        "pqrs", // 7
                        "tuv", // 8
                        "wxyz" // 9
                       };

    vector<string> res;

    void findCombination( const string& digits, int key, const string& s) {

        if( key >= digits.size()) {
            res.push_back( s);
            return;
        }

        int num = digits[key] - '0';
        assert( num >=2 && num <= 9);
        string tmp = dict[num];
        for( int i=0; i<dict[num].size(); ++i) {
            findCombination( digits, key + 1, s + tmp[i]);
        }

        return;
    }

};

void printVec(const vector<string>& vec){
    for(string s: vec)
        cout << s << endl;
}

int main() {

    printVec(Solution().letterCombinations("234"));

    return 0;
}
