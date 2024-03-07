/**
 * Problem Link: https://www.codingninjas.com/studio/problems/can-you-make_4244510
 * 
 * Problem statement
 * You are given 2 non-empty strings 's1' and 's2' consisting of lowercase English alphabets only.
 * In one operation you can do either of the following on 's1':
 *      (1) Remove a character from any position in 's1'.
 *      (2) Add a character to any position in 's1'.
 * Find the minimum number of operations required to convert string 's1' into 's2'.
 * Example:
 *      Input: 's1' = "abcd", 's2' = "anc"  Output: 3
 * 
 * Explanation:
 * Here, 's1' = "abcd", 's2' = "anc".
 * In one operation remove 's1[3]', after this operation 's1' becomes "abc".    
 * In the second operation remove 's1[1]', after this operation 's1' becomes "ac".
 * In the third operation add 'n' in 's1[1]', after this operation 's1' becomes "anc".
 * 
 * Intuition:  Keep the longest common subsequence intact in the string s1 and insert/delete the other chars
 * for ex: 
 *      lcs in "abcd" and "anc" is "ac"
 *      other chars in "abcd" are 'b' and 'd', so remove 'b' and 'd' counts to 2 operations
 *      other chars in "anc" is 'n', add 'n' to s1 counts to 1 operation
 *      so s1 will become "anc" thereby counting 3 total operations
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


int minOperationsReqd(string &s1, string &s2) {
    int m = s1.length(), n = s2.length();
    int lengthOfLCP = lcs(s1, s2);
    int ans = (m - lengthOfLCP) + (n - lengthOfLCP);
    return ans;
}


int main() {

    string s1, s2;
    cout << "Enter two strings separated by space: \n";
    cin >> s1 >> s2;
    cout << "Min no. of Insertions/Deletions required to convert " << s1 << " to " << s2 << " is/are: "
         << minOperationsReqd(s1, s2) << endl;
    return 0;
}
