#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> res;
        for ( int i = 0 ; i < s.length() ; i++ ){
            int disA = i, disBLeft = -1, disBRight = 0, disAns = 0;
            //Scan Left
            for ( int x = i ; x >= 0 ; x-- ){
                if ( s[x] == c ){
                    disBLeft = x;
                    break;
                }
            }
            // Scan Right
            for ( int x = i ; x < s.length() ; x++ ){
                if ( s[x] == c ){
                    disBRight = x;
                    break;
                }
            }
            if ( disBLeft != -1 ){
                disAns = min(abs(i-disBLeft),abs(i-disBRight));
            } else {
                disAns = abs(i-disBRight);
            }
            res.push_back(disAns);
        }

        return res;
    }
};

int main(){
    Solution solution;
    vector<int> res = solution.shortestToChar("aaab", 'b');
    for ( int i : res ){
        cout << i << " ";
    }
    return 0;
}