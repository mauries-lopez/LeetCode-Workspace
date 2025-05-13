#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        std::stack<int> res;
        res.push(-30001);
        std::sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++ ){
            if ( nums.at(i) != res.top()){
                res.push(nums.at(i));
            } else {
                res.pop();
            }
        }
        return res.top();
    }
};

int main(){
    std::vector<int> input = {-1};
    Solution solution;
    int res = solution.singleNumber(input);
    std::cout << res << std::endl;
}