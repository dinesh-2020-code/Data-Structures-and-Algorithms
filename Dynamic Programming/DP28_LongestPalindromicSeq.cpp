/**
 * 
 * Problem: Longest Palindromic Subsequence
 * 
 * s = "bbbab"
 * Palindromic subsequences are: "bb", "bbb", "bbbb", "bab"
 * Output : 4 (bbbb)
 * 
 * Idea: Reverse the given string and find the LCS of original string and reversed string.
 *  
 * 
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int lcs (string &s1, string &s2) {

    int m = s1.size(); 
    int n = s2.size();

    //shifting the index by 1 to the right to make tabulation easy as in base case we have neg index
    vector <vector<int> > dp (m + 1, vector <int> (n + 1, 0));
    //fill base case
    // by shifting the index by 1 to right will change the base cases as 
    // ind1 == 0 || ind2 == 0 => return 0;
    // ind1 == 0, ind2 can be anything from 0..n
    for (int ind2 = 0; ind2 <= n; ind2++) {
        dp[0][ind2] = 0;
    }
    //if ind2 == 0, ind1 can be anything from 0..m
    for (int ind1 = 0; ind1 <= m; ind1++) {
        dp[ind1][0] = 0;
    }
    for (int ind1 = 1; ind1 <= m; ind1++) {
        for (int ind2 = 1; ind2 <= n; ind2++) {
            if (s1[ind1-1] == s2[ind2-1])
                dp[ind1][ind2] =  1 + dp[ind1-1][ind2-1];
            else
                dp[ind1][ind2] = max(dp[ind1-1][ind2], dp[ind1][ind2-1]);
        }
    }
    return dp[m][n];
}


int longestPalindromicSubSequence (string &s1) {

    string s2 = s1;
    reverse(s2.begin(), s2.end());
    return lcs (s1, s2);
}


int main() {

    string s = "bbabcbcab";   // Output: 7 (babcbab)
    cout << longestPalindromicSubSequence(s) << endl;

    return 0;
}
// Time Complexity: O (m * n), where m is the length of string s1, n is the length of string s2