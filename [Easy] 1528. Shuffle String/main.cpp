#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        unordered_map<int,char> dictionary;
        for ( int i = 0; i < indices.size() ; i++ ){
            dictionary[indices[i]] = s[i];
        }

        string res;
        int i = 0;
        while ( i < indices.size() ){
            if ( dictionary.find(i) != dictionary.end() ){
                res += dictionary[i];
            }
            i++;
        }

        return res;
    }
};

int main(){
    Solution solution;
    vector<int> temp = {4,5,6,7,0,2,1,3};
    string res = solution.restoreString("codeleet",temp);
    cout << res << endl;
}