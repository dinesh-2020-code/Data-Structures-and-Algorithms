/**
 * Problem Link: https://www.codingninjas.com/studio/problems/highway-billboards_3125969
 * Problem Statement:
 * You are given a list of stock prices of size 'n' called ‘prices’, where ‘prices[i]’ represents the price on ‘i’th day.
 * Your task is to calculate the maximum profit you can earn by trading stocks if you can only hold one stock at a time.
 * After you sell your stock on the ‘i’th day, you can only buy another stock on ‘i + 2’ th day or later.
 * 
 * Input: 'prices' = [4, 9, 0, 4, 10]   Output: 11
 * Explanation:
 * You are given prices = [4, 9, 0, 4, 10]. To get maximum profits you will have to buy on day 0 and sell on day 1 to make a 
 * profit of 5, and then you have to buy on day 3  and sell on day 4 to make the total profit of 11. Hence the maximum profit is 11.
 * 
*/

#include <iostream>
#include <vector>

using namespace std; 


int maxProfit(int ind, int  buy, int n, vector<int> &prices, vector<vector<int>> &dp) {

    if (ind >= n)
        return 0;
    
    if ( dp[ind][buy] != -1)
        return dp[ind][buy];

    int profit = -1e9;
    //recursive cases
    if (buy) {
        int take = -prices[ind] + maxProfit(ind + 1, 0, n, prices, dp);
        int notTake = 0 + maxProfit(ind + 1, 1, n, prices, dp);
        profit = max(take, notTake);
    }
    else {  //sell teh stock
        int sell = prices[ind] + maxProfit(ind + 2, 1, n, prices, dp);
        int notSell = 0 + maxProfit(ind + 1, 0, n, prices, dp);
        profit = max(sell, notSell);
    }
    return dp[ind][buy] = profit;
}


int maxProfitTab(vector<int> &prices) {
    int n = prices.size();
    vector<vector<int>> dp (n + 2, vector<int> (2, 0) );
    int profit = -1e9;
    for (int ind = n-1; ind >= 0; ind--) {
        for (int buy = 1; buy >= 0; buy--) {
            if (buy == 1) {
                int take = -prices[ind] + dp[ind+1][0];
                int notTake = 0 + dp[ind+1][1];
                profit = max(take, notTake);
            }
            else {
                int sell = prices[ind] + dp[ind + 2][1];
                int notSell = dp[ind+1][0];
                profit = max(sell, notSell);
            }
            dp[ind][buy] = profit;
        }
    }
    return dp[0][1];
}


int memoizedSol(vector<int> &prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int> (2, -1));
    return maxProfit(0, 1, n, prices, dp);
}


int main() {

    vector<int> prices = {4, 9, 0, 4, 10};
    int n = prices.size(); 
    cout << "Max Profit: " << memoizedSol(prices) << "\n";
    cout << "Max Profit: " << maxProfitTab(prices) << "\n";
    return 0;
}
