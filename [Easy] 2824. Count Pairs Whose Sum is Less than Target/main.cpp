#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int count = 0;
        for ( int i = 0 ; i < nums.size() ; i++ ){
            for ( int x = i ; x < nums.size() - 1 ; x++ ){
                if ( nums[i] + nums[x+1] < target ){
                    count++;
                }
            }
        }
        return count;
    }
};

int main(){
    Solution solution;
    vector<int> temp = {-1,1,2,3,1};
    int res = solution.countPairs(temp,2);
    cout << res << endl;
}