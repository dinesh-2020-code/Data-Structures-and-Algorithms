/**
 * Problem Link: https://www.codingninjas.com/studio/problems/wildcard-pattern-matching_701650
 * Problem statement
 * Given a text and a wildcard pattern of size N and M respectively, implement a wildcard pattern
 * matching algorithm that finds if the wildcard pattern is matched with the text. The matching should 
 * cover the entire text not partial text.
 * 
 * The wildcard pattern can include the characters ‘?’ and ‘*’
 *  ‘?’ – matches any single character 
 *  ‘*’ – Matches any sequence of characters(sequence can be of length 0 or more)
 * 
 * Constraints:
 * 1 <= T <= 100
 * 1 <= N <= 200
 * 1 <= M <= 200
 * Where 'N' denotes the length of 'TEXT' and 'M' denotes the length of 'PATTERN'.
 * 'TEXT' and 'PATTERN' contain only lowercase letters and patterns may contain special characters ‘*’ and ‘?’
 * 
 * 3
 * '?ay'
 * ray
 * ab*cd
 * abdefcd
 * ab?d
 * abcc 
 * 
 * Output:
 * True
 * True
 * False
 * 
*/

#include <iostream>
#include <vector>

using namespace std;


bool wildcardMatching (int i, int j, string &patt, string &text, vector<vector<int>> &dp) {
   //base cases
   //if string 'patt' exhausted (i < 0) and string 'text' also got exhausted, return true
   if (i < 0 && j < 0)
      return true;
   //if string 'patt' exhausted and string 'text' doesn't get exhausted yet, return false
   if (i < 0 && j >= 0)
      return false;
   //if string 'text' got exhausted, the other string 'patt' must have all chars as '*'.
   if (j < 0 && i >= 0) {
      for (int k = 0; k <= i; k++)
         if (patt[k] != '*')
            return false;
      return true;
   }
   if (dp[i][j] != -1)
      return dp[i][j];

   //recursive cases
   // case1: If patt[i] == text[j] or patt[i] == '?'
   if (patt[i] == text[j] || patt[i] == '?')
      return dp[i][j] = wildcardMatching (i-1, j-1, patt, text, dp);
   
   // if patt[i] == '*', then take '*' as empty string f(i-1, j)
   // if patt[i] == '*', then keep taking the chars in 'text' f (i, j-1)
   else if (patt[i] == '*')
      return dp[i][j] = wildcardMatching(i-1, j, patt, text, dp)
                        | wildcardMatching(i, j-1, patt, text, dp);
   else
      return dp[i][j] = false;
}


bool wildcardMatchingTab(string &patt, string &text) {
   int m = patt.size();
   int n = text.size();
   vector<vector<bool>> dp (m + 1, vector <bool> (n + 1, false));
   //write base cases in dp table
   //case 1: i == 0 and j == 0
   dp[0][0] = true;

   //case 2: (i == 0 && j > 0)
   for (int j = 1; j <= n; j++)
      dp[0][j] = false;
   
   //case 3: (j == 0 && i > 0)
   for (int i = 1; i <= m; i++) { 
      bool flag = true;
      for (int k = 1; k <= i; k++) {
         if (patt[k - 1] != '*') {
            flag = false;
            break;
         }
      }
      dp[i][0] = flag;
   }

   for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
         if (patt[i-1] == text[j-1] || patt[i-1] == '?')
            dp[i][j] = dp[i-1][j-1];
         else if (patt[i-1] == '*')
            dp[i][j] = dp[i-1][j] || dp[i][j-1];
         else
            dp[i][j] = false;
      }
   }
   return dp[m][n];
}

bool memo(string pattern, string text) {
   int n = text.size();
   int m = pattern.size();
   vector<vector<int>> dp (m, vector <int> (n, -1));
   return wildcardMatching(m-1, n-1, pattern, text, dp);

}


int main() {

    string pattern; string text;
    cout << "Enter 'pattern' and 'text' strings separated by space: \n";
    cin >> pattern >> text;

    cout << memo(pattern, text) << endl;
    cout << wildcardMatchingTab(pattern, text) << "\n";
    return 0;
}
