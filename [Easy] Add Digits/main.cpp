#include <iostream>

using namespace std;

class Solution{
public:
    int addDigits(int num){
        int res = 0;
        
        while ( num > 0 || res > 9){
            if ( res > 9 && num <= 0 ){
                num = res;
                res = 0;
            }
            res += (num % 10);
            num /= 10;
        };
        return res;
    };
};

int main(){
    Solution solution;
    int res = solution.addDigits(119);
    cout << res << endl;
}