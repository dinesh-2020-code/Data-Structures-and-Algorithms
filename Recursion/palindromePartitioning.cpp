/**
 * Problem Link: https://leetcode.com/problems/palindrome-partitioning/description/
 * Statement:
 *      Given a string s, partition s such that every substring of the partition is a palindrome
 *      Return all possible palindrome partitioning of s.
 *          Example 1:
 *              Input: s = "aab"    Output: [["a","a","b"],["aa","b"]]
 * 
 * 
*/

#include <iostream>
#include <vector>

using namespace std;


bool isPalindrome(int start, int end, string s) {
    while (start <= end) {
        if (s[start++] != s[end--])
            return false;
    }
    return true;
}


void solve(int index, string s, vector<string> &path) {

    //base case
    if (index == s.size()) {
        //print path
        for (auto it : path) {
            cout << it << " " ; 
        }
        cout << "\n";
        return;
    }

    for (int i = index; i < s.size(); i++) {
        if (isPalindrome(index, i, s)) {
            path.push_back(s.substr(index, i - index + 1));
            solve(i + 1, s, path);
            path.pop_back();
        }
    }

}


int main() 
{
    string s = "aabb";
    vector<string> path; 
    solve(0, s, path);
    return 0;
}
