/**
 * 
 * Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
 * Problem Statement:
 * You are given an array prices where prices[i] is the price of a given stock on the ith day.
 * You want to maximize your profit by choosing a single day to buy one stock and choosing a
 * different day in the future to sell that stock.
 * Return the maximum profit you can achieve from this transaction. If you cannot achieve any
 * profit, return 0.
 * 
 * 
*/

#include <iostream>
#include <vector>

using namespace std;


int maximumProfit(vector<int> &prices){
    
    int mini = 0;
    int maxProfit = 0;

    for (int i = 1; i < prices.size(); i++) {
        int cost = prices[i] - prices[mini];
        maxProfit= max(maxProfit, cost);
        if (prices[i] < prices[mini])
            mini = i;
    } 
    return maxProfit;
}


int main() {

    vector <int> prices = {7, 1, 5, 3, 6, 4};
    cout << maximumProfit(prices) << "\n";
}
