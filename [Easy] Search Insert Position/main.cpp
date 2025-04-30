#include <vector>
#include <iostream>
#include <cmath>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        int startIndex = 0;
        int lastIndex = nums.size() - 1;
        while(startIndex <= lastIndex){
            int middleIndex = std::floor(( startIndex + lastIndex ) / 2);
            if (startIndex == static_cast<int>(nums.size() - 1) && target > nums.at(startIndex)){
                //std::cout << "startIndex: " << startIndex << std::endl;
                return startIndex + 1;
            } else if (nums.at(middleIndex) == target || (middleIndex > 0 && target > nums.at(middleIndex - 1) && target <= nums.at(middleIndex))){
                //std::cout << "middleIndex: " << middleIndex << std::endl;
                return middleIndex;
            } else if (nums.at(middleIndex) > target){
                lastIndex = middleIndex - 1;
                //std::cout << "0 nums.at(middleIndex): " << nums.at(middleIndex) << std::endl;
                //std::cout << "LastIndex: " << lastIndex << std::endl;
            } else if (nums.at(middleIndex) < target){
                startIndex = middleIndex + 1;
                //std::cout << "1 nums.at(middleIndex): " << nums.at(middleIndex) << std::endl;
                //std::cout << "startIndex: " << startIndex << std::endl;
            }
        }
        return 0;
    }
};

int main(){
    Solution solution;
    std::vector<int> inputList = {1,3};
    int ans = solution.searchInsert(inputList, 2);
    std::cout << ans << std::endl;
}