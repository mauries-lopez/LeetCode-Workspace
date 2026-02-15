#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        unordered_map<char,int> distances;
        unordered_map<char,int> checked;
        int decimalChar = 97;
        for ( int i : distance ){
            distances[char(decimalChar)] = i;
            decimalChar++;
        }

        for ( int i = 0 ; i < s.length() ; i++ ){
            if ( checked.find(s[i]) == checked.end() ){
                checked[s[i]] = 1;
                int dis = 0;
                for ( int x = i ; x < s.length() ; x++ ){
                    if ( s[i] == s[x+1] ){
                        dis = abs((i+1) - (x+1));
                        break;
                    }
                }
                cout << dis << endl;
                if ( distances[s[i]] != dis ){
                    return false;
                }
            }
        }

        return true;
    }
};

int main(){
    Solution solution;
    vector<int> distance = {1,3,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    bool res = solution.checkDistances("abaccb", distance);
    cout << res << endl;
    return 0;
}