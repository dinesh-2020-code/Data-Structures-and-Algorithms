/**
 *  Problem Link: https://leetcode.com/problems/n-queens/description/
 * 
 *  The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
 *  Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
 *  Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate 
 *  a queen and an empty space, respectively.
 * 
 *  Input: n = 4
 *  Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]] 
 *  Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
 * 
*/

#include <iostream>
#include <vector>

using namespace std;

bool isSafe(int row, int col, vector<string> &board, int n) { 
    int r = row, c = col;
    // check towards left of [row][col]
    while (c >= 0) {
        if (board[r][c] == 'Q')
            return false;
        c--;
    }
    // check towards right of [row][col]
    r = row; c = col;
    while (c < n) {
        if (board[r][c] == 'Q')
            return false;
        c++;
    }
    // check upwards to [row][col]
    r = row; c = col;
    while (r >= 0) {
        if (board[r][c] == 'Q')
            return false;
        r--;
    }
    // check downwards to [row][col]
    r = row; c = col;
    while (r < n) {
        if (board[r][c] == 'Q')
            return false;
        r++;
    }

    // check down-right diagonal
    r = row; c = col;
    while (r < n && c < n) {
        if (board[r][c] == 'Q')
            return false;
        r++; c++;
    }
    // check top-left diagonal
    r = row; c = col;
    while (r >= 0 && c >= 0) {
        if (board[r][c] == 'Q')
            return false;
        r--; c--;
    }
    // check down-left diagonal
    r = row; c = col;
    while (r < n && c >= 0) {
        if (board[r][c] == 'Q')
            return false;
        r++; c--;
    }
    //checking up-right diagonal
    r = row; c = col;
    while (r >= 0 && c < n) {
        if (board[r][c] == 'Q')
            return false;
        r--; c++;
    }

    return true;
}


bool isSafe2(int row, int col, vector<string> &board, int n) {
    // ponder you have to check for the queen in only 3 directions i.e., 
    // towards left, upper diagonal and lower diagonal of a cell
    // because there's no queen yet placed on the right side of the cell.

    int r = row, c = col;
    // check towards left of [row][col]
    while (c >= 0) {
        if (board[r][c] == 'Q')
            return false;
        c--;
    }
    // check upper-left diagonal
    r = row; c = col;
    while (r >= 0 && c >= 0) {
        if (board[r][c] == 'Q')
            return false;
        r--; c--;
    }
    // check lower-left diagonal
    r = row; c = col;
    while (r < n && c >= 0) {
        if (board[r][c] == 'Q')
            return false;
        r++; c--;
    }
    return true;
}

void solve(int col, int n, vector<string> &board) {
    //Base case
    if (col == n) {
        //prints the board.
        for (auto it : board) {
            cout << it << endl;
        }
        cout << "============\n";
        return;
    }

    // Check for each col whether the queen be placed in specific column col or not
    for (int row = 0; row < n; ++row) {
        //check if it is safe to place the queen
        if (isSafe2(row, col, board, n)) {
            board[row][col] = 'Q'; // if safe then place the queen
            solve(col + 1, n, board);
            board[row][col] = '.'; // remove the queen placed while backtracking
        }
    }
}


void solve2(int col, int n, vector<string> &board, vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal) {
    //Base case
    if (col == n) {
        //prints the board.
        for (auto it : board) {
            cout << it << endl;
        }
        cout << "============\n";
        return;
    }
    // Check for each col whether the queen be placed in specific column col or not
    for (int row = 0; row < n; ++row) {
        if (leftRow[row] == 0 && upperDiagonal[(n - 1) + (col - row)] == 0 && lowerDiagonal[row + col] == 0) {
            board[row][col] = 'Q';
            leftRow[row] = 1;
            upperDiagonal[(n - 1) + (col - row)] = 1;
            lowerDiagonal[row + col] = 1;
            solve2(col + 1, n, board, leftRow, upperDiagonal, lowerDiagonal);
            board[row][col] = '.';
            leftRow[row] = 0;
            upperDiagonal[(n - 1) + (col - row)] = 0;
            lowerDiagonal[row + col] = 0;
        }
    }
}

int main() {

    int n = 4; 
    vector<string> board(n);
    string s(n, '.'); //creates an string containing '.' for ex: "...." here
    //constructing board. Initially board is empty.
    for (int i = 0; i < n; i++) {
        board[i] = s;
    }
    // solve(0, n, board);
    // Optimizing isSafe() from O(n) to O(1) by using hashing concept.
    vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0); 
    solve2(0, n, board, leftRow, upperDiagonal, lowerDiagonal);
    return 0; 
}
