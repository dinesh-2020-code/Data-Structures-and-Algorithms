/**
 * Problem Link: https://www.codingninjas.com/studio/problems/longest-bitonic-sequence_1062688
 * Problem statement
 * A Bitonic Sequence is a sequence of numbers that is first strictly increasing and then strictly decreasing.
 * A strictly ascending order sequence is also considered bitonic, with the decreasing part as empty, and same 
 * for a strictly descending order sequence.
 * For example, the sequences [1, 3, 5, 3, 2], [1, 2, 3, 4] are bitonic, whereas the sequences [5, 4, 1, 4, 5] 
 * and [1, 2, 2, 3] are not.
 * You are given an array 'arr' consisting of 'n' positive integers.
 * Find the length of the longest bitonic subsequence of 'arr'.
 * 
 * Input: 'arr' = [1, 2, 1, 2, 1]   Output: 3 {[1, 2, 1]}
 * 
 * Input: arr = {1, 11, 2, 10, 4, 5, 2, 1}    Output: 6
 * 
 * Approach: 
 *      We will make use of Longest Increasing Subsequence algorithm. We will find the length of the longest
 *      increasing subsequences of 'arr' from left most and right most ends
 *      i.e., dp1[i] => stores the max length of longest increasing subsequence starting from index 0 till index i
 *            dp2[i] => stores the max length of longest increasing subsequence starting from index n-1 till index i
 *      
 *      Now we will find the length of longest bitonic subsequence using dp1, and dp2 arrays
 *      bitonic[i] = dp1[i] + dp2[i] - 1 (subtracting '1' because one element will be repeated twice)
 * 
 *      for ex:
 *              ind = {0,  1, 2,  3, 4, 5, 6, 7}
 *              arr = {1, 11, 2, 10, 4, 5, 2, 1}
 *              dp1 = {1,  2, 2,  3, 3, 4, 2, 1}
 *              dp2 = {1,  5, 2,  4, 3, 3, 2, 1}
 *          bitonic = {1,  6, 3,  6, 5, 6, 3, 1}
 *          ans will be max(bitonic array elements) = 6
 * 
 */

#include <iostream>
#include <vector>

using namespace std;


vector<int> LISFromFront (vector<int> &arr) {
    int n = arr.size();
    vector<int> dp(n, 1);
    for (int ind = 0; ind < n; ind++) {
        for (int prev = 0; prev < ind; prev++) {
            if (arr[prev] < arr[ind] && 1 + dp[prev] > dp[ind]) {
                dp[ind] = 1 + dp[prev];
            }
        }
    }
    return dp;
}


vector<int> LISFromBack (vector<int> &arr) {
    int n = arr.size();
    vector<int> dp(n, 1);
    for (int ind = n - 1; ind >= 0; ind--) {
        for (int prev = n - 1; prev > ind; prev--) {
            if (arr[prev] < arr[ind] && 1 + dp[prev] > dp[ind]) {
                dp[ind] = 1 + dp[prev];
            }
        }
    }
    return dp;
}


int longestBitonicSeq(vector <int> &arr) {
    int n = arr.size();
    int ans = 1;
    vector<int> dp1 (1, n), dp2 (1, n);
    dp1 = LISFromFront(arr);
    dp2 = LISFromBack (arr);
    //finding the ans
    for (int ind = 0; ind < n; ind++) {
        ans = max (ans, dp1[ind] + dp2[ind] - 1);
    }
    return ans;
}


int main() {

    // vector<int> arr = {1, 10, 2, 3, 4, 5, 6};
    vector<int> arr = {1, 11, 2, 10, 4, 5, 2, 1};
    cout << "Length of Longest Bitonic Subsequence is: " << longestBitonicSeq(arr);
    return 0;
}
