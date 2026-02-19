#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int getMaximumGenerated(int n) {
        vector<int> nums;
        for ( int i = 0 ; i <= n ; i++ ){
            int res = i;
            if ( i == 0 || i == 1 ){
                nums.push_back(res);
            }

            if ( (2*i) >= 2 && (2*i) <= n ){
                res = nums[i];
                nums.push_back(res);
            }

            if ( (2*i+1) >= 2 && (2*i+1) <= n ){
                res = nums[i] + nums[i+1];
                nums.push_back(res);
            }
        }
        
        int ans = 0;
        for ( int num : nums ){
            //cout << num << endl;
            ans = max(ans,num);
        }

        return ans;
    }
};

int main(){
    Solution solution;
    int res = solution.getMaximumGenerated(7);
    cout << res << endl;
    return 0;
}