#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int i = 1;
        while ( i < nums.size() ){
            if ( nums[i-1] % 2 == 0 && nums[i] % 2 != 0 ){
                i += 2;
            } else if ( nums[i-1] % 2 != 0 && nums[i] % 2 == 0 ){
                int temp = nums[i-1];
                nums[i-1] = nums[i];
                nums[i] = temp;
                i += 2;
            } else if ( nums[i-1] % 2 == 0 && nums[i] % 2 == 0 ){
                int x = i;
                while ( nums[x] % 2 == 0 ){
                    x++;
                }
                int temp = nums[i];
                nums[i] = nums[x];
                nums[x] = temp;
                i += 2;
            } else if ( nums[i-1] % 2 != 0 && nums[i] % 2 != 0 ){
                int x = i-1;
                while ( nums[x] % 2 != 0 ){
                    x++;
                }
                int temp = nums[i-1];
                nums[i-1] = nums[x];
                nums[x] = temp;
                i += 2;
            }
        }
        return nums;
    }
};

int main(){
    Solution solution;
    vector<int> temp = {4,2,5,7};
    vector<int> res = solution.sortArrayByParityII(temp);
    for ( int i : res ){
        cout << i << endl;
    }
    return 0;
}