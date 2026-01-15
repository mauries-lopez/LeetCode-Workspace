#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    int maximumProduct(vector<int>& nums){
        int backFirstIdx = 0, backSecondIdx = 1, backThirdIdx = 2;
        int frontFirstIdx = backFirstIdx + 1, frontSecondIdx = backSecondIdx + 1, frontThirdIdx = backThirdIdx + 1;
        int maxNum = 0;
        int res = -1874919423;
        sort(nums.begin(), nums.end());
        while(backFirstIdx != nums.size()){
            if ( frontThirdIdx == nums.size() ){
                frontThirdIdx = 0;
            } else if ( frontSecondIdx == nums.size() ){
                frontSecondIdx = 0;
            } else if ( frontFirstIdx == nums.size() ){
                frontFirstIdx = 0;
            } 
            
            if ( backThirdIdx == nums.size() ){
                backThirdIdx = 0;
            } else if ( backSecondIdx == nums.size() ) {
                backSecondIdx = 0;
            }
            
            maxNum = max(nums[backFirstIdx] * nums[backSecondIdx] * nums[backThirdIdx], nums[frontFirstIdx] * nums[frontSecondIdx] * nums[frontThirdIdx]);
            res = max(res, maxNum);
            
            backFirstIdx++;
            backSecondIdx++;
            backThirdIdx++;
            frontFirstIdx++;
            frontSecondIdx++;
            frontThirdIdx++;
        }

        return res;
    }
};

int main(){
    Solution solution;
    vector<int> temp = {3,4,0,0,-1,-5};
    int res = solution.maximumProduct(temp);
    cout << res << endl;
}