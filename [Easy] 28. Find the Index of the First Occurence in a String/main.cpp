#include <iostream>
#include <string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        return haystack.find(needle);
    }
};

int main() {
    Solution solution;
    std::string haystack = "sadbutsad";
    std::string needle = "sad";
    int index = solution.strStr(haystack, needle);
    std::cout << index << std::endl;
}