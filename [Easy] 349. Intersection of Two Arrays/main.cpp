#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> nums1Map;
        for ( int num : nums1 ){
            if ( nums1Map.find(num) == nums1Map.end() ){
                nums1Map[num] = 1;
            };
        }
        vector<int> res;
        for ( int num : nums2 ){
            if ( nums1Map.find(num) != nums1Map.end() && nums1Map[num] == 1 ){
                res.push_back(num);
                nums1Map[num]++;
            };            
        }
        return res;
    }
};

int main(){
    Solution solution;
    vector<int> temp1 = {1,2,2,1};
    vector<int> temp2 = {2,2};
    vector<int> res = solution.intersection(temp1,temp2);
    for ( int i : res ){
        cout << i << endl;
    }
    return 0;
}