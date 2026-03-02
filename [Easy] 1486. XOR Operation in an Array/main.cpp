#include <iostream>

using namespace std;

class Solution {
public:
    int xorOperation(int n, int start) {
        int res = 0;
        for ( int i = 0 ; i < n ; i++ ){
            res = res ^ start+2*i;
        };
        return res;
    }
};

int main(){
    Solution solution;
    int res = solution.xorOperation(5,0);
    cout << res << endl;
    return 0;
}