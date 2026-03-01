#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string toLowerCase(string s) {
        for ( int i = 0 ; i < s.length() ; i++ ){
            s[i] = (char)tolower(s[i]);
        }
        return s;
    }
};

int main(){
    Solution solution;
    string res = solution.toLowerCase("Hello");
    cout << res << endl;
    return 0;
}