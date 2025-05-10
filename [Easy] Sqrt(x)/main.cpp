#include <iostream>
#include <math.h>

class Solution {
public:
    int mySqrt(int x) {
        return std::sqrt(x);
    }
};

int main(){
    int x = 110;
    Solution solution;
    int res = solution.mySqrt(x);
    std::cout << res << std::endl;
}