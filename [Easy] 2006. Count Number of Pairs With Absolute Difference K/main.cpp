#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int startIdx = 0, lastIdx = nums.size() - 1;
        int count = 0;
        while ( startIdx < nums.size() ){
            for ( int i = startIdx ; i < nums.size() ; i++ ){
                int diff = abs(nums[startIdx] - nums[i]);
                if ( diff == k ){
                    count++;
                }
            }
            startIdx++;
        }

        return count;
    }
};

int main(){
    Solution solution;
    vector<int> temp = {3,2,1,5,4};
    int res = solution.countKDifference(temp,2);
    cout << res << endl;

    return 0;
}