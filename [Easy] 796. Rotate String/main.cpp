#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        string tempS = s;
        int i = 0;
        if ( s == goal ) return true;
        do{
            char c = tempS[0];
            tempS.erase(tempS.begin() + 0);
            tempS += c;
            //cout << tempS << endl;
            i++;
            if ( tempS == s ){
                return false;
                break;
            }
        }while ( tempS != goal );
 
        return true;
    }
};

int main(){
    Solution solution;
    bool res = solution.rotateString("abcde", "cdeab");
    cout << res << endl;
    return 0;
}