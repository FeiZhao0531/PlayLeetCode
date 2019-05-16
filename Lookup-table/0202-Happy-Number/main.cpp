/// Source : https://leetcode.com/problems/happy-number/
/// Author : Fei
/// Time   : May-16-2019

#include <iostream>
#include <unordered_set>
#include <cmath>
using namespace std;

/// hash table
/// Time complexity : O(n)
/// Space complexity: O(n)
class Solution {
public:
    bool isHappy(int n) {

        int tmp = 0;
        unordered_set<int> unSet;
        while( n != 1 && unSet.find(n) == unSet.end()) {
            cout << n <<endl;
            unSet.insert(n);
            while( n > 0) {
                tmp += pow( n % 10, 2);
                n /= 10;
            }
            n = tmp;
            tmp = 0;
        }
        if( n == 1)
            return true;

        return false;
    }
};

int main()
{
    int n = 2;
    if( Solution().isHappy(n))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    return 0;
}
