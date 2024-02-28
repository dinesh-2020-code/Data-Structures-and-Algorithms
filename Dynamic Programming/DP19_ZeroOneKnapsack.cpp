/**
 * Problem Link: https://www.codingninjas.com/studio/problems/0-1-knapsack_920542
 * Problem statement
 * A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are N items and the ith 
 * item weighs wi and is of value vi. Considering the constraints of the maximum weight that a knapsack can carry, 
 * you have to find and return the maximum value that a thief can generate by stealing items.
 * 
 * 
 * Input:
 * weights = {3, 2, 5}
 * values  = {30, 40, 60}
 * max_weight = 6
 * 
 * Output: 70
*/

#include <iostream>
#include <vector>

using namespace std;


int knapsack(int ind, int cap, vector<int> &weight, vector<int> &value, vector<vector<int>> &dp) {
	//base cases
	if (ind == 0) {
		//case 1: If cap left is >= weight at 0th index, so take it
		if (cap >= weight[0])
			return value[0];
		else
			return 0;
	}

	if (dp[ind][cap] != -1)
		return dp[ind][cap];

	int notTake = 0 + knapsack(ind - 1, cap, weight, value, dp);
	//take only if cap >= weight[ind]
	int take = (cap >= weight[ind]) ? value[ind] + knapsack(ind - 1, cap - weight[ind], weight, value, dp) : -1e9;
	return dp[ind][cap] = max(take, notTake);

	// Time complexity: O (2 ^ (N * MaxWeight)) Recursive
	// 					 O(N * MaxWeight)		Memoization
}


int main()
{
    vector<int> weights = {1, 2, 4, 5};
    vector<int> values  = {5, 4, 8, 6};
    int maxWeight = 5;
    int n = weights.size();
    vector<vector<int>> dp (n, vector<int> (maxWeight + 1, -1));
    cout << "The Maximum value of items the thief can steal is " << knapsack(n - 1, maxWeight, weights, values, dp);
    return 0; 
}