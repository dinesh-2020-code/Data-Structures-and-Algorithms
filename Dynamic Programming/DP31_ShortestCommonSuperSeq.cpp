/**
 * Shortest Common Super-sequence
 * Problem statement
 * Given two strings, ‘A’ and ‘B’. Return the shortest supersequence string ‘S’, containing both ‘A’ and ‘B’ as its 
 * subsequences. If there are multiple answers, return any of them.
 * Note: A string 's' is a subsequence of string 't' if deleting some number of characters from 't' (possibly 0) results 
 * in the string 's'.
 * For example: Suppose ‘A’ = “brute”, and ‘B’ = “groot”
 * The shortest supersequence will be “bgruoote”. As shown below, it contains both ‘A’ and ‘B’ as subsequences.
 * 
 * 
*/

#include <iostream>
#include <vector>

using namespace std;


string printLCS(string &s1, string &s2) {

	int m = s1.length(), n = s2.length();
	vector<vector<int>> dp (m + 1, vector <int> (n + 1, 0));

	//base cases
	for (int ind2 = 0; ind2 <= n; ind2++)
		dp[0][ind2] = 0;
	for (int ind1 = 0; ind1 <= m; ind1++)
		dp[ind1][0] = 0;

	for (int ind1 = 1; ind1 <= m; ind1++)
		for (int ind2 = 1; ind2 <= n; ind2++) 
			if (s1[ind1-1] == s2[ind2-1])
				dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
			else
				dp[ind1][ind2] = max (dp[ind1-1][ind2], dp[ind1][ind2-1]);

	//add the LCS ot ans + non-common chars to be added mandatorily
	
	string ans = "";
	int len = dp[m][n]; 
	int ans_len = (m - len) + (n - len) + len;
	ans_len = (m + n - len);
	for (int i = 0; i < ans_len; i++)
		ans += '$';

	int index = ans_len - 1;
	int ind1 = m, ind2 = n;

	while (ind1 > 0 && ind2 > 0) {
		if (s1[ind1-1] == s2[ind2-1]) {
			ans[index--] = s1[ind1-1]; // take the common char once
			ind1--; ind2--;
		}
		else if (dp[ind1-1][ind2] > dp[ind1][ind2-1]) {
            ans[index--] = s1[ind1-1];  // moving one row up will lose char in that row, so taking that char in the ans
			ind1--;
		}
		else {
            ans[index--] = s2[ind2-1]; // moving one col to left will lose char in that col, so taking that char in the ans
			ind2--;
        }
	}
    while (ind1 > 0) {
        ans[index--] = s1[ind1-1];
        ind1--;
    }

    while (ind2 > 0) {
        ans[index--] = s2[ind2-1];
        ind2--;
    }
	return ans;
}


string shortestSupersequence(string a, string b)
{
	return printLCS(a, b);
}


int main() {

    string s1, s2;
    s1 = "brute"; s2 = "groot";
    cout << shortestSupersequence(s1, s2);
    return 0;
}
