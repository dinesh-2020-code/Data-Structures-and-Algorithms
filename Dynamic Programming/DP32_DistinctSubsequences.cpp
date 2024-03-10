/**
 * Problem: Distinct Subsequences
 * Problem Link: https://leetcode.com/problems/distinct-subsequences/description/
 * Problem Statement
 * Given two strings s and t, return the number of distinct subsequences of s which equals t.
 * The test cases are generated so that the answer fits on a 32-bit signed integer.
 *
 * Example 1:
 * Input: s = "rabbbit", t = "rabbit"
 * Output: 3
 * Explanation:As shown below, there are 3 ways you can generate "rabbit" from s.
 * rabbbit
 * rabbbit
 * rabbbit
 * Example 2:
 * Input: s = "babgbag", t = "bag"
 * Output: 5
 * Explanation:
 * As shown below, there are 5 ways you can generate "bag" from s.
 * babgbag
 * babgbag
 * babgbag
 * babgbag
 * babgbag
 * Constraints:
 * 1 <= s.length, t.length <= 1000
 *
 */

#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int distinctSubsequence(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
    //base cases
	if (j < 0)	// if sub string exhausted, we found in string str
		return 1;
	if (i < 0) // if string str exhausted we can't find string 'sub' further
		return 0;
	
	//recursive cases
	// if str[i] == sub[j], then we have 2 cases
	// case 1: include the both chars at i and j i.e., call recursively for solve(i-1, j-1)
	// case 2: do not include the char at str[i], we will take another char from str
	// 			i.e., call solve(i-1, j)
	if (dp[i][j] != -1)
		return dp[i][j];

	if (s1[i] == s2[j]) 
		return dp[i][j] = (distinctSubsequence(i - 1, j - 1, s1, s2, dp)
                             + distinctSubsequence(i - 1, j, s1, s2, dp)) % MOD;
	// else chars not matching
	else	
		return dp[i][j] = (distinctSubsequence(i - 1, j, s1, s2, dp)) % MOD;

}

int distinctSubsequenceTab(string &s1, string &s2) {

    int m = s1.length();
    int n = s2.length();

    vector<vector<int>> dp (m + 1, vector <int> (n + 1, 0));

    //write base case in dp table
	// case 1: if second string exhausted, i.e., j == 0

	for (int i = 0; i <= m; i++) 
		dp[i][0] = 1;
	
	//case 2: If first string exhausted, i.e., i == 0, return 0
	for (int j = 1; j <= n; j++) 
		dp[0][j] = 0;

	//write recursive cases

	for (int i = 1; i <= m; i++) 
	{
		for (int j = 1; j <= n; j++)
		{
			if (s1[i-1] == s2[j-1])
				dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % MOD;
			else
				dp[i][j] = dp[i-1][j] % MOD;
		}
	}
	return dp[m][n];
}


int distinctSubsequenceSO(string &s1, string &s2) {
    int m = s1.length();
    int n = s2.length();

    vector <int> prev (n + 1, 0), curr (n + 1, 0);

    //write base case in dp table
	// case 1: if second string exhausted, i.e., j == 0
	
	//case 2: If first string exhausted, i.e., i == 0, return 0

	//write recursive cases
    prev[0] = 1; 
	for (int i = 1; i <= m; i++) 
	{
        curr[0] = 1;
		for (int j = 1; j <= n; j++)
		{
			if (s1[i-1] == s2[j-1])
				curr[j] = (prev[j-1] + prev[j]) % MOD;
			else
				curr[j] = prev[j] % MOD;
		}
        prev = curr;
	}
	return prev[n];
}


int distinctSubsequenceSOII(string &s1, string &s2) {
    // space optimization to single vector
    int m = s1.length();
    int n = s2.length();

    vector <int> prev (n + 1, 0);

    //write base case in dp table
	// case 1: if second string exhausted, i.e., j == 0
	
	//case 2: If first string exhausted, i.e., i == 0, return 0

	//write recursive cases
    prev[0] = 1;
	for (int i = 1; i <= m; i++) 
	{
		for (int j = n; j >= 1; j--)
		{
			if (s1[i-1] == s2[j-1])
				prev[j] = (prev[j-1] + prev[j]) % MOD;
		}
	}
	return prev[n];
}


int memoizedSol(string &s1, string &s2) {
    int m = s1.length();
    int n = s2.length();

    vector<vector<int>> dp (m, vector<int> (n, -1));
    return distinctSubsequence(m - 1, n - 1, s1, s2, dp);
}


int main() {

    string s1 = "babgbag", s2 = "bag";
    cout << memoizedSol(s1, s2) << "\n";
    cout << distinctSubsequenceTab(s1, s2) << "\n";
    cout << distinctSubsequenceSO(s1, s2) << "\n";
    cout << distinctSubsequenceSOII(s1, s2) << "\n";
    return 0;
}
