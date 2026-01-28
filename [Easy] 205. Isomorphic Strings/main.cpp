#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mapSLetters;
        unordered_map<char,char> mapTLetters;

        for ( int i = 0 ; i < s.length() ; i++ ){
            if ( mapSLetters.find(s[i]) == mapSLetters.end() ){
                mapSLetters[s[i]] = t[i];
            }
        }

        for ( int i = 0 ; i < t.length() ; i++ ){
            if ( mapTLetters.find(t[i]) == mapTLetters.end() ){
                mapTLetters[t[i]] = s[i];
            }
        }

        // for ( auto x : mapSLetters ){
        //     cout << x.first << " " << x.second << endl;
        // }

        for ( int i = 0 ; i < s.length() ; i++ ){
            if ( mapSLetters.find(s[i]) != mapSLetters.end() ){
                //cout << s[i] << " " << t[i] << endl;
                if ( mapSLetters[s[i]] != t[i] ){
                    return false;
                }
            }
        }

        for ( int i = 0 ; i < t.length() ; i++ ){
            if ( mapTLetters.find(t[i]) != mapTLetters.end() ){
                //cout << s[i] << " " << t[i] << endl;
                if ( mapTLetters[t[i]] != s[i] ){
                    return false;
                }
            }
        }

        return true;
    }
};

int main(){
    Solution solution;
    bool res = solution.isIsomorphic("egg", "add");
    cout << res << endl;
    return 0;
}