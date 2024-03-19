/**
 * Print the Longest Increasing Subsequence
 * 
 * 
 * 
 * Efficient Approach
 * [5, 4, 11, 1, 16, 8]
 * 
 * we will declare a dp array of length n, such that dp[i] signifies the length of 
 * the longest longest increasing subsequence that ends at index i
 * 
 * for ex: arr[] = {5, 4, 11, 1, 16, 8}
 *          dp[] = {1, 1,  2, 1,  3, 2}
 *  ans would be max(dp[])
 * 
 * Initially dp [] will be filled with all 1, because every element can be subsequence of length 1
 * 
*/

#include <iostream>
#include <vector>

using namespace std;

int longestIncreasingSubsequenceMemo(int ind, int prev, int n, vector<int> &arr,
                                    vector<vector<int>> &dp) {
    //base cases
    if (ind == n) {
        return 0;
    }

    if (dp[ind][prev + 1] != -1)
        return dp[ind][prev + 1];
    //Not take case
    int notTake = 0 + longestIncreasingSubsequenceMemo(ind + 1, prev, n, arr, dp);
    //Take case
    int take = -1e9;
    if (prev == -1 || arr[ind] > arr[prev])
        take = 1 + longestIncreasingSubsequenceMemo(ind + 1, ind, n, arr, dp);

    return dp[ind][prev + 1] = max(take, notTake);

    // Time: O(n)
    // Aux Space: O (n) + O(n * n)
}


int longestIncreasingSubsequenceTab(vector<int> &arr) {
    int n = arr.size();
    vector<vector<int>> dp (n + 1, vector<int> (n + 1, 0));
    for (int ind = n - 1; ind >= 0; ind--) {        
        for (int prev = ind - 1; prev >= -1; prev--) {
            int notTake = 0 + dp[ind + 1][prev + 1];
            //Take case
            int take = -1e9;
            if (prev == -1 || arr[ind] > arr[prev])
                take = 1 + dp[ind + 1][ind + 1];

            dp[ind][prev + 1] = max(take, notTake);
        }
    }
    return dp[0][0];
}


int longestIncreasingSubsequenceSO(vector<int> &arr) {
    //Time: O (n * n)
    // Space: O (n * 2)
    int n = arr.size();
    vector<int> curr (n + 1, 0), next (n + 1, 0);
    for (int ind = n - 1; ind >= 0; ind--) {        
        for (int prev = ind - 1; prev >= -1; prev--) {
            int notTake = 0 + next[prev + 1];
            //Take case
            int take = -1e9;
            if (prev == -1 || arr[ind] > arr[prev])
                take = 1 + next[ind + 1];

            curr[prev + 1] = max(take, notTake);
        }
        next = curr;
    }
    return next[0];
}


int memoizedSol(vector<int> &arr) {
    /**
     * This function returns the length of the longest increasing subsequence
     * using memoization technique.
     * params: arr is the arrays of nums
     * return: size of the longest increasing array
    */
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int> (n + 1, -1));
    // return longestIncreasingSubsequence(0, -1, n, arr);
    return longestIncreasingSubsequenceMemo(0, -1, n, arr, dp);
}


//Efficient Sol
int LIS (vector<int> &arr) {
    int n = arr.size();
    vector<int> dp(n, 1);
    int ans = 1;
    for (int ind = 0; ind < n; ind++) {
        for (int prev = 0; prev < ind; prev++) {
            if (arr[prev] < arr[ind]) 
                dp[ind] = max(1 + dp[prev], dp[ind]);
        }
        ans = max(ans, dp[ind]);
    }
    return ans;
}


int main() {

    vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Length of Longest Increasing Subsequence is(Memo): "<< memoizedSol(arr) << "\n";
    cout << "Length of Longest Increasing Subsequence is(Tab): "<< longestIncreasingSubsequenceTab(arr) << "\n";
    cout << "Length of Longest Increasing Subsequence is(SO): "<< longestIncreasingSubsequenceSO(arr) << "\n";
    cout << "Length of Longest Increasing Subsequence is: "<< LIS(arr) << "\n";
    return 0;
}

