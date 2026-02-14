#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,vector<int>> dictionary;
        vector<char> order;
        for ( int i = 0 ; i < s.length() ; i++ ){
            if ( dictionary.find(s[i]) == dictionary.end() ){
                dictionary[s[i]].push_back(i);
                dictionary[s[i]].push_back(1);
                order.push_back(s[i]);
            } else {
                dictionary[s[i]][1]++;
            }
        }

        for ( char letter : order ){
            if ( dictionary.find(letter) != dictionary.end() ){
                if ( dictionary[letter][1] == 1 ){
                    return dictionary[letter][0];
                }
            }
        }

        return -1;
    }
};

int main(){
    Solution solution;
    int res = solution.firstUniqChar("leetcode");
    cout << res << endl;
    return 0;
}