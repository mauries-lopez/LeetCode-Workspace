#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int curVal = nums[0];
        int prevCount = 0;
        int curCount = 1;
        int highestCount = 1;
        int res = curVal;
        
        for ( int i = 1 ; i < nums.size() ; i++ ){
            if ( curVal == nums[i] ){
                curCount++;
            } else {
                curVal = nums[i];
                prevCount = curCount;
                curCount = 1;
            }
            //cout << curVal << " | cur: " << curCount << " | prev: " << prevCount << "| high: " << highestCount << endl;

            if ( curCount >= prevCount && curCount >= highestCount ){
                highestCount = curCount;
                res = curVal;
            };
        }

        return res;
    };
};

int main(){
    Solution solution;
    vector<int> temp = {47,47,72,47,72,47,79,47,12,92,13,47,47,83,33,15,18,47,47,47,47,64,47,65,47,47,47,47,70,47,47,55,47,15,60,47,47,47,47,47,46,30,58,59,47,47,47,47,47,90,64,37,20,47,100,84,47,47,47,47,47,89,47,36,47,60,47,18,47,34,47,47,47,47,47,22,47,54,30,11,47,47,86,47,55,40,49,34,19,67,16,47,36,47,41,19,80,47,47,27};
    int res = solution.majorityElement(temp);
    cout << res << endl;

    return 0;
}