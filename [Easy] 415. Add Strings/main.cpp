#include <iostream>
#include <string>
#include <stack>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        stack<int> numStorage1;
        stack<int> numStorage2;
        int x = 0;
        int y = 0;
        while ( num1[x] != '\0' || num2[y] != '\0'){
            if ( num1[x] != '\0' ){
                numStorage1.push(num1[x] - '0');
                x++;
            }

            if ( num2[y] != '\0' ){
                numStorage2.push(num2[y] - '0');
                y++;
            }
        }

        string sum;
        int carry = 0;
        while ( !numStorage1.empty() || !numStorage2.empty() || carry ){
            int numA = 0;
            int numB = 0;

            if ( !numStorage1.empty() ){
                numA = numStorage1.top();
                numStorage1.pop();
            }

            if ( !numStorage2.empty() ){
                numB = numStorage2.top();
                numStorage2.pop();
            }

            int sumNum = numA + numB + (carry == 1 ? 1 : 0);
            if ( sumNum >= 10 ){
                int digit = sumNum % 10;
                sum.append(to_string(digit));
                carry = 1;
            } else {
                sum.append(to_string(sumNum));
                carry = 0;
            }
        }

        reverse(sum.begin(), sum.end());
        return sum;
    }
};

int main(){
    Solution solution;
    string res = solution.addStrings("1", "9");
    cout << res << endl;
}