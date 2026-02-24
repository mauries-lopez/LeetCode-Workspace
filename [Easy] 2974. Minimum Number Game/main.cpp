#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        stack<int> numStack;
        vector<int> res;
        sort(nums.begin(),nums.end());
        for ( int i = 1 ; i < nums.size() ; i++ ){
            numStack.push(nums[i-1]);
            numStack.push(nums[i]);
            while ( !numStack.empty() ){
                res.push_back(numStack.top());
                numStack.pop();
            };
            i++;
        }
        return res;
    }
};

int main(){
    Solution solution;
    vector<int> temp = {5,4,2,3};
    vector<int> res = solution.numberGame(temp);
    for ( int i : res ){
        cout << i << " ";
    };
    return 0;
}