/**
 * Maximum Path Sum in the matrix
 * Problem Link: https://www.codingninjas.com/studio/problems/maximum-path-sum-in-the-matrix_797998
 * Problem Statement:
 * You have been given an N*M matrix filled with integer numbers, find the maximum sum that can be obtained 
 * from a path starting from any cell in the first row to any cell in the last row.From a cell in a row, you 
 * can move to another cell directly below that row, or diagonally below left or right. So from a particular 
 * cell (row, col), we can move in three directions i.e.
 *      Down: (row+1,col)
 *      Down left diagonal: (row+1,col-1)
 *      Down right diagonal: (row+1, col+1)
 * 
 * Constraints:
 *      1 <= N <= 100
 *      1 <= M <= 100
 *      -10^4 <= matrix[i][j] <= 10^4
 * 
 *  Input 1:        Input 2:                    Input 3
 *  4 4               4 6                        3 3   // N M
 *  1 2 10 4          10 10 2 -13 20 4           10 2 3
 *  100 3 2 1         1 -9 -81 30 2 5            3 7 2
 *  1 1 20 2          0 10 4 -79 2 -10           8 1 5
 *  1 2 2 1           1 -5 2 20 -11 4
 * 
 *  Output: 105       74                          25
 * 
 * 
 * f(row, col) -> max path sum to reach (row, col) from any cell in the first row
*/


#include <iostream>
#include <vector>

using namespace std;


int maxPathSum(int row, int col, int n, int m, vector<vector<int>> &mat, vector<vector<int>> &dp) {
    //base cases
    if (col < 0 || col == m) //check for out of bounds
        return -1e9;

    if (row == n - 1) //reached the last row, so return element at last row
        return mat[row][col];

    if (dp[row][col] != -1)
        return dp[row][col]; 

    int down_left = mat[row][col] + maxPathSum(row + 1, col - 1, n, m, mat, dp); 
    int down      = mat[row][col] + maxPathSum(row + 1, col    , n, m, mat, dp); 
    int down_right= mat[row][col] + maxPathSum(row + 1, col + 1, n, m, mat, dp); 
    return dp[row][col] = max(down, max(down_left, down_right)); 
}

//Tabulation : Bottom Up approach, start from last row and fill towards up
int maxPathSumTab(int n, int m, vector<vector<int>> &mat) {

    vector<vector<int>> dp(n, vector<int> (m, 0)) ; //declares a DP table of n * m
    //fill the base case in the table first
    //fill the last row in dp table
    for (int i = 0; i < m; i++) {
        dp[n - 1][i] = mat[n - 1][i]; 
    }

    //last row is filled, start form (n-2)th row
    for (int row = n - 2; row >= 0; row--) {
        for (int col = 0; col < m; col++) {
            int cell = mat[row][col];
            int down_left = mat[row][col]; 
            if (col - 1 >= 0) {
                down_left += dp[row + 1][col - 1];
            }
            else
                down_left += -1e9;

            int down      = mat[row][col] + dp[row + 1][col];
            int down_right= mat[row][col];
            if (col + 1 < m) 
                down_right += dp[row + 1][col + 1]; 
            else
                down_right += -1e9;

            dp[row][col] = max(down, max(down_left, down_right)); 
        }
    }

    int ans = INT_MIN; 
    for (int i = 0; i < m; i++){
        //calculating the max element among row
        ans = max(ans, dp[0][i]); 
    }

    cout << ans << "\n"; 
}

int main() {

    vector<vector<int>> matrix = {

                                {-9999, -9888, -9777, -9666, -9555},
                                {1, 10, 2, 4, 5},
                                {-9999, -9888, -9777, -9666, -9555},
                                {0, 0, 0, 0, 0},
                                {-99, -98, -97, -96, -95}
                                // {-9999, -9888, -9777, -9666, -9555}};
                                // {
                                //     {1, 2, 10, 4}, 
                                //     {100, 3, 2, 1},
                                //     {1, 1, 20, 2}, 
                                //     {1, 2, 2, 1}
                             };
    int n = matrix.size(); //rows
    int m = matrix[0].size(); //cols

    vector<vector<int>> dp(n, vector<int>(m, -1)); 
    int ans = INT_MIN; 
    for (int i = 0; i < m; i++) {
        ans = max(ans, maxPathSum(0, i, n, m, matrix, dp));
    }
    cout << ans << "\n";

    maxPathSumTab(n, m, matrix); 

    return 0; 
}

/**
 * Asymptotic Analysis
 * Recursive: 
 *  Time : O(3 ^ n), where n is the rows
 *  Aux Stack space: O(n)
 * 
 *  Memoized Sol
 * Time: O(n * m) where n is the no of rows amd m is the no. of cols
 *  Aux Space: O(n) {Recursive stack space} + O(n * m) {DP table}
 * 
 *  Tabulation: 
 *  Time: O(n * m) where n is the no of rows amd m is the no. of cols
 *  Aux Space: 
 *  
*/