/**
 * Problem Link: https://leetcode.com/problems/longest-ideal-subsequence/description/
 * You are given a string s consisting of lowercase letters and an integer k. We call a string t 
 * ideal if the following conditions are satisfied:
 *      t is a subsequence of the string s.
 *      The absolute difference in the alphabet order of every two adjacent letters in t is less 
 *      than or equal to k.
 * 
 * Return the length of the longest ideal string.
 * A subsequence is a string that can be derived from another string by deleting some or no characters
 * without changing the order of the remaining characters.
 * Note that the alphabet order is not cyclic. For example, the absolute difference in the alphabet order 
 * of 'a' and 'z' is 25, not 1.
 * 
 * Input: s = "acfgbd", k = 2       Output: 4
 * 
 * 
*/

#include <iostream>
#include <vector>

using namespace std;

int longestIdealString(string s, int k)
{
    int n = s.size();

    vector<int> dp(n, 1);
    // dp[i] length of Longest ideal subsequence ending at index i
    int result = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (abs(s[i] - s[j]) <= k)
            {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        result = max(result, dp[i]);
    }
    return result;
}


int main() {

    string s; cout << "Enter value for string ";
    cin>>s; 
    cout << "Enter value for k: ";
    int k; cin>>k; 

    cout << "Length of longest ideal subseq is " << longestIdealString(s, k) << endl;


    return 0;
}