/// Source : https://leetcode.com/problems/restore-ip-addresses/
/// Author : Fei
/// Time   : Jun-28-2019

#include <iostream>
#include <vector>

using namespace std;


/// Backtrack
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {

        res.clear();
        int sLen = s.size();
        if( sLen < 4 || sLen > 16)
            return res;
        findIpAddress( s, 0, 0, "");

        return res;
    }

private:
    vector<string> res;

    void findIpAddress( const string& s, int sIndex, int section, const string& tmp) {

        if( section == 3 && isValid( s, sIndex, s.size()-1)) {
            if( s[sIndex] == '0' && sIndex != s.size() - 1)
                return;
            res.push_back( tmp + s.substr( sIndex, s.size() - sIndex));
            return;
        }

        if( s.size() - sIndex > 3*( 4 - section)) return;
        if( s.size() - sIndex < 4 - section) return;

        for( int i = sIndex; i < sIndex+3; ++i) {
            if( sIndex == i && s[i] == '0') {
                findIpAddress( s, i + 1, section + 1, tmp + s.substr( sIndex, 1) + '.');
                break;
            }
            if( isValid( s, sIndex, i))
                findIpAddress( s, i + 1, section + 1, tmp + s.substr( sIndex, i - sIndex + 1) + '.');
        }
        return;
    }

    bool isValid( const string&s , int l, int r) {  /// [ l, r]

        if( r >= s.size() || r < l)
            return false;
        if( r - l > 2)
            return false;
        if( r - l > 0 && s[l] == '0')
            return false;

        int num = 0;
        while( l <= r) {
            num = 10*num + ( s[l] - '0');
            l ++;
        }
        if( num > 255 )
            return false;

        return true;
    }
};


void print_vec(const vector<string>& vec){

    for(const string& e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    string s1 = "25525511135";
    print_vec(Solution().restoreIpAddresses(s1));
    // 255.255.111.35 255.255.11.135

    string s2 = "1";
    print_vec(Solution().restoreIpAddresses(s2));
    // empty

    string s3 = "010010";
    print_vec(Solution().restoreIpAddresses(s3));
    // 0.10.0.10 0.100.1.0

    return 0;
}
