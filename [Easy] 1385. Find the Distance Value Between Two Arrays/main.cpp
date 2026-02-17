#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count = 0;
        for ( int i = 0 ; i < arr1.size() ; i++ ){
            count++;
            for ( int x = 0 ; x < arr2.size() ; x++ ){
                if ( abs(arr1[i] - arr2[x]) <= d ){
                    count--;
                    break;
                }
            }
        }
        return count;
    };
};

int main(){
    Solution solution;
    vector<int> temp1 = {4,5,8};
    vector<int> temp2 = {10,9,1,8};
    int res = solution.findTheDistanceValue(temp1,temp2,2);
    cout << res << endl;
    return 0;
}