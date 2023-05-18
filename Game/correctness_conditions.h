#include "chessboard.h"


chessboard cb;

int chessboard::WhitePawn(int ox, int oy, int nx, int ny)
{
	if (oldPos.y == 6)
	{
		if ((ny == oy - 1 && nx == ox && this->board[oy-1][ox]==0)||(ny==oy-2 && nx==ox && this->board[oy - 1][ox] == 0 && this->board[oy - 2][ox]==0))
		{
			return 1;
		}
	}
	else if(ny == oy - 1 && nx == ox && this->board[oy - 1][ox] == 0)
	{
		return 1;
	}
	if (this->board[oy - 1][ox - 1] > 0)
	{
		if (ny == oy - 1 && nx == ox - 1)
		{
			return 1;
		}
	}
	if (this->board[oy - 1][ox + 1] > 0)
	{
		if (ny == oy - 1 && nx == ox + 1)
		{
			return 1;
		}
	}
	return 0;
}

int chessboard::BlackPawn(int ox, int oy, int nx, int ny)
{
	if (oldPos.y == 1)
	{
		if ((ny == oy + 1 && nx == ox && this->board[oy+1][ox]==0) || (ny == oy + 2 && nx == ox && this->board[oy + 1][ox] == 0 && this->board[oy + 2][ox] == 0))
		{
			return 1;
		}
	}
	else if (ny == oy + 1 && nx == ox && this->board[oy + 1][ox] == 0)
	{
		return 1;
	}
	if (this->board[oy + 1][ox - 1] < 0)
	{
		if (ny == oy + 1 && nx == ox - 1)
		{
			return 1;
		}
	}
	if (this->board[oy + 1][ox + 1] < 0)
	{
		if (ny == oy + 1 && nx == ox + 1)
		{
			return 1;
		}
	}
	return 0;
}

int chessboard::White_move(int ox, int oy, int nx, int ny)
{
	for (int i = ox-1; i >= 0; i--)
	{
		if (this->board[oy][i] >= 0 && (nx == i && ny == oy))
		{
			return 1;
		}
		else if (this->board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy - 1; i >= 0; i--)
	{
		if (this->board[i][ox] >= 0 && (ny == i && nx == ox))
		{
			return 1;
		}
		else if (this->board[i][ox] != 0 )
		{
			break;
		}
	}
	for (int i = ox + 1; i <= 7; i++)
	{
		if (this->board[oy][i]>=0 && (ny == oy && nx == i))
		{
			return 1;
		}
		else if (this->board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy + 1; i <= 7; i++)
	{
		if (this->board[i][ox]>=0 && (ny == i && nx == ox))
		{
			return 1;
		}
		else if (this->board[i][ox] != 0)
		{
			break;
		}
	}
	return 0;
}

int chessboard::Black_move(int ox, int oy, int nx, int ny)
{
	for (int i = ox - 1; i >= 0; i--)
	{
		if (this->board[oy][i] <= 0 && (nx == i && ny == oy))
		{
			return 1;
		}
		else if (this->board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy - 1; i >= 0; i--)
	{
		if (this->board[i][ox] <= 0 && (ny == i && nx == ox))
		{
			return 1;
		}
		else if (this->board[i][ox] != 0)
		{
			break;
		}
	}
	for (int i = ox + 1; i <= 7; i++)
	{
		if (this->board[oy][i] <= 0 && (ny == oy && nx == i))
		{
			return 1;
		}
		else if (this->board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy + 1; i <= 7; i++)
	{
		if (this->board[i][ox] <= 0 && (ny == i && nx == ox))
		{
			return 1;
		}
		else if (this->board[i][ox] != 0)
		{
			break;
		}
	}
	return 0;
}

int chessboard::White_elephant(int ox, int oy, int nx, int ny)
{
	int j = ox - 1;
	for (int i = oy - 1; i >= 0; i--)
	{
		if (this->board[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (this->board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy - 1; i >= 0; i--)
	{
		if (this->board[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (this->board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ox - 1;
	for (int i = oy + 1; i <= 7; i++) 
	{
		if (this->board[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (this->board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy + 1; i <= 7; i++)
	{
		if (this->board[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (this->board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int chessboard::Black_elephant(int ox, int oy, int nx, int ny)
{
	int j = ox - 1;
	for (int i = oy - 1; i >= 0; i--) // spre st sus
	{
		if (this->board[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (this->board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy - 1; i >= 0; i--) // spre d sus
	{
		if (this->board[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (this->board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ox - 1;
	for (int i = oy + 1; i <= 7; i++) // spre st jos
	{
		if (this->board[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (this->board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy + 1; i <= 7; i++)  // spre d jos
	{
		if (this->board[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (this->board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int chessboard::White_queen(int ox, int oy, int nx, int ny)
{
	for (int i = ox - 1; i >= 0; i--) // spre st
	{
		if (this->board[oy][i] >= 0 && (nx == i && ny == oy))
		{
			return 1;
		}
		else if (this->board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy - 1; i >= 0; i--) // sus
	{
		if (this->board[i][ox] >= 0 && (ny == i && nx == ox))
		{
			return 1;
		}
		else if (this->board[i][ox] != 0)
		{
			break;
		}
	}
	for (int i = ox + 1; i <= 7; i++) // spre d
	{
		if (this->board[oy][i] >= 0 && (ny == oy && nx == i))
		{
			return 1;
		}
		else if (this->board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy + 1; i <= 7; i++) // jos
	{
		if (this->board[i][ox] >= 0 && (ny == i && nx == ox))
		{
			return 1;
		}
		else if (this->board[i][ox] != 0)
		{
			break;
		}
	}
	int j = ox - 1;
	for (int i = oy - 1; i >= 0; i--) // spre st sus
	{
		if (this->board[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (this->board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy - 1; i >= 0; i--){
		if (this->board[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (this->board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ox - 1;

	for (int i = oy + 1; i <= 7; i++)
	{
		if (this->board[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (this->board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy + 1; i <= 7; i++)  
	{
		if (this->board[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (this->board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int chessboard::Black_queen(int ox, int oy, int nx, int ny)
{
	for (int i = ox - 1; i >= 0; i--)
	{
		if (this->board[oy][i] <= 0 && (nx == i && ny == oy))
		{
			return 1;
		}
		else if (this->board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy - 1; i >= 0; i--)
	{
		if (this->board[i][ox] <= 0 && (ny == i && nx == ox))
		{
			return 1;
		}
		else if (this->board[i][ox] != 0)
		{
			break;
		}
	}
	for (int i = ox + 1; i <= 7; i++)
	{
		if (this->board[oy][i] <= 0 && (ny == oy && nx == i))
		{
			return 1;
		}
		else if (this->board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy + 1; i <= 7; i++)
	{
		if (this->board[i][ox] <= 0 && (ny == i && nx == ox))
		{
			return 1;
		}
		else if (this->board[i][ox] != 0)
		{
			break;
		}
	}
	int j = ox - 1;
	for (int i = oy - 1; i >= 0; i--)
	{
		if (this->board[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (this->board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy - 1; i >= 0; i--)
	{
		if (this->board[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (this->board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ox - 1;
	for (int i = oy + 1; i <= 7; i++)
	{
		if (this->board[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (this->board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy + 1; i <= 7; i++)
	{
		if (this->board[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (this->board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int chessboard::White_horse(int ox, int oy, int nx, int ny)
{
	if (oy - 2 >= 0 && ox - 1 >= 0 && ny == oy - 2 && nx == ox - 1 && this->board[ny][nx] >= 0)
	{
		return 1;
	}
	if (oy - 2 >= 0 && ox + 1 <8 && ny == oy - 2 && nx == ox + 1 && this->board[ny][nx] >= 0)
	{
		return 1;
	}
	if (oy - 1 >= 0 && ox + 2 < 8 && ny==oy-1 && nx==ox+2 && this->board[ny][nx]>=0)
	{
		return 1;
	}
	if (oy + 1 >= 0 && ox + 2 < 8 && ny == oy + 1 && nx == ox + 2 && this->board[ny][nx] >= 0)
	{
		return 1;
	}
	if (oy+2<8 && ox+1<8 && ny==oy+2 && nx==ox+1 && this->board[ny][nx]>=0)
	{
		return 1;
	}
	if (oy + 2 < 8 && ox - 1 >= 0 && ny == oy + 2 && nx == ox - 1 && this->board[ny][nx] >= 0)
	{
		return 1;
	}
	if (oy+1<8 && ox-2>=0 && ny==oy+1 && nx==ox-2 && this->board[ny][nx]>=0 )
	{
		return 1;
	}
	if (oy - 1 >= 0 && ox - 2 >= 0 && ny == oy - 1 && nx == ox - 2 && this->board[ny][nx] >= 0)
	{
		return 1;
	}
	return 0;
}

int chessboard::Black_horse(int ox, int oy, int nx, int ny)
{
	if (oy - 2 >= 0 && ox - 1 >= 0 && ny == oy - 2 && nx == ox - 1 && this->board[ny][nx] <= 0)
	{
		return 1;
	}
	if (oy - 2 >= 0 && ox + 1 <8 && ny == oy - 2 && nx == ox + 1 && this->board[ny][nx] <= 0)
	{
		return 1;
	}
	if (oy - 1 >= 0 && ox + 2 < 8 && ny==oy-1 && nx==ox+2 && this->board[ny][nx] <= 0)
	{
		return 1;
	}
	if (oy + 1 >= 0 && ox + 2 < 8 && ny == oy + 1 && nx == ox + 2 && this->board[ny][nx] <= 0)
	{
		return 1;
	}
	if (oy+2<8 && ox+1<8 && ny==oy+2 && nx==ox+1 && this->board[ny][nx] <= 0)
	{
		return 1;
	}
	if (oy + 2 < 8 && ox - 1 >= 0 && ny == oy + 2 && nx == ox - 1 && this->board[ny][nx] <= 0)
	{
		return 1;
	}
	if (oy+1<8 && ox-2>=0 && ny==oy+1 && nx==ox-2 && this->board[ny][nx]<=0 )
	{
		return 1;
	}
	if (oy - 1 >= 0 && ox - 2 >= 0 && ny == oy - 1 && nx == ox - 2 && this->board[ny][nx] <= 0)
	{
		return 1;
	}
	return 0;
}


int chessboard::White_pawn_check(int posx, int posy, int destx, int desty)
{
	//std::cout << "ox=" << posx << " oy=" << posy << " destx=" << destx << " desty=" << desty << "\n\n\n";
	if (this->board[posy - 1][posx - 1] >= 0)
	{
		if (posy-1 == desty && posx - 1 == destx)
		{
			return 1;
		}
	}
	if (this->board[posy - 1][posx + 1] >= 0)
	{
		if (posy - 1 == desty && posx + 1==destx)
		{
			return 1;
		}
	}
	return 0;
}

int chessboard::White_rook_check(int ox, int oy, int destx, int desty)
{
	for (int i = ox - 1; i >= 0; i--) 
	{
		if (this->board[oy][i] >= 0 && (destx== i && desty == oy))
		{
			return 1;
		}
		else if(this->board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy - 1; i >= 0; i--)
	{
		if (this->board[i][ox] >= 0 && (desty == i && destx == ox))
		{
			return 1;
		}
		else if(this->board[i][ox] != 0)
		{
			break;
		}
	}
	for (int i = ox + 1; i < 8; i++)
	{
		if (this->board[oy][i] >= 0 && (desty == oy && destx == i))
		{
			return 1;
		}
		else if(this->board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy + 1; i < 8; i++)
	{
		if (this->board[i][ox] >= 0 && (desty == i && destx == ox))
		{
			return 1;
		}
		else if(this->board[i][ox] != 0)
		{
			break;
		}
	}
	return 0;
}

int chessboard::Black_elephant_check(int ox, int oy, int destx, int desty)
{
	int j = ox - 1;
	for (int i = oy - 1; i >= 0; i--) 
	{
		if (this->board[i][j] >= 0 && (desty == i && destx == j))
		{
			return 1;
		}
		else if(this->board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy - 1; i >= 0; i--)
	{
		if (this->board[i][j] >= 0 && (desty == i && destx == j))
		{
			return 1;
		}
		else if(this->board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ox - 1;
	for (int i = oy + 1; i <= 7; i++)
	{
		if (this->board[i][j] >= 0 && (desty == i && destx == j))
		{
			return 1;
		}
		else if (this->board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy + 1; i <= 7; i++)
	{
		if (this->board[i][j] >= 0 && (desty == i && destx == j))
		{
			return 1;
		}
		else if (this->board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int chessboard::White_queen_check(int ox, int oy, int destx, int desty)
{
	for (int i = ox - 1; i >= 0; i--)
	{
		if (this->board[oy][i] >= 0 && (destx == i && desty == oy))
		{
			return 1;
		}
		else if(this->board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy - 1; i >= 0; i--)
	{
		if (this->board[i][ox] >= 0 && (desty == i && destx == ox))
		{
			return 1;
		}
		else if(this->board[i][ox] != 0)
		{
			break;
		}
	}
	for (int i = ox + 1; i < 8; i++)
	{
		if (this->board[oy][i] >= 0 && (desty == oy && destx == i))
		{
			return 1;
		}
		else if (this->board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy + 1; i < 8; i++)
	{
		if (this->board[i][ox] >= 0 && (desty == i && destx == ox))
		{
			return 1;
		}
		else if(this->board[i][ox] != 0)
		{
			break;
		}
	}
	int j = ox - 1;
	for (int i = oy - 1; i >= 0; i--)
	{
		if (this->board[i][j] >= 0 && (desty == i && destx == j))
		{
			return 1;
		}
		else if(this->board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy - 1; i >= 0; i--)
	{
		if (this->board[i][j] >= 0 && (desty == i && destx == j))
		{
			return 1;
		}
		else if (this->board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ox - 1;
	for (int i = oy + 1; i <= 7; i++)
	{
		if (this->board[i][j] >= 0 && (desty == i && destx == j))
		{
			return 1;
		}
		else if(this->board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy + 1; i < 8; i++)
	{
		if (this->board[i][j] >= 0 && (desty == i && destx == j))
		{
			return 1;
		}
		else if(this->board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int chessboard::White_elephant_check(int ox, int oy, int destx, int desty)
{
	if (oy - 2 >= 0 && ox - 1 >= 0 && desty == oy - 2 && destx == ox - 1 && this->board[desty][destx] >= 0)
	{
		return 1;
	}
	if (oy - 2 >= 0 && ox + 1 < 8 && desty == oy - 2 && destx == ox + 1 && this->board[desty][destx] >= 0)
	{
		return 1;
	}
	if (oy - 1 >= 0 && ox + 2 < 8 && desty == oy - 1 && destx == ox + 2 && this->board[desty][destx] >= 0)
	{
		return 1; 
	}
	if (oy + 1 >= 0 && ox + 2 < 8 && desty == oy + 1 && destx == ox + 2 && this->board[desty][destx] >= 0)
	{
		return 1; 
	}
	if (oy + 2 < 8 && ox + 1 < 8 && desty == oy + 2 && destx == ox + 1 && this->board[desty][destx] >= 0)
	{
		return 1;
	}
	if (oy + 2 < 8 && ox - 1 >= 0 && desty == oy + 2 && destx == ox - 1 && this->board[desty][destx] >= 0)
	{
		return 1;
	}
	if (oy + 1 < 8 && ox - 2 >= 0 && desty == oy + 1 && destx == ox - 2 && this->board[desty][destx] >= 0)
	{
		return 1;
	}
	if (oy - 1 >= 0 && ox - 2 >= 0 && desty == oy - 1 && destx == ox - 2 && this->board[desty][destx] >= 0)
	{
		return 1;
	}
	return 0;
}

int chessboard::White_king_check(int ox, int oy, int destx, int desty)
{
	if (ox - 1 >= 0 && oy - 1 >= 0 && desty == oy - 1 && destx == ox - 1 && this->board[desty][destx] <= 0)
	{
		return 1;
	}
	if (oy - 1 >= 0 && destx == ox && desty == oy - 1 && this->board[desty][destx] <= 0)
	{
		return 1;
	}
	if (oy - 1 >= 0 && ox + 1 < 8 && destx == ox + 1 && desty == oy - 1 && this->board[desty][destx] <= 0)
	{
		return 1;
	}
	if (ox + 1 < 8 && desty == oy && destx == ox + 1 && this->board[desty][destx] <= 0)
	{
		return 1;
	}
	if (ox + 1 < 8 && oy + 1 < 8 && desty == oy + 1 && destx == ox + 1 && this->board[desty][destx] <= 0)
	{
		return 1;
	}
	if (oy + 1 < 8 && desty == oy + 1 && destx == ox && this->board[desty][destx] <= 0)
	{
		return 1;
	}
	if (ox - 1 >= 0 && oy + 1 < 8 && destx == ox - 1 && desty == oy + 1 && this->board[desty][destx] <= 0)
	{
		return 1;
	}
	if (ox - 1 >= 0 && desty == oy && destx == ox - 1 && this->board[desty][destx] <= 0)
	{
		return 1;
	}
	return 0;
}


int chessboard::Black_pawn_check(int ox, int oy, int destx, int desty)
{
	if (this->board[oy + 1][ox - 1] <= 0)
	{
		if (desty == oy + 1 && destx == ox - 1)
		{
			return 1;
		}
	}
	if (this->board[oy + 1][ox + 1] <= 0)
	{
		if (desty == oy + 1 && destx == ox + 1)
		{
			return 1;
		}
	}
	return 0;
}

int chessboard::Black_RookShah(int ox, int oy, int destx, int desty)
{
	for (int i = ox - 1; i >= 0; i--)
	{
		if (this->board[oy][i] <= 0 && (destx == i && desty == oy))
		{
			return 1;
		}
		else if (this->board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy - 1; i >= 0; i--)
	{
		if (this->board[i][ox] <= 0 && (desty == i && destx == ox))
		{
			return 1;
		}
		else if (this->board[i][ox] != 0)
		{
			break;
		}
	}
	for (int i = ox + 1; i < 8; i++)
	{
		if (this->board[oy][i] <= 0 && (desty == oy && destx == i))
		{
			return 1;
		}
		else if (this->board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy + 1; i < 8; i++)
	{
		if (this->board[i][ox] <= 0 && (desty == i && destx == ox))
		{
			return 1;
		}
		else if (this->board[i][ox] != 0)
		{
			break;
		}
	}
	return 0;
}

int chessboard::Black_ElephantShah(int ox, int oy, int destx, int desty)
{
	int j = ox - 1;
	for (int i = oy - 1; i >= 0; i--)
	{
		if (this->board[i][j] <= 0 && (desty == i && destx == j))
		{
			return 1;
		}
		else if (this->board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy - 1; i >= 0; i--)
	{
		if (this->board[i][j] <= 0 && (desty == i && destx == j))
		{
			return 1;
		}
		else if (this->board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ox - 1;
	for (int i = oy + 1; i <= 7; i++)
	{
		if (this->board[i][j] <= 0 && (desty == i && destx == j))
		{
			return 1;
		}
		else if (this->board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy + 1; i <= 7; i++)
	{
		if (this->board[i][j] <= 0 && (desty == i && destx == j))
		{
			return 1;
		}
		else if (this->board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int chessboard::Black_queen_check(int ox, int oy, int destx, int desty)
{
	for (int i = ox - 1; i >= 0; i--)
	{
		if (this->board[oy][i] <= 0 && (destx == i && desty == oy))
		{
			return 1;
		}
		else if (this->board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy - 1; i >= 0; i--)
	{
		if (this->board[i][ox] <= 0 && (desty == i && destx == ox))
		{
			return 1;
		}
		else if (this->board[i][ox] != 0)
		{
			break;
		}
	}
	for (int i = ox + 1; i < 8; i++)
	{
		if (this->board[oy][i] <= 0 && (desty == oy && destx == i))
		{
			return 1;
		}
		else if (this->board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy + 1; i < 8; i++) 
	{
		if (this->board[i][ox] <= 0 && (desty == i && destx == ox))
		{
			return 1;
		}
		else if (this->board[i][ox] != 0)
		{
			break;
		}
	}
	int j = ox - 1;
	for (int i = oy - 1; i >= 0; i--)
	{
		if (this->board[i][j] <= 0 && (desty == i && destx == j))
		{
			return 1;
		}
		else if (this->board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy - 1; i >= 0; i--)
	{
		if (this->board[i][j] <= 0 && (desty == i && destx == j))
		{
			return 1;
		}
		else if (this->board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ox - 1;
	for (int i = oy + 1; i <= 7; i++) 
	{
		if (this->board[i][j] <= 0 && (desty == i && destx == j))
		{
			return 1;
		}
		else if (this->board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy + 1; i < 8; i++)
	{
		if (this->board[i][j] <= 0 && (desty == i && destx == j))
		{
			return 1;
		}
		else if (this->board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int chessboard::Black_horse_check(int ox, int oy, int destx, int desty)
{
	if (oy - 2 >= 0 && ox - 1 >= 0 && desty == oy - 2 && destx == ox - 1 && this->board[desty][destx] <= 0)
	{
		return 1; // st sus
	}
	if (oy - 2 >= 0 && ox + 1 < 8 && desty == oy - 2 && destx == ox + 1 && this->board[desty][destx] <= 0)
	{
		return 1; 
	}
	if (oy - 1 >= 0 && ox + 2 < 8 && desty == oy - 1 && destx == ox + 2 && this->board[desty][destx] <= 0)
	{
		return 1; 
	}
	if (oy + 1 >= 0 && ox + 2 < 8 && desty == oy + 1 && destx == ox + 2 && this->board[desty][destx] <= 0)
	{
		return 1; 
	}
	if (oy + 2 < 8 && ox + 1 < 8 && desty == oy + 2 && destx == ox + 1 && this->board[desty][destx] <= 0)
	{
		return 1; 
	}
	if (oy + 2 < 8 && ox - 1 >= 0 && desty == oy + 2 && destx == ox - 1 && this->board[desty][destx] <= 0)
	{
		return 1; 
	}
	if (oy + 1 < 8 && ox - 2 >= 0 && desty == oy + 1 && destx == ox - 2 && this->board[desty][destx] <= 0)
	{
		return 1; 
	}
	if (oy - 1 >= 0 && ox - 2 >= 0 && desty == oy - 1 && destx == ox - 2 && this->board[desty][destx] <= 0)
	{
		return 1;
	}
	return 0;
}

int chessboard::Black_king_check(int ox, int oy, int destx, int desty)
{
	if (ox - 1 >= 0 && oy - 1 >= 0 && desty == oy - 1 && destx == ox - 1 && this->board[desty][destx] >= 0)
	{
		return 1;
	}
	if (oy - 1 >= 0 && destx == ox && desty == oy - 1 && this->board[desty][destx] >= 0)
	{
		return 1;
	}
	if (oy - 1 >= 0 && ox + 1 < 8 && destx == ox + 1 && desty == oy - 1 && this->board[desty][destx] >= 0)
	{
		return 1;
	}
	if (ox + 1 < 8 && desty == oy && destx == ox + 1 && this->board[desty][destx] >= 0)
	{
		return 1;
	}
	if (ox + 1 < 8 && oy + 1 < 8 && desty == oy + 1 && destx == ox + 1 && this->board[desty][destx] >= 0)
	{
		return 1;
	}
	if (oy + 1 < 8 && desty == oy + 1 && destx == ox && this->board[desty][destx] >= 0)
	{
		return 1;
	}
	if (ox - 1 >= 0 && oy + 1 < 8 && destx == ox - 1 && desty == oy + 1 && this->board[desty][destx] >= 0)
	{
		return 1;
	}
	if (ox - 1 >= 0 && desty == oy && destx == ox - 1 && this->board[desty][destx] >= 0)
	{
		return 1;
	}
	return 0;
}



int chessboard::Black_king_ShahCheck(int posdestx, int posdesty)
{
	int ok = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (this->board[i][j] < 0)
			{
				if (this->board[i][j] == -1)
				{
					ok=White_pawn_check(j, i, posdestx, posdesty);
				}
				if (this->board[i][j] == -2)
				{
					ok=White_rook_check(j, i, posdestx, posdesty);
				}
				if (this->board[i][j] == -3)
				{
					ok=White_rook_check(j, i, posdestx, posdesty);
				}
				if (this->board[i][j] == -4)
				{
					ok=White_elephant_check(j, i, posdestx, posdesty);
				}
				if (this->board[i][j] == -5)
				{
					ok=White_queen_check(j, i, posdestx, posdesty);
				}
				if (this->board[i][j] == -6)
				{
					ok=White_king_check(j, i, posdestx, posdesty);
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

int chessboard::Black_king(int ox, int oy, int nx, int ny)
{
	if (ox - 1 >= 0 && oy - 1 >= 0 && ny == oy - 1 && nx == ox - 1 && this->board[ny][nx] <= 0)
	{
		int ok = Black_king_ShahCheck(ox - 1, oy - 1);
		if (ok == 1)
		{
			return 1; 
		}
	}
	if (oy - 1 >= 0 && nx == ox && ny == oy-1 && this->board[ny][nx] <= 0)
	{
		int ok = Black_king_ShahCheck(ox, oy-1);
		if (ok == 1)
		{
			return 1;
		}
	}
	if (oy - 1 >= 0 && ox + 1 < 8 && nx == ox + 1 && ny == oy - 1 && this->board[ny][nx] <= 0)
	{
		int ok = Black_king_ShahCheck(ox+ 1, oy- 1);
		if (ok == 1)
		{
			return 1; 
		}
	}
	if (ox + 1 < 8 && ny == oy && nx == ox+1 && this->board[ny][nx] <= 0)
	{
		int ok = Black_king_ShahCheck(ox+1, oy);
		if (ok == 1)
		{
			return 1;
		}
	}
	if (ox + 1 < 8 && oy + 1 < 8 && ny == oy + 1 && nx == ox + 1 && this->board[ny][nx] <= 0)
	{
		int ok = Black_king_ShahCheck(ox + 1, oy + 1);
		if (ok == 1)
		{
			return 1; 
		}
	}
	if (oy + 1 < 8 && ny == oy+1 && nx == ox && this->board[ny][nx] <= 0)
	{
		int ok = Black_king_ShahCheck(ox, oy+1);
		if (ok == 1)
		{
			return 1; 
		}
	}
	if (ox - 1 >=0 && oy + 1 <8 && nx == ox - 1 && ny == oy + 1 && this->board[ny][nx] <= 0)
	{
		int ok = Black_king_ShahCheck(ox-1, oy+ 1);
		if (ok == 1)
		{
			return 1; 
		}
	}
	if (ox - 1 >= 0 && ny == oy && nx == ox-1 && this->board[ny][nx] <= 0)
	{
		int ok = Black_king_ShahCheck(ox-1, oy);
		if (ok == 1)
		{
			return 1;
		}
	}
	if (Rook_BlackD==0 && King_Black_==0 && this->board[0][5]==0 && this->board[0][6]==0 && ny==0 && nx==6)
	{
		int ok = Black_king_ShahCheck(4, 0);
		if (ok == 1)
		{
			ok = Black_king_ShahCheck(5, 0);
			if (ok == 1)
			{
				ok = Black_king_ShahCheck(6, 0);
				if (ok == 1)
				{
					King_Black_ = 1;
					Rook_BlackD = 1;
					this->board[0][7] = 0;
					this->board[0][5] = 2;
					return 1;
				}
			}
		}
	}
	if (Rook_BlackSt == 0 && King_Black_ == 0 && this->board[0][3] == 0 && this->board[0][2] == 0 && this->board[0][1] == 0 && ny == 0 && nx == 2)
	{
		int ok = (4, 0);
		if (ok == 1)
		{
			ok = Black_king_ShahCheck(3, 0);
			if (ok == 1)
			{
				ok = Black_king_ShahCheck(2, 0);
				if (ok == 1)
				{
					ok = Black_king_ShahCheck(1, 0);
					if (ok == 1)
					{
						King_Black_ = 1;
						Rook_BlackSt = 1;
						this->board[0][0] = 0;
						this->board[0][3] = 2;
						return 1;
					}
				}
			}
		}
	}
	return 0;
}


int chessboard::King_WhiteShahCheck(int posdestx, int posdesty)
{
	int ok = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (this->board[i][j] > 0)
			{
				if (this->board[i][j] == 1)
				{
					ok = Black_pawn_check(j, i, posdestx, posdesty);
				}
				if (this->board[i][j] == 2)
				{
					ok = Black_RookShah(j, i, posdestx, posdesty);
				}
				if (this->board[i][j] == 3)
				{
					ok = Black_horse_check(j, i, posdestx, posdesty);
				}
				if (this->board[i][j] == 4)
				{
					ok = Black_ElephantShah(j, i, posdestx, posdesty);
				}
				if (this->board[i][j] == 5)
				{
					ok = Black_queen_check(j, i, posdestx, posdesty);
				}
				if (this->board[i][j] == 6)
				{
					ok=Black_king_check(j, i, posdestx, posdesty);
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

int chessboard::White_king(int ox, int oy, int nx, int ny)
{
	if (ox - 1 >= 0 && oy - 1 >= 0 && ny == oy - 1 && nx == ox - 1 && this->board[ny][nx] >= 0)
	{
		int ok = King_WhiteShahCheck(ox - 1, oy - 1);
		if (ok == 1)
		{
			return 1;  
		}
	}
	if (oy - 1 >= 0 && nx == ox && ny == oy - 1 && this->board[ny][nx] >= 0)
	{
		int ok = King_WhiteShahCheck(ox, oy - 1);
		if (ok == 1)
		{
			return 1; 
		}
	}
	if (oy - 1 >= 0 && ox + 1 < 8 && nx == ox + 1 && ny == oy - 1 && this->board[ny][nx] >= 0)
	{
		int ok = King_WhiteShahCheck(ox + 1, oy - 1);
		if (ok == 1)
		{
			return 1; 
		}
	}
	if (ox + 1 < 8 && ny == oy && nx == ox + 1 && this->board[ny][nx] >= 0)
	{
		int ok = King_WhiteShahCheck(ox + 1, oy);
		if (ok == 1)
		{
			return 1; 
		}
	}
	if (ox + 1 < 8 && oy + 1 < 8 && ny == oy + 1 && nx == ox + 1 && this->board[ny][nx] >= 0)
	{
		int ok = King_WhiteShahCheck(ox + 1, oy + 1);
		if (ok == 1)
		{
			return 1; 
		}
	}
	if (oy + 1 < 8 && ny == oy + 1 && nx == ox && this->board[ny][nx] >= 0)
	{
		int ok = King_WhiteShahCheck(ox, oy + 1);
		if (ok == 1)
		{
			return 1; 
		}
	}
	if (ox - 1 >= 0 && oy + 1 < 8 && nx == ox - 1 && ny == oy + 1 && this->board[ny][nx] >= 0)
	{
		int ok = King_WhiteShahCheck(ox - 1, oy + 1);
		if (ok == 1)
		{
			return 1; 
		}
	}
	if (ox - 1 >= 0 && ny == oy && nx == ox - 1 && this->board[ny][nx] >= 0)
	{
		int ok = King_WhiteShahCheck(ox - 1, oy);
		if (ok == 1)
		{
			return 1; 
		}
	}
	
	if (King_White_ == 0 && Rook_WhiteD == 0 && this->board[7][5] == 0 && this->board[7][6] == 0 && ny==7 && nx==6)
	{
		int ok = 1;
		ok = King_WhiteShahCheck(4, 7);
		if (ok == 1)
		{
			ok = King_WhiteShahCheck(5, 7);
			if (ok == 1)
			{
				ok = King_WhiteShahCheck(6, 7);
				if (ok == 1)
				{
					this->board[7][7] = 0;
					this->board[7][5] = -2;
					King_White_ = 1;
					Rook_WhiteD = 1;
					return 1;
				}
			}
		}
	}
	// rocada in st
	if (King_White_ == 0 && Rook_WhiteD == 0 && this->board[7][3] == 0 && this->board[7][2] == 0 && this->board[7][1] == 0 && ny == 7 && nx == 2)
	{
		int ok = 1;
		ok = King_WhiteShahCheck(4, 7);
		if (ok == 1)
		{
			ok = King_WhiteShahCheck(3, 7);
			if (ok == 1)
			{
				ok = King_WhiteShahCheck(2, 7);
				if (ok == 1)
				{
					ok = King_WhiteShahCheck(1, 7);
					if (ok == 1)
					{
						this->board[7][0] = 0;
						this->board[7][3] = -2;
						King_White_ = 1;
						Rook_WhiteSt = 1;
						return 1;
					}
				}
			}
		}
	}
	return 0;
}


void chessboard::posKing_White()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (this->board[i][j] == -6)
			{
				controlWhite.x = j;
				controlWhite.y = i;
				break;
			}
		}
	}
}

void chessboard::posKing_Black()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (this->board[i][j] == 6)
			{
				controlBlack.y = i;
				controlBlack.x = j;
				break;
			}
		}
	}
}



