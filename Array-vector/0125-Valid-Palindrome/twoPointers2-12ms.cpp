/// Source : https://leetcode.com/problems/valid-palindrome/description/
/// Author : Fei
/// Time   : May-9-2019

#include <iostream>
#include <string>
using namespace std;

/// Two Pointers
/// Go through twice
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {

public:
    bool isPalindrome(string s) {

        if( s.empty())
            return true;

        string abbrStr;
        for( int i=0; i<s.size(); ++i) {
            if( ( s[i] >= 'a' && s[i] <= 'z') || ( s[i] >= '0' && s[i] <= '9'))
                abbrStr += s[i];
            else if( s[i] >= 'A' && s[i] <= 'Z')
                abbrStr += s[i] - 'A' + 'a';
        }

        int l = 0, r = abbrStr.size() - 1;
        while( l < r) {
            if( abbrStr[l ++] != abbrStr[r --])
                return false;
        }

        return true;
    }
};


void print_bool(bool res){
    cout << (res ? "True" : "False") << endl;
}

int main() {

    string s1 = "A man, a plan, a canal: Panama";
    print_bool(Solution().isPalindrome(s1));

    string s2 = "race a car";
    print_bool(Solution().isPalindrome(s2));

    return 0;
}
