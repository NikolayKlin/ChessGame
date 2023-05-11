#include <iostream>
#pragma once
class chessboard
{
public:
    int board[8][8];  // turn может быть w - белый и b - черный

    chessboard(){
    for (size_t i = 0; i < 8; ++i){
        for (size_t j = 0; j < 8; ++j){
            // пешка
            if (i == 1){
                this->board[i][j] = 1;
            }
            else if (i == 6){
                this->board[i][j] = -1;
            }

            // ладья 
            else if (i == 0 && j == 0 || i == 0 && j == 7){
                this->board[i][j] = 2;
            }
            else if (i == 7 && j == 0 || i == 7 && j == 7){
                this->board[i][j] = -2;
            }

            // конь
            else if (i == 0 && j == 1 || i == 0 && j == 6){
                this->board[i][j] = 3;
            }
            else if (i == 7 && j == 1 || i == 7 && j == 6){
                this->board[i][j] = -3;
            }
            
            // слон
            else if (i == 0 && j == 2 || i == 0 && j == 5){
                this->board[i][j] = 4;
            }
            else if (i == 7 && j == 2 || i == 7 && j == 5){
                this->board[i][j] = -4;
            }

            // ферзь
            else if (i == 0 && j == 3){
                this->board[i][j] = 5;
            }
            else if (i == 7 && j == 3){
                this->board[i][j] = -5;
            }

            //король
            else if (i == 0 && j == 4){
                this->board[i][j] = 6;
            }
            else if (i == 7 && j == 4){
                this->board[i][j] = -6;
            }

            else{
                this->board[i][j] = 0;
            }

        }
    }

}
};