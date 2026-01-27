#include <iostream>
#include <unordered_map>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int> sumDictionary;
        try{
            int sum = 0;
            while ( sum != 1 || n != 0 ){
                int remainder = n % 10;
                cout << "remainder: " << remainder << endl; 
                sum += pow(remainder,2); 
                cout << "sum: " << sum << endl;
                n /= 10;
                cout << "n: " << n << endl;

                cout << endl;
                
                if ( n == 0 ){
                    if ( sum == 1 ){
                        return true;
                    } else {
                        if ( sumDictionary.find(sum) != sumDictionary.end() ){
                            return false;
                        }
                    }
                    sumDictionary[sum] = sum;
                    n = sum;
                    sum = 0;
                }
            }
        } catch (...){}

        return false;
    }
};

int main(){
    Solution solution;
    bool res = solution.isHappy(19);
    cout << res << endl;
}