#include <vector>
#include <iostream>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        std::vector<int> tempList;
        for ( int i = 0; i < nums.size(); i++ ){
            if ( nums.at(i) != val ){
                tempList.push_back(nums.at(i));
            }
        }
        nums = tempList;
        return tempList.size();
    }
};

int main() {
    Solution solution;
    std::vector<int> inputList = {3,2,2,3};
    int val = 3;
    int commonPref = solution.removeElement(inputList, val);
    /*
    std::cout << "k: " << commonPref << std::endl;
    std::cout << "nums: " ;
    for ( auto x : inputList ){
        std::cout << x << " ";
    }
    */
}