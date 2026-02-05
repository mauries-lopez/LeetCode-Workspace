#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int getNumToRight(vector<int>& nums, int moveIdx, int curIdx){
        int step = 0;
        while ( step < moveIdx){
            if ( curIdx >= nums.size() - 1 ){
                curIdx = 0;
            } else {
                curIdx++;
            }
            step++;
        }
        return nums[curIdx];
    }

    int getNumToLeft(vector<int>& nums, int moveIdx, int curIdx){
        int step = 0;
        while ( step < abs(moveIdx)){
            if ( curIdx <= 0 ){
                curIdx = nums.size() - 1;
            } else {
                curIdx--;
            }
            step++;
        }
        return nums[curIdx];
    }

    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int> res;
        int moveIdx = 0, curIdx = 0;
        while ( curIdx < nums.size() ){
            moveIdx = nums[curIdx];
            if ( moveIdx < 0 ){
                res.push_back(getNumToLeft(nums,moveIdx,curIdx));
            } else if ( moveIdx > 0 ){
                res.push_back(getNumToRight(nums,moveIdx,curIdx));
            } else {
                res.push_back(nums[curIdx]);
            }
            curIdx++;
        }

        return res;
    }
};

int main(){
    Solution solution;
    vector<int> temp = {3,-2,1,1};
    vector<int> res = solution.constructTransformedArray(temp);
    for ( int i : res ){
        cout << i << endl;
    }

    return 0;
}