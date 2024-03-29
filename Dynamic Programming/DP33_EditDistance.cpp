/**
 * Problem: Edit Distance
 * Problem Statement:
 * Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
 * You have the following three operations permitted on a word:
 *      Insert a character
 *      Delete a character
 *      Replace a character
 * 
 * Input1: word1 = "horse", word2 = "ros"
 * Output: 3
 * Explanation: 
 *      horse -> rorse (replace 'h' with 'r')
 *      rorse -> rose (remove 'r')
 *      rose -> ros (remove 'e')
 * 
 * Input2: word1 = "intention", word2 = "execution"
 * Output: 5
 * Explanation: 
 *      intention -> inention (remove 't')
 *      inention -> enention (replace 'i' with 'e')
 *      enention -> exention (replace 'n' with 'x')
 *      exention -> exection (replace 'n' with 'c')
 *      exection -> execution (insert 'u')
 * 
*/

#include <iostream>
#include <vector>

using namespace std;


int editDistances (int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
    //Time complexity: O (m * n)
    //Aux Space: O (m * n) + O (m + n)

    //base cases
    // case 1: If string s1 got exhausted (i < 0)
    // min operations required to convert an empty string to some string s2[0..j] is j + 1
    if (i < 0)
        return j + 1;
    //case 2: If string s2 got exhausted (j < 0)
    // min operations required to convert string s1[0..i] to an empty string is i + 1 (u reqd to delete i + 1 chars from s1)
    if (j < 0)
        return i + 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    //recursive cases
    // case 1: if char at s1[i] and s2[j] matched
    if (s1[i] == s2[j])
        return dp[i][j] = 0 + editDistances(i - 1, j - 1, s1, s2, dp);
    else {    // case 2: chars not matching, we have 3 sub-operations (insert, delete, replace)
        int ins = 1 + editDistances(i, j - 1, s1, s2, dp);
        int del = 1 + editDistances(i - 1, j, s1, s2, dp);
        int rep = 1 + editDistances(i - 1, j - 1, s1, s2, dp);
        //returns min of all operations
        return dp[i][j] = min (ins, min (del, rep));
    }
}


int editDistancesTab (string &s1, string &s2) {
    //define dp table of m + 1 and n + 1 length
    //using 1-based indexing for strings
    int m = s1.length();
    int n = s2.length();
    vector <vector <int>> dp (m + 1, vector <int> (n + 1, 0));

    //write base cases in dp table
    // case1: string s1 exhausted (i == 0), 0 <= j <= n
    for (int j = 0; j <= n; j++) 
        dp[0][j] = j;
    
    //case2: string s2 exhausted (j == 0), 0 <= i <= m
    for (int i = 0; i <= m; i++)
        dp[i][0] = i;
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            // case1: if both chars are matching
            if (s1[i-1] == s2[j-1]) 
                dp[i][j] = dp[i-1][j-1];
            else {
                int ins = 1 + dp[i][j-1];
                int del = 1 + dp[i-1][j];
                int rep = 1 + dp[i-1][j-1];
                dp[i][j] = min (ins, min (del, rep));
            }
        }
    }
    return dp[m][n];
}


int editDistancesSO (string &s1, string &s2) {
    int m = s1.length();
    int n = s2.length();
    vector <int> prev (n + 1, 0), curr(n + 1, 0);

    // case1: string s1 exhausted (i == 0), 0 <= j <= n
    for (int j = 0; j <= n; j++) 
        prev[j] = j;
    
    for (int i = 1; i <= m; i++) {
        curr[0] = i;
        for (int j = 1; j <= n; j++) {
            // case1: if both chars are matching
            if (s1[i-1] == s2[j-1]) 
                curr[j] = prev[j-1];
            else {
                int ins = 1 + curr[j-1];
                int del = 1 + prev[j];
                int rep = 1 + prev[j-1];
                curr[j] = min (ins, min (del, rep));
            }
        }
        prev = curr;
    }
    return prev[n];
}


int memoisedSol(string &s1, string &s2) {

    int m = s1.size();
    int n = s2.size();

    vector<vector<int> > dp (m, vector<int> (n, -1));
    return editDistances(m - 1, n - 1, s1, s2, dp);
}


int main () {

    string s1, s2;
    cout << "Enter two strings separated by spaces\n";
    cin >> s1 >> s2;

    cout << "Min operations required to convert string '"<< s1 << "' to string '" << s2 << "' is: " << memoisedSol (s1, s2) << "\n";
    cout << "Min operations required to convert string '"<< s1 << "' to string '" << s2 << "' is: " << editDistancesTab (s1, s2) << "\n";
    cout << "Min operations required to convert string '"<< s1 << "' to string '" << s2 << "' is: " << editDistancesSO (s1, s2) << "\n";

    return 0;
}

