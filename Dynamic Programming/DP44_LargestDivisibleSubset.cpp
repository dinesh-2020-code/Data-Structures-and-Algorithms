/**
 * Problem: Largest Divisible Subset
 * Problem statement
 * You are given an array of distinct numbers ‘arr’ of size 'n'.
 * Your task is to return the largest subset of numbers from ‘arr’, such that any pair of numbers ‘a’ 
 * and ‘b’ from the subset satisfies the following: a % b == 0 or b % a == 0.
 * A subset is nothing but any possible combination of the original array
 * 
 * Input: ‘arr’ = [1, 16, 7, 8, 4]
 * Output: [1, 4, 8, 16]
 * 
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int longestDivisibleSubset (vector<int> &arr) {
    int n = arr.size();
    vector<int> dp(n, 1), hash(n);
    int ans = 1;
    int lastIndex = 0;
    sort(arr.begin(), arr.end());
    for (int ind = 0; ind < n; ind++) {
        hash[ind] = ind;
        for (int prev = 0; prev < ind; prev++) {
            if (arr[ind] % arr[prev] == 0 && 1 + dp[prev] > dp[ind]) {
                dp[ind] = 1 + dp[prev];
                hash[ind] = prev;

            }
        }
        if (dp[ind] > ans) {
            ans = dp[ind]; 
            lastIndex = ind;
        }
    }
    vector<int> lis(ans);
    lis[0] = arr[lastIndex];
    int ind = 1;
    while (hash[lastIndex] != lastIndex) {
        lastIndex = hash[lastIndex];
        lis[ind++] = arr[lastIndex];
    }
    reverse(lis.begin(), lis.end());
    cout << "Largest Divisible subset is: \n";
    for (auto it : lis) 
        cout << it << " "; 
    cout << endl; 
    return ans;
}


int main() {

    vector<int> arr = {1, 16, 7, 8, 4};
    cout << "Length of largest Divisible subset:    " << longestDivisibleSubset(arr) << "\n";
    return 0;
}