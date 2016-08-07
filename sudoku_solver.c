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

void print(int Board[SIZE][SIZE])
{
	int row, col;
	for(row=0; row<SIZE; ++row) {
		for(col=0; col<SIZE; ++col) {
			printf("%3d", Board[row][col]);
		}
		printf("\n");
	}
}

int main(void)
{
	/*
	int Board[SIZE][SIZE] = { {5, 3, 0, 0, 7, 0, 0, 0, 0},
				  {6, 0, 0, 1, 9, 5, 0, 0, 0},
				  {0, 9, 8, 0, 0, 0, 0, 6, 0},
				  {8, 0, 0, 0, 6, 0, 0, 0, 3},
				  {4, 0, 0, 8, 0, 3, 0, 0, 1},
				  {7, 0, 0, 0, 2, 0, 0, 0, 6},
				  {0, 6, 0, 0, 0, 0, 2, 8, 0},
				  {0, 0, 0, 4, 1, 9, 0, 0, 5},
				  {0, 0, 0, 0, 8, 0, 0, 7, 9},	
				};
	*/
        int Board[SIZE][SIZE] = { {0, 0, 5, 2, 0, 0, 1, 0, 0},
                                  {0, 3, 0, 0, 4, 0, 5, 0, 0},
                                  {1, 0, 4, 5, 3, 0, 9, 7, 0},
                                  {0, 0, 7, 0, 6, 3, 0, 9, 0},
                                  {0, 0, 2, 0, 0, 0, 6, 0, 0},
                                  {0, 9, 0, 7, 8, 0, 4, 0, 0},
                                  {0, 5, 1, 0, 2, 6, 7, 0, 4},
                                  {0, 0, 3, 0, 9, 0, 0, 6, 0},
                                  {0, 0, 8, 0, 0, 7, 3, 0, 0},  
                                };
	if(solve_sudoku(Board) == -1)
		printf("Not Solvable!\n");
	else
		print(Board);
	return 0;
}
