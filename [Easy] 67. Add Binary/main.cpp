#include <string>
#include <iostream>
#include <stack>
#include <algorithm>

class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        std::string res;
        int indexA = a.length() - 1, indexB = b.length() - 1;
        bool carry = false;
        int length = std::max(a.length(), b.length());
        while(length >= 0){
            char charA = (indexA >= 0 ? a[indexA] : '0');
            char charB = (indexB >= 0 ? b[indexB] : '0');
            //std::cout << "charA: " << charA << std::endl;
            //std::cout << "charB: " << charB << std::endl;
            if ( charA != charB ){
                if ( charA == '1' && charB != '0'){
                    //std::cout << "pushed a[indexA]" << std::endl;
                    res += charA;
                } else if (charB == '1' && charA != '0'){
                    //std::cout << "pushed b[indexB]" << std::endl;
                    res += charB;
                } else {
                    if ( carry ){
                        res += '0';
                        carry = true;
                    } else {
                        res += '1';
                        carry = false;
                    }
                }
            } else if ( charA == charB ){
                if ( charA == '1' && charB == '1' ){
                    //std::cout << "pushed 0" << std::endl;
                    if ( carry ){
                        res += '1';
                    } else {
                        res += '0';
                    }
                    carry = true;
                } else {
                    if ( carry ){
                        //std::cout << "pushed 1 (carry)" << std::endl;
                        res += '1';
                        carry = false;
                    } else {
                        if ( indexA >= 0 || indexB >= 0 ){
                            res += '0';
                        }
                    }
                }
            }

            if ( indexA == 0 && indexB == 0 && carry ){
                //std::cout << "pushed 1 (carry last)" << std::endl;
                res += '1';
                carry = false;
            }
            indexA--;
            indexB--;
            length--;
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution solution;
    std::string s1 = "0";
    std::string s2 = "0";
    std::string res = solution.addBinary(s1,s2);
    std::cout << res << std::endl;
}