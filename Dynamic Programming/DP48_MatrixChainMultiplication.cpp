/**
 * Problem Link: https://www.codingninjas.com/studio/problems/matrix-chain-multiplication_975344
 * Partition DP
 * 
 * Solve a problem in pattern
 * 
 * (1 + 2 + 3) * 5
 * (1 + 2) + (3 * 5) 
 * 
 * By both ways ans would be different
 *  
 * 
 * Rules: 
 *  1. Start with entire block/array f (i, j) where i is the starting point and j is the ending point
 *  2. Try all partitions (run a loop to try partitions)
 *  3. Return the best 2 partitions possible
 * 
 * Matrix Chain Multiplication (MCM):
 * Given the N matrix dimensions, find the min cost to multiply them to a single matrix
 * 
 * For ex: we have 3 matrices, given with dimensions as 
 * A (10 x 30), B (30 x 5) and C (5 x 60)
 * To multiply them, we have 2 ways: 
 *      case 1: (A B) C => cost is: (10 * 30 * 5) + (10 * 5 * 60)
 *      case 2: A (B C) => cost is: (10 * 30 * 60) + (30 * 5 * 60)
 * 
 * Given arr[] = {10, 20, 30, 40, 50} , N = 5
 *  arr is dimension of N-1 matrices
 *  A -> 10 x 20    B -> 20 x 30    C -> 30 x 40    D -> 40 x 50
 *  For ith matrix, dimensions is A[i-1] x A[i]
 *          i      0    1   2   3   4
 *  for the arr: {10, 20, 30, 40, 50}
 * 
 *  we will call f(1, 4) => return the min multiplications to multiply matrix 1 -> matrix 4
 *  f(1, n-1) generally
 *  
 *  f (i, j)
 *  {
 *      base case
 *      if (i == j) return 0; // when we left with single matrix, the operations will be 0
 *      
 *      Run a loop from k = (i -> j - 1), partitions can be p1 (i, k) and (k + 1, j)
 *      partitions can be k = 1, p1 = (1, 1) and p2 = (2, 4) etc
 * 
 *      mini = 1e9
 *      for (i <-- k to (j - 1) <-- k) {
 *          steps = (arr[i-1] * arr[k] * arr[j]) + f(i, k) + f (k + 1, j)
 *          mini = min(min, steps)
 *      }
 *      return minimal of all steps
 * 
 *  }
*/


#include <iostream>
#include <vector>

using namespace std;


//Time: O(N * N * N) ~ O(N^3)
//Aux Space: O(N * N) + O (N) {Recursive stack space}
int matrixChainMultiply (int i, int j, vector<int> &arr, vector<vector<int>> &dp) {
    //base case
    if (i == j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];
    //try all partitions
    int mini = 1e9;
    for (int k = i; k <= j - 1; k++) {
        int steps = arr[i-1] * arr[k] * arr[j] + matrixChainMultiply(i, k, arr, dp) + matrixChainMultiply(k + 1, j, arr, dp);
        mini = min (mini, steps);
    }
    return dp[i][j] = mini;

}


int matrixChainMultiplyTab (int N, vector<int> &arr) {
    vector<vector<int>> dp (N, vector<int> (N, 0));
    //fill base case in dp table
    for (int i = 0; i < N; i++) {
        dp[i][i] = 0;
    }

    for (int i = N - 1; i >= 1; i--) {
        for (int j = i + 1; j < N; j++) {
            int mini = 1e9;
            for (int k = i; k < j; k++) {
                int steps = arr[i-1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
                if (steps < mini)
                    mini = steps;
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][N - 1];
}


int memoizedSol(int N, vector<int> &arr) {
    vector<vector<int>> dp (N, vector<int> (N, -1));
    return matrixChainMultiply(1, N - 1, arr, dp);
}


int main() {

    int N = 4;
    vector<int> arr = {4, 5, 3, 2};
    cout << memoizedSol (N, arr) << endl;
    cout << matrixChainMultiplyTab(N, arr) << endl;
    
    return 0;
}
 