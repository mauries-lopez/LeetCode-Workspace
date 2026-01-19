#include <vector>
#include <iostream>

class Solution {
public:
    bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {
        int curNum = flowerbed.at(0);
        int numPlanted = 0;

        if ( flowerbed.size() > 1 ){
            for (int i = 0; i < flowerbed.size(); i++){
                if (i == 0 ){ // [0,0]
                    if ( flowerbed.at(i) == 0 && flowerbed.at(i+1) == 0 ){
                        flowerbed.at(i) = 1;
                        numPlanted++;
                        //std::cout << "Added["<< i << "]" << std::endl;
                    }else{
                        continue;
                    }
                } else if ( flowerbed.at(i-1) == 0 && i != flowerbed.size() - 1 && flowerbed.at(i) != 1){
                    if ( flowerbed.at(i+1) == 0 ){
                        flowerbed.at(i) = 1;
                        numPlanted++;
                        //std::cout << "Added["<< i << "]" << std::endl;
                    }
                } else if ( i == flowerbed.size() - 1 && flowerbed.at(i) == 0){
                    if (flowerbed.at(i-1) == 0 ){
                        flowerbed.at(i) = 1;
                        numPlanted++;
                    }
                }
            }
        } else {
            if ( flowerbed.at(0) == 0 ){
                flowerbed.at(0) = 1;
                numPlanted++;
            }
        }

        /*
        for ( auto x : flowerbed){
            std::cout << x << " " << std::endl;
        }
        std::cout << "numPlanted: " << numPlanted << std::endl;
        */
        
        if ( n <= numPlanted || n == 0){
            return true;
        }

        return false;
    }
};

int main () {
    Solution solution;
    std::vector<int> temp = {1,0,0,0,1,0,1};
    bool res = solution.canPlaceFlowers(temp,2);
    std::cout << std::boolalpha << res << std::endl;
}