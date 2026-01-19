#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, mid = 0, end = nums.size() - 1;
        int res = -1;

        // Initial Check
        if ( nums.size() > 1 ){
            while ( start <= end ){
                mid = floor((start+end) / 2);
                if (nums[mid] == target){
                    res = mid;
                    break;
                } 
                
                if ( nums[mid] > target ){
                    end = mid - 1;
                } else if ( nums[mid] < target ){
                    start = mid + 1;
                }
            }
        } else {
            res = nums[0] == target ? 0 : -1;
        }
        return res;
    }
};

int main(){
    Solution solution;
    vector<int> temp = {-1,0,3,5,9,12};
    int res = solution.search(temp, 2);
    cout << res << endl;
}