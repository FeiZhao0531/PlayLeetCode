/// Source : https://leetcode.com/problems/is-subsequence/
/// Author : Fei
/// Time   : Aug-3-2019

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/// Greedy Algorithm
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    bool isSubsequence(string s, string t) {

        if( s.size() == 0)
            return true;
        int si = 0, ti = 0;
        while( si < s.size() && ti < t.size()) {
            if( s[si] == t[ti]) {
                si ++;
                ti ++;
                if( si == s.size())
                    return true;
            }
            else
                ti ++;
        }

        return false;
    }
};

void printBool( bool b) {

    if( b)
        cout << "true";
    else
        cout << "false";

    cout << endl;
}

int main() {

    string s = "abc", t = "ahbgdc";
    printBool( Solution().isSubsequence( s, t));

    return 0;
}
