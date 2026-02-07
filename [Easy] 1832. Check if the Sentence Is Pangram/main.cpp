#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_map<char,int> alphabet = {
            {'a',0}, {'b',0}, {'c',0}, {'d',0}, {'e',0},
            {'f',0}, {'g',0}, {'h',0}, {'i',0}, {'j',0},
            {'k',0}, {'l',0}, {'m',0}, {'n',0}, {'o',0},
            {'p',0}, {'q',0}, {'r',0}, {'s',0}, {'t',0},
            {'u',0}, {'v',0}, {'w',0}, {'x',0}, {'y',0},
            {'z',0}
        };

        for ( int i = 0 ; i < sentence.length() ; i++ ) {
            if ( alphabet.find(sentence[i]) != alphabet.end() ){
                alphabet[sentence[i]]++;
            }
        }

        for ( auto letter : alphabet ){
            cout << letter.first << " " << letter.second << endl;
            if ( letter.second == 0 ){
                return false;
            }
        }

        return true;
    }
};

int main(){
    Solution solution;
    bool res = solution.checkIfPangram("leetcode");
    cout << res << endl;
    return 0;
}