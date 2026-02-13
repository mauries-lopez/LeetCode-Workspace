#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_map<char,int> letters;
        char ans;
        for ( int i = 0 ; i < s.length() ; i++ ){
            if ( letters.find(s[i]) == letters.end() ){
                letters[s[i]] = 1;
            } else {
                ans = s[i];
                break;
            }
        }
        return ans;
    }
};

int main(){
    Solution solution;
    char res = solution.repeatedCharacter("abccbaacz");
    cout << res << endl;
    return 0;
}