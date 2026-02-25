#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <bitset>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        map<int,vector<int>> mapArr;
        for ( int num : arr ){
            int countOne = 0;
            string bitString = bitset<16>(num).to_string();
            for ( int i = 0 ; i < bitString.length() ; i++ ){
                if ( bitString[i] == '1' ){
                    countOne++;
                }
            }
            mapArr[countOne].push_back(num);
        }
        
        vector<int> res;
        for ( auto i : mapArr ){
            sort(i.second.begin(),i.second.end());
            for ( int num : i.second ){
                cout << i.first << " " << num << endl;
                res.push_back(num);
            }
        }

        return res;
    }
};

int main(){
    Solution solution;
    vector<int> temp = {0,1,2,3,4,5,6,7,8};
    vector<int> res = solution.sortByBits(temp);
    for ( int i : res ){
        cout << i << " ";
    }

    return 0;
}