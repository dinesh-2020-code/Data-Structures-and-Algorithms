/**
 * Problem Link: https://leetcode.com/problems/partition-equal-subset-sum/description/
 * Problem Statement
 * Given an integer array nums, return true if you can partition the array into two subsets 
 * such that the sum of the elements in both subsets is equal or false otherwise.
 * 
 * Input: nums = [1,5,11,5]
 * Output: true
 * Explanation: The array can be partitioned as [1, 5, 5] and [11].
 * 
 * Input: nums = [1,2,3,5]
 * Output: false
 * Explanation: The array cannot be partitioned into equal sum subsets.
 * 
 * Solution: 
 *      if subsets to have equal sum of two parts , then sum of each subset will be totalSum / 2
 *      so the problem boils down to the prev problem of DP14 (subset sum equals totalSum/2)
 * 
 *      pseudocode
 *      f(arr){
 *          1. calculate total sum, say totalSum
 *          2. IF totalSum IS ODD
 *                  return false //array cannot be partitioned into equal sum subsets
 *          3. return (subsetSumEqualsTarget(n, totalSum / 2, arr))
 *      } 
 * 
*/


#include <iostream>
#include <vector>

using namespace std; 


int partitionEqualSubsetSum(int ind, int currSum, int totalSum, vector<int> &arr, vector<vector<int>> &dp) {
    if (ind == 0)
        return currSum == (totalSum - currSum);
    if (dp[ind][currSum] != -1)
        return dp[ind][currSum];
    // recursive cases
    int notPick = partitionEqualSubsetSum(ind - 1, currSum, totalSum, arr, dp);
    int pick = partitionEqualSubsetSum(ind - 1, (currSum + arr[ind]), totalSum, arr, dp);
    return dp[ind][currSum] = (pick | notPick);
}


void partitionEqualSubsetSumTab(vector<int> &nums) {

    int totalSum = 0, n = nums.size();
    for (auto it : nums)
        totalSum += it;

    vector<vector<int>> dp(n, vector<int>(totalSum + 1, 0));
    // Fill DP table
    // Base case if ind is 0
    for (int s1 = 0; s1 <= totalSum; s1++)
        dp[0][s1] = (s1 == (totalSum - s1)) ? 1 : 0;

    for (int ind = 1; ind < n; ind++) {

        for (int s1 = 0; s1 <= totalSum; s1++) {
            int notPick = dp[ind - 1][s1];
            int pick = (s1 - nums[ind] >= 0) ? dp[ind - 1][s1 - nums[ind]] : 0;
            dp[ind][s1] = pick | notPick;
        }
    }

    cout << dp[n - 1][totalSum] << "\n";
}


void partitionEqualSubsetSumSO(vector<int> &nums) {
    int totalSum = 0, n = nums.size();
    for (auto it : nums)
        totalSum += it;
    vector<int> prev(totalSum + 1, 0); 
    for (int s1 = 0; s1 <= totalSum; s1++)
        prev[s1] = (s1 == (totalSum - s1)) ? 1 : 0;

    for (int ind = 1; ind < n; ind++) {
        vector <int> curr(totalSum + 1, 0); 
        for (int s1 = 0; s1 <= totalSum; s1++) {
            int notPick = prev[s1];
            int pick = (s1 - nums[ind] >= 0) ? prev[s1 - nums[ind]] : 0;
            curr[s1] = pick | notPick;
        }
        prev = curr; 
    }

    cout <<  prev[totalSum] << "\n";
}


int main() {

    vector<int> arr = {3, 1, 1, 2, 2, 1};
    int totalSum = 0; 
    int n = arr.size();
    for (auto it : arr)
        totalSum += it; 
    
    vector<vector<int>> dp(n, vector<int> (totalSum + 1, -1));
    cout << partitionEqualSubsetSum(n - 1, 0, totalSum, arr, dp) << endl;
    partitionEqualSubsetSumTab(arr);
    partitionEqualSubsetSumSO(arr);
    return 0; 
}

