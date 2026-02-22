#include <iostream>
#include <stack>
#include <bitset>
#include <algorithm>

using namespace std;

class Solution {
public:
    int binaryGap(int n) {
        stack<int> bits;
        string binaryString = bitset<32>(n).to_string();
        cout << binaryString << endl;
        int i = 0, dis = 0;
        while ( i < binaryString.length() ){
            int tempDis = 0;
            if ( binaryString[i] == '1' ){
                int step = i + 1;
                while ( step < binaryString.length() ){
                    if ( binaryString[step] == '1'){
                        tempDis = abs(i-step);
                        i = step - 1;
                        break;
                    }
                    step++;
                }
            }
            dis = max(dis, tempDis);
            i++;
        }
        return dis;
    }
};

int main(){
    Solution solution;
    int res = solution.binaryGap(22);
    cout << res << endl;
    return 0;
}