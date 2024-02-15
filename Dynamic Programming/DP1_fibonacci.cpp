/**
 * Dynamic Programming: 
 *      Two ways.   
 *          1. Memoization: Top Down -> tend to store the value of sub-problems
 *       2. Tabulation: Bottom up approach -> Base case to the required ans
 *         Fibonacci Series: 
 *              recurrence relation: f(n) = f(n - 1) + f(n-2)
*/

#include <iostream>

using namespace std;

int fib(int n, int dp[]) {
    if (n <= 1)
        return 1;
    
    if (dp[n] != -1)
        return dp[n];
    
    dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
}

int fib_tab(int n) {
    int dp[n + 1];
    dp[0] = 0; dp[1] = 1; // write base case in the table
    
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int fib_space_optimization(int n) {
     //Time : O(n), space : O(1)
     int prev2 = 0, prev = 1;
     for (int i = 2; i <= n; i++) {
        int curr = prev + prev2;
        prev2 = prev;
        prev = curr;
     }
     return prev; 
}
int main() 
{
    int number; 
    cin >> number;
    int dp[number + 1];
    memset(dp, -1, sizeof(dp));
    cout << fib(number, dp); 
    return 0;
}

// Time: O(n)
// Space : O(n)