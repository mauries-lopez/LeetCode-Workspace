#include <iostream>

using namespace std;

class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1, sum = 0;
        while ( n != 0 ){
            int digit = n % 10;
            product *= digit;
            sum += digit;
            n /= 10;
        }
        return product - sum;
    }
};

int main(){
    Solution solution;
    int res = solution.subtractProductAndSum(234);
    cout << res << endl;
    return 0;
}