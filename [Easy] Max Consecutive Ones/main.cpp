#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution{
public:
    int findMaxConsecutiveOnes(vector<int>& nums){
        stack<int> s;
        vector<int> sizes;
        for ( int num : nums ){
            if ( num == 1 ){
                s.push(num);
            } else {
                sizes.push_back(s.size());
                s = stack<int>();
            }
        }

        sizes.push_back(s.size());
        sort(sizes.begin(), sizes.end(), greater<>());

        return sizes[0];
    };
};

int main(){
    Solution solution;
    vector<int> temp = {1,0,1,1,0,1};
    int res = solution.findMaxConsecutiveOnes(temp);
    cout << res << endl;
}