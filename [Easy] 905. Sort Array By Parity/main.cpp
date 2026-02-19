#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> sortedArr;
        for ( int num : nums ){
            if ( num % 2 == 0 ){
                sortedArr.push_back(num);
            }
        }

        for ( int num : nums ){
            if ( num % 2 != 0 ){
                sortedArr.push_back(num);
            }
        }
        return sortedArr;
    }
};

int main(){
    Solution solution;
    vector<int> temp = {3,1,2,4};
    vector<int> res = solution.sortArrayByParity(temp);
    for ( int i : res ){
        cout << i << endl;
    }
    return 0;
}