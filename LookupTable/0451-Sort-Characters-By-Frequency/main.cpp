/// Source : https://leetcode.com/problems/sort-characters-by-frequency/
/// Author : Fei
/// Time   : May-16-2019

#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char, int> unMap;
        for( char e : s)
            unMap[e] ++;
        vector< pair<char,int> > tVec;
        mapSortByValue( unMap, tVec);
        string res = "";
        for( auto iter=tVec.begin(); iter != tVec.end(); ++iter) {
            string tmp( (*iter).second, (*iter).first);
            res += tmp;
        }

        return res;
    }
private:
    void mapSortByValue( const unordered_map<char,int>& unMap, vector< pair<char,int> >& tVec) {

        for( auto iter=unMap.begin(); iter != unMap.end(); ++iter)
            tVec.push_back( make_pair( (*iter).first, (*iter).second));

        auto cmp = []( pair<char,int>& p1, pair<char,int>& p2){
            return p1.second > p2.second;
        };
        sort( tVec.begin(), tVec.end(), cmp);
    }
};


int main() {

    cout << Solution().frequencySort("tree") << endl;
    cout << Solution().frequencySort("cccaaa") << endl;
    cout << Solution().frequencySort("Aabb") << endl;

    return 0;
}
