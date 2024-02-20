/**
 * Problem Link: https://www.codingninjas.com/studio/problems/minimum-path-sum_985349
 * Problem statement
 * Ninjaland is a country in the shape of a 2-Dimensional grid 'GRID', with 'N' rows and 'M' columns.
 * Each point in the grid has some cost associated with it.
 * Find a path from top left i.e. (0, 0) to the bottom right i.e. ('N' - 1, 'M' - 1) which minimizes
 * the sum of the cost of all the numbers along the path. You need to tell the minimum sum of that path.
 * Note:You can only move down or right at any point in time.
 * 
 * Constraints: 
 *      1 <= N, M <= 10^2
 *      1 <= GRID[i][j] <= 10^5
 * 
 *  Input 1: 
 *   2 3     // N M
 *   5 9 6
 *   11 5 2
 * 
 *  Output: 21
*/


#include <iostream>
#include <vector>

using namespace std; 


//Memoization approach: moving (row-1, col-1) to (0, 0)
int minPathSum(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp) {

    //base case
    if (row == 0 && col == 0)
        return grid[row][col];
    if (row < 0 || col < 0)
        return 1e9;     //if the path goes out of boundary, then return very large value 
                            //so that when taking min, ans wouldn't be effected
    if (dp[row][col] != -1)
        return dp[row][col];
    int up = grid[row][col] + minPathSum(row - 1, col, grid, dp); //take the current element and 
    int left = grid[row][col] + minPathSum(row, col - 1, grid, dp); //solve recursively the rest

    return dp[row][col] = min(up, left);
}

int main() {

    int n = 2, m = 3; // n -> rows, m -> columns
    vector<vector<int>> grid = {
        {5, 9, 6},
        {11, 5, 2}
    };
    vector<vector<int>> dp (n, vector<int> (m, -1));
    cout << "Min path sum is: " << minPathSum(n - 1, m - 1, grid, dp) << "\n"; 



    return 0; 
}