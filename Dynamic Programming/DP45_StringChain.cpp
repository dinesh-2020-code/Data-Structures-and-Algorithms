/**
 * Problem Link:
 * https://www.codingninjas.com/studio/problems/longest-string-chain_3752111
 * Problem statement
 * You are given an array 'arr' of strings, where each string consists of English lowercase letters.
 * A string chain of 'arr' is defined as:
 * (1) A sequence of string formed using elements of 'arr'.
 * (2) Every string in the sequence can be formed by inserting a lowercase English letter into the
 * previous string (except the first string).
 * Find the length of the longest possible string chain of 'arr'.
 * 
 *  
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool cmp (string &s1, string &s2) {
    return s1.size() < s2.size();
}


bool checkPossible (string &s1, string &s2) {

    if (s1.size() != s2.size() + 1)
        return false;

    int first = 0; // points to s1 (bcda)
    int second = 0; // points to s2 (bcd)
    
    while (first < s1.size()) {
        if (second < s2.size() && s1[first] == s2[second])
        {
            first++;
            second++;
        }
        else {
            first++;
        }
    }
    if (first == s1.size() && second == s2.size())
        return true;
    return false;
}


int longestStringChain (vector<string> &arr) {

    int n = arr.size();
    sort(arr.begin(), arr.end(), cmp);  // sort on basis of length
    vector<int> dp(n, 1);
    int ans = 1;
    for (int ind = 0; ind < n; ind++) {
        for (int prev = 0; prev < ind; prev++) {
            if (checkPossible(arr[ind], arr[prev]) && 1 + dp[prev] > dp[ind]) 
                dp[ind] = 1 + dp[prev];
        }
        if (dp[ind] > ans) {
            ans = dp[ind]; 
        }
    }
    return ans;
}


int main() {

    vector<string> arr = {"a", "b", "ba", "bca", "bda", "bdca"};
    cout << "Length of longest string chain is " << longestStringChain(arr) << endl;

    return 0;
}
