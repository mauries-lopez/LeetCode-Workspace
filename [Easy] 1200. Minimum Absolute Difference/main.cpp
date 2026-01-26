#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    vector<vector<int>> minimumAbsDifference (vector<int>& arr){
        sort(arr.begin(), arr.end());
        vector<vector<int>> res;
        long long minDiff = 9999999999;

        // Find minimum difference
        for ( int i = 1 ; i < arr.size() ; i++ ){
            int currDiff = abs(arr[i-1] - arr[i]);
            if ( currDiff < minDiff ){
                minDiff = currDiff;
            }
        }

        // Find all pairs that has the same difference with minimum difference
        for ( int i = 1 ; i < arr.size() ; i++ ){
            int currDiff = abs(arr[i-1] - arr[i]);
            if ( currDiff == minDiff ){
                vector<int> temp;
                temp.push_back(arr[i-1]);
                temp.push_back(arr[i]);
                res.push_back(temp);
            }
        }

        return res;
    }
};

int main(){
    Solution solution;
    vector<int> temp = {40,11,26,27,-20};
    vector<vector<int>> res = solution.minimumAbsDifference(temp);
    for ( auto i : res ){
        cout << i[0] << " " << i[1] << endl;
    }
    return 0;
}