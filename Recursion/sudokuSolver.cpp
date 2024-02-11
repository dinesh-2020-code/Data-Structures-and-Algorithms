/**
 * Problem Link: https://leetcode.com/problems/sudoku-solver/description/
 * Problem statement: 
 *  Write a program to solve a Sudoku puzzle by filling the empty cells.
 *  A sudoku solution must satisfy all of the following rules:
 *      1. Each of the digits 1-9 must occur exactly once in each row.
 *      2. Each of the digits 1-9 must occur exactly once in each column.
 *      3. Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
 *  The '.' character indicates empty cells.
 * 
 *  Input: board = [
 *                  ['5','3','.','.','7','.','.','.','.'],
 *                  ['6','.','.','1','9','5','.','.','.'],
 *                  ['.','9','8','.','.','.','.','6','.'],
 *                  ['8','.','.','.','6','.','.','.','3'],
 *                  ['4','.','.','8','.','3','.','.','1'],
 *                  ['7','.','.','.','2','.','.','.','6'],
 *                  ['.','6','.','.','.','.','2','8','.'],
 *                  ['.','.','.','4','1','9','.','.','5'],
 *                  ['.','.','.','.','8','.','.','7','9']
 *                 ]
 * 
 * Output:         [
                    ['5','3','4','6','7','8','9','1','2'],
                    ['6','7','2','1','9','5','3','4','8'],
                    ['1','9','8','3','4','2','5','6','7'],
                    ['8','5','9','7','6','1','4','2','3'],
                    ['4','2','6','8','5','3','7','9','1'],
                    ['7','1','3','9','2','4','8','5','6'],
                    ['9','6','1','5','3','7','2','8','4'],
                    ['2','8','7','4','1','9','6','3','5'],
                    ['3','4','5','2','8','6','1','7','9']
                   ]
* 
    Constraints:
        1. board.length == 9
        2. board[i].length == 9
        3. board[i][j] is a digit or '.'.
        4. It is guaranteed that the input board has only one solution.
*/

#include <iostream>
#include <vector>

using namespace std;


bool isValid(vector<vector<char>> board, int row, int col, char c) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == c) //checking in row
            return false;
        
        if (board[i][col] == c) //checking in col
            return false;
        
        //checking in sub-board of size 3 X 3
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) 
            return false;
    }
    return true; 
}

bool solve(vector<vector<char>> & board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] == '.') {
                for (char c = '1'; c <= '9'; c++) {
                    if (isValid(board, i, j, c)) {
                        board[i][j] = c;
                        
                        if (solve(board) == true)
                            return true;
                        else 
                            board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}


void printBoard(vector<vector<char>> &board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            cout << board[i][j] << " "; 
        }
        cout << "\n";
    }
}


int main() {

    vector<vector<char>> board = 
    {           {'5','3','.','.','7','.','.','.','.'},
                {'6','.','.','1','9','5','.','.','.'},
                {'.','9','8','.','.','.','.','6','.'},
                {'8','.','.','.','6','.','.','.','3'},
                {'4','.','.','8','.','3','.','.','1'},
                {'7','.','.','.','2','.','.','.','6'},
                {'.','6','.','.','.','.','2','8','.'},
                {'.','.','.','4','1','9','.','.','5'},
                {'.','.','.','.','8','.','.','7','9'}
    };
    solve(board);
    printBoard(board);
    return 0;
}

/*
    Time complexity: O(9^(n*n)
*/