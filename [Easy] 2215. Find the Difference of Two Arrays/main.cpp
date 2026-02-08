#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:

    vector<int> getDifference(vector<int>& nums1, vector<int>& nums2, unordered_map<int,int>& nums1Dict, unordered_map<int,int>& nums2Dict){
        vector<int> temp;
        int i = 0;
        while ( i < nums1.size() ) {
            // true && 
            if ( nums2Dict.find(nums1[i]) == nums2Dict.end() && nums1Dict[nums1[i]] == 0 ){
                nums1Dict[nums1[i]]++;
                temp.push_back(nums1[i]);
            }
            i++;
        }
        return temp;
    }

    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> res;
        unordered_map<int,int> nums1Dict;
        unordered_map<int,int> nums2Dict;
        for ( int i = 0 ; i < nums1.size() ; i++ ){
            nums1Dict[nums1[i]] = 0;
        }

        for ( int i = 0 ; i < nums2.size() ; i++ ){
            nums2Dict[nums2[i]] = 0;
        }

        res.push_back(getDifference(nums1, nums2, nums1Dict, nums2Dict));
        res.push_back(getDifference(nums2, nums1, nums2Dict, nums1Dict));

        return res;
    }
};

int main(){
    Solution solution;
    vector<int> nums1 = {1,2,3};
    vector<int> nums2 = {2,4,6};
    vector<vector<int>> res = solution.findDifference(nums1,nums2);
    for ( auto i : res ){
        for ( int x : i ){
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}