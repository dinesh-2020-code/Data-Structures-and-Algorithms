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

int main() {

    vector<int> arr = {5, 2, 6, 4};
    int n    = arr.size(); 
    int diff = 3; 
    cout << "Total Partitions with Diff D are: " << countPartitionWithGivenDiff(arr, diff) << endl;
    return 0; 
}
