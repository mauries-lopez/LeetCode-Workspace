#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

class Solution{
public:
    string reverseVowels(string s){
        stack<char> stackChar;
        queue<char> queueChar;
        
        for ( int i = 0 ; i < s.length() ; i++ ){
            if ((int)s[i] == 65 || (int)s[i] == 69 || (int)s[i] == 73 || (int)s[i] == 79 || (int)s[i] == 85 || 
                (int)s[i] == 97 || (int)s[i] == 101 || (int)s[i] == 105 || (int)s[i] == 111 || (int)s[i] == 117 ){
                    stackChar.push((int)s[i]);
                    queueChar.push((int)s[i]);
                }
        }

        int i = 0;
        while(!queueChar.empty() && !stackChar.empty()){
            if ( queueChar.front() == s[i] ){
                s[i] = stackChar.top();
                stackChar.pop();
                queueChar.pop();
            }
            i++;
        }

        return s;
    }
};

int main(){
    Solution solution;
    string res = solution.reverseVowels("leetcode");
    cout << res << endl;

    return 0;
}