/**
 * Problem: Number of Longest Increasing Subsequences
 * Problem Link: https://www.codingninjas.com/studio/problems/number-of-longest-increasing-subsequence_3751627
 * Problem Statement:
 * Given an integer array ‘arr’ of length ‘n’, return the number of longest increasing subsequences in it.
 * The longest increasing subsequence(LIS) is the longest subsequence of the given sequence such that all 
 * subsequent elements are in strictly increasing order.
 * 
 * Input: arr = {1, 3, 5, 4, 7}
 * Output: 2 {{1, 3, 4, 7}, {1, 3, 5, 7}}
 * 
 * 
 * Efficient Approach: 
 *     We will make use of LIS algorithm
 *     We will find the LIS array (say dp) where dp[i] tells that length of Longest Increasing subsequence
 *     starting from index 0 till index '1', i.e., [0..i]
 *     Also we will make use of another array cnt, where cnt[i] tells that total number of subsequences from
 *     index 0 till index 'i' with maximum length of dp[i].
 * 
 *      for instance
 *      ind = {0, 1, 2, 3, 4, 5, 6,  7, 8, 9}
 *      arr = {1, 5, 4, 3, 2, 6, 7, 10, 8, 9}
 *      dp  = {1, 2, 2, 2, 2, 3, 4,  5, 5, 6}
 *      cnt = {1, 1, 1, 1, 1, 4, 4,  4, 4, 4}
 * 
 *      Length of longest increasing subsequence here is max (dp[i]s) which is 6 here
 *  
*/

#include <iostream>
#include <vector>


using namespace std;


int numOfLongestIncreasingSubseq (vector<int> &arr) {

    int n = arr.size();
    vector<int> dp (n, 1), cnt (n, 1);
    int maxLength = 1;
    for (int ind = 0; ind < n; ind++) {
        for (int prev = 0; prev < ind; prev++) {
            if (arr[prev] < arr[ind] && 1 + dp[prev] > dp[ind]) {
                dp[ind] = 1 + dp[prev];
                //inherit the cound
                cnt[ind] = cnt[prev];
            }
            else if (arr[prev] < arr[ind] && 1 + dp[prev] == dp[ind]) {
                //increment the cnt[i]
                cnt[ind] += cnt[prev];
            }
        }
        maxLength = max(maxLength, dp[ind]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] == maxLength)
            ans += cnt[i];
    }
    return ans;

}


int main() {

    // vector<int> arr = {1, 3, 5, 4, 7};
    vector<int> arr = {1, 5, 4, 3, 2, 6, 7, 10, 8, 9};
    cout << numOfLongestIncreasingSubseq (arr) << endl;
    return 0;
}
