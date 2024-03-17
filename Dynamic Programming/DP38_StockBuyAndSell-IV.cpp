/**
 * Problem Link: https://www.codingninjas.com/studio/problems/best-time-to-buy-and-sell-stock_1080698
 * Problem Statement:
 * You have been given an array 'PRICES' consisting of 'N' integers where PRICES[i] denotes the price of a given stock
 * on the i-th day. You are also given an integer 'K' denoting the number of possible transactions you can make.
 * Your task is to find the maximum profit in at most K transactions. A valid transaction involves buying a stock and then 
 * selling it.
 * Note: You can’t engage in multiple transactions simultaneously, i.e. you must sell the stock before rebuying it.
 * 
 * 
*/


#include <iostream>
#include <vector>
#include <cstring>

using namespace std;


long maxProfit(int ind, int buy, int cap, int n, long prices[], vector<vector<vector<long>>> &dp) {
    //ind is the index
    //buy = [0,1] tells whether we can buy stock or not. 
    // buy=1, we can buy the stock(i.e., we aren't holding any stock)
    // buy=0, we can't buy the stock (i.e., we are currently holding the stock)

    //base cases
    //if capacity becomes 0 (transaction limit exhausted)
    if (cap == 0)
        return 0;
    //if ind reached out of bound, then we don't matter whether we have stock or not, 
    // we can't get any profit
    if (ind == n)
        return 0;

    if (dp[ind][buy][cap] != -1)
        return dp[ind][buy][cap];
    //recursive cases
    //two case: Either buy or sell
    //case1: Buy stock
    long profit = -1e9;
    if (buy) {
        long buy   = -prices[ind] + maxProfit(ind + 1, 0, cap, n, prices, dp); //take case
        long notBuy= 0 + maxProfit(ind + 1, 1, cap, n, prices, dp);        //not-take case
        profit = max(buy, notBuy);
    }
    else { //case2: Sell stock
        long sell    = prices[ind] + maxProfit(ind + 1, 1, cap - 1, n, prices, dp);
        long notSell = 0 + maxProfit(ind + 1, 0, cap, n, prices, dp);
        profit = max(sell, notSell);
    }
    return dp[ind][buy][cap] = profit;
}


long maxProfitTab(long prices[], int n, int k) {
    long dp[n + 1][2][k + 1];
    memset(dp, 0, sizeof(dp));

    //writing base cases
    //base case: if cap == 0, return 0
    // index can be anything (0 -> n-1) and buy [0, 1]

    for (int ind = 0; ind < n; ind++) 
        for (int buy = 0; buy < 2; buy++) 
            dp[ind][buy][0] = 0;

    //case 2: ind == n 
    for (int buy = 0; buy < 2; buy++)
        for (int cap = 0; cap <= k; cap++) 
            dp[n][buy][cap] = 0;
    
    long profit = -1e9;
    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 1; buy >= 0; buy--) {
            for (int cap = k; cap >= 1; cap--) {  //cap ranges from [1, 2]because for cap = 0, ans is 0 (base case)
                if (buy) {
                    long buy   = -prices[ind] + dp[ind + 1][0][cap]; //take case
                    long notBuy= 0 + dp[ind + 1][1][cap];           //not-take case
                    profit = max(buy, notBuy);
                }
                else { //case2: Sell stock
                    long sell    = prices[ind] + dp[ind + 1][1][cap - 1];
                    long notSell = 0 + dp[ind + 1][0][cap];
                    profit = max(sell, notSell);
                }
                dp[ind][buy][cap] = profit;
            }
        }
    }
    return dp[0][1][k];
}


long maxProfitSO(long prices[], int n, int k) {
    // Aux Space: O(1)
    vector<vector <int>> next (2, vector<int> (k + 1, 0));
    vector<vector <int>> curr (2, vector<int> (k + 1, 0));
    
    //writing base cases
    //base case: if cap == 0, return 0
    // index can be anything (0 -> n-1) and buy [0, 1]
    //No need to write base cases as next is already filled with 0
    // for (int ind = 0; ind < n; ind++) 
    //     for (int buy = 0; buy < 2; buy++) 
    //         dp[ind][buy][0] = 0;

    // //case 2: ind == n 
    // for (int buy = 0; buy < 2; buy++)
    //     for (int cap = 0; cap < 3; cap++) 
    //         dp[n][buy][cap] = 0;
    
    long profit = -1e9;
    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 1; buy >= 0; buy--) {
            for (int cap = k; cap >= 1; cap--) {  //cap ranges from [1, 2]because for cap = 0, ans is 0 (base case)
                if (buy) {
                    long buy   = -prices[ind] + next[0][cap]; //take case
                    long notBuy= 0 + next[1][cap];           //not-take case
                    profit = max(buy, notBuy);
                }
                else { //case2: Sell stock
                    long sell    = prices[ind] + next[1][cap - 1];
                    long notSell = 0 + next[0][cap];
                    profit = max(sell, notSell);
                }
                curr[buy][cap] = profit;
            }
        }
        next = curr;
    }
    return next[1][k];
}


long memoizedSol(long prices[], int n, int k) {
    // 0 <= ind < n
    // buy can have two states, buy = [0, 1], 0 means can't buy, 1 means can buy
    // cap can have 3 states, cap = [0, 1, 2], 0 means can't do anymore transactions
                                // 1 , 2 means can left with one and two transaction(s) respectively
    vector<vector<vector<long>>> dp (n, vector<vector<long> > (2, vector<long> (k + 1, -1)));
    return maxProfit(0, 1, k, n, prices, dp);
}


int main() {

    long prices[] = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = sizeof(prices) / sizeof(prices[0]);
    int k = 3;
    cout << "Max Profit: " << memoizedSol(prices, n, k) << "\n";
    cout << "Max Profit: " << maxProfitTab(prices, n, k) << "\n";
    cout << "Max Profit: " << maxProfitSO(prices, n, k) << "\n";
    return 0;
}
