#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

class Solution {
public:
    int thirdMax(std::vector<int>& nums) {
        std::stack<int> distNums;
        std::sort(nums.begin(), nums.end(), std::greater<>());
        distNums.push(nums.at(0));
        for ( int i = 0 ; i < nums.size() ; i++ ){
            if ( i + 1 < nums.size() ){
                if ( distNums.top() != nums.at(i+1) ){
                    distNums.push(nums.at(i+1));
                }
            }
        };
   
        /*
        while(!distNums.empty()) {
            std::cout << distNums.top() << std::endl;
            distNums.pop();
        }
        */
        
        if ( distNums.size() > 1 && distNums.size() < 3 ){
            distNums.pop();
        } else {
            while(distNums.size() >= 4 ){
                distNums.pop();
            }
        }
        
        return distNums.top();
    }
};

int main(){
    Solution solution;
    std::vector<int> temp = {1,2,2,5,3,5};
    int ans = solution.thirdMax(temp);
    std::cout << ans << std::endl;
}