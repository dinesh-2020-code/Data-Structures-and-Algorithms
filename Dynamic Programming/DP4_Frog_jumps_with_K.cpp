/**
 * Problem Link: https://atcoder.jp/contests/dp/tasks/dp_b
 * Problem Statement
 * There are N stones, numbered 1,2,…,N. For each i (1 ≤ i ≤ N), the height of Stone i is h[i].
 * There is a frog who is initially on Stone 1. He will repeat the following action some number
 * of times to reach Stone N
 * 
 * If the frog is currently on Stone i, jump to one of the following: Stone i+1,i+2,…,i+K. 
 * Here, a cost of |h[i] − h[j]| is incurred, where j is the stone to land on.
 * Find the minimum possible total cost incurred before the frog reaches Stone N.
 * 
 * Constraints:  All values in input are integers.
 *              2 ≤ N ≤ 10^5
 *              1 ≤ K ≤ 100
 *              1 ≤ h[i] ≤ 10^4
 * 
 * Sample Input 1: 
 *      5 3 // N K
 *      10 30 40 50 20 //h[i]s
 * Sample output 1 
 *      30
 *      If we follow the path 1 -> 2 -> 5, the total cost incurred would be |10 - 30| + |30 - 20| = 30
 * 
 * Sample Input 2: 
 *      10 4
 *      40 10 20 70 80 10 20 70 80 60
 * Sample Output 2:
 *      40  If we follow the path 1 -> 4 -> 8 -> 10,the total cost incurred would be ∣40−70∣+∣70−70∣+∣70−60∣=40.

*/

#include <iostream>
#include <vector>

using namespace std; 

//Memoization
int frogJumpsWithK(int ind, int k, int arr[], vector<int> &dp) {
    //base case
    if (ind == 0)
        return 0; 
    if (dp[ind] != -1)
        return dp[ind];

    int ans = INT_MAX;
    for (int i = 1; i <= k; i++) {
        if (ind - i >= 0) {
            int jumps = frogJumpsWithK(ind - i, k, arr, dp) + abs(arr[ind] - arr[ind - i]);
            ans = min(ans, jumps);
        }
    }
    return dp[ind] = ans; 

}


//Tabulation 
void frogJumpsWithKTab(int n, int k, int arr[]) {

    vector<int> dp(n, -1);
    dp[0] = 0; 
    for (int i = 1; i < n; i++) {
        int minSteps = INT_MAX;
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                int jumpEnergy = dp[i - j] + abs(arr[i] - arr[i-j]);
                minSteps = min(minSteps, jumpEnergy);
            }
        }
        dp[i] = minSteps;
    }

    cout << dp[n-1] << "\n";
}

int main () {

    int n = 10, k = 4;
    int arr[] = {40, 10, 20, 70, 80, 10, 20, 70, 80, 60};
    vector<int> dp(n + 1, -1);
    cout << frogJumpsWithK(n - 1, k, arr, dp) << "\n";
    frogJumpsWithKTab(n, k, arr);
    return 0; 
}

/*
    Time and space analysis
    Memoization: O(n * k) + O(n) (stack space), where k is the no. of steps that frog can take
    Recursive space memoization:  O(n) (memoization space)

    Tabulation: 
    Time : O(n * k) where k is the no. of steps that frog can take
    Aux SPace: O(n)

    ==> Space optimization : we would require array of k length which will store last k values
        when there will be new i , insert in the data structure and remote the first element of data structure (i - k - 1)th element u can remove
        data structure can be deque in which insertions and deletions can be possible from both ends

        In worst case, K = N, so in that case there would not be any space optimization possible. 
*/