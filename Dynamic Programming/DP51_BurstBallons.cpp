/**
 * Problem Link: https://leetcode.com/problems/burst-balloons/description/
 * Problem Statement:
 * You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it 
 * represented by an array nums. You are asked to burst all the balloons.If you burst the ith balloon, 
 * you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the 
 * array, then treat it as if there is a balloon with a 1 painted on it. Return the maximum coins you 
 * can collect by bursting the balloons wisely.
 * 
 * Input: nums = [3,1,5,8]      Output: 167
 * Explanation:
 * nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
 * coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
*/

#include <iostream>
#include <vector>

using namespace std;


int maxCoins(int i, int j, vector<int> &arr, vector<vector<int>> &dp) {
    if (i > j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int maxi = INT_MIN;
    for (int ind = i; ind <= j; ind++) {
        int cost = arr[i - 1] * arr[ind] * arr[j + 1]
                + maxCoins(i, ind - 1, arr, dp) + maxCoins(ind + 1, j, arr, dp);
        maxi = max(maxi, cost);
    }
    return dp[i][j] = maxi;
}

void printV(vector<vector<int>> &v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << "----------------------------------\n";
}

int maxCoinsTab(vector <int> arr) {

    int n = arr.size();
    arr.push_back(1);
    arr.insert(arr.begin(), 1);
    vector <vector <int> > dp (n + 2, vector<int> (n + 2, 0));

    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= n; j++) {
            if (i > j)
                continue;
            int maxi = INT_MIN;
            for (int ind = i; ind <= j; ind++) {
                int cost = arr[i - 1] * arr[ind] * arr[j + 1]
                        + dp[i][ind - 1] + dp[ind + 1][j];
                maxi = max(maxi, cost);
            }
            dp[i][j] = maxi;
            // printV(dp);
        }
    }
    return dp[1][n];
    // Time Complexity: O(N * N * N) ~ O(N^3)
    // Aux Space: O(N^2)
}


int memoSol (vector <int> arr) {
    int n = arr.size();
    arr.push_back(1);
    arr.insert(arr.begin(), 1);
    vector <vector <int> > dp (n + 1, vector<int> (n + 1, -1));
    return maxCoins(1, n, arr, dp);
}


int main() {

    vector<int> arr = {3, 1, 5, 8}; 
    cout << "Max Coins are: " << memoSol(arr) << "\n";
    cout << "Max Coins are: " << maxCoinsTab(arr) << "\n";
    return 0;
}
