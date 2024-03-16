/**
 * Problem: Stock Buy And Sell-III
 * Problem Link: https://www.codingninjas.com/studio/problems/buy-and-sell-stock_1071012
 * Problem Statement:
 * 
 * 
*/

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;


long maxProfit(int ind, int buy, int cap, int n, long prices[], long dp[][2][3]) {
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


long maxProfitTab(long prices[], int n) {
    long dp[n + 1][2][3];
    memset(dp, 0, sizeof(dp));

    //writing base cases
    //base case: if cap == 0, return 0
    // index can be anything (0 -> n-1) and buy [0, 1]

    for (int ind = 0; ind < n; ind++) 
        for (int buy = 0; buy < 2; buy++) 
            dp[ind][buy][0] = 0;

    //case 2: ind == n 
    for (int buy = 0; buy < 2; buy++)
        for (int cap = 0; cap < 3; cap++) 
            dp[n][buy][cap] = 0;
    
    long profit = -1e9;
    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 1; buy >= 0; buy--) {
            for (int cap = 2; cap >= 1; cap--) {  //cap ranges from [1, 2]because for cap = 0, ans is 0 (base case)
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
    return dp[0][1][2];
}


long memoizedSol(long prices[], int n) {
    // 0 <= ind < n
    // buy can have two states, buy = [0, 1], 0 means can't buy, 1 means can buy
    // cap can have 3 states, cap = [0, 1, 2], 0 means can't do anymore transactions
                                // 1 , 2 means can left with one and two transaction(s) respectively
    long dp[n][2][3]; 
    memset(dp, -1, sizeof(dp));
    return maxProfit(0, 1, 2, n, prices, dp);
}


int main() {

    long prices[] = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = sizeof(prices) / sizeof(prices[0]);
    cout << "Max Profit: " << memoizedSol(prices, n) << "\n";
    cout << "Max Profit: " << maxProfitTab(prices, n) << "\n";
    return 0;
}