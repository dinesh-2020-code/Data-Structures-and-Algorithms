/**
 * 
 * Problem: https://www.codingninjas.com/studio/problems/minimum-insertions-to-make-palindrome_985293
 * 
 * A  palindrome string is one that reads the same backward as well as forward.You are given a string 'str'.
 * Find the minimum number of characters needed to insert in 'str' to make it a palindromic string
 * 
 * Input: str = "abca", Output: 1 (If we insert the character ‘b’ after ‘c’, we get the string "abcba", 
 *                                  which is a palindromic string.)
 * 
 * str = "abcaa"    Output: 2
 * rev = "aacba"
 * 
 * Idea: Keep the longest palindromic string intact.
 *  here, "aaa" keep it intact, and the strings which is not matching, just put the reverse of it on other side to make it palindrome.
 * Min insertions required will be len(string) - len(longest palindromic subsequence)
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

int minInsertionsReqToMakePalindrome(string &s) {
    int lengthOfLongestPalindromicSubseq = longestPalindromicSubSequence(s);
    int totalLength = s.length();
    return totalLength - lengthOfLongestPalindromicSubseq;
}


int main() {

    string s1 = "abcaa";
    cout << "Min insertions reqd. to make '" << s1 << "' a palindromic string is: " 
        << minInsertionsReqToMakePalindrome(s1) << endl;

    return 0;
}
