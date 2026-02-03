#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> freqNum;
        for ( int num : nums ){
            if ( freqNum.find(num) == freqNum.end() ){
                freqNum[num] = 1;
            } else {
                freqNum[num]++;
            }
        }

        int maxFreq = 0;
        for ( auto i : freqNum ){
            maxFreq = max(maxFreq, i.second);
        }

        int count = 0;
        for ( auto i : freqNum ){
            if ( i.second == maxFreq ){
                count += i.second;
            }
        }

        return count;
    }
};

int main(){
    Solution solution;
    vector<int> temp = {1,2,2,3,1,4};
    int res = solution.maxFrequencyElements(temp);
    cout << res << endl;

    return 0;
}