/// Source : https://leetcode.com/problems/reverse-string/
/// Author : Fei
/// Time   : May-9-2019

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/// Two Pointers
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    void reverseString(vector<char>& s) {

        int l = 0, r = s.size() - 1;
        while( l < r) {
            swap( s[l], s[r]);
            l ++;
            r --;
        }
        return;
    }
};

void print_vector( vector<char>& s) {

    for( char e : s)
        cout<< e <<" ";
    cout<<endl;
}

int main() {

    char a[5] = {'h','e','l','l','o'};
    vector<char> s;
    for( int i=0; i<5; ++i)
        s.push_back( a[i]);
    Solution().reverseString(s);
    print_vector( s);

    return 0;
}
