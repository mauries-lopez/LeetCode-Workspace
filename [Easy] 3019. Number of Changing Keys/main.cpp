#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int countKeyChanges(string s) {
        char prevChar = (char)tolower(s[0]);
        int count = 0;
        for ( int i = 1 ; i < s.length() ; i++ ){
            char curChar = (char)tolower(s[i]);
            if ( curChar != prevChar ){
                count++;
            }
            prevChar = curChar;
        }
        return count;
    }
};

int main(){
    Solution solution;
    int res = solution.countKeyChanges("aAbBcC");
    cout << res << endl;
    return 0;
}