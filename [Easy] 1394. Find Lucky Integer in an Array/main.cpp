#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> tempArr;
        for ( int num : arr ){
            if ( tempArr.find(num) == tempArr.end() ){
                tempArr[num] = 1;
            } else {
                tempArr[num]++;
            }
        }

        int res = -1;
        for ( auto i : tempArr) {
            if ( i.first == i.second ){
                res = max(res, i.first);
            }
        }

        return res;
    }
};

int main(){
    Solution solution;
    vector<int> test = {1,2,2,3,3,3};
    int res = solution.findLucky(test);
    cout << res << endl;
    return 0;
}