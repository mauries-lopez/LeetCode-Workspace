#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

class Solution{
public:
    int missingNumber(std::vector<int>& nums){
        std::sort(nums.begin(), nums.end());
        std::queue<int> numQueue;

        // Initialize Queue
        for (int i = 0 ; i <= nums.size(); i++ ){
            numQueue.push(i);
        }

        // Pop Values
        for ( int i = 0 ; i < nums.size(); i++ ){
            if ( numQueue.front() == nums.at(i) ){
                numQueue.pop();
            } else {
                break;
            }
        }

        /*
        while(!numQueue.empty()){
            std::cout << numQueue.front() << std::endl;
            numQueue.pop();
        };
        */

        return numQueue.front();
    };
};

int main(){
    Solution solution;
    std::vector<int> temp = {9,6,4,2,3,5,7,0,1};
    int res = solution.missingNumber(temp);
    std::cout << res << std::endl;
};