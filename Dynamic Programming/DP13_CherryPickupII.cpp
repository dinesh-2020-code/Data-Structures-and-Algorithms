/**
 * Problem LinK: https://leetcode.com/problems/cherry-pickup-ii/description/
 * Problem Statement: 
 * You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] represents the number of 
 * cherries that you can collect from the (i, j) cell.You have two robots that can collect cherries for you:
 * Robot #1 is located at the top-left corner (0, 0), and
 * Robot #2 is located at the top-right corner (0, cols - 1).
 * Return the maximum number of cherries collection using both robots by following the rules below:
 * 
 * From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
 * When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
 * When both robots stay in the same cell, only one takes the cherries.
 * Both robots cannot move outside of the grid at any moment.
 * Both robots should reach the bottom row in grid
 * 
 * 
 * Input: grid = {{3,1,1},{2,5,1},{1,5,5},{2,1,1}}
 * Output: 24
*/

#include <iostream>
#include <vector>

using namespace std;


int cherryPickup(int row, int col1, int col2, int m, int n, vector<vector<int>> &grid) {

    //base case
    //check for out of bound
    if (col1 < 0 || col2 < 0 || col1 >= n || col2 >= n) 
        return -1e8;

    //if we reach at bottom row
    if (row == m - 1) {
        //if both robots reach at same cell at last row, then take only once
        if (col1 == col2)
            return grid[row][col1];
        else 
            return (grid[row][col1] +  grid[row][col2]);
    }
    // int col_change[] = {-1, 0, +1};     //change in cols
    int maxi = -1e9;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            //if both robots ended at same cell
            if (col1 == col2)
                maxi = max(maxi, grid[row][col1] + cherryPickup(row + 1, col1 + i, col2 + j, m, n, grid)); 
            else 
                maxi = max(maxi, grid[row][col1] + grid[row][col2] + cherryPickup(row + 1, col1 + i, col2 + j, m, n, grid)); 
        }
    }
    return maxi; 
}

int main() {
    vector<vector<int>> grid = {{3,1,1},{2,5,1},{1,5,5},{2,1,1}};

    int m = grid.size(); //rows
    int n = grid[0].size(); //cols
    cout << cherryPickup(0, 0, n - 1, m, n,  grid) << "\n"; 
    return 0; 
}

/**
 * Asymptotic analysis
 * Recursive sol
 *      Time: O(3 ^ n * 3 ^ n); 
 *      Aux space: O(n) stacks pace
 * Time
*/