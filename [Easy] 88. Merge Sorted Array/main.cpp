#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        for(int i = 0; i < m+n; i++){
            if ( nums1.at(i) == 0 && !nums2.empty()){
                //std::cout << nums1.at(i) << std::endl;
                //std::cout << nums2.front() << std::endl;
                nums1.at(i) = nums2.front();
                nums2.erase(nums2.begin());
            }
            //std::cout << nums1.at(i) << std::endl;
        }
        std::sort(nums1.begin(), nums1.end());
    }
};

int main(){
    Solution solution;
    std::vector<int> inputList1 = {0};
    std::vector<int> inputList2 = {1};
    solution.merge(inputList1, 0, inputList2, 1);
}