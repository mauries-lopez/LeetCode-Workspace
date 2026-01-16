#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos = 0, neg = 0;
        int res = 0;
        for ( int num : nums ){
            if ( num > 0 ){
                pos++;
            } else if ( num < 0 ){
                neg++;
            }
            res = max(pos,neg);
        }
        return res;
    }
};

int main(){
    Solution solution;
    vector<int> temp = {-2,-1,-1,1,2,3};
    int res = solution.maximumCount(temp);
    cout << res << endl;
}