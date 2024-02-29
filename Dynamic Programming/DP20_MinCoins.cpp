/**
 * Problem Link: https://www.codingninjas.com/studio/problems/minimum-elements_3843091
 *               https://leetcode.com/problems/coin-change/description/
 * 
 * Problem statement
 * You are given an array of ‘N’ distinct integers and an integer ‘X’ representing the target sum. You have to tell 
 * the minimum number of elements you have to take to reach the target sum ‘X’.
 * 
 * Return the fewest number of elements that you need to make up X. If X cannot be made 
 * up by any combination of the elements, return -1.
 * 
 * Note: You have an infinite number of elements of each type.
 * For example If N=3 and X=7 and array elements are [1,2,3]. 
 * Way 1 - You can take 4 elements  [2, 2, 2, 1] as 2 + 2 + 2 + 1 = 7.
 * Way 2 - You can take 3 elements  [3, 3, 1] as 3 + 3 + 1 = 7.
 * Here, you can see in Way 2 we have used 3 coins to reach the target sum of 7.
 * Hence the output is 3.
 * 
 * Input: 
 *  4 5  // N Target
 *  17 7 8 6  //coins denominations
 * 
 * Output: -1
 * 
 * 
*/

#include <iostream>
#include <vector>

using namespace std; 


int minCoins (int ind, int target, vector<int> &coins, vector<vector<int>> &dp) {

    //base case
    if (ind == 0) {
        if (target % coins[0] == 0) 
            return target / coins[0];
        else 
            return 1e9;
    }
    if (dp[ind][target] != -1)
        return dp[ind][target];

    //notTake case
    int notTake = minCoins(ind - 1, target, coins, dp);
    //take case
    //take the coin at index ind iff coins[ind] <= target
    int take = (coins[ind] <= target) ? (1 + minCoins(ind, target - coins[ind], coins, dp)) : 1e9;
    return dp[ind][target] = min(take, notTake);
}

int memoizedSol (vector<int> &coins, int target) {

    int n = coins.size();
    vector<vector<int>> dp (n, vector<int> (target + 1, -1));
    int ans = minCoins(n - 1, target, coins, dp);
    if (ans == 1e9)
        return -1;
    return ans;
}


int minCoinsTab (vector<int> &coins, int target) {
    int n = coins.size();
    vector<vector<int>> dp (n, vector<int> (target + 1, 0));
    //write base cases in table
    //case1: if ind = 0
    for (int t = 0; t <= target; t++) {
        dp[0][t] = (t % coins[0] == 0) ? t / coins[0] : 1e9;
    }

    //recursive cases
    for (int ind = 1; ind < n; ind++) {
        
        for (int t = 0; t <= target; t++) {
            int notTake = dp[ind - 1][t];
            int take = (coins[ind] <= t) ? (1 + dp[ind][t - coins[ind]]) : 1e9;
            dp[ind][t] = min(take, notTake);
        }
    }
    int ans = dp[n-1][target];
    return (ans == 1e9) ? -1 : ans;
}

int main() {

    int n;
    cout << "Enter total No. of coins: "; 
    cin >> n;

    vector<int> coins(n);   //coins = {9, 6, 5, 1} , target = 11     Output: 2 (1 coin of denominations 6 and 5 each)
    cout << "Enter " << n << " denominations of coins separated by space:\n";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    
    int target;
    cout << "Enter target summation of coins: ";
    cin >> target;

    cout << "The minimum amount of Coins required to make target of " << target << " are: " << memoizedSol (coins, target) << "\n";
    cout << "The minimum amount of Coins required to make target of " << target << " are: " << minCoinsTab (coins, target) << "\n";

    return 0;
}

/**
 * Complexity: 
 * Recursive  Time: : >> O(2^n) or exponential     Space: O(target)
 * Memoization Time: : O(N * target)     Aux Space: O(N * target)[dp array] + O(N)[stack space]
 * 
*/
