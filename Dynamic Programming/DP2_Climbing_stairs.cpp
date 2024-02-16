/**
 * 
 * Problem Link: https://www.codingninjas.com/studio/problems/count-ways-to-reach-nth-stairs_798650?source=youtube&campaign=striver_dp_videos
 * 
 * Problem statement
 * You have been given a number of stairs. Initially, you are at the 0th stair, and you need to reach the Nth stair.
 * Each time, you can climb either one step or two steps.
 * You are supposed to return the number of distinct ways you can climb from the 0th step to the Nth step.
 * 
 * Example: n = 3
 * We can climb one step at a time i.e. {(0, 1) ,(1, 2),(2,3)} or we can climb the first two-step and then one step
 * i.e. {(0,2),(1, 3)} or we can climb first one step and then two step i.e. {(0,1), (1,3)}.
 * Constraints :
        1 <= 'T' <= 10
        0 <= 'N' <= 10^5
    print the output modulo 10^9 + 7


    How to understand whether it's a DP problem
        -> Count the total no. of ways
        -> Min/Max output
        -> Try all possible ways (count no, of ways, or best possible ways)

    Steps: 
        1. Try to represent the problem in terms of index
        2. Do all possible stuffs on that index acc to the problem statement
        3. Sum of all ways -> count all ways
            min of all stuffs -> finds min 

        f(n) -> no. of ways to reach from 0 to n
        
        f(ind) {
            if (ind == 0) 
                return 1 // we can't jump only one way

            if (ind == 1)
                return 1
            left = f(ind - 1)
            right = f(ind - 2)

            return left + right
        }
*/

#include <iostream>
#include <vector>

using namespace std;

int numOfWays(int n, vector<int> &dp) {
    if (n <= 1)
        return n;

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = numOfWays(n - 1, dp) + numOfWays(n - 2, dp);
    
}

int main() {
    int n; 
    cin >> n; 
    vector<int> dp(n + 1, -1);
    cout << numOfWays(n, dp);
    return 0; 
}