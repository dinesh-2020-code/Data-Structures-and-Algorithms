/**
 *  Given an integer n, return the least number of perfect square numbers that sum to n.
 *  A perfect square is an integer that is the square of an integer; in other words,
 *  it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.
 * 
 *  Example 1: 
 * Input: n = 12
 * Output: 3
 * Explanation: 12 = 4 + 4 + 4.
 * 
 * Example 2:
 * Input: n = 13
 * Output: 2
 * Explanation: 13 = 4 + 9.
 * Constraints: 1 <= n <= 10^4
*/

#include <iostream>
#include <vector>
using namespace std;


int solve(int n, vector<int> &dp) {
    //Base case
    if (n == 0)
        return 0;

    if (dp[n] != -1)
        return dp[n];

    int ans = n;
    for (int i = 1; i * i <= n; i++) {
        ans = min(ans, 1 + solve(n - (i * i), dp));
    }  
    return dp[n] = ans;
}
int main() 
{
    int n = 43;
    vector<int> dp(n+1, -1);
    cout << solve(n, dp) << "\n";

    return 0; 
}

// Time Complexity: O(n * sqrt(n))
// Space complexity: O(n)