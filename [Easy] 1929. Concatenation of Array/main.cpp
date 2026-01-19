#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<int> getConcatenation(vector<int>& nums){
        int size = nums.size();
        for ( int i = 0 ; i < size ; i++ ){
            nums.push_back(nums[i]);
        }
        return nums;
    }
};

int main(){
    Solution solution;
    vector<int> temp = {1,2,1};
    vector<int> res = solution.getConcatenation(temp);
    for ( int num : res ){
        std::cout << num << std::endl;
    }
}