#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int elementSum = 0, digitSum = 0;
        for ( int i = 0 ; i < nums.size() ; i++ ){
            elementSum += nums[i];
            if ( nums[i] > 9 ){
                int temp = nums[i];
                while ( temp > 0 ){
                    digitSum += temp % 10;
                    temp /= 10;
                }
            } else {
                digitSum += nums[i];
            }
            cout << elementSum << " " << digitSum << endl;
        }
        return abs(elementSum - digitSum);
    }
};

int main(){
    Solution solution;
    vector<int> temp = {1,15,6,3};
    int res = solution.differenceOfSum(temp);
    cout << res << endl;
    return 0;
}