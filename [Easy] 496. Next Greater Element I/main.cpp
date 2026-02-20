#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> numsMap;
        vector<int> res;

        if ( nums1.size() == 1 && nums2.size() == 1 ){
            res.push_back(-1);
            return res;
        }

        for ( int i = 0 ; i < nums2.size() ; i++ ){
            for ( int x = i ; x < nums2.size() - 1; x++ ){
                if ( nums2[i] < nums2[x+1] ){
                    numsMap[nums2[i]] = nums2[x+1];
                    break;
                }
            }
        }

        // for ( auto i : numsMap ){
        //     cout << i.first << " " << i.second << endl;
        // }

        for ( int i : nums1 ){
            if ( i > numsMap[i] ){
                res.push_back(-1);
            } else {
                res.push_back(numsMap[i]);
            }
        }
        return res;
    }
};

int main(){
    Solution solution;
    vector<int> temp1 = {4,1,2};
    vector<int> temp2 = {1,3,4,2};
    vector<int> res = solution.nextGreaterElement(temp1,temp2);
    for ( int i : res ){
        cout << i << endl;
    };
    return 0;
}