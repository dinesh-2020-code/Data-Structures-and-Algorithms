/**
 * Problem: Length of Longest Increasing Subsequence
 * Problem Link: https://www.codingninjas.com/studio/problems/longest-increasing-subsequence_630459
 * Problem Statement:
 * For a given array with N elements, you need to find the length of the longest subsequence from the 
 * array such that all the elements of the subsequence are sorted in strictly increasing order.
 * Strictly Increasing Sequence is when each term in the sequence is larger than the preceding term.
 * For example:
 * [1, 2, 3, 4] is a strictly increasing array, while [2, 1, 4, 3] is not.
 * 
 * prev is the ind of the previously chosen element , initially prev = -1
 * LIS(ind, prev) => represents length of LIS starting from index ind, whose previous index is prev
 * 
*/

#include <iostream>
#include <vector>

using namespace std;


int longestIncreasingSubsequence(int ind, int prev, int n, vector<int> &arr) {
    //base cases
    if (ind == n - 1) {
        return arr[ind] > arr[prev];
    }
    //Not take case
    int notTake = 0 + longestIncreasingSubsequence(ind + 1, prev, n, arr);
    //Take case
    int take = -1e9;
    if (prev == -1 || arr[ind] > arr[prev])
        take = 1 + longestIncreasingSubsequence(ind + 1, ind, n, arr);

    return max(take, notTake);

    // Time: 2 ^ n
    // Aux Space: O (n)
}


int longestIncreasingSubsequenceMemo(int ind, int prev, int n, vector<int> &arr,
                                    vector<vector<int>> &dp) {
    // We will shift each index by 1, to deal with prev = -1 case
    // ind [1..n] and prev = 0, initially
    //base cases
     // We will shift each index by 1, to deal with prev = -1 case
    // ind [1..n] and prev = 0, initially
    //base cases
    if (ind == n+1) {
        return 0;
    }

    if (dp[ind][prev] != -1)
        return dp[ind][prev];
    //Not take case
    int notTake = 0 + longestIncreasingSubsequenceMemo(ind + 1, prev, n, arr, dp);
    //Take case
    int take = -1e9;
    if (prev == 0 || arr[ind - 1] > arr[prev - 1])
        take = 1 + longestIncreasingSubsequenceMemo(ind + 1, ind, n, arr, dp);

    return dp[ind][prev] = max(take, notTake);

    // Time: O(n)
    // Aux Space: O (n) + O(n * n)
}


int memoizedSol(vector<int> &arr) {
    /**
     * This function returns the length of the longest increasing subsequence
     * using memoization technique.
     * params: arr is the arrays of nums
     * return: size of the longest increasing array
    */
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
    // return longestIncreasingSubsequence(0, -1, n, arr);
    return longestIncreasingSubsequenceMemo(1, 0, n, arr, dp);
}

int main() {

    vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Length of Longest Increasing Subsequence is: "<< memoizedSol(arr) << "\n";
    return 0;
}
