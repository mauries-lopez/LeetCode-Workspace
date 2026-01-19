#include <iostream>
#include <cmath>

using namespace std;

class Solution{
public:
    bool isPerfectSquare(int num){
        for ( unsigned int i = 1; i <= num; i++ ){
            if ( pow(i,2) == num ){
                return true;
            }
        }
        return false;
    }
};

int main(){
    Solution solution;
    bool res = solution.isPerfectSquare(100000001);
    cout << res << endl;
}