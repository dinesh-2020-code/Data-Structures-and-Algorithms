/**
 * 
 * Subsequence: A subsequence is a sequence that can be derived an array by 
 * deleting some or no elements without changing the order of the remaining elements.
 * 
 * For a string of length n, we have 2 ^ n subsequences 
 * we will make use of indexes to represent the two strings (ind1, ind2)
 * f (ind1, ind2) => LCS of strings s1(0..ind1) and s2(0..ind2)
 * 
 * Do comparison character wise
 * 
 * s1 = acd
 * s2 = ced
 * 
 * f (ind1, ind2) {
 *      base case
 *      if (ind1 < 0 || ind2 < 0) //end of string
 *           return 0
 * 
 *      if (s1[ind1] == s2[ind2])
 *          return 1 + f(ind1-1, ind2-1)
 * 
 *      case1 = 0 + f(ind1 - 1, ind2)
 *      case2 = 0 + f(ind1, ind2 - 1)
 *      return max(case1, case2)
 * }
 * 
 * Recursive Time Complexity: (2 ^ n * 2 ^ m) which is exponential.
 * 
 *  
*/

#include <iostream>
#include <vector>

using namespace std;


// Time Complexity: O (m * n)
// Aux Space: O (m * n) + O (m + n) {recursive stack space}
int lcs (int ind1, int ind2, string &s1, string &s2, vector<vector<int>> &dp) {
    //base case
    if (ind1 < 0 || ind2 < 0)
        return 0;

    //char matches
    if (s1[ind1] == s2[ind2])
        return 1 + lcs (ind1 - 1, ind2 - 1, s1, s2, dp);

    //not matching
    return max (lcs (ind1 - 1, ind2, s1, s2, dp), lcs (ind1, ind2 - 1, s1, s2, dp));
}


int lcsTab(string &s1, string &s2) {

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


int memoizedSol (string &s1, string &s2) {

    int m = s1.size(), n = s2.size();
    vector <vector<int >> dp (m, vector<int> (n, -1));
    return lcs(m - 1, n - 1, s1, s2, dp);
}


int main() {

    string s1, s2;
    cin >> s1 >> s2;

    int m = s1.size(), n = s2.size();
    cout << memoizedSol(s1, s2) << "\n";
    cout << lcsTab(s1, s2) << "\n";
    return 0;
}
