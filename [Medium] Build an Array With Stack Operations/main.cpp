#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution{
public:
    vector<string> buildArray(vector<int>& target, int n){
        int i = 1;
        int x = 1;
        int curNum = 0;
        vector<string> res;
        vector<int> temp;
        while ( temp != target ){
            curNum = target[i-1];
            if ( x != curNum ){
                res.push_back("Push");
                res.push_back("Pop");
            } else {
                res.push_back("Push");
                temp.push_back(x);
                i++;
            }
            x++;
        }
        return res;
    };
};

int main(){
    Solution solution;
    vector<int> temp = {2,3,4};
    vector<string> res = solution.buildArray(temp, 4);
    for ( string s : res ){
        cout << s << endl;
    }
}