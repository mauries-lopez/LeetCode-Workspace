#include <iostream>

using namespace std;

class Solution {
public:
    int theMaximumAchievableX(int num, int t) {
        return ( num + ( t + t ) );
    }
};

int main(){
    Solution solution;
    int res = solution.theMaximumAchievableX(4,1);
    cout << res << endl;
    return 0;
}