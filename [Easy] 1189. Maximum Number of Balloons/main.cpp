#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> letters = {
            {'b',0}, // -1
            {'a',0}, // -1
            {'l',0}, // -2
            {'o',0}, // -2
            {'n',0} // -1
        };
        for ( char letter : text ){
            if ( letters.find(letter) != letters.end() ){
                letters[letter]++;
            }
        }
        
        int count = 0;
        while ( letters['b'] >= 1 && letters['a'] >= 1 && letters['l'] >= 2 && letters['o'] >= 2 && letters['n'] >= 1 ){
            count++;
            letters['b'] -= 1;
            letters['a'] -= 1;
            letters['l'] -= 2;
            letters['o'] -= 2;
            letters['n'] -= 1;
        }

        return count;
    }
};

int main(){
    Solution solution;
    int res = solution.maxNumberOfBalloons("nlaebolko");
    cout << res << endl;
    return 0;
}