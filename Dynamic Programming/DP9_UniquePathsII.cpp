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

int uniquePathsII(int row, int col, vector<vector<int>> &mat) {
    
    //If the cell is a dead cell.
    if (row >= 0 && col >= 0 && mat[row][col] == -1)
        return 0; 
    
    if (row == 0 && col == 0)
        return 1; 

    if (row < 0 || col < 0)
        return 0; 

    int left = uniquePathsII(row, col - 1, mat); 
    int   up = uniquePathsII(row - 1, col, mat);

    return left + up; 
} 
int main() {

    int n = 3, m = 3; 
    vector<vector<int>> mat = {
        {0, 0, 0}, 
        {0, -1, 0}, 
        {0, 0, 0}
    }; 

    cout << uniquePathsII(n - 1, m - 1, mat) << endl; 

    return 0; 
}