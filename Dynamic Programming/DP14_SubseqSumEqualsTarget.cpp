/**
 * Problem Link: https://www.codingninjas.com/studio/problems/subset-sum-equal-to-k_1550954
 * Problem statement
 * You are given an array/list ‘ARR’ of ‘N’ positive integers and an integer ‘K’. 
 * Your task is to check if there exists a subsequence in ‘ARR’ with a sum equal to ‘K’.
 * Note: Return true if there exists a subset with sum equal to ‘K’. Otherwise, return false.
 * For Example :
 * If ‘ARR’ is {1,2,3,4} and ‘K’ = 4, then there exists 2 subsets with sum = 4. These are {1,3}
 * and {4}. Hence, return true.
 * 
 * Input: {6, 1, 2, 1}, k = 4   Output: true
 * 
 * fun(n-1, target) => represents in entire array, till index n-1, does there exists any target?
 * 
 * pseudocode
 * 
 * f(ind, target) 
 * {
 *     if (target == 0)
 *         return true
 *     if (ind == 0)
 *         return (arr[0] == target) ? true: false
 * 
 *     bool notTake = f(ind - 1, target)
 *      bool take = false; 
 *      if (target >= arr[ind]) 
 *          take = f(ind - 1, target - arr[ind])
 * 
 *      return take or notTake
 * }
 * 
*/

#include <iostream>
#include <vector> 

using namespace std; 


int subsetSumEqualsK(int ind, int target, vector<int> &arr, vector<vector<int>> &dp) {

    //base case
    if (target == 0)
        return true; 
    
    if (ind == 0) 
        return (arr[ind] == target) ? true : false;

    if (dp[ind][target] != -1)
        return dp[ind][target];

    bool notTake = subsetSumEqualsK(ind - 1, target, arr, dp); 
    bool take = false;
    //when to take current element? Take the current element when curr_element is <= target
    if (arr[ind] <= target) {
        take = subsetSumEqualsK(ind - 1, target - arr[ind], arr, dp);
    }
    return dp[ind][target] = (take || notTake); 
}


void subsetSumEqualsKTab(int n, int k, vector<int> &arr) {

    vector<vector<int> > dp (n, vector<int> (k + 1, 0));

    // Fill DP table with base cases
    // case 1: IF target IS 0: index ranges as  0 <= ind < n
    // case 2: IF ind IS 0 => if arr[ind] is also 0, then return true;

    // case 1:
    for (int ind = 0; ind < n; ind++) {
        dp[ind][0] = 1; 
    }

    // case 2: 
    if (arr[0] <= k) 
        dp[0][arr[0]] = 1; // dp[0][1] means that till index 0 and sum is 1 (acc to input {1, 2, 3, 4})

    for (int ind = 1; ind < n; ind++) {
        
        for (int target = 1; target <= k; target++) {  
            int notTake = dp[ind - 1][target]; 
            int take = 0; 
            //take if arr[ind] <= target
            if (arr[ind] <= target) 
                take = dp[ind - 1][target - arr[ind]]; 

            dp[ind][target] = take || notTake; 
        }
    }
    cout << dp[n - 1][k] << "\n";
}


void subsetSumEqualsKSO(int n, int k, vector<int> &arr) {

    vector<int> prev (k + 1, 0); 
    prev[0] = 1; 
    if (arr[0] <= k) 
        prev[arr[0]] = 1;

    for (int ind = 1; ind < n; ind++) {
        vector<int> curr(k + 1, 0); 
        curr[0] = 1; //0th col is marked as 1 for every row
        for (int target = 1; target <= k; target++) {
            int notTake = prev[target];
            int take = (arr[ind] <= target) ? prev[target - arr[ind]] : 0; 
            curr[target] = take || notTake; 
        }
        prev = curr; 
    }
    cout << prev[k] << "\n";     
}


int main() {

    vector<int> arr = {1, 2, 3, 4}; 
    int n = arr.size(); 
    int k = 4; 

    //we have 2 states index (0 <= ind < n) and target (0 <= target <= k)
    vector<vector<int>> dp(n, vector<int>(k + 1, -1)); 
    cout << subsetSumEqualsK(n - 1, k, arr, dp) << "\n"; 
    subsetSumEqualsKTab (n, k, arr);
    subsetSumEqualsKSO (n, k, arr); 
    return 0; 

}

/**
 * Asymptotic Analysis
 * Recursive code: 
 *      Time: O(2 ^ n)
 *      Aux Space: O(n) recursive stack space
 * 
 * Memoization: 
 *      Time: O(n * k)
 *      Aux Space: O(n) recursive stack space + O (n * k) Dp table
 * 
 * Tabulation: 
 *      Time: O(n * k)
 *      Aux Space: O(n * k)
 * 
 * Space Optimization: O(k) 
*/