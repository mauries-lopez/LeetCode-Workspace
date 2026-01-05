#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

class Solution{
public:
    char findTheDifference(std::string s, std::string t){
        std::queue<char> extraChar;
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());
        
        for ( int i = 0; i < t.size(); i++ ){
            extraChar.push(t.at(i));
        }

        for ( int i = 0 ; i < s.size(); i++ ) {
            if ( extraChar.front() == s.at(i) ){
                extraChar.pop();
            }
        }

        return extraChar.front();
    }
};

int main(){
    Solution solution;
    char res = solution.findTheDifference("", "y");
    std::cout <<  res << std::endl;
}