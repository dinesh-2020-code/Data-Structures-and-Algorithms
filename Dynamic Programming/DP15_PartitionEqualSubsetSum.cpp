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

int main() {

    vector<int> arr = {3, 1, 1, 2, 2, 1};
    int totalSum = 0; 
    int n = arr.size();
    for (auto it : arr)
        totalSum += it; 
    
    vector<vector<int>> dp(n, vector<int> (totalSum + 1, -1));
    cout << partitionEqualSubsetSum(n - 1, 0, totalSum, arr, dp) << endl;

    return 0; 
}

