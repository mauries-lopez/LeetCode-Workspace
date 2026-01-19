#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> buildArray(std::vector<int>& nums) {
        std::vector<int> ans;
        for (int i = 0; i<nums.size(); i++){
            ans.push_back(nums.at(nums.at(i)));
        }
        return ans;
    }
};

int main(){
    Solution solution;
    std::vector<int> nums = {0,2,1,5,3,4};
    std::vector<int> res = solution.buildArray(nums);
    for (int i = 0; i<res.size(); i++){
        std::cout << res.at(i) << std::endl;
    }
}