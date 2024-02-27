/**
 * Problem Link: https://www.codingninjas.com/studio/problems/number-of-subsets_3952532
 * Problem statement
 * You are given an array 'arr' of size 'n' containing positive integers and a target sum 'k'.
 * Find the number of ways of selecting the elements from the array such that the sum of chosen 
 * elements is equal to the target 'k'.
 * 
 * Input: 4 5 // N K
 * array: {1, 4, 4, 5}
 * 
 * Output: 3
 * 
 * Input: 3 4
 * array: {0, 1, 3}
 * 
 * Output: 2 {0, 1, 3} and {1, 3}
*/

#include <iostream>
#include <vector>

using namespace std;

const int mod = 1000000007; 

int countSubsetsWithSumK(int ind, int curr_sum, vector<int> &arr, vector<vector<int>> &dp) {

	//base cases
	if (ind == 0) {
		if (curr_sum == 0 && arr[0] == 0)
			return 2; // 2 possible case, either take 0 or don't take 0
		
		if (curr_sum == 0 || arr[0] == curr_sum)
			return 1; 
		else
			return 0; 
	}
	if (dp[ind][curr_sum] != -1)
		return dp[ind][curr_sum]; 

	int notPick = countSubsetsWithSumK(ind - 1, curr_sum, arr, dp); 
	int pick    = (arr[ind] <= curr_sum) ? countSubsetsWithSumK(ind - 1, curr_sum - arr[ind], arr, dp) : 0; 
	return dp[ind][curr_sum] = (notPick + pick ) % mod; 
}



int main() {

    vector<int> arr = {0, 0, 3};
    int k = 3; 
    int n = arr.size(); 
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    cout << countSubsetsWithSumK(n - 1, k, arr, dp) << "\n";

    return 0;
}
