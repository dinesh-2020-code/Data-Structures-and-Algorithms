/**
 * Problem Link: https://www.codingninjas.com/studio/problems/rahul-and-his-chocolates_3118974
 * Problem Statement:
 * You are given an array 'prices' of size 'n', denoting the price of stocks on 'n' days.
 * Rahul can buy one stock at a time, and he must sell it before buying stock on another day.
 * The entire transaction of selling and buying the stock requires some transaction fee, given as 'fee'.
 * Find the maximum profit Rahul can achieve by trading on the stocks.
 * 
 * Example :
 * Input: 'prices' =  [1, 2, 3] and 'fee' = 1    Output: 1
 * Explanation: We can generate the maximum profit of 1 by buying the stock on the first day for price = 1 and 
 * then selling it on the third day for price = 3.
 * The profit will be: 3 - 1 - 1(transaction fee) = 1
*/

#include <iostream>
#include <vector>

using namespace std;

int maxProfit(int ind, int buy, int fee, int n, vector<int> &prices, vector<vector<int>> &dp) {

	if (ind == n)
		return 0;

	if (dp[ind][buy] != -1)
		return dp[ind][buy];
	//recursive cases
	int profit = -1e9;
	if (buy) {
		int buy = -prices[ind] + maxProfit(ind + 1, 0, fee, n, prices, dp);
		int notBuy = 0 + maxProfit(ind + 1, 1, fee, n, prices, dp);
		profit = max(buy, notBuy);

	} else {  //sell the stock

		int notSell = maxProfit(ind + 1, 0, fee, n, prices, dp);
		int sell = prices[ind] - fee + maxProfit(ind + 1, 1, fee, n, prices, dp);
		profit = max(sell, notSell);
	}
	return dp[ind][buy] = profit;
}


long maxProfitTab (vector<int> &prices, int n, int fee) {
    vector<vector<int>> dp (n + 1, vector<int> (2, 0));

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
                long sell    = prices[ind] + dp[ind + 1][1] - fee;
                long notSell = 0 + dp[ind + 1][0];
                profit = max(sell, notSell);
            }
            dp[ind][buy] = profit;
        }
    }
    return dp[0][1];
    
}


long maxProfitSO (vector<int> &prices, int n, int fee) {
    vector<int> next(2, 0), curr(2, 0);
    long profit = -1e9;
    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 1; buy >= 0; buy--) {
            if (buy) {
                long buy   = -prices[ind] + next[0];  //take case
                long notBuy=  0 + next[1];            //not-take case
                profit = max(buy, notBuy);
            }
            else { //case2: Sell stock
                long sell    = prices[ind] + next[1] - fee;
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


int memoizedSol(vector<int> &prices, int n, int fee) {
	vector<vector<int>> dp (n, vector<int> (2, -1));
    return maxProfit(0, 1, fee, n, prices, dp);
}


int main() {

    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int n = prices.size();
    int fee = 2;
    cout << "Max Profit is : "<< memoizedSol(prices, n, fee) << endl;
    cout << "Max Profit is : "<< maxProfitTab(prices, n, fee) << endl;
    cout << "Max Profit is : "<< maxProfitSO(prices, n, fee) << endl;

    return 0;
}
