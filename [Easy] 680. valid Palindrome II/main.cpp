#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Slow Algorithm but it works. This fails on very very very long case. [First Solution]
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

    // Line 51 : 110 -> [Second Solution]. Still slow but much faster
    bool checkLeft(string s){
        int begin = 0, end = s.length() - 1, mid = floor(s.length()/2);
        int skipIdx = -1;
        while ( begin <= mid && skipIdx != s.length() ){
            if ( skipIdx == begin ){
                begin++;
            }

            if ( s[begin] != s[end] ){
                skipIdx++;
                begin = -1;
                end = s.length();
            }
            begin++;
            end--;
        }

        if ( skipIdx == s.length() ){
            return false;
        }

        return true;
    }

    bool checkRight(string s){
        int begin = 0, end = s.length() - 1, mid = floor(s.length()/2);
        int skipIdx = s.length();
        while ( end >= mid && skipIdx != 0 ){
            if ( skipIdx == end ){
                end--;
            }


            if ( s[begin] != s[end] ){
                skipIdx--;
                begin = -1;
                end = s.length();
            }
            begin++;
            end--;
        }

        if ( skipIdx == 0 ){
            return false;
        }

        return true;
    }

    bool validPalindromeTwo(string s){
        bool isPalLeft = checkLeft(s);
        bool isPalRight = checkRight(s);
        
        if ( isPalLeft || isPalRight ){
            return true;
        } 

        return false;
    }

    // Line 113 : 137 -> [Third Solution]. An answer I copied from the solutions. I was close getting similar answer (Same logic but I wrote mine in an unoptimized way). Nice try!!
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