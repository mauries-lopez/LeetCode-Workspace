#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<int> sumZero(int n){
        vector<int> ans;
        int idx = n;
        while ( ans.size() < n - 1  ){
            ans.push_back(-idx);
            ans.push_back(idx);
            idx--;
        }
        if ( n % 2 != 0 ){
            ans.push_back(0);
        }
        return ans;
    }
};

int main(){
    Solution solution;
    vector<int> res = solution.sumZero(1);
    for( int i : res ){
        cout << i << endl;
    }
}