#include <iostream>

using namespace std;

class Solution{
public:
    int fib(int n){
        if ( n <= 1) {
            return n;
        }
        return fib(n-1) + fib(n-2);
    }
};

int main(){
    Solution solution;
    int res = solution.fib(3);
    cout << res << endl;
} 