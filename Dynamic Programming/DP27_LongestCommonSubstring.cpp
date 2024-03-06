/**
 * 
 * Problem: Longest common substring
 * s1 = "abcjklp", s2 = "acjkp" , output: 'cjk
 * 
 * 
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;


void longestCommonSubstring(string &s1, string &s2) {

    int m = s1.length();
    int n = s2.length();

    vector<vector<int>> dp (m + 1, vector <int> (n + 1, 0));
    for (int ind2 = 0; ind2 <= n; ind2++)
        dp[0][ind2] = 0;
    for (int ind1 = 0; ind1 <= m; ind1++) 
        dp[ind1][0] = 0;

    int ans = -1e9;
    for (int ind1 = 1; ind1 <= m; ind1++) {
        for (int ind2 = 1; ind2 <= n; ind2++) {
            if (s1[ind1-1] == s2[ind2-1]) {
                dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
                ans = max (ans, dp[ind1][ind2]);
            }
            else
                dp[ind1][ind2] = 0;
        }
    }

    cout << "Length of longest common substring " << ans << endl;

}


int main() {

    string s1, s2;
    cout << "Enter two strings separated by space: \n";
    cin >> s1 >> s2;

    longestCommonSubstring(s1, s2);

    return 0;
}

