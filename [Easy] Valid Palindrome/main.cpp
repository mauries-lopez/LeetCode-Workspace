#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

class Solution {
public:
    bool isPalindrome(std::string s) {
        std::stack<char> charStack;
        std::vector<char> tempString;
        if (s.length() > 0){
            for(int i = 0; i < s.length(); i++){
                if ( tolower(s.at(i)) >= 97 && tolower(s.at(i)) <= 122 || tolower(s.at(i)) >= 48 && tolower(s.at(i)) <= 57){
                    charStack.push((char)tolower(s.at(i)));
                    tempString.push_back((char)tolower(s.at(i)));
                    //std::cout << (char)tolower(s.at(i)) << std::endl;
                }
            }
            for (int i = 0; i < tempString.size(); i++){
                //std::cout << tempString.at(i) << " - " << charStack.top() << std::endl;
                if ( tempString.at(i) == charStack.top() ){
                    charStack.pop();
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};

int main(){
    std::string input = "0P";
    Solution solution;
    bool res = solution.isPalindrome(input);
    std::cout << std::boolalpha << res << std::endl;
    return 0;
}