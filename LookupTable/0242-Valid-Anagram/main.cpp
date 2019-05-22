/// Source : https://leetcode.com/problems/valid-anagram/
/// Author : Fei
/// Time   : May-16-2019

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

/// Using Hashtable
/// Time Complexity: O( len(s))
/// Space Complexity: O( len(s))
class Solution {
public:
    bool isAnagram(string s, string t) {

        if( s.size() != t.size())
            return false;
        unordered_map<char,int> unMap;

        for( int i=0; i<t.size(); ++i) {
            unMap[ s[i]] ++;
            unMap[ t[i]] --;
        }
        for( auto iter=unMap.begin(); iter != unMap.end(); ++iter)
            if( (*iter).second != 0)
                return false;

        return true;
    }
};


int main() {

    cout << Solution().isAnagram("anagram", "nagaram") << endl;
    cout << Solution().isAnagram("rat", "car") << endl;
    cout << Solution().isAnagram("ab", "a") << endl;

    return 0;
}
