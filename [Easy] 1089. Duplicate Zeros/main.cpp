#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        queue<int> nums;
        int i = 0;
        while ( nums.size()  < arr.size() ){
            if ( arr[i] != 0 ){
                nums.push(arr[i]);
            } else {
                nums.push(arr[i]);
                if ( nums.size() + 1 <= arr.size() ){
                    nums.push(0);
                }
            }
            i++;
        }
        arr = vector<int>();
        while ( !nums.empty() ){
            cout << nums.front() << endl;
            arr.push_back(nums.front());
            nums.pop();
        }
    }
};

int main(){
    Solution solution;
    vector<int> temp = {1,0,2,3,0,4,5,0};
    solution.duplicateZeros(temp);
}