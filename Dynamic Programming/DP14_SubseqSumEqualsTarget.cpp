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


int main() {

    vector<int> arr = {1, 2, 3, 4}; 
    int n = arr.size(); 
    int k = 4; 

    //we have 2 states index (0 <= ind < n) and target (0 <= target <= k)
    vector<vector<int>> dp(n, vector<int>(k + 1, -1)); 
    cout << subsetSumEqualsK(n - 1, k, arr, dp) << "\n"; 
    return 0; 
}
