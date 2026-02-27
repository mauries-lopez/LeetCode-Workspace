#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for ( int i = 0 ; i < nums.size() ; i++ ){
            nums[i] = pow(nums[i],2);
        }
        sort(nums.begin(),nums.end());
        return nums;
    }
};

int main(){
    Solution Solution;
    vector<int> temp = {-4,-1,0,3,10};
    vector<int> res = Solution.sortedSquares(temp);
    for ( int i : res ){
        cout << i << endl;
    }
    return 0;
}