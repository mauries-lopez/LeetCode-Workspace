#include <iostream>
#include <string>
#include <cmath>
#include <unordered_map>

using namespace std;

class Solution{
public:
    string categorizeBox(int length, int width, int height, int mass){
        unordered_map<string,string> res;
        long long volume = (long long) length*width*height;
        if ( (length >= pow(10,4) || width >= pow(10,4) || height >= pow(10,4) || mass >= pow(10,4)) || (volume >= pow(10,9))){
            res["Bulky"] = "Bulky";
        }
        
        if ( mass >= 100 ){
            res["Heavy"] = "Heavy";
        };

        if ( res.find("Bulky") != res.end() && res.find("Heavy") != res.end()){
            return "Both";
        } else if ( res.find("Bulky") != res.end() && res.find("Heavy") == res.end() ){
            return "Bulky";
        } else if ( res.find("Heavy") != res.end() && res.find("Bulky") == res.end() ){
            return "Heavy";
        } else {
            return "Neither";
        }
    }
};

int main(){
    Solution solution;
    string ans = solution.categorizeBox(2909,3968,3272,727);
    cout << ans << endl;
}