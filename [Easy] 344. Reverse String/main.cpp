#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int start = 0, end = s.size() - 1;
        int mid = floor(s.size() / 2);
        while ( start < mid ){
            cout << "start: " << start << "end: " << end << endl;
            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            start++;
            end--;
        }
    }
};

int main(){
    Solution solution;
    vector<char> temp = {'h','e','l','l','o'};
    solution.reverseString(temp);
    return 0;
}