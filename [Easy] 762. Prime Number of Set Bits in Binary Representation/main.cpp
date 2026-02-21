#include <iostream>
#include <string>
#include <bitset>

using namespace std;

class Solution {
public:
    bool isPrime(int num){
        int factorCount = 0;
        if ( num == 1 ) return false;
        for ( int i = 1 ; i <= num ; i++ ){
            if ( num % i == 0 ){
                factorCount++;
            }
            if ( factorCount > 2 ){
                return false;
            }
        }
        return true;
    }

    int countPrimeSetBits(int left, int right) {
        int primeCount = 0;
        for ( int i = left ; i <= right ; i++ ){
            string bitLeftString = bitset<32>(i).to_string();
            int oneCounter = 0;
            for ( char digit : bitLeftString ){
                if ( digit == '1' ){
                    oneCounter++;
                }
            }
            if ( isPrime(oneCounter) ){
                primeCount++;
            }
        }
        return primeCount;
    }
};

int main(){
    Solution solution;
    int res = solution.countPrimeSetBits(6,10);
    cout << res << endl;
    return 0;
}