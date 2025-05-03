#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>

class Solution {
public:
    bool isPowerOfThree(int n) {
        double res = double(n);
        while(true){
            res = (res / 3.0f);
            res = std::round(res * 1e12) / 1e12;
            //std::cout << std::fixed << std::setprecision(12) << res << std::endl;
            if ( res <= 0.333333333333f ){
                break;
            }
        }
        if ( res == 0.333333333333 && n != 0 ){
            return true;
        }
        return false;
    }
};

int main() {
    Solution solution;
    int n = 43046720;
    bool res = solution.isPowerOfThree(n);
    std::cout << std::boolalpha << res << std::endl;
}