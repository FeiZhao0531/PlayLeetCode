/// Source : https://leetcode.com/problems/palindrome-partitioning/submissions/
/// Author : Fei
/// Time   : Jun-27-2019

#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

/// Backtracking
/// Time Complexity: O(n^2)
/// Space Complexity: O(n^2)
class Solution {
public:
    vector<vector<string>> partition(string s) {

        res.clear();
        if( s.empty())
            return res;
        vector<string> path;
        findPartition( s, 0, path);

        return res;
    }
private:
    vector< vector<string> > res;

    void findPartition( const string& s, int sIndex, vector<string>& path) {

        if( sIndex >= s.size()) {
            res.push_back( path);
            return;
        }

        int l = sIndex, r = s.size() - 1;
        for( ; r >= l; r --)
            if( isPalindrome( s, l, r)) {
                path.push_back( s.substr( l, r - l + 1));
                findPartition( s, r + 1, path);
                path.pop_back();
            }

        return;
    }

    bool isPalindrome( const string& s, int l ,int r) {

        assert( l <= r);// [ l, r] for check
        while( l < r ) {
            if( s[l] != s[r])
                return false;
            l ++;
            r --;
        }

        return true;
    }
};


void print2DVec(const vector< vector<string> >& vec){

    auto iter = vec.begin();
    for( ; iter != vec.end(); ++iter) {
        for( string s : *iter)
            cout << s << "  ";
        cout << endl;
    }
}

int main() {

    print2DVec(Solution().partition("aaab"));

    return 0;
}
