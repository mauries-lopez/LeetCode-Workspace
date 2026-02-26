#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int res = 0;
        for ( auto account : accounts ){
            int sum = 0;
            for ( int wealth : account ){
                sum += wealth;
            }
            res = max(res,sum);
        }
        return res;
    }
};

int main(){
    Solution solution;
    vector<vector<int>> temp = {{1,2,3},{3,2,1}};
    int res = solution.maximumWealth(temp);
    cout << res << endl;
    return 0;
}