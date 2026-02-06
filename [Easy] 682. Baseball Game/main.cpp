#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> res;
        int ans = 0;

        for ( string i : operations ){
            try{
                res.push(stoi(i));
            }catch(...){
                cout << i << endl;
                if ( i == "C" ){
                    res.pop();
                } else if ( i == "D" ){
                    int temp = res.top() * 2;
                    res.push(temp);
                } else if ( i == "+" ){
                    int numA = res.top();
                    res.pop();
                    int numB = res.top();
                    int temp = numA + numB;
                    res.push(numA);
                    res.push(temp);
                }
            };
        }

        while(!res.empty()){
            ans += res.top();
            res.pop();
        }
        
        return ans;
    }
};

int main(){
    Solution solution;
    vector<string> temp = {"5","2","C","D","+"};
    int res = solution.calPoints(temp);
    cout << res << endl;
    return 0;
}