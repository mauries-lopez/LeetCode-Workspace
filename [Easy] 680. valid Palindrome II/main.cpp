#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Slow Algorithm but it works. This fails on very very very long case.
    bool validPalindromeOne(string s) {
        stack<char> letters;   
        int prevSkipIdx = -1;     
        int skipIdx = -1;
        while ( true ){
            if ( skipIdx == s.length() ){
                return false;
            };

            for ( int i = 0 ; i < s.length() ; i++ ){
                if ( skipIdx != i ){
                    letters.push(s[i]);
                }
            }

            int i = 0;
            while ( !letters.empty() ){
                if ( i == skipIdx ){
                    i++;
                }
                if ( letters.top() == s[i] ){
                    letters.pop();
                } else {
                    letters = stack<char>();
                    skipIdx++;
                }
                i++;
            }
            
            if ( prevSkipIdx == skipIdx ){
                return true;
            } else {
                prevSkipIdx = skipIdx;
            }
        }

        return true;
    }

    bool checkPal(string s, int begin, int end){
        while ( begin < end ){
            if ( s[begin] != s[end] ){
                return false;
            }
            begin++;
            end--;
        }

        return true;
    }

    // Much faster than before but still considered slow on very very long cases.
    bool validPalindrome(string s){
        int begin = 0, end = s.length() - 1;
        while ( begin < end ){
            if ( s[begin] != s[end] ){
                return checkPal(s, begin + 1, end) || checkPal(s, begin, end - 1);
            }
            begin++;
            end--;
        }
        return true;
    }
};

int main(){
    Solution solution;
    bool res = solution.validPalindrome("deeee");
    cout << res << endl;

    return 0;
}