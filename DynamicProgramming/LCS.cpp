/// Longest Common Sequence
/// Author: Fei
/// Time: Jul-31-2019

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestCommonSequence( const string& s1, const string& s2) {

        int l1 = s1.size(), l2 = s2.size();
        if( l1 == 0 || l2 == 0)
            return 0;

        LCS = vector<vector<int>>( 1 + l1, vector<int>( 1 + l2, 0));
        for( int i = 1; i <= l1; ++ i) {
            for( int j = 1; j <= l2; ++ j) {
                if( s1[i-1] == s2[j-1])
                    LCS[i][j] = 1 + LCS[i-1][j-1];
                else
                    LCS[i][j] = max( LCS[i-1][j], LCS[i][j-1]);
            }
        }

        return LCS[l1][l2];
    }

    int longestCommonSequence( const string& s1, const string& s2, bool isMemorySearch) {

        if( !isMemorySearch)
            return longestCommonSequence( s1, s2);

        int l1 = s1.size(), l2 = s2.size();
        if( l1 == 0 || l2 == 0)
            return 0;

        LCS = vector<vector<int>>( 1 + l1, vector<int>( 1 + l2, -1));
        LCS[0][0] = 0;
        return memorySearch( s1, s2, l1-1, l2-1);
    }
private:
    vector<vector<int>> LCS;

    int memorySearch( const string& s1, const string& s2, int p1, int p2) {

        if( p1 < 0 || p2 < 0)
            return 0;
        if( LCS[p1][p2] != -1)
            return LCS[p1][p2];

        if( s1[p1] == s2[p2])
            LCS[p1][p2] = 1 + memorySearch( s1, s2, p1 - 1, p2 - 1);
        else
            LCS[p1][p2] = max( memorySearch( s1, s2, p1, p2 - 1), memorySearch( s1, s2, p1 - 1, p2));

        return LCS[p1][p2];
    }
};

int main()
{
    string s11 = "AAACCGTGAGTTATTCGTTCTAGAA";
    string s12 = "CACCCCTAAGGTACCTTTGGTTC";
    Solution s1;
    cout << s1.longestCommonSequence( s11, s12, true) << endl;
    cout << "First case complete" << endl;
    /// ACCTAGTATTGTTC output = 14

    string s21 = "ABCDEFG";
    string s22 = "AEBDFGH";
    Solution s2;
    cout << s2.longestCommonSequence( s21, s22, true) << endl;
    cout << "Second case complete" << endl;
    /// ABDFG output = 5

    return 0;
}
