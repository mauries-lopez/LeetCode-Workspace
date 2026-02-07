#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> res;
        int sum = 0;
        for ( int num : nums ){
            sum += num;
            res.push_back(sum);
        }

        return res;
    }
};

int main(){
    Solution solution;
    vector<int> temp = {1,2,3,4};
    vector<int> res = solution.runningSum(temp);
    for ( int i : res ){
        cout << i << endl;
    }
    return 0;
}