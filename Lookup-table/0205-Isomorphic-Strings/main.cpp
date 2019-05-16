/// Source : https://leetcode.com/problems/isomorphic-strings/description/
/// Author : Fei
/// Time   : May-16-2019

#include <iostream>

using namespace std;

/// Mapping
/// Time Complexity: O(len(s)^2)
/// Space Complexity: O(len of charset)
class Solution {
public:
    bool isIsomorphic(string s, string t) {

        if( s.size() != t.size())
            return false;

        unordered_map<char,char> unMap;
        for( int i=0; i<s.size(); ++i) {
            if( unMap.count(s[i]) != 0) {
                if( unMap[s[i]] != t[i])
                    return false;
            }
            else {
                for( auto iter=unMap.begin(); iter != unMap.end(); ++iter)
                    if( (*iter).second == t[i])
                        return false;

                unMap[s[i]] = t[i];
            }
        }

        return true;
    }
};

void print_bool(bool res){
    cout << (res ? "True" : "False") << endl;
}

int main() {

    print_bool(Solution().isIsomorphic("egg", "add"));
    print_bool(Solution().isIsomorphic("foo", "bar"));
    print_bool(Solution().isIsomorphic("paper", "title"));
    print_bool(Solution().isIsomorphic("aa", "ab"));

    return 0;
}
