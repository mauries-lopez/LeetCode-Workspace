#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        if ( nums.size() <= 3 ) return false;
        int p = 0, q = 0;

        // Find P
        int prevNum = nums[0];
        for ( int i = 1 ; i <= nums.size() - 1; i++ ){
            if ( prevNum > nums[i] ){
                p = i - 1;
                break;
            }
            prevNum = nums[i];
        }

        // Find Q
        prevNum = nums[p];
        for ( int i = p + 1 ; i <= nums.size() - 1 ; i++ ){
            if ( nums[i] > prevNum ){
                q = i - 1;
                break;
            }
            prevNum = nums[i];
        }

        cout << "p: " << p << " q: " << q << endl;
        if ( p <= 0 ) return false;
        if ( q <= p ) return false;

        // Increase Criteria
        prevNum = nums[0];
        cout << "Increase Criteria" << endl;
        for ( int i = 0 ; i <= p - 1; i++ ){
            cout << "prev: " << prevNum << " nums[i]: " << nums[i+1] << endl;
            if ( prevNum >= nums[i+1] ){
                return false;
            }
            prevNum = nums[i+1];
        }

        // Decrease Criteria
        prevNum = nums[p];
        cout << "Decrease Criteria" << endl;        
        for ( int i = p ; i <= q - 1; i++ ){
            cout << "prev: " << prevNum << " nums[i]: " << nums[i + 1] << endl;
            if ( nums[i + 1] >= prevNum ){
                return false;
            }
            prevNum = nums[i+1];
        }

        // Increasing last Criteria
        prevNum = nums[q];
        cout << "Increase last Criteria" << endl;        
        for ( int i = q; i < nums.size() - 1 ; i++ ){
            cout << "prev: " << prevNum << " nums[i]: " << nums[i + 1] << endl;            
            if ( prevNum >= nums[i + 1] ){
                return false;
            }
            prevNum = nums[i+1];
        }
       
        return true;
    }
};

int main(){
    Solution solution;
    vector<int> temp = {1,3,5,4,2,6};
    bool res = solution.isTrionic(temp);

    cout << res << endl;

    return 0;
}