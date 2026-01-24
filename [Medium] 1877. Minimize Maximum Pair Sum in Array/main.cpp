#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution{
public:
    int minPairSum(vector<int>& nums){
        int res = 0;
        sort(nums.begin(), nums.end());
        int start = 0;
        int last = nums.size() - 1;
        int mid = floor(nums.size() / 2);
        int prevVal = 0;
        while ( start < mid ){
            int cur = nums[start] + nums[last];
            res = max(cur, prevVal);
            prevVal = res;
            start++;
            last--;
        }
        return res;
    }
};

int main(){
    Solution solution;
    vector<int> temp = {3,5,4,2,4,6};
    int res = solution.minPairSum(temp);
    cout << res << endl;
}