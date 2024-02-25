/**
 * Problem Link: 
 * Problem Statement:
 * 
 * 
 * Idea: 
 *      From DP14 (Subset sum equals target k)
 *      For target k, we can derive if every possible target between [1, k] is found or not 
 *      We will make use of this idea, that from the last row of DP table used in DP14, we will 
 *      find the s1 and s2 (totalSum - s1) and check if it is possible to get sum of s1
 * 
 *      For ex: 
 *      Input: [3, 2, 7]
 *      totalSum = 12
 *      Min Value of s1 = 0(second partition contains all elements)                        Max Value os s1 = 12 (s1 partition contains all elements and s2 is empty)
 *      
 *      DP table Last row
 *      (till index n-1 is it possible to get target sum of i (0 <= i <= totalSum))
 *      sum        i 0 1 2 3 4 5 6 7 8 9 10 11 12
 *      dp[n-1][i] = 1 0 1 1 0 1 0 1 0 1  1  0  1   => dp[n-1][i] = 1 : if till index n-1, we have subset sum equals i, 0 otherwise
 *      
 *      Possible sums are: filter dp[n-1][i] = 1 values
 *             s1 ->       0  2  3  5  7  9  10  12
 *             s2 ->       12 10 9  7  5  3   2   0
 *      |s1 - s2| ->       12 8  6  2  2  6   8   12
 *      Output: min of all sums which is 2
 *  
*/ 

#include <iostream>
#include <vector>

using namespace std;


int subsetSumEqualsK(int ind, int target, vector<int> &arr, vector<vector<int>> &dp) {

    //base case
    if (target == 0)
        return dp[ind][target] = 1; 
    
    if (ind == 0) 
        return dp[ind][target] = (arr[ind] == target);

    if (dp[ind][target] != -1)
        return dp[ind][target];

    bool notTake = subsetSumEqualsK(ind - 1, target, arr, dp); 
    bool take = false;
    //when to take current element? Take the current element when curr_element is <= target
    if (arr[ind] <= target) {
        take = subsetSumEqualsK(ind - 1, target - arr[ind], arr, dp);
    }
    return dp[ind][target] = (take | notTake); 
}


int minSubsetSumDifference(vector<int> &arr, int n) {
    int totalSum = 0, s1 = 0, s2 = 0;
    int diff = 0;
    // Calculate the total sum of the array
    for (int i = 0; i < n; i++) {
        totalSum += arr[i];
    }
    int k = totalSum;
    // Initialize a DP table to store the results of the subset sum problem
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    for (int i = 0; i <= k; i++)
        bool dummy = subsetSumEqualsK(n - 1, i, arr, dp);
    int ans = 1e9;
    // Traverse through (last) row
    for (int i = 0; i <= (k / 2); i++) {
        if (dp[n - 1][i]) {
            s1 = i; 
            s2 = totalSum - i; 
            diff = abs(s1 - s2); 
            ans = min(ans, diff); 
        }
    }
    return ans;
}

int main() {

    vector<int> arr = {3, 2, 7}; //{1, 2, 3, 4};
    int n = arr.size();

    cout << "The minimum absolute difference is: " << minSubsetSumDifference(arr, n) << "\n";

    return 0; 
}
