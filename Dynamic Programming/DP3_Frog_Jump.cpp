/**
 * Problem Link: https://www.codingninjas.com/studio/problems/frog-jump_3621012?source=youtube&campaign=striver_dp_videos
 * Problem Statement: 
 * There is a frog on the '1st' step of an 'N' stairs long staircase. The frog wants to reach the 'Nth' stair.
 * 'HEIGHT[i]' is the height of the '(i+1)th' stair.If Frog jumps from 'ith' to 'jth' stair, the energy lost in the jump is given by absolute value 
 * of ( HEIGHT[i-1] - HEIGHT[j-1] ). If the Frog is on 'ith' staircase, he can jump either to '(i+1)th' stair or to '(i+2)th' stair. 
 * Your task is to find the minimum total energy used by the frog to reach from '1st' stair to 'Nth' stair.
 * 
 * For Example
 * If the given ‘HEIGHT’ array is [10,20,30,10], the answer 20 as the frog can jump from 1st stair
 * to 2nd stair (|20-10| = 10 energy lost) and then
 * a jump from 2nd stair to last stair (|10-20| = 10
 * energy lost). So, the total energy lost is 20.
 * 
 * 
 *  Solution
 *      f(n-1) => min energy reqd to reach (n-1) from 0
 *     
 *      f(ind, a) {
 *         if ind is 0
 *              return 0
 * 
 *          if ind is 1
 *              return 1
 *          
 *          left = f(ind - 1) + abs(a[ind] - a[ind - 1])
 *          if ind > 1
 *              right = f(ind - 2) + abs(a[ind] - a[ind - 2])
 *  
 *          return min(left, right);
 *      }
*/

#include <iostream>
#include <vector>

using namespace std; 

int frogJumps(int ind, vector<int> &heights, vector<int> &dp) {

    if (ind == 0)
        return 0;

    if (dp[ind] != -1)
        return dp[ind];

    int left = frogJumps(ind - 1, heights, dp) + abs(heights[ind] - heights[ind - 1]);
    int right = INT_MAX;
    if (ind > 1)
        right = frogJumps(ind - 2, heights, dp) + abs(heights[ind] - heights[ind - 2]);

    return dp[ind] = min(left, right);
}

int frogJumpsTab(vector<int> &arr, vector<int> &dp) {
    dp[0] = 0;

    for (int i = 1; i < arr.size(); i++) {
        int left = dp[i - 1] + abs(arr[i] - arr[i - 1]);
        int right = INT_MAX;
        if (i > 1)
            right = dp[i - 2] + abs(arr[i] - arr[i - 2]);

        dp[i] = min(left, right);
    }

    return dp[arr.size() - 1];

}

int main() {
    
    int n = 4;
    vector <int> arr {10, 20, 30, 10};
    vector<int> dp(n + 1, -1); 
    // cout << frogJumps(n-1, arr, dp) << "\n";
    cout << frogJumpsTab(arr, dp);

    return 0; 
}
