/**
 * Problem Link:
 * https://www.codingninjas.com/studio/problems/maximum-sum-of-non-adjacent-elements_843261?source=youtube&campaign=striver_dp_videos
 * 
 * Problem statement : Maximum sum of non-adjacent elements
 * You are given an array/list of ‘N’ integers. You are supposed to return the maximum
 * sum of the subsequence with the constraint that no two elements are adjacent in the given array/list.
 * Note: A subsequence of an array/list is obtained by deleting some number of elements (can be zero) from
 * the array/list, leaving the remaining elements in their original order.
 * 
 * Constraints:
 *      1 <= T <= 500
 *      1 <= N <= 1000
 *      0 <= ARR[i] <= 10^5
 * 
 * 
 * 
*/

#include <iostream>
#include <cstring>

using namespace std;

int maxSumofNonAdacentElements(int ind, int arr[], int dp[]) {

    //base cases
    if (ind == 0) {  // if this base case hits it means that we haven't taken arr[1] element
        return arr[0]; //take arr[0] element
    }
    if (ind < 0) 
        return 0;
    if (dp[ind] != -1)
        return dp[ind];

    int pick = arr[ind] + maxSumofNonAdacentElements(ind - 2, arr, dp); // if u take current element then move to i-2 index
    int notPick = maxSumofNonAdacentElements(ind - 1, arr, dp); // if not taken current element then u are free to take i-1 element
    return dp[ind] = max(pick, notPick);
}

void maxSumofNonAdacentElementsTab(int n, int arr[], int dp[]) {

    //tabulation approach
    // Time : O(n), recursive stack space is eliminated here
    // filling base cases
    dp[0] = arr[0]; 
    dp[1] = max(arr[0], arr[1]);

    for (int i = 2; i < n; i++) {
        int pick = arr[i] + dp[i - 2];
        int notPick = dp[i - 1];
        dp[i] = max(pick, notPick);
    }
    cout << dp[n-1] << "\n";

}

void maxSumofNonAdacentElementsTabSO(int n, int arr[]) {
    
    // Space Optimization to O(1)
    int prev2 = arr[0]; 
    int prev = max(arr[0], arr[1]);

    for (int i = 2; i < n; i++) {
        int pick = arr[i] + prev2; 
        int notPick = prev;
        int curr = max(pick, notPick);
        prev2 = prev; 
        prev = curr; 
    }
    cout << prev << "\n"; 
}

int main() {

    const int n = 9;
    int arr[n] = {1, 2, 3, 1, 3, 5, 8, 1, 9};
    int dp[n];
    memset(dp, -1, sizeof(dp));
    cout << maxSumofNonAdacentElements(n - 1, arr, dp) << "\n";
    memset(dp, -1, sizeof(dp));
    maxSumofNonAdacentElementsTab(n, arr, dp);
    maxSumofNonAdacentElementsTabSO(n, arr);
    return 0; 
}

/**
 * Asymptotic Analysis
 *   Recursive solution: O(2 ^ n)
 *   Memoization Sol: O(n) time, Aux Space: O(n)(dp array) + O(n) stack space
 *   
*/