/// Longest Common Sequence
/// Author: Fei
/// Time: Jul-31-2019
/// Update: Aug-1-2019 #1
///         1.memory compression for DP
///         2.memorySearch revision
///         3.API for the output the string of LCS

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    int getLengthLCS( const string& s1, const string& s2, bool isDP) {

        int n1 = s1.size(), n2 = s2.size();
        if( n1 == 0 || n2 == 0)
            return 0;

        return ( isDP ? lengthLCS_DP( s1, n1, s2, n2) : lengthLCS_memorySearch( s1, n1, s2, n2));
    }

    string getLCS( const string& s1, const string& s2) {

        int n1 = s1.size(), n2 = s2.size();
        int len = lengthLCS_memorySearch( s1, n1, s2, n2);

        string res;
        findLCS( res, s1, n1, s2, n2);
        reverse( res.begin(), res.end());

        return res;
    }

    void printLCSMatrix( ) {

        for( auto iter = LCS.begin(); iter != LCS.end(); ++ iter) {
            for( int n : *iter)
                cout << n << ", ";
            cout << endl;
        }
    }

private:
    vector<vector<int>> LCS;

    /// Dynamic Programming for smaller space complexity
    int lengthLCS_DP( const string& s1, int n1, const string& s2, int n2) {

        LCS.clear();
        LCS = vector<vector<int>>( 2, vector<int>( 1 + n2, 0));
        for( int i = 1; i <= n1; ++ i) {
            for( int j = 1; j <= n2; ++ j) {
                if( s1[i - 1] == s2[j - 1])
                    LCS[i % 2][j] = 1 + LCS[(i - 1) % 2][j - 1];
                else
                    LCS[i % 2][j] = max( LCS[(i - 1) % 2][j], LCS[i % 2][j - 1]);
            }
        }

        return LCS[n1 % 2][n2];
    }

    /// memorySearch of Backtracking
    int lengthLCS_memorySearch( const string& s1, int n1, const string& s2, int n2) {

        LCS.clear();
        LCS = vector<vector<int>>( 1 + n1, vector<int>( 1 + n2, -1));

        return memorySearch( s1, s2, n1, n2);
    }

    int memorySearch( const string& s1, const string& s2, int p1, int p2) {

        if( p1 == 0 || p2 == 0)
            return LCS[p1][p2] = 0;
        if( LCS[p1][p2] != -1)
            return LCS[p1][p2];

        if( s1[p1 - 1] == s2[p2 - 1])
            LCS[p1][p2] = 1 + memorySearch( s1, s2, p1 - 1, p2 - 1);
        else
            LCS[p1][p2] = max( memorySearch( s1, s2, p1, p2 - 1), memorySearch( s1, s2, p1 - 1, p2));

        return LCS[p1][p2];
    }

    void findLCS( string& res, const string& s1, int p1, const string& s2, int p2) {

        //cout << "p1 = " << p1 << ", p2 = " << p2 << endl;
        if( LCS[p1][p2] == 0)
            return;

        if( s1[p1 - 1] == s2[p2 - 1]) {
            res += s1[p1 - 1];
            findLCS( res, s1, p1 - 1, s2, p2 - 1);
            return;
        }
        else {
            if( LCS[p1][p2] == LCS[p1][p2 - 1]) {
                findLCS( res, s1, p1, s2, p2 - 1);
                return;
            }
            else{
                assert( LCS[p1 - 1][p2] == LCS[p1][p2]);
                findLCS( res, s1, p1 - 1, s2, p2);
                return;
            }
        }

        return;
    }
};

int main()
{
    bool isDP = true;

    string s11 = "AAACCGTGAGTTATTCGTTCTAGAA";
    string s12 = "CACCCCTAAGGTACCTTTGGTTC";
    Solution s1;
    cout << s1.getLengthLCS( s11, s12, isDP) << endl;
    cout << endl << s1.getLCS( s11, s12) << endl;
    s1.printLCSMatrix();
    cout << "First case complete" << endl << endl;;
    /// ACCTA GTATT GTTC output = 14

    string s21 = "ABCDEFG";
    string s22 = "AEBDFGH";
    Solution s2;
    cout << s2.getLengthLCS( s21, s22, isDP) << endl << endl;;
    cout << endl << s2.getLCS( s21, s22) << endl;
    s2.printLCSMatrix();
    cout << endl << "Second case complete" << endl << endl;
    /// ABDFG output = 5

    return 0;
}
