#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution{
public:
    int evalRPN(vector<string>& tokens){
        stack<int> num;
        char op;
        bool compute = false;
        
        for ( string token : tokens ){
            try{
                if ( token == "+" || token == "-" || token == "/" || token == "*" ) {
                    op = token[0];
                    compute = true;
                }
            } catch ( exception e){
                
            }

            if (compute){
                //cout << "op: " << op << endl;

                int numA = 0, numB = 0;
                try{
                    // << "numA: " << num.top() << endl;
                    numA = num.top();
                    num.pop();                    
                } catch ( exception e ){
                    numA = 0;
                }
                
                try{
                    //cout << "numB: " << num.top() << endl;
                    numB = num.top();
                    num.pop();
                } catch ( exception e){
                    numB = 0;
                }
                
                int res = 0;

                switch (op){
                    case '+':
                        res = numA + numB;
                        break;
                    case '-':
                        res = numB - numA;
                        break;
                    case '/':
                        res = numB / numA;
                        break;
                    case '*':
                        res = numB * numA;
                        break;
                }
                
                //cout << "res: " << res << endl;
                num.push(res);
                compute = false;       
            } else {
                num.push(stoi(token));
            }
        }
        return num.top();
    }
};

int main(){
    Solution solution;
    vector<string> temp = {"4", "3", "-"};
    int res = solution.evalRPN(temp);
    cout << res << endl;
}