#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:

    int findJudge(int n, vector<vector<int>>& trust) {

        if ( n == 1 ){return n;}

        int id = 0;
        unordered_map<int,int> person;
        int res = -1;
        int personCount = 0;
        int trustCount = 0;
                
        for ( int i = 1 ; i <= n ; i++ ){
            person[i] = i;
        };

        for ( auto individual : trust ){
            if ( person.find(individual[0]) != person.end() ){
                person.erase(individual[0]);
                personCount++;
            } 
        }

        if ( personCount > 0 ){
            int count = 0;
            for ( auto individual : person ){
                res = individual.first;
                count++;
            }

            if ( count > 1 ){
                return -1;
            }

            for ( auto individual : trust ){
                if ( res == individual[1] ){
                    trustCount++;
                }
            }

            if ( personCount != trustCount ){
                res = -1;
            }
        }


        return res;
    }
};

int main(){
    Solution solution;
    vector<vector<int>> temp = {{1,3},{1,4},{2,3}};
    int res = solution.findJudge(4, temp);
    cout << res << endl;
};