/**
 * Dynamic Programming: 
 *      Two ways.   
 *          1. Memoization: Top Down -> tend to store the value of sub-problems
 *       2. Tabulation: Bottom up approach
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
int main() 
{
    int number; 
    cin >> number;
    int dp[number + 1];
    memset(dp, -1, sizeof(dp));
    return 0;
}