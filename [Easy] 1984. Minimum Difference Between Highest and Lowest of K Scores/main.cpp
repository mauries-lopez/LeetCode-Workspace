#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    int minimumDifference(vector<int>& nums, int k){
        int res = nums[0];
        int prevVal = INT_MAX;
        sort(nums.begin(), nums.end(), greater<>());
        // cout << nums.size() << endl;
        // for ( int i : nums ){
        //     cout << i << endl;
        // }

        //cout << endl;
        int i = 0;

        if  ( nums.size() > 1 ){
            while ( i < nums.size() && ((i-1)+k) < nums.size() ){
                //cout << nums[i] << " " << nums[(i-1)+k] << endl;
                res = min(prevVal, nums[i] - nums[(i-1)+k]);
                prevVal = res;
                //cout << res << endl;
                i++;
            };
        } else {
            res -= nums[0];
        }
        return res;
    };
};

int main(){
    Solution solution;
    vector<int> temp = {41900,69441,94407,37498,20299,10856,36221,2231,54526,79072,84309,76765,92282,13401,44698,17586,98455,47895,98889,65298,32271,23801,83153,12186,7453,79460,67209,54576,87785,47738,40750,31265,77990,93502,50364,75098,11712,80013,24193,35209,56300,85735,3590,24858,6780,50086,87549,7413,90444,12284,44970,39274,81201,43353,75808,14508,17389,10313,90055,43102,18659,20802,70315,48843,12273,78876,36638,17051,20478};
    int res = solution.minimumDifference(temp,5);
    cout << res << endl;
}
