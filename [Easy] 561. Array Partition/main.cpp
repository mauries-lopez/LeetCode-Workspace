#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0, x = 1;
        int res = 0;
        while ( x < nums.size()){
            //cout << i << x << endl;
            res += min(nums[i],nums[x]);
            i = x + 1;
            x = i + 1;
        }
        return res;
    }
};

int main(){
    Solution solution;
    vector<int> temp = {6,2,6,5,1,2};
    int res = solution.arrayPairSum(temp);
    cout << res << endl;
}