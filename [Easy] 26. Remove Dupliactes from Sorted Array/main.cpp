#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int curVal = -999;
        for ( int i = 0 ; i < nums.size() - 1 ; i++ ){
            if ( nums[i] == nums[i+1] ){
                nums.erase(nums.begin() + (i+1));
                i--;
            }
        }
        return nums.size();
    }
};

int main(){
    Solution solution;
    vector<int> temp = {1,1,2};
    int res = solution.removeDuplicates(temp);
    cout << res << endl;
}