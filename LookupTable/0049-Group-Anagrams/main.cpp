/// Source : https://leetcode.com/problems/group-anagrams/description/
/// Author : Fei
/// Time   : May-21-2019

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


/// Using HashMap
/// Using sorted string as key
///
/// Time Complexity: O(n*klogk) where k is the max length of string in strs
/// Space Complexity: O(n*k)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector< vector<string> > res;
        unordered_map<string, vector<string> > unMap;
        for( const string& s : strs) {
            string tmp = s;
            sort( tmp.begin(), tmp.end());
            unMap[tmp].push_back(s);
        }
        for( const auto& iter : unMap)
            res.push_back( iter.second);

        return res;
    }
};

void print2DVec( const vector< vector<string> >& strVec) {

    for( const auto& tmp : strVec) {
        for( const auto& s : tmp)
            cout<< s <<"  ";
        cout<<endl;
    }
    return;
}

int main() {

    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    print2DVec( Solution().groupAnagrams( strs));
    return 0;
}
