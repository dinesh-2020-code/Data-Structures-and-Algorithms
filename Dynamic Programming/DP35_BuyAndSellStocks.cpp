/**
 * 
 * Problem Link: 
 * Problem Statement:
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
