#include <iostream>

class Solution {
public:
    int i = 0;
    int res = 0;
    int climbStairs(int n) {
        fibonacci(0, 1, n);
        return res;
    };

    void fibonacci(int num1, int num2, int n){
        if ( i == n ){
            res = num2;
            return;
        }
        int temp = num2;
        num2 = num1 + num2;
        num1 = temp;
        i++;
        fibonacci(num1,num2,n);
    }
};

int main(){
    int n = 4;
    Solution solution;
    int res = solution.climbStairs(n);
    std::cout << res << std::endl;
};