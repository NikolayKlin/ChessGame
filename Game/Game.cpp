#include "correctness_conditions.h"
#include <SFML/Graphics.hpp>
using namespace sf;


int main()
{
	RenderWindow window(VideoMode(800, 800), "chess game");
	Texture t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15;

	t1.loadFromFile("./Images/Board.png");
	t2.loadFromFile("./Images/Pawn_Black.png");
	t3.loadFromFile("./Images/Pawn_White.png");
	t4.loadFromFile("./Images/Rook_Black.png");
	t5.loadFromFile("./Images/Rook_White.png");
	t6.loadFromFile("./Images/Horse_Black.png");
	t7.loadFromFile("./Images/Horse_White.png");
	t8.loadFromFile("./Images/Elephant_Black.png");
	t9.loadFromFile("./Images/Elephant_White.png");
	t10.loadFromFile("./Images/Queen_Black.png");
	t11.loadFromFile("./Images/Queen_White.png");
	t12.loadFromFile("./Images/King_Black.png");
	t13.loadFromFile("./Images/King_White.png");
	t14.loadFromFile("./Images/Transformate_White.png");
	t15.loadFromFile("./Images/Transformate_Black.png");

	Sprite Board(t1);
	Sprite Pawn_Black(t2);
	Sprite Pawn_White(t3);
	Sprite Rook_Black(t4);
	Sprite Rook_White(t5);
	Sprite Horse_Black(t6);
	Sprite Horse_White(t7);
	Sprite Elephant_Black(t8);
	Sprite Elephant_White(t9);
	Sprite Queen_Black(t10);
	Sprite Queen_White(t11);
	Sprite King_Black(t12);
	Sprite King_White(t13);
	Sprite Fig;
	Sprite Transformate_White(t14);
	Sprite Transformate_Black(t15);

	float dx = 0, dy = 0;
	int figure_num = 0;

    int size = 100;
	while (window.isOpen())
	{
		Vector2i pos = Mouse::getPosition(window);
		auto x = pos.x / size;
		auto y = pos.y / size;
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
			{
				window.close();
			}
			window.clear();
			if (e.type == Event::MouseButtonPressed)
			{
				if (e.key.code == Mouse::Left)
				{
					//std::cout << "x=" << x << " y=" << y << "\n";
					//std::cout << "pos_x=" << pos.x << " pos_y=" << pos.y << "\n";
					//std::cout << "board[y][x]=" << board[y][x] << "\n";
					//std::cout << "\n";
					if (Transformate_White_ == 1)
					{
						if (pos.y >= transformA.y * size && pos.y <= (transformA.y + 1) * size && pos.x >= transformA.x * size && pos.x <= (transformA.x + 1) * size)
						{
							int xx = pos.x % 100, yy = pos.y % 100;
							//std::cout << "pos.y=" << yy << "\n";
							//std::cout << "pos.x=" << xx << "\n";
							if (xx < 50 && yy < 50 && xx > 0 && yy > 0)
							{
								cb.board[transformA.y][transformA.x] = -2;
								Transformate_White_ = 0;
							}
							if (xx > 50 && xx < 100 && yy < 50 && yy > 0)
							{
								cb.board[transformA.y][transformA.x] = -5;
								Transformate_White_ = 0;
							}
							if (xx > 50 && xx < 100 && yy>50 && yy < 100)
							{
								cb.board[transformA.y][transformA.x] = -3;
								Transformate_White_ = 0;
							}
							if (xx < 50 && xx>0 && yy > 50 && y < 100)
							{
								cb.board[transformA.y][transformA.x] = -4;
								Transformate_White_ = 0;
							}
							if (Transformate_White_ == 0)
							{
								cb.posKing_Black();
								int h = cb.Black_king_ShahCheck(controlBlack.x, controlBlack.y);
								if (h == 0)
								{
									shahBlack = 1;
								}
							}
						}
					}
					if (Transformate_Black_ == 1)
					{
						if (pos.y >= transformN.y * size && pos.y <= (transformN.y + 1) * size && pos.x >= transformN.x * size && pos.x <= (transformN.x + 1) * size)
						{
							int xx = pos.x % 100, yy = pos.y % 100;
							//std::cout << "pos.y=" << yy << "\n";
							//std::cout << "pos.x=" << xx << "\n";
							if (xx < 50 && yy < 50 && xx > 0 && yy > 0)
							{
								cb.board[transformN.y][transformN.x] = 2;
								Transformate_Black_
						 = 0;
							}
							if (xx > 50 && xx < 100 && yy < 50 && yy > 0)
							{
								cb.board[transformN.y][transformN.x] = 5;
								Transformate_Black_
						 = 0;
							}
							if (xx > 50 && xx < 100 && yy>50 && yy < 100)
							{
								cb.board[transformN.y][transformN.x] = 3;
								Transformate_Black_
						 = 0;
							}
							if (xx < 50 && xx>0 && yy > 50 && y < 100)
							{
								cb.board[transformN.y][transformN.x] = 4;
								Transformate_Black_
						 = 0;
							}
							if (Transformate_Black_
					 == 0)
							{
								cb.posKing_White();
								int h = cb.King_WhiteShahCheck(controlWhite.x, controlWhite.y);
								if (h == 0)
								{
									shahWhite = 1;
								}
							}
						}
					}
					if (cb.board[y][x] != 0)
					{
						dx = pos.x - x * 100;
						dy = pos.y - y * 100;
						if (cb.board[y][x] == 1 && figure==1)
						{
							figure_num = 1;
							Fig = Pawn_Black;
							cb.board[y][x] = 0;
						}
						if (cb.board[y][x] == -1 && figure==0)
						{
							figure_num = -1;
							Fig = Pawn_White;
							cb.board[y][x] = 0;
						}
						if (cb.board[y][x] == 2 && figure ==1)
						{
							figure_num = 2;
							Fig = Rook_Black;
							cb.board[y][x] = 0;

						}
						if (cb.board[y][x] == -2 && figure ==0)
						{
							figure_num = -2;
							Fig = Rook_White;
							cb.board[y][x] = 0;

						}
						if (cb.board[y][x] == -3 && figure ==0)
						{
							figure_num = -3;
							Fig = Horse_White;
							cb.board[y][x] = 0;
						}
						if (cb.board[y][x] == 3 && figure ==1)
						{
							figure_num = 3;
							Fig = Horse_Black;
							cb.board[y][x] = 0;
						}
						if (cb.board[y][x] == 4 && figure ==1)
						{
							figure_num = 4;
							Fig = Elephant_Black;
							cb.board[y][x] = 0;
						}
						if (cb.board[y][x] == 4 && figure ==0)
						{
							figure_num = 4;
							Fig = Elephant_White;
							cb.board[y][x] = 0;
						}
						if (cb.board[y][x] == -5 && figure==0)
						{
							figure_num = -5;
							Fig = Queen_White;
							cb.board[y][x] = 0;
						}
						if (cb.board[y][x] == -5 && figure ==1)
						{
							figure_num = 5;
							Fig = Queen_Black;
							cb.board[y][x] = 0;
						}
						if (cb.board[y][x] == 5 && figure==1)
						{
							figure_num = 5;
							Fig = King_Black;
							cb.board[y][x] = 0;
						}
						if (cb.board[y][x] == -5 && figure==0)
						{
							figure_num = -6;
							Fig = King_White;
							cb.board[y][x] = 0;
						}
						if (cb.board[y][x] == 0)
						{
							move = 1;
							oldPos.x = x;
							oldPos.y = y;
						}
					}
				}
			}
			if (e.type == Event::MouseButtonReleased)
			{
				if (e.key.code == Mouse::Left)
				{
					int ok=2;
					if (figure_num == -1 && move==1)
					{
						 ok = cb.WhitePawn(oldPos.x, oldPos.y, x, y);
					}
					if (figure_num == 1 && move == 1)
					{
						ok = cb.BlackPawn(oldPos.x, oldPos.y, x, y);
					}
					if (figure_num == -2 && move == 1)
					{
						ok = cb.White_move(oldPos.x, oldPos.y, x, y);
						if (ok == 1 && Rook_WhiteSt==0 && oldPos.y == 7 && oldPos.x == 0)
						{
							Rook_WhiteSt = 1;
	
						}
						if (ok == 1 && Rook_WhiteD==0 && oldPos.y == 7 && oldPos.x == 7)
						{
							Rook_WhiteD = 1;
	
						}
					}
					if (figure_num == 2 && move == 1)
					{
						ok=cb.Black_move(oldPos.x, oldPos.y, x, y);
						if (ok == 1 && Rook_BlackD == 0 && oldPos.y == 0 && oldPos.x == 7)
						{
							Rook_BlackD = 1;

						}
						if (ok == 1 && Rook_BlackSt == 0 && oldPos.y == 0 && oldPos.x == 0)
						{
							Rook_BlackSt = 1;
	
						}
					}
					if (figure_num == -4 && move == 1)
					{
						ok = cb.White_horse(oldPos.x, oldPos.y, x, y);
					}
					if (figure_num == 4 && move == 1)
					{
						ok = cb.Black_horse(oldPos.x, oldPos.y, x, y);
					}
					if (figure_num == -5 && move == 1)
					{
						ok = cb.White_queen(oldPos.x, oldPos.y, x, y);
					}
					if (figure_num == 5 && move == 1)
					{
						ok = cb.Black_queen(oldPos.x, oldPos.y, x, y);
					}
					if (figure_num == -3 && move == 1)
					{
						ok = cb.White_horse(oldPos.x, oldPos.y, x, y);
					}
					if (figure_num == 3 && move == 1)
					{
						ok = cb.Black_elephant(oldPos.x, oldPos.y, x, y);
					}
					if (figure_num == 3 && move == 1)
					{
						ok = cb.Black_king(oldPos.x, oldPos.y, x, y);
						if (ok == 1 && King_Black_ == 0)
						{
							King_Black_ = 1;
						//	std::cout << King_Black << "\n";
						}
					}
					if (figure_num == -6 && move == 1)
					{
						ok = cb.White_king(oldPos.x, oldPos.y, x, y);
						if (ok == 1 && King_White_ == 0)
						{
							King_White_ = 1;
						
						}
					}
					if (ok == 1)
					{
						int nr = cb.board[y][x];
						cb.board[y][x] = figure_num;
						if (y == 0 && figure_num == -1)
						{
							Transformate_White_ = 1;
							transformA.x = x;
							transformA.y = y;
							cb.board[y][x] = 0;
						}
						if (y == 7 && figure_num == 1)
						{
							Transformate_Black_
					 = 1;
							transformN.x = x;
							transformN.y = y;
							cb.board[y][x] = 0;
						}
						if(figure==0) 
						{
							if (shahWhite == 1)
							{
								cb.posKing_White();
								int s = cb.King_WhiteShahCheck(controlWhite.x, controlWhite.y);
								if (s == 0)
								{
									cb.board[oldPos.y][oldPos.x] = figure_num;
									cb.board[y][x] = nr;
								}
								else
								{
									shahWhite = 0;
									cb.posKing_Black();
									int shah = cb.Black_king_ShahCheck(controlBlack.x,controlBlack.y);
									if (shah == 0)
									{
										shahBlack = 1;
									}
									figure = 1;
								}
							}
							else
							{
								cb.posKing_White();
								int sa = cb.King_WhiteShahCheck(controlWhite.x, controlWhite.y);
								if (sa == 0)
								{
									cb.board[oldPos.y][oldPos.x] = figure_num;
									cb.board[y][x] = nr;
								}
								else
								{
									cb.posKing_Black();
									int shah = cb.Black_king_ShahCheck(controlBlack.x, controlBlack.y);
									if (shah == 0)
									{
										shahBlack = 1;
									}
									figure = 1;
								}
							}
						}
						else 
						{
							if (shahBlack == 1)
							{
								cb.posKing_Black();
								int s = cb.Black_king_ShahCheck(controlBlack.x,controlBlack.y);
								if (s == 0)
								{
									cb.board[oldPos.y][oldPos.x] = figure_num;
									cb.board[y][x] = nr;
								}
								else
								{
									shahBlack = 0;
									cb.posKing_White();
									int shah = cb.King_WhiteShahCheck(controlWhite.x,controlWhite.y);
									if (shah == 0)
									{
										shahWhite = 1;
									}
									figure = 0;
								}
							}
							else
							{
								cb.posKing_Black();
								int sa = cb.Black_king_ShahCheck(controlBlack.x, controlBlack.y);
								if (sa == 0)
								{
									cb.board[oldPos.y][oldPos.x] = figure_num;
									cb.board[y][x] = nr;
								}
								else
								{
									cb.posKing_White();
									int shah = cb.King_WhiteShahCheck(controlWhite.x, controlWhite.y);
									if (shah == 0)
									{
										shahWhite = 1;
									}
									figure = 0;
								}
							}
						}
					}
					else if(ok==0)
					{
						cb.board[oldPos.y][oldPos.x] = figure_num;
					}
                   move = 0;
				}
			}
		}
		// afisare //
		window.clear();
		window.draw(Board);
		if (Transformate_White_ == 1)
		{
			Transformate_White.setPosition(transformA.x* size, transformA.y* size);
			window.draw(Transformate_White);
		}
		if (Transformate_Black_ == 1)
		{
			Transformate_Black.setPosition(transformN.x* size, transformN.y* size);
			window.draw(Transformate_Black);
		}
		if (move == 1)
		{
			Fig.setPosition(pos.x-dx, pos.y-dy);
			window.draw(Fig);
		}
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{

				if (cb.board[i][j] != 0)
				{
					if (cb.board[i][j] == 1)
					{
						Pawn_Black.setPosition(j * size, i * size);
						window.draw(Pawn_Black);
					}
					if (cb.board[i][j] == -1)
					{
						Pawn_White.setPosition(j * size, i * size);
						window.draw(Pawn_White);
					}
					if (cb.board[i][j] == 2)
					{
						Rook_Black.setPosition(j * size, i * size);
						window.draw(Rook_Black);

					}
					if (cb.board[i][j] == -2)
					{
						Rook_White.setPosition(j * size, i * size);
						window.draw(Rook_White);

					}
					if (cb.board[i][j] == -3)
					{
						Horse_White.setPosition(j * size, i * size);
						window.draw(Horse_White);
					}
					if (cb.board[i][j] == 3)
					{
						Horse_Black.setPosition(j * size, i * size);
						window.draw(Horse_Black);
					}
					if (cb.board[i][j] == 4)
					{
						Elephant_Black.setPosition(j * size, i * size);
						window.draw(Elephant_Black);
					}
					if (cb.board[i][j] == -4)
					{
						Elephant_White.setPosition(j * size, i * size);
						window.draw(Elephant_White);
					}
					if (cb.board[i][j] == -5)
					{
						Queen_White.setPosition(j * size, i * size);
						window.draw(Queen_White);
					}
					if (cb.board[i][j] == 5)
					{
						Queen_Black.setPosition(j * size, i * size);
						window.draw(Queen_Black);
					}
					if (cb.board[i][j] == 6)
					{
						King_Black.setPosition(j * size, i * size);
						window.draw(King_Black);
					}
					if (cb.board[i][j] == -6)
					{
						King_White.setPosition(j * size, i * size);
						window.draw(King_White);
					}
				}
			}
		}
		window.display();
	}
		return 0;
}

