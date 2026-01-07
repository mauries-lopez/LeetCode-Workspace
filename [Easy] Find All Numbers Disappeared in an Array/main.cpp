#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int idx = 0;
        int num = 1;
        vector<int> res;

        sort(nums.begin(), nums.end());

        while (idx < nums.size()) {
            if (nums[idx] == num) {
                // skip duplicates
                while (idx + 1 < nums.size() && nums[idx] == nums[idx + 1]) {
                    idx++;
                }
                idx++;
            } else if (nums[idx] > num) {
                // missing number
                res.push_back(num);
            }
            num++;
        }

        // numbers greater than the last element
        while (num <= nums.size()) {
            res.push_back(num);
            num++;
        }

        return res;
    }
};

int main(){
    Solution solution;
    vector<int> temp = {4,3,2,7,8,2,3,1};
    vector<int> res = solution.findDisappearedNumbers(temp);
    for ( int num : res ){
        cout << num << endl;
    }
}