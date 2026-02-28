#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string triangleType(vector<int>& nums) {
        if ( nums[0] + nums[1] > nums[2] && nums[1] + nums[2] > nums[0] && nums[0] + nums[2] > nums[1] ){
            if ( nums[0] == nums[1] && nums[0] == nums[2] && nums[1] == nums[2] ){
                return "equilateral";
            } else if ( nums[0] == nums[1] || nums[0] == nums[2] || nums[1] == nums[2] ){
                return "isosceles";
            } else if ( nums[0] != nums[1] && nums[0] != nums[2] && nums[1] != nums[2] ) {
                return "scalene";
            } 
        }
        return "none";
    }
};

int main(){
    Solution solution;
    vector<int> temp = {3,3,3};
    string res = solution.triangleType(temp);
    cout << res << endl;
    return 0;
}