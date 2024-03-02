/**
 * 
 * 
*/

#include <iostream>
#include <vector>

using namespace std; 


int unboundedKnapsack (int ind, int cap, vector <int> &profit, vector <int> &weight, vector<vector<int>> &dp) {
    
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

    cout << "Max Profit is: " << memoizedSol(n - 1, capacity, profit, weight) << "\n";

}
