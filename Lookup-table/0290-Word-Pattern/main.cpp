/// Source : https://leetcode.com/problems/word-pattern/description/
/// Author : Fei
/// Time   : May-16-2019

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

/// Time complexity : O( len(pattern)^2 )
/// Space complexity: O( size of char set)
class Solution {
public:
    bool wordPattern(string pattern, string str) {

        unordered_map< string, char > unMap;
        int start = 0, index = 0;
        str += ' ';
        string tmp = "";
        for( int i=0; i<str.size(); ++i) {
            if( str[i] == ' ') {
                tmp += str.substr( start, i - start);
                //cout<<" i = "<<i<<" , substr = "<< tmp<<endl;
                if( unMap.count(tmp)) {
                    //cout<<"unMap[tmp] = "<<unMap[tmp]<<" , patter[index] = "<<pattern[index]<<endl<<endl;
                    if( unMap[tmp] != pattern[index])
                        return false;
                }
                else {
                    for( auto iter=unMap.begin(); iter != unMap.end(); ++iter)
                        if( (*iter).second == pattern[index])
                            return false;

                    unMap[tmp] = pattern[index];
                }

                index ++;
                tmp = "";
                start = i + 1;
            }
        }

        return true;
    }
};

int main()
{
    string pattern = "abba";
    string str = "dog cat cat fish";

    string res = Solution().wordPattern( pattern, str) ? "true" : "false";
    cout<< res <<endl;

    return 0;
}
