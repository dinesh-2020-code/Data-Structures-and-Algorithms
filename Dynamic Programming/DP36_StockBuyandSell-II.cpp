/**
 * Problem: Stock Buy and Sell-II
 * Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
 * Problem Statement:
 * You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
 * On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the
 * stock at any time. However, you can buy it then immediately sell it on the same day.
 * Find and return the maximum profit you can achieve.
 * 
 * 
 * Input: prices = [7,1,5,3,6,4]
 * Output: 7
 * Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
 * Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
 * Total profit is 4 + 3 = 7.
 * 
*/

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;


long maxProfit(int ind, int buy, int n, long prices[], long dp[][2]) {
    //ind is the index
    //buy = [0,1] tells whether we can buy stock or not. 
    // buy=1, we can buy the stock(i.e., we aren't holding any stock)
    // buy=0, we can't buy the stock (i.e., we are currently holding the stock)

    //base cases
    //if ind reached out of bound, then we don't matter whether we have stock or not, 
    // we can't get any profit
    if (ind == n)
        return 0;

    if (dp[ind][buy] != -1)
        return dp[ind][buy];
    //recursive cases
    //two case: Either buy or sell
    //case1: Buy stock
    long profit = -1e9;
    if (buy) {
        long buy   = -prices[ind] + maxProfit(ind + 1, 0, n, prices, dp); //take case
        long notBuy= 0 + maxProfit(ind + 1, 1, n, prices, dp);            //not-take case
        profit = max(buy, notBuy);
    }
    else { //case2: Sell stock
        long sell    = prices[ind] + maxProfit(ind + 1, 1, n, prices, dp);
        long notSell = 0 + maxProfit(ind + 1, 0, n, prices, dp);
        profit = max(sell, notSell);
    }
    return dp[ind][buy] = profit;
}


long memoizedSol(long prices[], int n) {
    long dp[n][2]; 
    memset(dp, -1, sizeof(dp));
    return maxProfit(0, 1, n, prices, dp);
}


long maxProfitTab (long prices[], int n) {
    long dp[n + 1][2];
    memset(dp, 0, sizeof(dp));

    //fill base case in dp table
    //base case: if index is n, return 0
    dp[n][0] = dp[n][1] = 0;
    long profit = -1e9;
    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 1; buy >= 0; buy--) {
            if (buy) {
                long buy   = -prices[ind] + dp[ind + 1][0]; //take case
                long notBuy=  0 + dp[ind + 1][1];            //not-take case
                profit = max(buy, notBuy);
            }
            else { //case2: Sell stock
                long sell    = prices[ind] + dp[ind + 1][1];
                long notSell = 0 + dp[ind + 1][0];
                profit = max(sell, notSell);
            }
            dp[ind][buy] = profit;
        }
    }
    return dp[0][1];
    
}


long maxProfitSO (long prices[], int n) {
    long next[2], curr[2];
    memset(next, 0, sizeof(next));
    memset(curr, 0, sizeof(curr));
    long profit = -1e9;
    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 1; buy >= 0; buy--) {
            if (buy) {
                long buy   = -prices[ind] + next[0];  //take case
                long notBuy=  0 + next[1];            //not-take case
                profit = max(buy, notBuy);
            }
            else { //case2: Sell stock
                long sell    = prices[ind] + next[1];
                long notSell = 0 + next[0];
                profit = max(sell, notSell);
            }
            curr[buy] = profit;
        }
        //assign values of curr[] to next[]
        for (int x = 0; x < 2; x++)
            next[x] = curr[x];
    }
    return next[1]; //till index 0 (starting from index n-1), how much profit we can get if we are not holding any stocks previously
}


int main() {

    long prices[] = {7, 1, 5, 3, 6, 4};
    int n = sizeof(prices) / sizeof(prices[0]);
    cout << "Max Profit: " << memoizedSol(prices, n) << "\n";
    cout << "Max Profit: " << maxProfitTab(prices, n) << "\n";
    cout << "Max Profit: " << maxProfitSO(prices, n) << "\n";
    return 0;
}
/**
 * Asymptotic analysis
 *      Simple Recursive: Time: O(2^n) and Space: O(n) Aux stack space
 *      memoisedSol(prices, n) -> Time: O(n * 2), Aux Space: O(n) {aux stack space} + O(n * 2) dp table
 *      maxProfitTab(prices, n) -> Time: O(n * 2), Aux space: O(n * 2) dp table
 *      maxProfitSO(prices, n) -> Time: O(n * 2), Aux space: O(1)
*/