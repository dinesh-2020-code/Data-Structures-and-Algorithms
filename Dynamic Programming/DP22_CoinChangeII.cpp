/**
 * 
 * Problem Link: https://www.codingninjas.com/studio/problems/ways-to-make-coin-change_630471
 * Problem Statement
 * You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}. 
 * You need to figure out the total number of ways W, in which you can make a change for value V using 
 * coins of denominations from D. Print 0, if a change isn't possible
 * 
 * Constraints:
 * 1 <= N <= 15
 * 1 <= nums[i] <= (2^31) - 1
 * 1 <= value <= 10000
 * 
 * Input:
 * 3    // n
 * 1 2 3  // Denominations
 * 4  //value
 * Output: 4
 * 
 * We can make a change for the value V = 4 in four ways.
 * 1. (1,1,1,1), 
 * 2. (1,1, 2), [One thing to note here is, (1, 1, 2) is same as that of (2, 1, 1) and (1, 2, 1)]
 * 3. (1, 3), and 
 * 4. (2, 2)
 * 
*/

#include <iostream>
#include <vector>

using namespace std;


long long int countWays(int ind, int value, vector<int> coins, vector<vector<long long int>> &dp) {

    //base cases
    if (ind == 0) {
        if (value % coins[0] == 0)
            return 1;
        else 
            return 0;
    }
    if (dp[ind][value] != -1)
        return dp[ind][value];
    //recursive cases
    long long int notTake = countWays(ind - 1, value, coins, dp);
    //take case
    //you can only take the denomination if value to achieve is >= coins[ind]
    long long int take = (value >= coins[ind]) ? countWays(ind, value - coins[ind], coins, dp) : 0;
    return dp[ind][value] = (take + notTake);
}


long long int countWaysTab (int n, int value, vector<int> &coins) {
    //declare a DP array
    vector<vector<long long int>> dp(n, vector <long long int> (value + 1, 0));
    //write base cases in dp table
    //case 1: if ind = 0, then if val % coins[0]  is divisible then fill 1, else fill 0
    for (int v = 0; v <= value; v++) {
        if (v % coins[0] == 0)
            dp[0][v] = 1;
    }

    //write recursive cases in Dp table
    for (int ind = 1; ind < n; ind++) {
        for (int v = 0; v <= value; v++) {
            //not Take case
            long long notTake = dp[ind - 1][v];
            //take case
            long long take = (v >= coins[ind]) ? dp[ind][v - coins[ind]] : 0;
            dp[ind][v] = take + notTake;
        }
    }
    return dp[n - 1][value];
}


long long int countWaysSO (int n, int value, vector<int> &coins) {
    //declare a DP array
    vector <long long int> prev (value + 1, 0);
    //write base cases in dp table
    //case 1: if ind = 0, then if val % coins[0]  is divisible then fill 1, else fill 0
    for (int v = 0; v <= value; v++) {
        if (v % coins[0] == 0)
            prev[v] = 1;
    }

    //write recursive cases in Dp table
    for (int ind = 1; ind < n; ind++) {
        vector<long long > curr (value + 1, 0);
        for (int v = 0; v <= value; v++) {
            //not Take case
            long long notTake =prev[v];
            //take case
            long long take = (v >= coins[ind]) ? curr[v - coins[ind]] : 0;
            curr[v] = take + notTake;
        }
        prev = curr;
    }
    return prev[value];
}


long long int memoisedSol(int n, int value, vector<int> &coins) {

    vector<vector<long long int>> dp (n, vector<long long int> (value + 1, -1));
    return countWays(n - 1, value, coins, dp);
}


int main() {

    vector<int> denom = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};  //denominations of coins
    int value = 1000;
    int n = denom.size();

    cout << "Total no. of ways: " << memoisedSol  (n, value, denom) << "\n";
    cout << "Total no. of ways: " << countWaysTab (n, value, denom) << "\n";
    cout << "Total no. of ways: " << countWaysSO  (n, value, denom) << "\n";

    return 0;
}
/*
    10
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    1000
*/
