#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    vector<int> findErrorNums(vector<int>& nums){
        sort(nums.begin(), nums.end());
        vector<int> res;
        int curNum = 0;
        int missingNum = 1;
        for (int i = 1 ; i <= nums.size() - 1; i++ ){
            curNum = nums[i-1];
            if ( i+1 > nums[i-1] && i+1 != nums[i] ){
                missingNum = i+1;
            }

            if ( curNum == nums[i] ){
                res.push_back(curNum);
            } 
        }
        
        res.push_back(missingNum);
        return res;
    };
};

int main(){
    Solution solution;
    vector<int> temp = {2,2};
    vector<int> res = solution.findErrorNums(temp);
    for (int num : res ){
        cout << num << endl;
    }
}