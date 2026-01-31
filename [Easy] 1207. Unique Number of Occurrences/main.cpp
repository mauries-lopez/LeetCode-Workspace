#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> nums;
        vector<int> counts;
        for ( int num : arr ){
            if ( nums.find(num) == nums.end() ){
                nums[num] = 1;
            } else {
                nums[num]++;
            }
        }

        for ( auto num : nums ){
            counts.push_back(num.second);
        }

        for ( int i = 0 ; i < counts.size() ; i++ ){
            for ( int x = i + 1 ; x < counts.size() ; x++ ){
                if ( counts[i] == counts[x] ){
                    return false;
                }
            }
        }

        return true;
    }
};

int main(){
    Solution solution;
    vector<int> temp = {1,2,2,1,1,3};
    bool res = solution.uniqueOccurrences(temp);
    cout << res << endl;

    return 0;
}