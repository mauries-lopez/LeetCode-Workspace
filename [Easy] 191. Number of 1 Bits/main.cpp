#include <iostream>
#include <bitset>
#include <string>

using namespace std;

class Solution {
public:
    int hammingWeight(int n) {
        string bitNString = bitset<64>(n).to_string();
        int count = 0;
        for ( char letter : bitNString ){
            if ( letter == '1' ){
                count++;
            }
        }
        return count;
    }
};

int main(){
    Solution solution;
    int res = solution.hammingWeight(11);
    cout << res << endl;
    return 0;
}