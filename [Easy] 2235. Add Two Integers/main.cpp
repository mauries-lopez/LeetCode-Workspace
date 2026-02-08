#include <iostream>

using namespace std;

class Solution {
public:
    int sum(int num1, int num2) {
        return (num1 + num2);
    }
};

int main(){
    Solution solution;
    int res = solution.sum(12,5);
    cout << res << endl;
}