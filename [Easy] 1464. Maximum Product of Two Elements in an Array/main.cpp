#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<>());
        return (nums[0]-1)*(nums[1]-1);
    }
};

int main(){
    Solution solution;
    vector<int> temp = {3,4,5,2};
    int res = solution.maxProduct(temp);
    cout << res << endl;
    return 0;
}