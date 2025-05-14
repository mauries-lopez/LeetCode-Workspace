#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++){
            if ( nums.at(i) == nums.at(i-1) ){
                return true;
            }
        }
        return false;
    }
};

int main(){
    std::vector<int> input = {1,2,3,4};
    Solution solution;
    bool res = solution.containsDuplicate(input);
    std::cout << std::boolalpha << res << std::endl;
}