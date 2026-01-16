#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int x = 0, y = 0;
        int neg = 0;
        while ( x <= grid.size() - 1){
            if( grid[x][y] < 0 ){
                neg++;
            };

            if ( y < grid[x].size() - 1 ){
                y++;
            } else {
                x++;
                y = 0;
            }
        }
        return neg;
    };
};

int main(){
    Solution solution;
    vector<vector<int>> temp = {{4,3,2,-1},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-3}};
    int res = solution.countNegatives(temp);
    cout << res << endl;
}