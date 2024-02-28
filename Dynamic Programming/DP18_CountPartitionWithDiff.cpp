/**
 * Problem statement
 * Given an array ‘ARR’, partition it into two subsets (possibly empty) such that their union
 * is the original array. Let the sum of the elements of these two subsets be ‘S1’ and ‘S2’.
 * Given a difference ‘D’, count the number of partitions in which ‘S1’ is greater than or 
 * equal to ‘S2’ and the difference between ‘S1’ and ‘S2’ is equal to ‘D’. Since the answer 
 * may be too large, return it modulo ‘10^9 + 7’.
 * 
 * If ‘Pi_Sj’ denotes the Subset ‘j’ for Partition ‘i’. Then, two partitions P1 and P2 are 
 * considered different if:
 * 1) P1_S1 != P2_S1 i.e, at least one of the elements of P1_S1 is different from P2_S2.
 * 2) P1_S1 == P2_S2, but the indices set represented by P1_S1 is not equal to the indices 
 *    set of P2_S2. Here, the indices set of P1_S1 is formed by taking the indices of the elements 
 *    from which the subset is formed.
 * Refer to the example below for clarification.
 * Note that the sum of the elements of an empty subset is 0.
 * 
 * For example :
 * If N = 4, D = 3, ARR = {5, 2, 5, 1}
 * There are only two possible partitions of this array.
 * Partition 1: {5, 2, 1}, {5}. The subset difference between subset sum is: (5 + 2 + 1) - (5) = 3
 * Partition 2: {5, 2, 1}, {5}. The subset difference between subset sum is: (5 + 2 + 1) - (5) = 3
 * These two partitions are different because, in the 1st partition, S1 contains 5 from index 0, and 
 * in the 2nd partition, S1 contains 5 from index 2.
 * 
 * Idea : 
 *      we know for s1 >= s2, given s1 - s2 = d
 *          => (totalSum - s2) - s2 = d, 
 *          => totalSum - 2s2 = d
 *          => s2 = (totalSum - d) / 2
 * 
 *          we need to find the target s2 in array
 * 
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

int countPartitionWithGivenDiff(vector<int> &arr, int diff) {
    int totalSum = 0; 
    for (auto it : arr)
        totalSum += it;

    if ((totalSum - diff) < 0 || (totalSum - diff) % 2)
        return 0;
    int n = arr.size();
    int target = (totalSum - diff) / 2;
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    int ans = countSubsetsWithSumK(n - 1, target, arr, dp);
    return ans;
    
}


int countPartitionWithGivenDiffTab( vector<int> &arr, int diff) {
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


int main() {

    // vector<int> arr = {5, 2, 6, 4}; diff = 3
    vector<int> arr = {1, 1, 1, 1};
    int n    = arr.size(); 
    int diff = 0; 
    cout << "Total Partitions with Diff " << diff << " are: " << countPartitionWithGivenDiff(arr, diff) << endl;
    cout << "Total Partitions with Diff " << diff << " are: " << countPartitionWithGivenDiffTab(arr, diff) << endl;
    return 0; 
}
