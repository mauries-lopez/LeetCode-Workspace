#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> indices;
        for ( int i = 0 ; i < words.size() ; i++ ){
            if ( words[i].contains(x) ){
                indices.push_back(i);
            }
        }
        return indices;
    }
};

int main(){
    Solution solution;
    vector<string> temp = {"leet", "code"};
    vector<int> res = solution.findWordsContaining(temp,'e');
    for ( int i : res ){
        cout << i << " ";
    }
    return 0;
}