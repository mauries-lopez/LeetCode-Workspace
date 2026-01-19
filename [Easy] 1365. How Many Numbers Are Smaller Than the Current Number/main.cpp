#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums){
        int count = 0;
        vector<int> res;
        for ( int i = 0; i < nums.size(); i++ ){
            for ( int x = 0; x < nums.size(); x++ ){
                if ( nums[i] > nums[x] ){
                    count++;
                }
            }
            res.push_back(count);
            count = 0;
        }
        return res;
    }
};

int main(){
    Solution solution;
    vector<int> temp = {7,7,7,7};
    vector<int> res = solution.smallerNumbersThanCurrent(temp);
    for ( int num : res ){
        cout << num << endl;
    }
    return 0;
}