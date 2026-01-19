#include <iostream>

class Solution{
public:
    int arrangeCoins(int n){
        int coinRemain = n;
        int idx = 1;
        int res = 0;

        for ( int i = 1 ; i <= n ; i++ ){
            res = coinRemain - i;
            if ( res - (i+1) < 0 ){
                idx = i;
                break;
            } else {
                coinRemain = res;
            }
        }
        return idx;
    };
};

int main(){
    Solution solution;
    int res = solution.arrangeCoins(846930886);
    std::cout << res << std::endl;
};