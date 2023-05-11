#include "chessboard.h"


struct poz
{
	int x, y;
}oldPoz, regeleAlb, regeleNegru, transformA, transformN;

chessboard cb;

int move = 0;

int turnAlbDreapta = 0, turnAlbStanga = 0, regeAlb = 0;
int turnNegruDreapta = 0, turnNegruStanga = 0, regeNegru = 0;

int mutare = 0;

int sahAlb = 0, sahNegru = 0;

int transformareAlb = 0, transformareNegru = 0;


int WhitePawn(int ox, int oy, int nx, int ny)
{
	if (oldPoz.y == 6)
	{
		if ((ny == oy - 1 && nx == ox && cb.board[oy-1][ox]==0)||(ny==oy-2 && nx==ox && cb.board[oy - 1][ox] == 0 && cb.board[oy - 2][ox]==0))
		{
			return 1;
		}
	}
	else if(ny == oy - 1 && nx == ox && cb.board[oy - 1][ox] == 0)
	{
		return 1;
	}
	if (cb.board[oy - 1][ox - 1] > 0)
	{
		if (ny == oy - 1 && nx == ox - 1)
		{
			return 1;
		}
	}
	if (cb.board[oy - 1][ox + 1] > 0)
	{
		if (ny == oy - 1 && nx == ox + 1)
		{
			return 1;
		}
	}
	return 0;
}

int BlackPawn(int ox, int oy, int nx, int ny)
{
	if (oldPoz.y == 1)
	{
		if ((ny == oy + 1 && nx == ox && cb.board[oy+1][ox]==0) || (ny == oy + 2 && nx == ox && cb.board[oy + 1][ox] == 0 && cb.board[oy + 2][ox] == 0))
		{
			return 1;
		}
	}
	else if (ny == oy + 1 && nx == ox && cb.board[oy + 1][ox] == 0)
	{
		return 1;
	}
	if (cb.board[oy + 1][ox - 1] < 0)
	{
		if (ny == oy + 1 && nx == ox - 1)
		{
			return 1;
		}
	}
	if (cb.board[oy + 1][ox + 1] < 0)
	{
		if (ny == oy + 1 && nx == ox + 1)
		{
			return 1;
		}
	}
	return 0;
}

int White_move(int ox, int oy, int nx, int ny)
{
	for (int i = ox-1; i >= 0; i--)
	{
		if (cb.board[oy][i] >= 0 && (nx == i && ny == oy))
		{
			return 1;
		}
		else if (cb.board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy - 1; i >= 0; i--)
	{
		if (cb.board[i][ox] >= 0 && (ny == i && nx == ox))
		{
			return 1;
		}
		else if (cb.board[i][ox] != 0 )
		{
			break;
		}
	}
	for (int i = ox + 1; i <= 7; i++)
	{
		if (cb.board[oy][i]>=0 && (ny == oy && nx == i))
		{
			return 1;
		}
		else if (cb.board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy + 1; i <= 7; i++)
	{
		if (cb.board[i][ox]>=0 && (ny == i && nx == ox))
		{
			return 1;
		}
		else if (cb.board[i][ox] != 0)
		{
			break;
		}
	}
	return 0;
}

int Black_move(int ox, int oy, int nx, int ny)
{
	for (int i = ox - 1; i >= 0; i--)
	{
		if (cb.board[oy][i] <= 0 && (nx == i && ny == oy))
		{
			return 1;
		}
		else if (cb.board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy - 1; i >= 0; i--)
	{
		if (cb.board[i][ox] <= 0 && (ny == i && nx == ox))
		{
			return 1;
		}
		else if (cb.board[i][ox] != 0)
		{
			break;
		}
	}
	for (int i = ox + 1; i <= 7; i++)
	{
		if (cb.board[oy][i] <= 0 && (ny == oy && nx == i))
		{
			return 1;
		}
		else if (cb.board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy + 1; i <= 7; i++)
	{
		if (cb.board[i][ox] <= 0 && (ny == i && nx == ox))
		{
			return 1;
		}
		else if (cb.board[i][ox] != 0)
		{
			break;
		}
	}
	return 0;
}

int White_elephant(int ox, int oy, int nx, int ny)
{
	int j = ox - 1;
	for (int i = oy - 1; i >= 0; i--)
	{
		if (cb.board[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (cb.board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy - 1; i >= 0; i--)
	{
		if (cb.board[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (cb.board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ox - 1;
	for (int i = oy + 1; i <= 7; i++) 
	{
		if (cb.board[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (cb.board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy + 1; i <= 7; i++)
	{
		if (cb.board[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (cb.board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int Black_elephant(int ox, int oy, int nx, int ny)
{
	int j = ox - 1;
	for (int i = oy - 1; i >= 0; i--) // spre stanga sus
	{
		if (cb.board[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (cb.board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy - 1; i >= 0; i--) // spre dreapta sus
	{
		if (cb.board[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (cb.board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ox - 1;
	for (int i = oy + 1; i <= 7; i++) // spre stanga jos
	{
		if (cb.board[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (cb.board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy + 1; i <= 7; i++)  // spre dreapta jos
	{
		if (cb.board[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (cb.board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int White_queen(int ox, int oy, int nx, int ny)
{
	for (int i = ox - 1; i >= 0; i--) // spre stanga
	{
		if (cb.board[oy][i] >= 0 && (nx == i && ny == oy))
		{
			return 1;
		}
		else if (cb.board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy - 1; i >= 0; i--) // sus
	{
		if (cb.board[i][ox] >= 0 && (ny == i && nx == ox))
		{
			return 1;
		}
		else if (cb.board[i][ox] != 0)
		{
			break;
		}
	}
	for (int i = ox + 1; i <= 7; i++) // spre dreapta
	{
		if (cb.board[oy][i] >= 0 && (ny == oy && nx == i))
		{
			return 1;
		}
		else if (cb.board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy + 1; i <= 7; i++) // jos
	{
		if (cb.board[i][ox] >= 0 && (ny == i && nx == ox))
		{
			return 1;
		}
		else if (cb.board[i][ox] != 0)
		{
			break;
		}
	}
	int j = ox - 1;
	for (int i = oy - 1; i >= 0; i--) // spre stanga sus
	{
		if (cb.board[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (cb.board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy - 1; i >= 0; i--){
		if (cb.board[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (cb.board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ox - 1;

	for (int i = oy + 1; i <= 7; i++)
	{
		if (cb.board[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (cb.board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy + 1; i <= 7; i++)  
	{
		if (cb.board[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (cb.board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int Black_queen(int ox, int oy, int nx, int ny)
{
	for (int i = ox - 1; i >= 0; i--)
	{
		if (cb.board[oy][i] <= 0 && (nx == i && ny == oy))
		{
			return 1;
		}
		else if (cb.board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy - 1; i >= 0; i--)
	{
		if (cb.board[i][ox] <= 0 && (ny == i && nx == ox))
		{
			return 1;
		}
		else if (cb.board[i][ox] != 0)
		{
			break;
		}
	}
	for (int i = ox + 1; i <= 7; i++)
	{
		if (cb.board[oy][i] <= 0 && (ny == oy && nx == i))
		{
			return 1;
		}
		else if (cb.board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy + 1; i <= 7; i++)
	{
		if (cb.board[i][ox] <= 0 && (ny == i && nx == ox))
		{
			return 1;
		}
		else if (cb.board[i][ox] != 0)
		{
			break;
		}
	}
	int j = ox - 1;
	for (int i = oy - 1; i >= 0; i--)
	{
		if (cb.board[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (cb.board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy - 1; i >= 0; i--)
	{
		if (cb.board[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (cb.board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ox - 1;
	for (int i = oy + 1; i <= 7; i++)
	{
		if (cb.board[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (cb.board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy + 1; i <= 7; i++)
	{
		if (cb.board[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (cb.board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int White_horse(int ox, int oy, int nx, int ny)
{
	if (oy - 2 >= 0 && ox - 1 >= 0 && ny == oy - 2 && nx == ox - 1 && cb.board[ny][nx] >= 0)
	{
		return 1;
	}
	if (oy - 2 >= 0 && ox + 1 <8 && ny == oy - 2 && nx == ox + 1 && cb.board[ny][nx] >= 0)
	{
		return 1;
	}
	if (oy - 1 >= 0 && ox + 2 < 8 && ny==oy-1 && nx==ox+2 && cb.board[ny][nx]>=0)
	{
		return 1;
	}
	if (oy + 1 >= 0 && ox + 2 < 8 && ny == oy + 1 && nx == ox + 2 && cb.board[ny][nx] >= 0)
	{
		return 1;
	}
	if (oy+2<8 && ox+1<8 && ny==oy+2 && nx==ox+1 && cb.board[ny][nx]>=0)
	{
		return 1;
	}
	if (oy + 2 < 8 && ox - 1 >= 0 && ny == oy + 2 && nx == ox - 1 && cb.board[ny][nx] >= 0)
	{
		return 1;
	}
	if (oy+1<8 && ox-2>=0 && ny==oy+1 && nx==ox-2 && cb.board[ny][nx]>=0 )
	{
		return 1;
	}
	if (oy - 1 >= 0 && ox - 2 >= 0 && ny == oy - 1 && nx == ox - 2 && cb.board[ny][nx] >= 0)
	{
		return 1;
	}
	return 0;
}

int Black_horse(int ox, int oy, int nx, int ny)
{
	if (oy - 2 >= 0 && ox - 1 >= 0 && ny == oy - 2 && nx == ox - 1 && cb.board[ny][nx] <= 0)
	{
		return 1;
	}
	if (oy - 2 >= 0 && ox + 1 < 8 && ny == oy - 2 && nx == ox + 1 && cb.board[ny][nx] <= 0)
	{
		return 1;
	}
	if (oy - 1 >= 0 && ox + 2 < 8 && ny == oy - 1 && nx == ox + 2 && cb.board[ny][nx] <= 0)
	{
		return 1;
	}
	if (oy + 1 >= 0 && ox + 2 < 8 && ny == oy + 1 && nx == ox + 2 && cb.board[ny][nx] <= 0)
	{
		return 1;
	}
	if (oy + 2 < 8 && ox + 1 < 8 && ny == oy + 2 && nx == ox + 1 && cb.board[ny][nx] <= 0)
	{
		return 1;
	}
	if (oy + 2 < 8 && ox - 1 >= 0 && ny == oy + 2 && nx == ox - 1 && cb.board[ny][nx] <= 0)
	{
		return 1;
	}
	if (oy + 1 < 8 && ox - 2 >= 0 && ny == oy + 1 && nx == ox - 2 && cb.board[ny][nx] <= 0)
	{
		return 1;
	}
	if (oy - 1 >= 0 && ox - 2 >= 0 && ny == oy - 1 && nx == ox - 2 && cb.board[ny][nx] <= 0)
	{
		return 1;
	}
	return 0;
}


int White_pawn_check(int posx, int posy, int regex, int regey)
{
	//std::cout << "ox=" << posx << " oy=" << posy << " regex=" << regex << " regey=" << regey << "\n\n\n";
	if (cb.board[posy - 1][posx - 1] >= 0)
	{
		if (posy-1 == regey && posx - 1 == regex)
		{
			return 1;
		}
	}
	if (cb.board[posy - 1][posx + 1] >= 0)
	{
		if (posy - 1 == regey && posx + 1==regex)
		{
			return 1;
		}
	}
	return 0;
}

int White_rook_check(int ox, int oy, int regex, int regey)
{
	for (int i = ox - 1; i >= 0; i--) 
	{
		if (cb.board[oy][i] >= 0 && (regex== i && regey == oy))
		{
			return 1;
		}
		else if(cb.board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy - 1; i >= 0; i--)
	{
		if (cb.board[i][ox] >= 0 && (regey == i && regex == ox))
		{
			return 1;
		}
		else if(cb.board[i][ox] != 0)
		{
			break;
		}
	}
	for (int i = ox + 1; i < 8; i++)
	{
		if (cb.board[oy][i] >= 0 && (regey == oy && regex == i))
		{
			return 1;
		}
		else if(cb.board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy + 1; i < 8; i++)
	{
		if (cb.board[i][ox] >= 0 && (regey == i && regex == ox))
		{
			return 1;
		}
		else if(cb.board[i][ox] != 0)
		{
			break;
		}
	}
	return 0;
}

int Black_elephant_check(int ox, int oy, int regex, int regey)
{
	int j = ox - 1;
	for (int i = oy - 1; i >= 0; i--) 
	{
		if (cb.board[i][j] >= 0 && (regey == i && regex == j))
		{
			return 1;
		}
		else if(cb.board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy - 1; i >= 0; i--)
	{
		if (cb.board[i][j] >= 0 && (regey == i && regex == j))
		{
			return 1;
		}
		else if(cb.board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ox - 1;
	for (int i = oy + 1; i <= 7; i++)
	{
		if (cb.board[i][j] >= 0 && (regey == i && regex == j))
		{
			return 1;
		}
		else if (cb.board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy + 1; i <= 7; i++)
	{
		if (cb.board[i][j] >= 0 && (regey == i && regex == j))
		{
			return 1;
		}
		else if (cb.board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int White_queen_check(int ox, int oy, int regex, int regey)
{
	for (int i = ox - 1; i >= 0; i--)
	{
		if (cb.board[oy][i] >= 0 && (regex == i && regey == oy))
		{
			return 1;
		}
		else if(cb.board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy - 1; i >= 0; i--)
	{
		if (cb.board[i][ox] >= 0 && (regey == i && regex == ox))
		{
			return 1;
		}
		else if(cb.board[i][ox] != 0)
		{
			break;
		}
	}
	for (int i = ox + 1; i < 8; i++)
	{
		if (cb.board[oy][i] >= 0 && (regey == oy && regex == i))
		{
			return 1;
		}
		else if (cb.board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy + 1; i < 8; i++)
	{
		if (cb.board[i][ox] >= 0 && (regey == i && regex == ox))
		{
			return 1;
		}
		else if(cb.board[i][ox] != 0)
		{
			break;
		}
	}
	int j = ox - 1;
	for (int i = oy - 1; i >= 0; i--)
	{
		if (cb.board[i][j] >= 0 && (regey == i && regex == j))
		{
			return 1;
		}
		else if(cb.board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy - 1; i >= 0; i--)
	{
		if (cb.board[i][j] >= 0 && (regey == i && regex == j))
		{
			return 1;
		}
		else if (cb.board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ox - 1;
	for (int i = oy + 1; i <= 7; i++)
	{
		if (cb.board[i][j] >= 0 && (regey == i && regex == j))
		{
			return 1;
		}
		else if(cb.board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy + 1; i < 8; i++)
	{
		if (cb.board[i][j] >= 0 && (regey == i && regex == j))
		{
			return 1;
		}
		else if(cb.board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int White_elephant_check(int ox, int oy, int regex, int regey)
{
	if (oy - 2 >= 0 && ox - 1 >= 0 && regey == oy - 2 && regex == ox - 1 && cb.board[regey][regex] >= 0)
	{
		return 1;
	}
	if (oy - 2 >= 0 && ox + 1 < 8 && regey == oy - 2 && regex == ox + 1 && cb.board[regey][regex] >= 0)
	{
		return 1;
	}
	if (oy - 1 >= 0 && ox + 2 < 8 && regey == oy - 1 && regex == ox + 2 && cb.board[regey][regex] >= 0)
	{
		return 1; 
	}
	if (oy + 1 >= 0 && ox + 2 < 8 && regey == oy + 1 && regex == ox + 2 && cb.board[regey][regex] >= 0)
	{
		return 1; 
	}
	if (oy + 2 < 8 && ox + 1 < 8 && regey == oy + 2 && regex == ox + 1 && cb.board[regey][regex] >= 0)
	{
		return 1;
	}
	if (oy + 2 < 8 && ox - 1 >= 0 && regey == oy + 2 && regex == ox - 1 && cb.board[regey][regex] >= 0)
	{
		return 1;
	}
	if (oy + 1 < 8 && ox - 2 >= 0 && regey == oy + 1 && regex == ox - 2 && cb.board[regey][regex] >= 0)
	{
		return 1;
	}
	if (oy - 1 >= 0 && ox - 2 >= 0 && regey == oy - 1 && regex == ox - 2 && cb.board[regey][regex] >= 0)
	{
		return 1;
	}
	return 0;
}

int White_king_check(int ox, int oy, int regex, int regey)
{
	if (ox - 1 >= 0 && oy - 1 >= 0 && regey == oy - 1 && regex == ox - 1 && cb.board[regey][regex] <= 0)
	{
		return 1;
	}
	if (oy - 1 >= 0 && regex == ox && regey == oy - 1 && cb.board[regey][regex] <= 0)
	{
		return 1;
	}
	if (oy - 1 >= 0 && ox + 1 < 8 && regex == ox + 1 && regey == oy - 1 && cb.board[regey][regex] <= 0)
	{
		return 1;
	}
	if (ox + 1 < 8 && regey == oy && regex == ox + 1 && cb.board[regey][regex] <= 0)
	{
		return 1;
	}
	if (ox + 1 < 8 && oy + 1 < 8 && regey == oy + 1 && regex == ox + 1 && cb.board[regey][regex] <= 0)
	{
		return 1;
	}
	if (oy + 1 < 8 && regey == oy + 1 && regex == ox && cb.board[regey][regex] <= 0)
	{
		return 1;
	}
	if (ox - 1 >= 0 && oy + 1 < 8 && regex == ox - 1 && regey == oy + 1 && cb.board[regey][regex] <= 0)
	{
		return 1;
	}
	if (ox - 1 >= 0 && regey == oy && regex == ox - 1 && cb.board[regey][regex] <= 0)
	{
		return 1;
	}
	return 0;
}


int Black_pawn_check(int ox, int oy, int regex, int regey)
{
	if (cb.board[oy + 1][ox - 1] <= 0)
	{
		if (regey == oy + 1 && regex == ox - 1)
		{
			return 1;
		}
	}
	if (cb.board[oy + 1][ox + 1] <= 0)
	{
		if (regey == oy + 1 && regex == ox + 1)
		{
			return 1;
		}
	}
	return 0;
}

int TurnNSah(int ox, int oy, int regex, int regey)
{
	for (int i = ox - 1; i >= 0; i--)
	{
		if (cb.board[oy][i] <= 0 && (regex == i && regey == oy))
		{
			return 1;
		}
		else if (cb.board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy - 1; i >= 0; i--)
	{
		if (cb.board[i][ox] <= 0 && (regey == i && regex == ox))
		{
			return 1;
		}
		else if (cb.board[i][ox] != 0)
		{
			break;
		}
	}
	for (int i = ox + 1; i < 8; i++)
	{
		if (cb.board[oy][i] <= 0 && (regey == oy && regex == i))
		{
			return 1;
		}
		else if (cb.board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy + 1; i < 8; i++)
	{
		if (cb.board[i][ox] <= 0 && (regey == i && regex == ox))
		{
			return 1;
		}
		else if (cb.board[i][ox] != 0)
		{
			break;
		}
	}
	return 0;
}

int NebunNSah(int ox, int oy, int regex, int regey)
{
	int j = ox - 1;
	for (int i = oy - 1; i >= 0; i--)
	{
		if (cb.board[i][j] <= 0 && (regey == i && regex == j))
		{
			return 1;
		}
		else if (cb.board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy - 1; i >= 0; i--)
	{
		if (cb.board[i][j] <= 0 && (regey == i && regex == j))
		{
			return 1;
		}
		else if (cb.board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ox - 1;
	for (int i = oy + 1; i <= 7; i++)
	{
		if (cb.board[i][j] <= 0 && (regey == i && regex == j))
		{
			return 1;
		}
		else if (cb.board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy + 1; i <= 7; i++)
	{
		if (cb.board[i][j] <= 0 && (regey == i && regex == j))
		{
			return 1;
		}
		else if (cb.board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int Black_queen_check(int ox, int oy, int regex, int regey)
{
	for (int i = ox - 1; i >= 0; i--)
	{
		if (cb.board[oy][i] <= 0 && (regex == i && regey == oy))
		{
			return 1;
		}
		else if (cb.board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy - 1; i >= 0; i--)
	{
		if (cb.board[i][ox] <= 0 && (regey == i && regex == ox))
		{
			return 1;
		}
		else if (cb.board[i][ox] != 0)
		{
			break;
		}
	}
	for (int i = ox + 1; i < 8; i++)
	{
		if (cb.board[oy][i] <= 0 && (regey == oy && regex == i))
		{
			return 1;
		}
		else if (cb.board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy + 1; i < 8; i++) 
	{
		if (cb.board[i][ox] <= 0 && (regey == i && regex == ox))
		{
			return 1;
		}
		else if (cb.board[i][ox] != 0)
		{
			break;
		}
	}
	int j = ox - 1;
	for (int i = oy - 1; i >= 0; i--)
	{
		if (cb.board[i][j] <= 0 && (regey == i && regex == j))
		{
			return 1;
		}
		else if (cb.board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy - 1; i >= 0; i--)
	{
		if (cb.board[i][j] <= 0 && (regey == i && regex == j))
		{
			return 1;
		}
		else if (cb.board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ox - 1;
	for (int i = oy + 1; i <= 7; i++) 
	{
		if (cb.board[i][j] <= 0 && (regey == i && regex == j))
		{
			return 1;
		}
		else if (cb.board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy + 1; i < 8; i++)
	{
		if (cb.board[i][j] <= 0 && (regey == i && regex == j))
		{
			return 1;
		}
		else if (cb.board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int Black_horse_check(int ox, int oy, int regex, int regey)
{
	if (oy - 2 >= 0 && ox - 1 >= 0 && regey == oy - 2 && regex == ox - 1 && cb.board[regey][regex] <= 0)
	{
		return 1; // stanga sus
	}
	if (oy - 2 >= 0 && ox + 1 < 8 && regey == oy - 2 && regex == ox + 1 && cb.board[regey][regex] <= 0)
	{
		return 1; 
	}
	if (oy - 1 >= 0 && ox + 2 < 8 && regey == oy - 1 && regex == ox + 2 && cb.board[regey][regex] <= 0)
	{
		return 1; 
	}
	if (oy + 1 >= 0 && ox + 2 < 8 && regey == oy + 1 && regex == ox + 2 && cb.board[regey][regex] <= 0)
	{
		return 1; 
	}
	if (oy + 2 < 8 && ox + 1 < 8 && regey == oy + 2 && regex == ox + 1 && cb.board[regey][regex] <= 0)
	{
		return 1; 
	}
	if (oy + 2 < 8 && ox - 1 >= 0 && regey == oy + 2 && regex == ox - 1 && cb.board[regey][regex] <= 0)
	{
		return 1; 
	}
	if (oy + 1 < 8 && ox - 2 >= 0 && regey == oy + 1 && regex == ox - 2 && cb.board[regey][regex] <= 0)
	{
		return 1; 
	}
	if (oy - 1 >= 0 && ox - 2 >= 0 && regey == oy - 1 && regex == ox - 2 && cb.board[regey][regex] <= 0)
	{
		return 1;
	}
	return 0;
}

int Black_King_check(int ox, int oy, int regex, int regey)
{
	if (ox - 1 >= 0 && oy - 1 >= 0 && regey == oy - 1 && regex == ox - 1 && cb.board[regey][regex] >= 0)
	{
		return 1;
	}
	if (oy - 1 >= 0 && regex == ox && regey == oy - 1 && cb.board[regey][regex] >= 0)
	{
		return 1;
	}
	if (oy - 1 >= 0 && ox + 1 < 8 && regex == ox + 1 && regey == oy - 1 && cb.board[regey][regex] >= 0)
	{
		return 1;
	}
	if (ox + 1 < 8 && regey == oy && regex == ox + 1 && cb.board[regey][regex] >= 0)
	{
		return 1;
	}
	if (ox + 1 < 8 && oy + 1 < 8 && regey == oy + 1 && regex == ox + 1 && cb.board[regey][regex] >= 0)
	{
		return 1;
	}
	if (oy + 1 < 8 && regey == oy + 1 && regex == ox && cb.board[regey][regex] >= 0)
	{
		return 1;
	}
	if (ox - 1 >= 0 && oy + 1 < 8 && regex == ox - 1 && regey == oy + 1 && cb.board[regey][regex] >= 0)
	{
		return 1;
	}
	if (ox - 1 >= 0 && regey == oy && regex == ox - 1 && cb.board[regey][regex] >= 0)
	{
		return 1;
	}
	return 0;
}



int Black_king_SahCheck(int posRegex, int posRegey)
{
	int ok = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (cb.board[i][j] < 0)
			{
				if (cb.board[i][j] == -1)
				{
					ok=White_pawn_check(j, i, posRegex, posRegey);
				}
				if (cb.board[i][j] == -2)
				{
					ok=White_rook_check(j, i, posRegex, posRegey);
				}
				if (cb.board[i][j] == -3)
				{
					ok=White_rook_check(j, i, posRegex, posRegey);
				}
				if (cb.board[i][j] == -4)
				{
					ok=White_elephant_check(j, i, posRegex, posRegey);
				}
				if (cb.board[i][j] == -5)
				{
					ok=White_queen_check(j, i, posRegex, posRegey);
				}
				if (cb.board[i][j] == -6)
				{
					ok=White_king_check(j, i, posRegex, posRegey);
				}
				if (ok == 1)
				{
					return 0;
				}
			}
		}
	}
	return 1;
}

int RegeN(int ox, int oy, int nx, int ny)
{
	if (ox - 1 >= 0 && oy - 1 >= 0 && ny == oy - 1 && nx == ox - 1 && cb.board[ny][nx] <= 0)
	{
		int ok = Black_king_SahCheck(ox - 1, oy - 1);
		if (ok == 1)
		{
			return 1; 
		}
	}
	if (oy - 1 >= 0 && nx == ox && ny == oy-1 && cb.board[ny][nx] <= 0)
	{
		int ok = Black_king_SahCheck(ox, oy-1);
		if (ok == 1)
		{
			return 1;
		}
	}
	if (oy - 1 >= 0 && ox + 1 < 8 && nx == ox + 1 && ny == oy - 1 && cb.board[ny][nx] <= 0)
	{
		int ok = Black_king_SahCheck(ox+ 1, oy- 1);
		if (ok == 1)
		{
			return 1; 
		}
	}
	if (ox + 1 < 8 && ny == oy && nx == ox+1 && cb.board[ny][nx] <= 0)
	{
		int ok = Black_king_SahCheck(ox+1, oy);
		if (ok == 1)
		{
			return 1;
		}
	}
	if (ox + 1 < 8 && oy + 1 < 8 && ny == oy + 1 && nx == ox + 1 && cb.board[ny][nx] <= 0)
	{
		int ok = Black_king_SahCheck(ox + 1, oy + 1);
		if (ok == 1)
		{
			return 1; 
		}
	}
	if (oy + 1 < 8 && ny == oy+1 && nx == ox && cb.board[ny][nx] <= 0)
	{
		int ok = Black_king_SahCheck(ox, oy+1);
		if (ok == 1)
		{
			return 1; 
		}
	}
	if (ox - 1 >=0 && oy + 1 <8 && nx == ox - 1 && ny == oy + 1 && cb.board[ny][nx] <= 0)
	{
		int ok = Black_king_SahCheck(ox-1, oy+ 1);
		if (ok == 1)
		{
			return 1; 
		}
	}
	if (ox - 1 >= 0 && ny == oy && nx == ox-1 && cb.board[ny][nx] <= 0)
	{
		int ok = Black_king_SahCheck(ox-1, oy);
		if (ok == 1)
		{
			return 1;
		}
	}
	if (turnNegruDreapta==0 && regeNegru==0 && cb.board[0][5]==0 && cb.board[0][6]==0 && ny==0 && nx==6)
	{
		int ok = Black_king_SahCheck(4, 0);
		if (ok == 1)
		{
			ok = Black_king_SahCheck(5, 0);
			if (ok == 1)
			{
				ok = Black_king_SahCheck(6, 0);
				if (ok == 1)
				{
					regeNegru = 1;
					turnNegruDreapta = 1;
					cb.board[0][7] = 0;
					cb.board[0][5] = 2;
					return 1;
				}
			}
		}
	}
	if (turnNegruStanga == 0 && regeNegru == 0 && cb.board[0][3] == 0 && cb.board[0][2] == 0 && cb.board[0][1] == 0 && ny == 0 && nx == 2)
	{
		int ok = (4, 0);
		if (ok == 1)
		{
			ok = Black_king_SahCheck(3, 0);
			if (ok == 1)
			{
				ok = Black_king_SahCheck(2, 0);
				if (ok == 1)
				{
					ok = Black_king_SahCheck(1, 0);
					if (ok == 1)
					{
						regeNegru = 1;
						turnNegruStanga = 1;
						cb.board[0][0] = 0;
						cb.board[0][3] = 2;
						return 1;
					}
				}
			}
		}
	}
	return 0;
}


int RegeAlbSahCheck(int posRegex, int posRegey)
{
	int ok = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (cb.board[i][j] > 0)
			{
				if (cb.board[i][j] == 1)
				{
					ok = Black_pawn_check(j, i, posRegex, posRegey);
				}
				if (cb.board[i][j] == 2)
				{
					ok = TurnNSah(j, i, posRegex, posRegey);
				}
				if (cb.board[i][j] == 3)
				{
					ok = Black_horse_check(j, i, posRegex, posRegey);
				}
				if (cb.board[i][j] == 4)
				{
					ok = NebunNSah(j, i, posRegex, posRegey);
				}
				if (cb.board[i][j] == 5)
				{
					ok = Black_queen_check(j, i, posRegex, posRegey);
				}
				if (cb.board[i][j] == 6)
				{
					ok=Black_King_check(j, i, posRegex, posRegey);
				}
				if (ok == 1)
				{
					return 0;
				}
			}
		}
	}
	return 1;
}

int RegeA(int ox, int oy, int nx, int ny)
{
	if (ox - 1 >= 0 && oy - 1 >= 0 && ny == oy - 1 && nx == ox - 1 && cb.board[ny][nx] >= 0)
	{
		int ok = RegeAlbSahCheck(ox - 1, oy - 1);
		if (ok == 1)
		{
			return 1;  
		}
	}
	if (oy - 1 >= 0 && nx == ox && ny == oy - 1 && cb.board[ny][nx] >= 0)
	{
		int ok = RegeAlbSahCheck(ox, oy - 1);
		if (ok == 1)
		{
			return 1; 
		}
	}
	if (oy - 1 >= 0 && ox + 1 < 8 && nx == ox + 1 && ny == oy - 1 && cb.board[ny][nx] >= 0)
	{
		int ok = RegeAlbSahCheck(ox + 1, oy - 1);
		if (ok == 1)
		{
			return 1; 
		}
	}
	if (ox + 1 < 8 && ny == oy && nx == ox + 1 && cb.board[ny][nx] >= 0)
	{
		int ok = RegeAlbSahCheck(ox + 1, oy);
		if (ok == 1)
		{
			return 1; 
		}
	}
	if (ox + 1 < 8 && oy + 1 < 8 && ny == oy + 1 && nx == ox + 1 && cb.board[ny][nx] >= 0)
	{
		int ok = RegeAlbSahCheck(ox + 1, oy + 1);
		if (ok == 1)
		{
			return 1; 
		}
	}
	if (oy + 1 < 8 && ny == oy + 1 && nx == ox && cb.board[ny][nx] >= 0)
	{
		int ok = RegeAlbSahCheck(ox, oy + 1);
		if (ok == 1)
		{
			return 1; 
		}
	}
	if (ox - 1 >= 0 && oy + 1 < 8 && nx == ox - 1 && ny == oy + 1 && cb.board[ny][nx] >= 0)
	{
		int ok = RegeAlbSahCheck(ox - 1, oy + 1);
		if (ok == 1)
		{
			return 1; 
		}
	}
	if (ox - 1 >= 0 && ny == oy && nx == ox - 1 && cb.board[ny][nx] >= 0)
	{
		int ok = RegeAlbSahCheck(ox - 1, oy);
		if (ok == 1)
		{
			return 1; 
		}
	}
	
	if (regeAlb == 0 && turnAlbDreapta == 0 && cb.board[7][5] == 0 && cb.board[7][6] == 0 && ny==7 && nx==6)
	{
		int ok = 1;
		ok = RegeAlbSahCheck(4, 7);
		if (ok == 1)
		{
			ok = RegeAlbSahCheck(5, 7);
			if (ok == 1)
			{
				ok = RegeAlbSahCheck(6, 7);
				if (ok == 1)
				{
					cb.board[7][7] = 0;
					cb.board[7][5] = -2;
					regeAlb = 1;
					turnAlbDreapta = 1;
					return 1;
				}
			}
		}
	}
	// rocada in stanga
	if (regeAlb == 0 && turnAlbDreapta == 0 && cb.board[7][3] == 0 && cb.board[7][2] == 0 && cb.board[7][1] == 0 && ny == 7 && nx == 2)
	{
		int ok = 1;
		ok = RegeAlbSahCheck(4, 7);
		if (ok == 1)
		{
			ok = RegeAlbSahCheck(3, 7);
			if (ok == 1)
			{
				ok = RegeAlbSahCheck(2, 7);
				if (ok == 1)
				{
					ok = RegeAlbSahCheck(1, 7);
					if (ok == 1)
					{
						cb.board[7][0] = 0;
						cb.board[7][3] = -2;
						regeAlb = 1;
						turnAlbStanga = 1;
						return 1;
					}
				}
			}
		}
	}
	return 0;
}


void pozRegeAlb()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (cb.board[i][j] == -6)
			{
				regeleAlb.x = j;
				regeleAlb.y = i;
				break;
			}
		}
	}
}

void pozRegeNegru()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (cb.board[i][j] == 6)
			{
				regeleNegru.y = i;
				regeleNegru.x = j;
				break;
			}
		}
	}
}



