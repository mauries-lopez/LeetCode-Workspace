#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int> res;
        for ( int num : nums ){
            if ( res.find(num) == res.end() ){
                res[num] = 1;
            } else {
                res[num]++;
            }
        }

        int sum = 0;
        for ( auto i : res ){
            if ( i.second == 1 ){
                sum += i.first;
            }
        }

        return sum;
    }
};

int main(){
    Solution solution;
    vector<int> temp = {1,2,3,2};
    int res = solution.sumOfUnique(temp);
    cout << res << endl;
    return 0;
}