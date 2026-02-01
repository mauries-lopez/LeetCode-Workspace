#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count = 0;
        for ( int num : arr ){
            if ( count >= 3 ){
                break;
            }
            if ( num % 2 != 0 ){
                count++;
            } else {
                count = 0;
            }
        }

        if ( count >= 3 ){
            return true;
        }

        return false;
    };
};

int main(){
    Solution solution;
    vector<int> temp = {2,6,4,1};
    bool res = solution.threeConsecutiveOdds(temp);
    cout << res << endl;

    return 0;
}