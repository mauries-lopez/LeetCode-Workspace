#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        int numPref = 1;
        std::string curString = "";
        std::string longestCommonPrefixWord = "";
        int longestCommonPrefixFreq = 0;
        std::vector<std::pair<std::string,int>> bestPrefixPerIteration;

        if ( strs.at(0) != "" && !strs.empty()){
            // Get the length of the longest word
            for (int i = 0; i < strs.size(); i++){
                if ( strs.at(i).length() >= curString.length() ){
                    curString = strs.at(i);
                }
            }

            do {
                std::vector<std::pair<std::string,int>> listOfPrefix;

                for (int i = 0; i < strs.size(); i++){
                    if ( strs.at(i).length() >= numPref){
                        std::pair<std::string,int> data = {strs.at(i).substr(0,numPref), 0};
                        listOfPrefix.push_back(data); //Stores all prefixes
                    }
                }
        
                for (int i = 0; i < listOfPrefix.size(); i++){
                    std::string prefix = listOfPrefix.at(i).first; // Get a prefix
                    for(int x = i; x < listOfPrefix.size(); x++){
                        if ( prefix == listOfPrefix.at(x).first ){
                            listOfPrefix.at(i).second++;
                        }
                    }
                }

                std::stable_sort(listOfPrefix.begin(), listOfPrefix.end(),
                [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
                    return a.second < b.second; // descending order
                });
                bestPrefixPerIteration.push_back(listOfPrefix.at(listOfPrefix.size()-1));
                numPref++;
            } while ( numPref <= static_cast<int>(curString.length()));
                        
            if ( bestPrefixPerIteration.size() > 1 ){
                for (int i = bestPrefixPerIteration.size() - 1; i >= 0; i--){
                    if ( bestPrefixPerIteration.at(i).second >= static_cast<int>(strs.size()) && bestPrefixPerIteration.at(i).second != 1){
                        //std::cout << bestPrefixPerIteration.at(i).first << " " << bestPrefixPerIteration.at(i).second << std::endl;
                        if ( bestPrefixPerIteration.at(i).first.length() >= longestCommonPrefixWord.length()){
                            longestCommonPrefixWord = bestPrefixPerIteration.at(i).first;
                            longestCommonPrefixFreq = bestPrefixPerIteration.at(i).second;
                        }
                    }
                }
            } else {
                longestCommonPrefixWord = bestPrefixPerIteration.at(0).first;
            }               
            //Verify if all contains the prefix
            int verifiedWordCount = 0;
            for (auto x : strs){
                if ( x.find(longestCommonPrefixWord) == 0 ){
                    verifiedWordCount++;
                }
            }
            
            if ( verifiedWordCount != static_cast<int>(strs.size())){
                return "";
            }     
        }
        return longestCommonPrefixWord;
    }
};

int main(){
    Solution solution;
    std::vector<std::string> inputList = {"flower","flower","flower","flower"};
    std::string commonPref = solution.longestCommonPrefix(inputList);
    std::cout << commonPref << std::endl;
}