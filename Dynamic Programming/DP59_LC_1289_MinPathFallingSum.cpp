/**
 * Problem Link: https://leetcode.com/problems/minimum-falling-path-sum-ii/description/
 * Problem
 * Given an n x n integer matrix grid, return the minimum sum of a falling path with non-zero shifts.
 * A falling path with non-zero shifts is a choice of exactly one element from each row of grid such 
 * that no two elements chosen in adjacent rows are in the same column.Statement: 
 * 
 * Given an n x n integer matrix grid, return the minimum sum of a falling path with non-zero shifts.
 * 
 * A falling path with non-zero shifts is a choice of exactly one element from each row of grid such 
 * that no two elements chosen in adjacent rows are in the same column.
 * 
*/

#include <iostream>
#include <vector>

using namespace std;


int solve(int row, int col, int n, vector<vector<int>> &grid,
          vector<vector<int>> &memo)
{
    // base case -> If there is no next row
    if (row == n - 1)
    {
        return grid[row][col];
    }

    if (memo[row][col] != -1)
        return memo[row][col];

    // select current element and move to the next row and try all possible element in cols except the col picked
    // in last row.
    int nextMin = INT_MAX;
    for (int nextRowCol = 0; nextRowCol < n; nextRowCol++)
    {
        if (nextRowCol != col)
        {
            nextMin = min(nextMin, solve(row + 1, nextRowCol, n, grid, memo));
        }
    }
    return memo[row][col] = grid[row][col] + nextMin;
}


int minFallingPathSum(vector<vector<int>> &grid)
{
    int n = grid.size();
    vector<vector<int>> memo(n, vector<int>(n, -1));
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        ans = min(ans, solve(0, i, n, grid, memo));
    }
    return ans;
}


int main() {

    vector<vector<int> > grid = {
        {1, 2, 3}, 
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Min path falling sum is: " << minFallingPathSum(grid) << "\n";

    return 0;
}