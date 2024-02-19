/**
 *  DP on Grids: 
 *  Problem Link: https://www.codingninjas.com/studio/problems/total-unique-paths_1081470
 *  Problem statement
 * You are present at point ‘A’ which is the top-left cell of an M X N matrix, your destination is point ‘B’,
 * which is the bottom-right cell of the same matrix. Your task is to find the total number of unique paths from
 * point ‘A’ to point ‘B’.In other words, you will be given the dimensions of the matrix as integers ‘M’ and ‘N’, 
 * your task is to find the total number of unique paths from the cell MATRIX[0][0] to MATRIX['M' - 1]['N' - 1].
 * To traverse in the matrix, you can either move Right or Down at each step. For example in a given point MATRIX[i][j], 
 * you can move to either MATRIX[i + 1][j] or MATRIX[i][j + 1].
 * 
 * Constraints:
        1 ≤ T ≤ 100
        1 ≤ M ≤ 15
        1 ≤ N ≤ 15
    Where ‘M’ is the number of rows and ‘N’ is the number of columns in the matrix. 

*/

#include <iostream>
#include <vector>

using namespace std; 

//Top Down Approach: Memo
int uniquePaths(int row, int col, vector<vector<int>> &dp) {
    //base case, here we are going backwards from (row - 1, col - 1) to (0, 0)
    if (row == 0 && col == 0) 
        return 1; //reached the destination cell
    if (row < 0 || col < 0)
        return 0; 

    if (dp[row][col] != -1)
        return dp[row][col];

    int left = uniquePaths(row, col - 1, dp); 
    int   up = uniquePaths(row - 1, col, dp); 
    return dp[row][col] = (left + up); //return the paths when following left and up directions
}

int main() {

    const int m = 3; //rows
    const int n = 3; //columns
    vector<vector<int>> dp(m, vector<int>(n, -1));
    cout <<  uniquePaths(m - 1, n - 1, dp) << "\n"; 
    return 0; 
}