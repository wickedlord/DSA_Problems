#include <bits/stdc++.h>
using namespace std; 

bool isSafe(vector<vector<int>>& board, int row, int col, int value) {
    //first checking for row and column
    for (int i=0; i<9; i++) {
        //first its col checking, then its row checking
        if ((board[row][i] == value) || (board[i][col] == value)) {
            return false;
        }

        //checking 3x3 matrix
        if (board[3*(row/3)+i/3][3*(col/3)+i%3] == value) {
            return false;
        }
    }
    return true;
}

bool solve (vector<vector<int>>& board) {
    int n = board[0].size();
    for (int row=0; row<n; row++) {
        for (int col=0; col<n; col++) {
            //if empty element is found
            if (board[row][col] == 0) {
                //try putting elements from 1 to 9
                for (int val=1; val<=9; val++) {
                    if (isSafe(board,row,col,val)) {
                        board[row][col] = val;
                        //check further solution depending on that value
                        if (solve(board)) {
                            return true;
                        }
                        else {
                            //go backtrack
                            board[row][col] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
}

void solveSudoku(vector<vector<int>>& sudoku)
{
    //just follow the rules of sudoku and solve
	solve(sudoku);
}