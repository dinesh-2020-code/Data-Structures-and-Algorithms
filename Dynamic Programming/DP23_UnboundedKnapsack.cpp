/**
 * 
 * 
*/

#include <iostream>
#include <vector>

using namespace std; 


int unboundedKnapsack (int ind, int cap, vector <int> &profit, vector <int> &weight, vector<vector<int>> &dp) {
    // Time: O (n * cap)
    // Aux Space: O (n * cap) + O (cap) {recursive stack space}
    //base cases
    if (ind == 0) {

        if (cap >= weight[0]) {
            // cap/weight[0] is the max no. of times we can take element with weight[0] 
            return ((cap / weight[0]) * profit[0]);
        }
        else
            return 0;
    }

    if (dp[ind][cap] != -1)
        return dp[ind][cap];
    //notTake case
    int notTake = unboundedKnapsack(ind - 1, cap, profit, weight, dp);
    //take case
    int take = (cap >= weight[ind]) ? (profit[ind] + unboundedKnapsack(ind, cap - weight[ind], profit, weight, dp)) : -1e9;
    return dp[ind][cap] = max(take, notTake);

}


int unboundedKnapsackTab (int n, int cap, vector <int> &profit, vector <int> &weight) {
    // Time: O (n * cap)
    // Aux Space: O (n * cap)
    vector<vector<int>> dp (n, vector<int> (cap + 1, 0));
    //fill base case in DP table
    //ind is 0, capacity can range as 0 <= cap <= maxCapacity
    for (int c = 0; c <= cap; c++) {
        if (c >= weight[0]) 
            dp[0][c] = (c / weight[0]) * profit[0];
    }

    //recursive cases
    for (int ind = 1; ind < n; ind++) {
        for (int c = 0; c <= cap; c++) {
            int notTake = dp[ind - 1][c];
            int take = (c >= weight[ind]) ? profit[ind] + dp[ind][c - weight[ind]] : -1e9;
            dp[ind][c] = max (take, notTake);
        }
    }
    return dp[n - 1][cap];
}


int unboundedKnapsackSO (int n, int cap, vector <int> &profit, vector <int> &weight) {
    // Time: O (n * cap)
    // Aux Space: O (n * cap)
    vector<int> prev (cap + 1, 0), curr (cap + 1, 0);
    //fill base case in DP table
    //ind is 0, capacity can range as 0 <= cap <= maxCapacity
    for (int c = 0; c <= cap; c++) {
        if (c >= weight[0]) 
            prev[c] = (c / weight[0]) * profit[0];
    }

    //recursive cases
    for (int ind = 1; ind < n; ind++) {
        for (int c = 0; c <= cap; c++) {
            int notTake = prev[c];
            int take = (c >= weight[ind]) ? profit[ind] + curr[c - weight[ind]] : -1e9;
            curr[c] = max (take, notTake);
        }
        prev = curr;
    }
    return prev[cap];
}


int memoizedSol (int n, int cap, vector <int> &profit, vector <int> &weight) {

    vector<vector<int>> dp (n, vector<int> (cap + 1, -1));
    return unboundedKnapsack(n - 1, cap, profit, weight, dp);
}


int main() {

    int capacity = 4;
    vector <int> profit = {5, 4, 8, 9, 1, 6, 3, 2, 7, 10 };
    vector <int> weight = {5, 6, 3, 4, 1, 2, 10, 7, 8, 9 };
    int n = profit.size();

    cout << "Max Profit is: " << memoizedSol(n, capacity, profit, weight) << "\n";
    cout << "Max Profit is: " << unboundedKnapsackTab (n, capacity, profit, weight) << "\n";
    cout << "Max Profit is: " << unboundedKnapsackSO  (n, capacity, profit, weight) << "\n";

}
