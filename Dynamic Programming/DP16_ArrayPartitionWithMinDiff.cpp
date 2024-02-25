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


int minSubsetSumDifferenceTab(vector<int> &arr, int n) {
    int totalSum = 0, s1 = 0, s2 = 0;
    int diff = 0;
    // Calculate the total sum of the array
    for (int i = 0; i < n; i++) {
        totalSum += arr[i];
    }
    int k = totalSum;
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

    // dp[n - 1][col <-- 0 to k]
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


int minSubsetSumDifferenceSO(vector<int> &arr, int n) {
    int totalSum = 0; 
    int s1 = 0, s2 = 0, diff = 0;  //partition sums 
    for (auto it : arr)
        totalSum += it; 
    int k = totalSum; 
    vector<int> prev(k + 1, 0);
    prev[0] = 1;
    if (arr[0] <= k)
        prev[arr[0]] = 1;

    for (int ind = 1; ind < n; ind++) {
        vector<int> curr(k + 1, 0);
        curr[0] = 1; // 0th col is marked as 1 for every row
        for (int target = 1; target <= k; target++) {
            int notTake = prev[target];
            int take = (arr[ind] <= target) ? prev[target - arr[ind]] : 0;
            curr[target] = take || notTake;
        }
        prev = curr;
    }
    int ans = 1e9; 
    // Traverse through prev (last) row
    for (int i = 0; i <= (k / 2); i++) {
        if (prev[i]) {
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
    cout << "The minimum absolute difference is: " << minSubsetSumDifferenceSO(arr, n) << "\n";
    cout << "The minimum absolute difference is: " << minSubsetSumDifferenceTab(arr, n) << "\n";
    return 0; 
}
