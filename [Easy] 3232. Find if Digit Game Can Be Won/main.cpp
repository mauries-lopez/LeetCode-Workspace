#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int singleDigitSum = 0, doubleDigitSum = 0;
        for ( int num : nums ){
            if ( num < 10 ){
                singleDigitSum += num;
            } else {
                doubleDigitSum += num;
            }
        }

        if ( singleDigitSum > doubleDigitSum || doubleDigitSum > singleDigitSum ){
            return true;
        }
        return false;
    }
};

int main(){
    Solution solution;
    vector<int> temp = {1,2,3,4,10};
    bool res = solution.canAliceWin(temp);
    cout << res << endl;
    return 0;
}