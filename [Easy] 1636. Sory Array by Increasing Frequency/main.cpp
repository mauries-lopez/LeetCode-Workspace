#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution{
public:
    vector<int> frequencyShort(vector<int>& nums){
        unordered_map<int,int> map;
        for ( int num : nums ){
            map[num]++;
        }

        vector<vector<int>> temp;
        for ( int i = 1 ; i <= nums.size() ; i++ ){
            vector<int> digit;
            for ( auto x : map ){
                if ( x.second == i ){
                    for ( int i = 0 ; i < x.second ; i++ ){
                        digit.push_back(x.first);
                    }
                }
            }
            sort(digit.begin(),digit.end(),greater<>());
            temp.push_back(digit);
        }

        vector<int> res;
        for ( auto i : temp ){
            for ( int x : i ){
                res.push_back(x);
            }
        }

        return res;
    };
};

int main(){
    Solution solution;
    vector<int> temp = {1,1,2,2,2,3};
    vector<int> res = solution.frequencyShort(temp);
    for ( int i : res ){
        cout << i << endl;
    }
    return 0;
}