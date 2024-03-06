/**
 * 
 * Given two strings s1 and s2, you need to print the longest common subsequence of two strings.
 * 
 * for Ex: s1 = "abccd", s2 = "abd"
 * Output: "abd"
 * 
 * 
*/

#include <iostream>
#include <vector>


using namespace std;


void print2DVec (vector<vector<int>> &v) {
    int m = v.size();
    int n = v[0].size();

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) 
            cout << v[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
}


void printLCS (string &s1, string &s2) {

    // s1 = "abcde", s2 = bdgek
    int m = s1.length();  //ind1 (1..m)
    int n = s2.length();  //ind2 (1..n)

    vector<vector<int>> dp (m + 1, vector <int> (n + 1, 0));
    //fill base cases
    for (int ind2 = 0; ind2 <= n; ind2++)
        dp[0][ind2] = 0;
    
    for (int ind1 = 0; ind1 <= m; ind1++)
        dp[ind1][0] = 0;

    for (int ind1 = 1; ind1 <= m; ind1++) {
        for (int ind2 = 1; ind2 <= n; ind2++) {
            if (s1[ind1-1] == s2[ind2-1])
                dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
            else 
                dp[ind1][ind2] = max (dp[ind1-1][ind2], dp[ind1][ind2-1]);
        }
    }
    // print2DVec(dp);

    //constructs the LCS of length dp[m][n]
    //dp[m][n] = stores the length of LCS of string s1 and s2
    int len = dp[m][n];
    string ans = "";
    //initializing ans with dummy string 
    for (int i = 0; i < len; i++)
        ans += '$';

    int index = len - 1;
    int ind1 = m, ind2 = n;

    // O(m + n) Time for backtracking 
    while (ind1 > 0 && ind2 > 0) {
        if (s1[ind1-1] == s2[ind2-1]) {
            ans[index--] = s1[ind1-1];
            ind1--; ind2--;
        }
        else if ((dp[ind1-1][ind2] > dp[ind1][ind2-1])) 
            ind1--;
        else
            ind2--;
    }
    cout << ans << "\n";
}


int main() {

    string s1, s2; // s1 = "abcde", s2 = "bdgek"
    cout << "Enter two space separated strings: \n";
    cin >> s1 >> s2;
    printLCS(s1, s2);

    return 0;
}
