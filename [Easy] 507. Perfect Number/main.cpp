#include <iostream>

using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 0;
        for ( int i = 1 ; i < num ; i++ ){
            if ( num % i == 0 ){
                sum += i;
            }
        }

        if ( num == sum ){
            return true;
        }

        return false;
    }
};

int main(){
    Solution solution;
    bool res = solution.checkPerfectNumber(7);
    cout << res << endl;
}