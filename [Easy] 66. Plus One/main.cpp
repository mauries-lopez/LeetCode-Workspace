#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        if (digits.size() >= 1 ){
            if ( digits[digits.size()-1] == 9 ){
                std::vector<int> tempDigits;
                int carry = 0;
                for ( int i = digits.size() - 1; i >= 0; i-- ){
                    //std::cout << digits[i] << std::endl;
                    if ( digits[i] == 9 ){
                        //std::cout << "if-in" << i << std::endl;
                        if ( carry == 0 && i != digits.size() - 1){
                            tempDigits.push_back(digits[i]);
                        } else {
                            tempDigits.push_back(0);
                            carry = 1;               
                        }
                    } else {
                        //std::cout << "else-in" << i << std::endl;
                        digits[i] = digits[i] + carry;
                        carry = 0;
                        tempDigits.push_back(digits[i]);
                    }
                }
                if ( carry == 1 ){
                    tempDigits.push_back(1);
                }
                std::reverse(tempDigits.begin(), tempDigits.end());
                return tempDigits;
            } else {
                digits[digits.size()-1]++;
            }
            return digits;
        } else {
            return {0};
        }
    }
};

int main(){
    Solution solution;
    std::vector<int> inputList = {9,8,9};
    std::vector<int> ans = solution.plusOne(inputList);
    for ( auto x : ans ){
        std::cout << x << std::endl;
    }
}