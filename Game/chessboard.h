#include <iostream>
#pragma once


struct pos
{
	int x, y;
}oldPos, controlWhite, controlBlack, transformA, transformN;


int move = 0;

int Rook_WhiteD = 0, Rook_WhiteSt = 0, King_White_ = 0;
int Rook_BlackD = 0, Rook_BlackSt = 0, King_Black_ = 0;

int figure = 0;

int shahWhite = 0, shahBlack = 0;

int Transformate_White_ = 0, Transformate_Black_ = 0;



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
                //пустота
                else{
                    this->board[i][j] = 0;
                }
            

            }
        }

    }
    int WhitePawn(int ox, int oy, int nx, int ny);
    int BlackPawn(int ox, int oy, int nx, int ny);
    int White_move(int ox, int oy, int nx, int ny);
    int Black_move(int ox, int oy, int nx, int ny);
    int White_elephant(int ox, int oy, int nx, int ny);
    int Black_elephant(int ox, int oy, int nx, int ny);
    int White_queen(int ox, int oy, int nx, int ny);
    int Black_queen(int ox, int oy, int nx, int ny);
    int White_horse(int ox, int oy, int nx, int ny);
    int Black_horse(int ox, int oy, int nx, int ny);
    int White_pawn_check(int posx, int posy, int destx, int desty);
    int Black_pawn_check(int posx, int posy, int destx, int desty);
    int White_rook_check(int ox, int oy, int destx, int desty);
    int White_elephant_check(int ox, int oy, int destx, int desty);
    int Black_elephant_check(int ox, int oy, int destx, int desty);
    int White_queen_check(int ox, int oy, int destx, int desty);
    int Black_queen_check(int ox, int oy, int destx, int desty);
    int White_king_check(int ox, int oy, int destx, int desty);
    int Black_king_check(int ox, int oy, int destx, int desty);
    int Black_king_ShahCheck(int posdestx, int posdesty);
    int King_WhiteShahCheck(int posdestx, int posdesty);
    int Black_king(int ox, int oy, int nx, int ny);
    int White_king(int ox, int oy, int nx, int ny);
    int Black_RookShah(int ox, int oy, int destx, int desty);
    int Black_ElephantShah(int ox, int oy, int destx, int desty);
    int Black_horse_check(int ox, int oy, int destx, int desty);
    void posKing_White();
    void posKing_Black();

};