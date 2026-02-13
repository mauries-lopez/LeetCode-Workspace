#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int i = num.size() - 1;
        vector<int> ans;
        while (i >= 0 || k > 0) {
            if (i >= 0) {
                k += num[i];
                i--;
            }
            ans.push_back(k % 10);
            k /= 10;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(){
    Solution solution;
    vector<int> temp = {1,2,0,0};
    vector<int> res = solution.addToArrayForm(temp,34);
    for ( int i : res ){
        cout << i << endl;
    }
    return 0;
}