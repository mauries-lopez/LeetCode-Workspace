#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int product = 1;
        for ( int num : nums ){
            if ( num > 0 ){
                product *= 1;
            } else if ( num < 0 ) {
                product *= -1;
            } else {
                product *= 0;
            }
        }
        
        return product;
    }
};

int main(){
    Solution solution;
    vector<int> temp = {-1,-2,-3,-4,3,2,1};
    int res = solution.arraySign(temp);
    cout << res << endl;

    return 0;
}