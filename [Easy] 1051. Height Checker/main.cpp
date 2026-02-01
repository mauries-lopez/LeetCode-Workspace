#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected = heights;
        int count = 0;
        sort(expected.begin(),expected.end());
        for ( int i = 0 ; i < heights.size() ; i++ ){
            if ( heights[i] != expected[i] ){
                count++;
            }
        }
        return count;
    }
};

int main(){
    Solution solution;
    vector<int> temp = {1,1,4,2,1,3};
    int res = solution.heightChecker(temp);
    cout << res << endl;
    
};