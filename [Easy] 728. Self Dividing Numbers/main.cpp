#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        int i = left;
        while ( i <= right ){
            int num = i;
            bool selfDividingNum = true;
            int tempNum = num;
            while ( tempNum != 0 ){
                int digit = tempNum % 10;
                if ( digit != 0 ){
                    if ( num % digit == 0 ){
                        tempNum /= 10;
                    } else {
                        selfDividingNum = false;
                        break;
                    }
                } else {
                    selfDividingNum = false;
                    break;
                }
            }

            if ( selfDividingNum ){
                res.push_back(i);
            }

            i++;
        }
        return res;
    }
};

int main(){
    Solution solution;
    vector<int> res = solution.selfDividingNumbers(47,85);
    for ( int i : res ){
        cout << i << endl;
    }
    return 0;
}