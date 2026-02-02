#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool checkWinner(vector<vector<char>> board, char player){
        int count = 0;

        //Vertical
        for ( int i = 0 ; i < 3 ; i++ ){
            for ( int a = 0 ; a < 3 ; a++ ){
                cout << "[" << i << "][" << a << "]: " << board[i][a] << " Count: " << count << endl; 
                if ( board[i][a] == player ){
                    count++;
                } else {
                    count = 0;
                }
            }
            if ( count >= 3 ){
                cout << "Vertical" << endl;
                return true;
            };
        }

        count = 0;
        //Horizontal
        for ( int i = 0 ; i < 3 ; i++ ){
            for ( int a = 0 ; a < 3 ; a++ ){
                if ( board[a][i] == player ){
                    count++;
                } else {
                    count = 0;
                }
            }
            if ( count >= 3 ){
                cout << "Horizontal" << endl;
                return true;
            };
        }        

        count = 0;
        //Diagonal (Top Left to Bottom Right)
        for ( int i = 0 ; i < 3 ; i++ ){
            if ( board[i][i] == player ){
                count++;
                if ( count >= 3 ){
                    cout << "Diagonal (TR)" << endl;
                    return true;
                }
            } else {
                count = 0;
            }
        }  
        
        count = 0;
        //Diagonal (Top Right to Bottom Left)
        int y = 2;
        for ( int i = 0 ; i < 3 ; i++ ){
            if ( board[i][y] == player ){
                count++;
                if ( count >= 3 ){
                    cout << "Vertical (TL)" << endl;
                    return true;
                }
            } else {
                count = 0;
            }
            y--;
        }

        cout << endl;

        return false;
    }

    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<char>> board(3, vector<char>(3, '_'));
        char playerSymbol = 'A';
        bool statusA = false, statusB = false;
        int i = 0;
        while ( i < moves.size() && (!statusA  || !statusB)){
            //cout << moves[i][0] << " " << moves[i][1] << endl;
            if ( i % 2 == 0 ){
                board[moves[i][0]][moves[i][1]] = 'A';
            } else {
                board[moves[i][0]][moves[i][1]] = 'B';
            }

            statusA = checkWinner(board,'A');
            //cout << statusA << endl;
            if ( statusA ){
                return "A";
            };

            //statusB = checkWinner(board,'B');
            //cout << statusA << endl;
            if ( statusB ){
                return "B";
            }

            i++;
        }

        if ( i < 9 ){
            return "Pending";
        }

        return "Draw";
    }
};

int main(){
    Solution solution;
    vector<vector<int>> temp = {{0,2},{2,2},{1,0},{0,0},{1,2},{2,0},{1,1}};
    string res = solution.tictactoe(temp);
    cout << res << endl;
}