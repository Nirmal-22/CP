#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<char>>& board, int row, int col, char num) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[startRow + i][startCol + j] == num) {
                return false;
            }
        }
    }

    return true;
}

int solve(vector<vector<char>> &A)
{
    for (int row = 0; row < 9; row++) 
    {
        for (int col = 0; col < 9; col++) 
        {
            if (board[row][col] == '.') 
            {
                for (char num = '1'; num <= '9'; num++) 
                {
                    if (isSafe(board, row, col, num)) 
                    {
                        board[row][col] = num;
                        if (solveSudoku(board)) 
                        {
                            return true;
                        }
                        board[row][col] = '.'; 
                    }
                }
                return false; 
            }
        }
    }
}
void solveSudoku(vector<vector<char>>& A) 
{
    if (solve(A)) 
    {
        for (int i = 0; i < 9; i++) 
        {
            for (int j = 0; j < 9; j++) 
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    } 
}

int main() {
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    solveSudoku(board);
    return 0;
}
