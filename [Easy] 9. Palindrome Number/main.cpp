#include <iostream>
#include <stack>
#include <cmath>

class Solution {
public:
    bool isPalindrome(int x) {

        if ( x == -1 ){
            return false;
        }

        stack<int> digits;
        int tempX = x;
        while ( tempX != 0 ){
            int digit = tempX % 10;
            digits.push(digit);
            tempX /= 10;
        }

        while ( x != 0 ){
            int digit = x % 10;
            if ( digit == digits.top() ){
                digits.pop();
            } else {
                return false;
            }
            x = abs(x/10);
        }
        return true;
    }
};

int main(){
    Solution solution;
    bool res = solution.isPalindrome(121);
    cout << res << endl;
}