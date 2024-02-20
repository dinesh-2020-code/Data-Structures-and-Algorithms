/**
 * Problem Link: https://www.codingninjas.com/studio/problems/unique-paths-ii_977241
 * Problem statement
 * Given a ‘N’ * ’M’ maze with obstacles, count and return the number of unique paths to reach
 * the right-bottom cell from the top-left cell. A cell in the given maze has a value '-1' if it
 * is a blockage or dead-end, else 0. From a given cell, we are allowed to move to cells (i+1, j) 
 * and (i, j+1) only. Since the answer can be large, print it modulo 10^9 + 7.
 * For Example :
 * Consider the maze below :
 * 0 0 0 
 * 0 -1 0 
 * 0 0 0
 * 
 * There are two ways to reach the bottom left corner - 
 *      (1, 1) -> (1, 2) -> (1, 3) -> (2, 3) -> (3, 3)
 *      (1, 1) -> (2, 1) -> (3, 1) -> (3, 2) -> (3, 3)
 * 
 * Hence the answer for the above test case is 2.
 * 
*/

#include <iostream>
#include <vector>

using namespace std; 

const int mod = (int)(1e9 + 7);


void uniquePathsIITab(int row, int col, vector<vector<int>> &mat) {
    vector<vector<int>> dp(row, vector<int> (col, -1));

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (i >= 0 && j >= 0 && mat[i][j] == -1)
                dp[i][j] = 0;
            else if (i == 0 && j == 0)
                dp[i][j] = 1; 
            else {
                int left = (j - 1 >= 0) ? dp[i][j-1] : 0;
                int up = (i - 1 >= 0) ? dp[i - 1][j] : 0;
                dp[i][j] = (left + up) % mod; 
            }
        }
    }
    cout <<  dp[row - 1][col - 1] % mod << "\n"; 
}


int uniquePathsII(int row, int col, vector<vector<int>> &mat, vector<vector<int>> &memo) {
    
    //If the cell is a dead cell.
    if (row >= 0 && col >= 0 && mat[row][col] == -1)
        return 0; 
    
    if (row == 0 && col == 0)
        return 1; 

    if (row < 0 || col < 0)
        return 0; 
    
    if (memo[row][col] != -1)
        return memo[row][col];

    int left = uniquePathsII(row, col - 1, mat, memo); 
    int   up = uniquePathsII(row - 1, col, mat, memo);

    return memo[row][col] = (left + up) % mod;; 
} 
int main() {

    int n = 3, m = 3; 
    vector<vector<int>> mat = {
        {0, 0, 0}, 
        {0, -1, 0}, 
        {0, 0, 0}
    }; 
    vector<vector<int>> memo(n, vector<int> (m, -1));
    cout << uniquePathsII(n - 1, m - 1, mat, memo) << endl; 
    uniquePathsIITab(n, m, mat);
    return 0; 
}