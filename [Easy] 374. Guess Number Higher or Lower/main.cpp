#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int guess(int num){
        int picked = 10; // Change this... This is a parameter; This is the TARGET!

        if ( num > picked ){
            return -1;
        } else if ( num < picked ){
            return 1;
        } else {
            return 0;
        }
    }

    int guessNumber(int n) {
        int guessNum = 0;
        unsigned int start = 0, mid = 0, end = n;
        int res = 0;

        // Initial Guess
        guessNum = guess(n);
        if ( guessNum == 0 ){
            return n;
        }

        do{
            mid = floor((start + end) / 2);
            guessNum = guess(mid);
            if ( guessNum == 0 ){
                res = mid;
                break;
            } else if ( guessNum == 1 ){
                start = mid + 1;
            } else if ( guessNum == -1 ){
                end = mid - 1;
            }
        }while(guessNum != 0);

        return res;
    }
};

int main(){
    Solution solution;
    int res = solution.guessNumber(1000);
    cout << res << endl;
}