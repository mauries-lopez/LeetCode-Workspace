#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int firstNumIdx = 0;
        int count = 0;

        while ( firstNumIdx < nums.size() ){
            for ( int i = firstNumIdx + 1; i < nums.size(); i++ ){
                if ( nums[firstNumIdx] == nums[i] ){
                    if ( (firstNumIdx * i) % k == 0 ){
                        cout << firstNumIdx << " * " << i << " = " << firstNumIdx * i << endl;
                        count++;
                    }
                };
            }
            firstNumIdx++;
        }
        return count;
    }
};

int main(){
    Solution solution;
    vector<int> temp = {3,1,2,2,2,1,3};
    int res = solution.countPairs(temp,2);
    cout << res << endl;
}