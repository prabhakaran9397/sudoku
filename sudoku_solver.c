#include <stdio.h>
#define SIZE 9

int isSafe(int Board[SIZE][SIZE], int row, int col, int num)
{
	int mover;
	//Travel Horizontally & Vertically
	for(mover=0; mover<SIZE; ++mover)
		if(Board[row][mover] == num || Board[mover][col] == num)
			return 0;
	//Search in the box
	int Box_row = (row/3)*3, Box_col = (col/3)*3;
	int mov_row, mov_col;
	for(mov_row=Box_row; mov_row<Box_row+3; ++mov_row)
		for(mov_col=Box_col; mov_col<Box_col+3; ++mov_col)
			if(Board[mov_row][mov_col] == num)
				return 0;
	return 1;
}

int solve_sudoku(int Board[SIZE][SIZE])
{
	int row, col, num;
	for(row=0; row<SIZE; ++row) {
		for(col=0; col<SIZE; ++col) {
			if(Board[row][col] == 0) {
				for(num=1; num<=9; ++num) {
					if(isSafe(Board, row, col, num)) {
						Board[row][col] = num;
						if(solve_sudoku(Board) == -1) {
							Board[row][col] = 0;
						}
						else {
							break;
						}
					}
				}
				if(Board[row][col] == 0) {
					return -1;
				}
			}	
		}
	}
}

void print(int B[SIZE][SIZE])
{
	printf (" %d %d %d | %d %d %d | %d %d %d\n", B[0][0], B[0][1], B[0][2], B[0][3], B[0][4], B[0][5], B[0][6], B[0][7], B[0][8]);
	printf (" %d %d %d | %d %d %d | %d %d %d\n", B[1][0], B[1][1], B[1][2], B[1][3], B[1][4], B[1][5], B[1][6], B[1][7], B[1][8]);
	printf (" %d %d %d | %d %d %d | %d %d %d\n", B[2][0], B[2][1], B[2][2], B[2][3], B[2][4], B[2][5], B[2][6], B[2][7], B[2][8]);
	printf ("-------+-------+-------\n");
	printf (" %d %d %d | %d %d %d | %d %d %d\n", B[3][0], B[3][1], B[3][2], B[3][3], B[3][4], B[3][5], B[3][6], B[3][7], B[3][8]);
	printf (" %d %d %d | %d %d %d | %d %d %d\n", B[4][0], B[4][1], B[4][2], B[4][3], B[4][4], B[4][5], B[4][6], B[4][7], B[4][8]);
	printf (" %d %d %d | %d %d %d | %d %d %d\n", B[5][0], B[5][1], B[5][2], B[5][3], B[5][4], B[5][5], B[5][6], B[5][7], B[5][8]);
	printf ("-------+-------+-------\n");
	printf (" %d %d %d | %d %d %d | %d %d %d\n", B[6][0], B[6][1], B[6][2], B[6][3], B[6][4], B[6][5], B[6][6], B[6][7], B[6][8]);
	printf (" %d %d %d | %d %d %d | %d %d %d\n", B[7][0], B[7][1], B[7][2], B[7][3], B[7][4], B[7][5], B[7][6], B[7][7], B[7][8]);
	printf (" %d %d %d | %d %d %d | %d %d %d\n", B[8][0], B[8][1], B[8][2], B[8][3], B[8][4], B[8][5], B[8][6], B[8][7], B[8][8]);
}

int main(int argc, char *argv[])
{
	int Board[SIZE][SIZE] = { 
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},  
	};

	if(argc == 2) {
		FILE *fp;
		fp = fopen(argv[1], "r");
		int i, j;
		for(i=0; i<9; ++i) {
			for(j=0; j<9; ++j) {
				fscanf(fp, "%1d", &Board[i][j]);
			}
		}
	}
	
	if(solve_sudoku(Board) == -1)
		printf("Not Solvable!\n");
	else
		print(Board);
	
	return 0;
}
