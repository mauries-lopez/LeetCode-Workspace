#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> letters;
        int oddCount = 0;
        int charCount = 0;
        for ( char letter : s ){
            letters[letter] = 0;
            charCount++;
        }

        cout << charCount << endl;

        for ( char letter : s ){
            if ( letters.find(letter) != letters.end() ){
                letters[letter]++;
            }
        }

        for ( auto i : letters ){
            cout << i.first << " " << i.second << endl;
            if ( i.second % 2 != 0 ){
                oddCount++;
            }
        }

        if ( oddCount > 1 ){
            cout << oddCount << endl;
            charCount = charCount - (oddCount - 1);
        }

        return charCount;
    }
};

int main(){
    Solution solution;
    int res = solution.longestPalindrome("abccccdd");
    cout << res << endl;

    return 0;
}