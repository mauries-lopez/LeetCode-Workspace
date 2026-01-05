#include <iostream>
#include <vector>
#include <stack>
#include <string>

// This was hard for me. I couldnt figure out the interval until I looked into the discussions.

class Solution{
public:
    int findPoisonedDuration(std::vector<int>& timeSeries, int duration){
        int res = 0;
        for ( int i = 0 ; i < timeSeries.size() - 1 ; i++ ){
            int interval = timeSeries.at(i+1) - timeSeries.at(i);
            res += std::min(interval, duration);
        }
        return res+duration;
    }
};

int main(){
    Solution solution;
    std::vector<int> tempTime = {1,4};
    int tempDur = 2;
    int res = solution.findPoisonedDuration(tempTime, tempDur);
    std::cout << res << std::endl;
}