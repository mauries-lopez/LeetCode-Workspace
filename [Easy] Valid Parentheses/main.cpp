#include <stack>
#include <iostream>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> stack;
        int i = 0;
        if ( s.length() % 2 == 0 ){
            while( i < s.length() ){
                //std::cout << s[i] << std::endl;
                if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
                    stack.push(s[i]);
                } else {
                    //std::cout << s[i] << std::endl;
                    //std::cout << stack.top() << std::endl;
                    if ( !stack.empty() ){
                        switch(s[i]){
                            case ')':
                                //std::cout << s[i] << std::endl;
                                if ( stack.top() == '(' ){
                                    stack.pop();
                                } else {
                                    return false;
                                }
                                break;
                            case ']':
                                if ( stack.top() == '[' ){
                                    stack.pop();
                                } else {
                                    return false;
                                }
                                break;
                            case '}':
                                if ( stack.top() == '{' ){
                                    stack.pop();
                                } else {
                                    return false;
                                }
                                break;
                            default:
                                return false;
                        };
                    } else {
                        return false;
                    };
                };
                i++;
            }
            return ( stack.size() == 0 ? true : false );
        }
        return false;
    }
};

int main() {
    Solution solution;
    std::string s = "))";
    bool res = solution.isValid(s);
    std::cout << std::boolalpha << res << std::endl;
}