/**
 * 
 * Rod Cutting Problem
 * Problem statement
 * Given a rod of length ‘N’ units. The rod can be cut into different sizes and each size has a cost associated with it. 
 * Determine the maximum cost obtained by cutting the rod and selling its pieces.
 * Note:
 * 1. The sizes will range from 1 to ‘N’ and will be integers.
 * 2. The sum of the pieces cut should be equal to ‘N’.
 * 3. Consider 1-based indexing
 * 
 * Constraints:
 * 1 <= T <= 50
 * 1 <= N <= 100
 * 1 <= A[i] <= 100
 * 
 * Input 1
 * 2
 * 5
 * 2 5 7 8 10
 * 8
 * 3 5 8 9 10 17 17 20
 * 
 * Output 1:
 * 12
 * 24
 * 
 * For test-case 1
 * All possible partitions are:
 * 1,1,1,1,1           max_cost=(2+2+2+2+2)=10
 * 1,1,1,2             max_cost=(2+2+2+5)=11
 * 1,1,3               max_cost=(2+2+7)=11
 * 1,4                 max_cost=(2+8)=10
 * 5                   max_cost=(10)=10
 * 2,3                 max_cost=(5+7)=12
 * 1,2,2               max _cost=(1+5+5)=12    
 * 
 * Idea: Try to pick lengths in all possible ways and sum them up to make N
*/


#include <iostream>
#include <vector> 

using namespace std;

int rodCutting (int ind, int rodLength, vector<int> &price, vector<vector<int>> &dp) {

	if (ind == 0) 
		return (rodLength / 1) * price[0];

	if (dp[ind][rodLength] != -1)
		return dp[ind][rodLength];

	//recursive cases
	//not take the current length
	int notTake = 0 + rodCutting (ind - 1, rodLength, price, dp);
	// take the current length
	int take = (rodLength >= ind + 1) ? (price[ind] + rodCutting (ind, rodLength - (ind + 1), price, dp)) : -1e9;
	return dp[ind][rodLength] = max(notTake, take);
}


int rodCuttingTab (int n, vector <int> &price) {
    // create DP table
    vector<vector<int> > dp (n, vector <int> (n + 1, 0));
    //fill base case in DP table. 
    // ind is 0, while rodLength varies
    for (int l = 0; l <= n; l++)
        dp[0][l] = l * price[0];
    
    //recursive cases
    for (int ind = 1; ind < n; ind++) {
        for (int l = 0; l <= n; l++) {
            int notTake = dp[ind - 1][l];
            int take = (l >= ind + 1) ? price[ind] + dp[ind - 1][l - (ind + 1)] : -1e9;
            dp[ind][l] = max (take, notTake);
        }
    }
    return dp[n - 1][n];
}


int rodCuttingSO (int n, vector <int> &price) {
    // create DP table
    vector <int> curr (n + 1, 0);
    //fill base case in DP table. 
    // ind is 0, while rodLength varies
    for (int l = 0; l <= n; l++)
        curr[l] = l * price[0];
    
    //recursive cases
    for (int ind = 1; ind < n; ind++) {
        for (int l = 0; l <= n; l++) {
            int notTake = curr[l];
            int take = (l >= ind + 1) ? price[ind] + curr[l - (ind + 1)] : -1e9;
            curr[l] = max (take, notTake);
        }
    }
    return curr[n];
}


int memoizedSol (int n, vector<int> &price)
{
	//ind : 0..n-1 and rod-length: 1..n
	vector<vector<int>> dp (n, vector<int> (n + 1, -1));
	return rodCutting (n - 1, n, price, dp);
}


int main () {

    // vector<int> price  = {3, 5, 8, 9, 10, 17, 17, 20};
    // int n = price.size();
    int n; cin >> n;
    vector<int> price (n, 0);
    for (int i = 0; i < n; i++)
        cin >> price[i];

    cout << "Max Cost is: " << memoizedSol (n, price) << "\n";
    cout << "Max Cost is: " << rodCuttingTab (n, price) << "\n";
    cout << "Max Cost is: " << rodCuttingSO (n, price) << "\n";

    return 0;
}
