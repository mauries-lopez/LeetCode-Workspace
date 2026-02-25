#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int count = 0;
        for ( string sentence : sentences ){
            int spaceCount = 0;
            for ( int i = 0 ; i < sentence.length() ; i++ ){
                if ( sentence[i] == ' ' ){
                    spaceCount++;
                }
            }
            count = max(count,spaceCount);
        }
        return count + 1;
    }
};

int main(){
    Solution solution;
    vector<string> temp = {"alice and bob love leetcode","i think so too", "this is great thanks very much"};
    int res = solution.mostWordsFound(temp);
    cout << res << endl;
    return 0;
}