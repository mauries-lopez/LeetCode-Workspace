#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Athlete{
    int num;
    std::string place;
};

class Solution {
public:
    std::vector<std::string> findRelativeRanks(std::vector<int>& score) {
        std::vector<Athlete> athleteList;
        std::vector<std::string> res;

        for (int i = 0; i < score.size(); i++){
            Athlete athlete;
            athlete.num = score.at(i);
            athlete.place = " ";
            athleteList.push_back(athlete);
        }

        std::sort(score.begin(), score.end(), std::greater<>());
        for ( int x = score.size() - 1; x >= 0; x-- ){
            for ( int y = 0; y < athleteList.size(); y++ ){
                if ( score[x] == athleteList.at(y).num ){
                    if ( x >= 3 ){
                        athleteList.at(y).place = std::to_string(x + 1);
                    } else if ( x == 2 ){
                        athleteList.at(y).place = "Bronze Medal";
                    } else if ( x == 1 ) {
                        athleteList.at(y).place = "Silver Medal";
                    } else if ( x == 0 ){
                        athleteList.at(y).place = "Gold Medal";
                    }
                }
            }
        }

        for ( int i = 0; i < athleteList.size(); i++ ){
            res.push_back(athleteList.at(i).place);
        }

        return res;
    }
};

int main() {
    std::vector<int> score = {10,3,8,9,4};
    Solution solution;
    std::vector<std::string> res = solution.findRelativeRanks(score);
    for ( auto x : res ){
        std::cout << x << std::endl;
    }
}