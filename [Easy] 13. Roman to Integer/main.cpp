#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int convertLetterToNum(char c){
        switch(c){
            case 'I':
                return 1;
                break;
            case 'V':
                return 5;
                break;
            case 'X':
                return 10;
                break;
            case 'L':
                return 50;
                break;
            case 'C':
                return 100;
                break;
            case 'D':
                return 500;
                break;
            case 'M':
                return 1000;
                break;
        }

        return 0;
    }
    
    int romanToInt(string s) {
        int res = 0;
        int prevNum = 0;
        for ( int i = s.length() - 1 ; i >= 0 ; i-- ){
            cout << convertLetterToNum(s[i]) << endl;
            int curNum = convertLetterToNum(s[i]);
            if ( curNum < prevNum ){
                res -= curNum;
            } else {
                res += curNum;
            }
            prevNum = curNum;
        }

        return res;
    }
};

int main(){
    Solution solution;
    int res = solution.romanToInt("III");
    cout << res << endl;
}