#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<int> shuffle(vector<int>& nums, int n){
        vector<int> res;
        int a = n;
        for ( int i = 0 ; i < n ; i++, a++ ) {
            res.push_back(nums[i]);
            res.push_back(nums[a]);
        }
        return res;
    };
};

int main(){
    Solution solution;
    vector<int> temp = {2,5,1,3,4,7};
    vector<int> res =  solution.shuffle(temp, 3);
    for ( int num : res ){
        cout << num << endl;
    }
}