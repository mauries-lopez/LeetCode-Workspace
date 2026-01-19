#include <vector>
#include <iostream>

class Solution {
public:
    bool repeatedSubstringPattern(std::string s) {
        std::string firstString;
        std::string secondString;
        bool skipCheck = false;
        bool allSameChar = true;

        if ( s.length() >= 2 && s.length() != 0 ){
            int firstStringStartIndex = 0;
            int firstStringEndIndex = 1;
            int secondStringStartIndex = s.length() - 1;
            int secondStringEndIndex = 0;
            if ( s.length() == 2 ) {
                secondStringEndIndex = s.length() - 1;
            } else {
                secondStringEndIndex = s.length() - 2;
            }
            
            int i = 1;
            firstString = s.substr(firstStringStartIndex, firstStringEndIndex + 0);
            secondString = s.substr(secondStringStartIndex - 0, secondStringEndIndex);

            while ( true ){
                if ( (firstStringEndIndex + i) > (secondStringStartIndex - i)){
                    for (int i = 0; i < s.length(); i++){
                        if ( s[i] != s[0]){
                            allSameChar = false;
                            break;
                        }
                    }
                    break;
                }
    
                if ( firstString == secondString ){  
                    std::string tempFirstString = s.substr(firstStringStartIndex, firstStringEndIndex + i);
                    std::string tempSecondString = s.substr(secondStringStartIndex - i, secondStringEndIndex);
   
                    tempFirstString = s.substr(firstStringStartIndex, firstStringEndIndex + i);
                    tempSecondString = s.substr(secondStringStartIndex - i, secondStringEndIndex);
                    if ( tempFirstString != tempSecondString ){             
                        if ( (tempFirstString[tempFirstString.length() - 1] == tempSecondString[1]) && (tempSecondString[0] == tempFirstString[tempFirstString.length() - 2])){
                            skipCheck = true;
                            break;
                        } else {
                            firstString = tempFirstString;
                            secondString = tempSecondString;
                        }
                    } else {                    
                        firstString = tempFirstString;
                        secondString = tempSecondString;
                        if ( firstString == secondString ){
                            skipCheck = true;
                        }
                        break;
                    }
                }
    
                if ( firstString != secondString ){
                    firstString = s.substr(firstStringStartIndex, firstStringEndIndex + i);
                    secondString = s.substr(secondStringStartIndex - i, secondStringEndIndex);
                    i++;
                }
            }
        }
        
        if ( s.length() > 1 && (((firstString == secondString) && ((firstString.length() + secondString.length()) == s.length())) || skipCheck || allSameChar) ){
            return true;
        }

        return false;
    }
};

int main() {
    Solution solution;
    std::string s = "abaababaab";
    bool res = solution.repeatedSubstringPattern(s);
    std::cout << std::boolalpha << res << std::endl;
}