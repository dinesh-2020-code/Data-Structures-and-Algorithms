/**
 * 
 * Problem Link: 
 * Problem statement
 * You are given an array ‘ARR’ of ‘N’ integers and a target number, ‘TARGET’. Your task is to build 
 * an expression out of an array by adding one of the symbols '+' and '-' before each integer in an 
 * array, and then by concatenating all the integers, you want to achieve a target. You have to return
 *  the number of ways the target can be achieved.
 * For Example :
 * You are given the array ‘ARR’ = [1, 1, 1, 1, 1], ‘TARGET’ = 3. The number of ways this target can 
 * be achieved is:
 * 1. -1 + 1 + 1 + 1 + 1 = 3
 * 2. +1 - 1 + 1 + 1 + 1 = 3
 * 3. +1 + 1 - 1 + 1 + 1 = 3
 * 4. +1 + 1 + 1 - 1 + 1 = 3
 * 5. +1 + 1 + 1 + 1 - 1 = 3
 * These are the 5 ways to make. Hence the answer is 5.
 * 
 * Idea: Let us assume that array contains elements as [1 2 3 1], target = 3
 *      we have to assign the sign to each number, 
 *      one possible way can be: -1 + 2 + 3 -1
 *      we can write as {2 + 3} - {1 + 1} = 3
 *      This means we have tod divide the elements into two sets S1 and S2 such that there diff is exactly target
 *      S1 = {2, 3} S2 = {1, 1}
 *      sum(S1) = 5, sum(S2) = 2 => S1 - S2 = 3 => DP18
 *      
*/

#include <iostream>
#include <vector>

using namespace std;


const int mod = 1000000007; 

int countSubsetsWithSumK(int ind, int curr_sum, vector<int> &arr, vector<vector<int>> &dp) {

	//base cases
	if (ind == 0) {
		if (curr_sum == 0 && arr[0] == 0)  //case 1
			return 2; // 2 possible case, either take 0 or don't take 0
		
		if (curr_sum == 0 || arr[0] == curr_sum)  // case 2
			return 1; 
		else
			return 0;  // case 3
	}
	if (dp[ind][curr_sum] != -1)
		return dp[ind][curr_sum]; 

	int notPick = countSubsetsWithSumK(ind - 1, curr_sum, arr, dp); 
	int pick    = (arr[ind] <= curr_sum) ? countSubsetsWithSumK(ind - 1, curr_sum - arr[ind], arr, dp) : 0; 
	return dp[ind][curr_sum] = (notPick + pick ) % mod; 
}


int targetSum (int diff, vector<int> &arr, vector<vector<int>> &dp) {
    int totalSum = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
        totalSum += arr[i];

    if ((totalSum - diff) < 0 || (totalSum - diff) % 2 == 1)  // s1 - s2 = diff
        return 0;

    int target = (totalSum - diff) / 2;
    // cout << target << "\n";
    return countSubsetsWithSumK(n - 1, target, arr, dp);
}



int targetSumTab (vector<int> &arr, int diff) {
    int totalSum = 0; 
    for (auto it : arr)
        totalSum += it;

    if ((totalSum - diff) < 0 || (totalSum - diff) % 2)
        return 0;
    int n = arr.size();
    int k = (totalSum - diff) / 2; // s1 - s2 = d, putting s1 as totalSum - s2
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));
    
    //write base cases in table
    if (arr[0] == 0)   // case 1
        dp[0][0] = 2;
    else 
        dp[0][0] = 1; // case 2
    
    if (arr[0] != 0 && arr[0] <= k)   // case 2 (arr[0] == curr_sum arr [5], curr_sum is also 5, so there is 1 way only)
        dp[0][arr[0]] = 1;

    for (int ind = 1; ind < n; ind++) {

        for (int curr_sum = 0; curr_sum <= k; curr_sum++) {
            int notPick = dp[ind - 1][curr_sum];
            int pick = (arr[ind] <= curr_sum) ? dp[ind - 1][curr_sum - arr[ind]] : 0;
            dp[ind][curr_sum] = (pick + notPick) % mod; 
        }
    }
    return dp[n-1][k]; 
}


int memoizedSol(vector<int> &arr, int target) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int> (target + 1, -1));
    return targetSum(target, arr, dp);
}

int main() {

    vector<int> arr = {1, 1, 1, 1, 1};
    int target = 3;

    cout << "The total no. of ways to form  " << target << " are: " << memoizedSol(arr, target) << "\n"; 
    cout << "The total no. of ways to form  " << target << " are: " << targetSumTab(arr, target) << "\n"; 

    return 0;
}
