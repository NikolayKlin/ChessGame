#include "correctness_conditions.h"
#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(800, 800), "chess game");
	Texture t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15;

	t1.loadFromFile("board.png");
	t2.loadFromFile("PionNegru.png");
	t3.loadFromFile("PionAlb.png");
	t4.loadFromFile("TurnNegru.png");
	t5.loadFromFile("TurnAlb.png");
	t6.loadFromFile("CalAlb.png");
	t7.loadFromFile("CalNegru.png");
	t8.loadFromFile("NebunNegru.png");
	t9.loadFromFile("NebunAlb.png");
	t10.loadFromFile("ReginaAlb.png");
	t11.loadFromFile("ReginaNegru.png");
	t12.loadFromFile("RegeNegru.png");
	t13.loadFromFile("RegeAlb.png");
	t14.loadFromFile("TransformareAlb.png");
	t15.loadFromFile("TransformareNegru.png");

	Sprite tabla(t1);
	Sprite PionNegru(t2);
	Sprite PionAlb(t3);
	Sprite TurnNegru(t4);
	Sprite TurnAlb(t5);
	Sprite CalAlb(t6);
	Sprite CalNegru(t7);
	Sprite NebunNegru(t8);
	Sprite NebunAlb(t9);
	Sprite ReginaAlb(t10);
	Sprite ReginaNegru(t11);
	Sprite RegeNegru(t12);
	Sprite RegeAlb(t13);
	Sprite Mutare;
	Sprite TransformareALB(t14);
	Sprite TransformareNEGRU(t15);

	float dx = 0, dy = 0;
	int numarPiesaMutata = 0;

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
					if (transformareAlb == 1)
					{
						if (pos.y >= transformA.y * size && pos.y <= (transformA.y + 1) * size && pos.x >= transformA.x * size && pos.x <= (transformA.x + 1) * size)
						{
							int xx = pos.x % 100, yy = pos.y % 100;
							//std::cout << "pos.y=" << yy << "\n";
							//std::cout << "pos.x=" << xx << "\n";
							if (xx < 50 && yy < 50 && xx > 0 && yy > 0)
							{
								cb.board[transformA.y][transformA.x] = -2;
								transformareAlb = 0;
							}
							if (xx > 50 && xx < 100 && yy < 50 && yy > 0)
							{
								cb.board[transformA.y][transformA.x] = -5;
								transformareAlb = 0;
							}
							if (xx > 50 && xx < 100 && yy>50 && yy < 100)
							{
								cb.board[transformA.y][transformA.x] = -3;
								transformareAlb = 0;
							}
							if (xx < 50 && xx>0 && yy > 50 && y < 100)
							{
								cb.board[transformA.y][transformA.x] = -4;
								transformareAlb = 0;
							}
							if (transformareAlb == 0)
							{
								pozRegeNegru();
								int h = Black_king_SahCheck(regeleNegru.x, regeleNegru.y);
								if (h == 0)
								{
									sahNegru = 1;
								}
							}
						}
					}
					if (transformareNegru == 1)
					{
						if (pos.y >= transformN.y * size && pos.y <= (transformN.y + 1) * size && pos.x >= transformN.x * size && pos.x <= (transformN.x + 1) * size)
						{
							int xx = pos.x % 100, yy = pos.y % 100;
							//std::cout << "pos.y=" << yy << "\n";
							//std::cout << "pos.x=" << xx << "\n";
							if (xx < 50 && yy < 50 && xx > 0 && yy > 0)
							{
								cb.board[transformN.y][transformN.x] = 2;
								transformareNegru = 0;
							}
							if (xx > 50 && xx < 100 && yy < 50 && yy > 0)
							{
								cb.board[transformN.y][transformN.x] = 5;
								transformareNegru = 0;
							}
							if (xx > 50 && xx < 100 && yy>50 && yy < 100)
							{
								cb.board[transformN.y][transformN.x] = 3;
								transformareNegru = 0;
							}
							if (xx < 50 && xx>0 && yy > 50 && y < 100)
							{
								cb.board[transformN.y][transformN.x] = 4;
								transformareNegru = 0;
							}
							if (transformareNegru == 0)
							{
								pozRegeAlb();
								int h = RegeAlbSahCheck(regeleAlb.x, regeleAlb.y);
								if (h == 0)
								{
									sahAlb = 1;
								}
							}
						}
					}
					if (cb.board[y][x] != 0)
					{
						dx = pos.x - x * 100;
						dy = pos.y - y * 100;
						if (cb.board[y][x] == 1 && mutare==1)
						{
							numarPiesaMutata = 1;
							Mutare = PionNegru;
							cb.board[y][x] = 0;
						}
						if (cb.board[y][x] == -1 && mutare==0)
						{
							numarPiesaMutata = -1;
							Mutare = PionAlb;
							cb.board[y][x] = 0;
						}
						if (cb.board[y][x] == 2 && mutare ==1)
						{
							numarPiesaMutata = 2;
							Mutare = TurnNegru;
							cb.board[y][x] = 0;

						}
						if (cb.board[y][x] == -2 && mutare ==0)
						{
							numarPiesaMutata = -2;
							Mutare = TurnAlb;
							cb.board[y][x] = 0;

						}
						if (cb.board[y][x] == -3 && mutare ==0)
						{
							numarPiesaMutata = -3;
							Mutare = CalAlb;
							cb.board[y][x] = 0;
						}
						if (cb.board[y][x] == 3 && mutare ==1)
						{
							numarPiesaMutata = 3;
							Mutare = CalNegru;
							cb.board[y][x] = 0;
						}
						if (cb.board[y][x] == 4 && mutare ==1)
						{
							numarPiesaMutata = 4;
							Mutare = NebunNegru;
							cb.board[y][x] = 0;
						}
						if (cb.board[y][x] == 4 && mutare ==0)
						{
							numarPiesaMutata = 4;
							Mutare = NebunAlb;
							cb.board[y][x] = 0;
						}
						if (cb.board[y][x] == -5 && mutare==0)
						{
							numarPiesaMutata = -5;
							Mutare = ReginaAlb;
							cb.board[y][x] = 0;
						}
						if (cb.board[y][x] == -5 && mutare ==1)
						{
							numarPiesaMutata = 5;
							Mutare = ReginaNegru;
							cb.board[y][x] = 0;
						}
						if (cb.board[y][x] == 5 && mutare==1)
						{
							numarPiesaMutata = 5;
							Mutare = RegeNegru;
							cb.board[y][x] = 0;
						}
						if (cb.board[y][x] == -5 && mutare==0)
						{
							numarPiesaMutata = -6;
							Mutare = RegeAlb;
							cb.board[y][x] = 0;
						}
						if (cb.board[y][x] == 0)
						{
							move = 1;
							oldPoz.x = x;
							oldPoz.y = y;
						}
					}
				}
			}
			if (e.type == Event::MouseButtonReleased)
			{
				if (e.key.code == Mouse::Left)
				{
					int ok=2;
					if (numarPiesaMutata == -1 && move==1)
					{
						 ok = WhitePawn(oldPoz.x, oldPoz.y, x, y);
					}
					if (numarPiesaMutata == 1 && move == 1)
					{
						ok = BlackPawn(oldPoz.x, oldPoz.y, x, y);
					}
					if (numarPiesaMutata == -2 && move == 1)
					{
						ok = White_move(oldPoz.x, oldPoz.y, x, y);
						if (ok == 1 && turnAlbStanga==0 && oldPoz.y == 7 && oldPoz.x == 0)
						{
							turnAlbStanga = 1;
							//std::cout << turnAlbStanga << "\n";
						}
						if (ok == 1 && turnAlbDreapta==0 && oldPoz.y == 7 && oldPoz.x == 7)
						{
							turnAlbDreapta = 1;
							//std::cout << turnAlbDreapta << "\n";
						}
					}
					if (numarPiesaMutata == 2 && move == 1)
					{
						ok=Black_move(oldPoz.x, oldPoz.y, x, y);
						if (ok == 1 && turnNegruDreapta == 0 && oldPoz.y == 0 && oldPoz.x == 7)
						{
							turnNegruDreapta = 1;
							//std::cout << turnNegruDreapta<< "\n";
						}
						if (ok == 1 && turnNegruStanga == 0 && oldPoz.y == 0 && oldPoz.x == 0)
						{
							turnNegruStanga = 1;
							//std::cout << turnNegruStanga << "\n";
						}
					}
					if (numarPiesaMutata == -4 && move == 1)
					{
						ok = White_horse(oldPoz.x, oldPoz.y, x, y);
					}
					if (numarPiesaMutata == 4 && move == 1)
					{
						ok= Black_horse(oldPoz.x, oldPoz.y, x, y);
					}
					if (numarPiesaMutata == -5 && move == 1)
					{
						ok=White_queen(oldPoz.x, oldPoz.y, x, y);
					}
					if (numarPiesaMutata == 5 && move == 1)
					{
						ok=Black_queen(oldPoz.x, oldPoz.y, x, y);
					}
					if (numarPiesaMutata == -3 && move == 1)
					{
						ok=White_horse(oldPoz.x, oldPoz.y, x, y);
					}
					if (numarPiesaMutata == 3 && move == 1)
					{
						ok = Black_elephant(oldPoz.x, oldPoz.y, x, y);
					}
					if (numarPiesaMutata == 3 && move == 1)
					{
						ok=RegeN(oldPoz.x, oldPoz.y, x, y);
						if (ok == 1 && regeNegru == 0)
						{
							regeNegru = 1;
						//	std::cout << regeNegru << "\n";
						}
					}
					if (numarPiesaMutata == -6 && move == 1)
					{
						ok=RegeA(oldPoz.x, oldPoz.y, x, y);
						if (ok == 1 && regeAlb == 0)
						{
							regeAlb = 1;
							//std::cout << "primaMutareREGEalb=" << regeAlb << "\n";
						}
					}
					if (ok == 1)
					{
						int nr = cb.board[y][x];
						cb.board[y][x] = numarPiesaMutata;
						if (y == 0 && numarPiesaMutata == -1)
						{
							transformareAlb = 1;
							transformA.x = x;
							transformA.y = y;
							cb.board[y][x] = 0;
						}
						if (y == 7 && numarPiesaMutata == 1)
						{
							transformareNegru = 1;
							transformN.x = x;
							transformN.y = y;
							cb.board[y][x] = 0;
						}
						if(mutare==0) // albul a mutat si urmeaza negrul
						{
							if (sahAlb == 1)
							{
								pozRegeAlb();
								int s = RegeAlbSahCheck(regeleAlb.x, regeleAlb.y);
								if (s == 0)
								{
									cb.board[oldPoz.y][oldPoz.x] = numarPiesaMutata;
									cb.board[y][x] = nr;
								}
								else
								{
									sahAlb = 0;
									pozRegeNegru();
									int sah = Black_king_SahCheck(regeleNegru.x,regeleNegru.y);
									if (sah == 0)
									{
										sahNegru = 1;
									}
									mutare = 1;
								}
							}
							else
							{
								pozRegeAlb();
								int sa = RegeAlbSahCheck(regeleAlb.x, regeleAlb.y);
								if (sa == 0)
								{
									cb.board[oldPoz.y][oldPoz.x] = numarPiesaMutata;
									cb.board[y][x] = nr;
								}
								else
								{
									pozRegeNegru();
									int sah = Black_king_SahCheck(regeleNegru.x, regeleNegru.y);
									if (sah == 0)
									{
										sahNegru = 1;
									}
									mutare = 1;
								}
							}
						}
						else // negrul a mutat si urmeaza albul
						{
							if (sahNegru == 1)
							{
								pozRegeNegru();
								int s = Black_king_SahCheck(regeleNegru.x,regeleNegru.y);
								if (s == 0)
								{
									cb.board[oldPoz.y][oldPoz.x] = numarPiesaMutata;
									cb.board[y][x] = nr;
								}
								else
								{
									sahNegru = 0;
									pozRegeAlb();
									int sah = RegeAlbSahCheck(regeleAlb.x,regeleAlb.y);
									if (sah == 0)
									{
										sahAlb = 1;
									}
									mutare = 0;
								}
							}
							else
							{
								pozRegeNegru();
								int sa = Black_king_SahCheck(regeleNegru.x, regeleNegru.y);
								if (sa == 0)
								{
									cb.board[oldPoz.y][oldPoz.x] = numarPiesaMutata;
									cb.board[y][x] = nr;
								}
								else
								{
									pozRegeAlb();
									int sah = RegeAlbSahCheck(regeleAlb.x, regeleAlb.y);
									if (sah == 0)
									{
										sahAlb = 1;
									}
									mutare = 0;
								}
							}
						}
					}
					else if(ok==0)
					{
						cb.board[oldPoz.y][oldPoz.x] = numarPiesaMutata;
					}
                   move = 0;
				}
			}
		}
		// afisare //
		window.clear();
		window.draw(tabla);
		if (transformareAlb == 1)
		{
			TransformareALB.setPosition(transformA.x* size, transformA.y* size);
			window.draw(TransformareALB);
		}
		if (transformareNegru == 1)
		{
			TransformareNEGRU.setPosition(transformN.x* size, transformN.y* size);
			window.draw(TransformareNEGRU);
		}
		if (move == 1)
		{
			Mutare.setPosition(pos.x-dx, pos.y-dy);
			window.draw(Mutare);
		}
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{

				if (cb.board[i][j] != 0)
				{
					if (cb.board[i][j] == 1)
					{
						PionNegru.setPosition(j * size, i * size);
						window.draw(PionNegru);
					}
					if (cb.board[i][j] == -1)
					{
						PionAlb.setPosition(j * size, i * size);
						window.draw(PionAlb);
					}
					if (cb.board[i][j] == 2)
					{
						TurnNegru.setPosition(j * size, i * size);
						window.draw(TurnNegru);

					}
					if (cb.board[i][j] == -2)
					{
						TurnAlb.setPosition(j * size, i * size);
						window.draw(TurnAlb);

					}
					if (cb.board[i][j] == -3)
					{
						CalAlb.setPosition(j * size, i * size);
						window.draw(CalAlb);
					}
					if (cb.board[i][j] == 3)
					{
						CalNegru.setPosition(j * size, i * size);
						window.draw(CalNegru);
					}
					if (cb.board[i][j] == 4)
					{
						NebunNegru.setPosition(j * size, i * size);
						window.draw(NebunNegru);
					}
					if (cb.board[i][j] == -4)
					{
						NebunAlb.setPosition(j * size, i * size);
						window.draw(NebunAlb);
					}
					if (cb.board[i][j] == -5)
					{
						ReginaAlb.setPosition(j * size, i * size);
						window.draw(ReginaAlb);
					}
					if (cb.board[i][j] == 5)
					{
						ReginaNegru.setPosition(j * size, i * size);
						window.draw(ReginaNegru);
					}
					if (cb.board[i][j] == 6)
					{
						RegeNegru.setPosition(j * size, i * size);
						window.draw(RegeNegru);
					}
					if (cb.board[i][j] == -6)
					{
						RegeAlb.setPosition(j * size, i * size);
						window.draw(RegeAlb);
					}
				}
			}
		}
		window.display();
	}
		return 0;
}

