/**
 * Given a string s, return the number of palindromic substrings in it.
 * A string is a palindrome when it reads the same backward as forward.
 * A substring is a contiguous sequence of characters within the string.
 * Example 1:
 * Input: s = "abc"  Output: 3
 * Explanation: Three palindromic strings: "a", "b", "c".
 * Example 2:
 * Input: s = "aaa"  Output: 6 
 * Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 * Constraints: 
 *      1 <= s.length <= 1000
 *      s consists of lowercase English letters.
 * 
 * Problem Link: https://leetcode.com/problems/palindromic-substrings/description/?envType=daily-question&envId=2024-02-10
 * 
*/

#include <iostream>
#include <vector>
using namespace std;


int countSubstrings(string s) {
    // DP solution
    int n = s.length();
    int ans = 0;
    vector<vector<bool> > dp (n, vector<bool> (n, false));
    int gap = 0; // difference of start and end i.e., gap = end - start
    for (gap = 0; gap < n; gap++) {
        for (int i = 0, j = gap; j < n; j++, i++) {
            if (gap == 0) { // single character substring i.e., start and end point to same char
                dp[i][j] = true;
            }
            else if (gap == 1) { // string consists of two characters
                if (s[i] == s[j]) 
                    dp[i][j] = true;
                else 
                    dp[i][j] = false;
            }
            else { // for strings more than two chars, extreme chars must be same and string between extreme chars must be a palindrome.
                if (s[i] == s[j] && dp[i + 1][j - 1] == true) 
                    dp[i][j] = true;
                else 
                    dp[i][j] = false;
            }

            if (dp[i][j] == true) 
                ans++;
        }
    }
    return ans; 
}

int main() 
{
    string s = "abccbc";
    cout << countSubstrings(s);
    return 0; 
}

// Time Complexity: O(n * n)
// Aux. Space: O(n * n)