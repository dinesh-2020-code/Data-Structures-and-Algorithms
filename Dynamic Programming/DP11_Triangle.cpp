/**
 * Problem Link: https://www.codingninjas.com/studio/problems/triangle_1229398
 * Problem statement
 * You are given a triangular array/list 'TRIANGLE'. Your task is to return the minimum path sum to reach from
 * the top to the bottom row.The triangle array will have N rows and the i-th row, where 0 <= i < N will have 
 * i + 1 elements.You can move only to the adjacent number of row below each step. For example, if you are at 
 * index j in row i, then you can move to i or i + 1 index in row j + 1 in each step.
 * For Example :If the array given is 'TRIANGLE' = [[1], [2,3], [3,6,7], [8,9,6,1]] the triangle array will look like:
 *      1
 *      2,3
 *      3,6,7
 *      8,9,6,10
 * For the given triangle array the minimum sum path would be 1->2->3->8. Hence the answer would be 14.
 * 
 * 
 * f(0, 0) -> min path sum from (0, 0) to last row
 * 
*/

#include <iostream>
#include <vector>

using namespace std; 


int minPathSumInTriangle(int row, int col, int n, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
	//base case
	if (row == n-1) {
		return triangle[row][col];
	}
	if (dp[row][col] != -1)
		return dp[row][col];

	int down = triangle[row][col] + minPathSumInTriangle(row + 1, col, n, triangle, dp); 
	int diag = triangle[row][col] + minPathSumInTriangle(row + 1, col + 1, n, triangle, dp); 
	return dp[row][col] = min(down, diag); 
}

int main() 
{
    vector<vector<int>> triangle = {
        {1}, 
        {2, 3}, 
        {3, 6, 7}, 
        {8, 9, 6, 10}
    };
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int> (n, -1));
    cout << minPathSumInTriangle(0, 0, n, triangle, dp) << "\n";  

    return 0; 
}

/**
 *  Asymptotic analysis
 * we have 1 + 2 + 3 + ... n cols in a triangle starting from top to bottom
 *  every cell has two options, either go down or go diagonally downwards, so 
 *  we have 2 ^ (1 + 2 + 3 + ...+ n) operations  for recursive sol
 *  Space Complexity: O(n) stack space
 * 
 * Memoization code
 * 
*/