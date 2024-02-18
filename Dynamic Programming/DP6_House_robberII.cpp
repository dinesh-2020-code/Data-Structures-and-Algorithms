/**
 * Problem Link: https://www.codingninjas.com/studio/problems/house-robber_839733
 * 
 * Problem statement
 * Mr. X is a professional robber planning to rob houses along a street. Each house has a certain
 * amount of money hidden.All houses along this street are arranged in a circle. That means the 
 * first house is the neighbour of the last one. Meanwhile, adjacent houses have a security system
 * connected, and it will automatically contact the police if two adjacent houses are broken into 
 * on the same night.You are given an array/list of non-negative integers 'ARR' representing the 
 * amount of money of each house. Your task is to return the maximum amount of money Mr. X can rob 
 * tonight without alerting the police.
 * Note: It is possible for Mr. X to rob the same amount of money by looting two different sets of
 * houses. Just print the maximum possible robbed amount, irrespective of sets of houses robbed.
 * 
 * Sample INput: 
 * 5 // no of houses
 * 1 5 1 2 6
 * 
 * Output: 11
 * 
 * Sample INput 2: 
 * 9
 * {1, 2, 3, 1, 3, 5, 8, 1, 9}
 * 
 * Output: 23
 * 
 * 
 */

#include <iostream>
#include <vector>

using namespace std;


int maxSumofNonAdacentElements(int n, vector<int> &arr) {
    
    // Space Optimization to O(1)
    int prev2 = arr[0]; 
    int prev = max(arr[0], arr[1]);

    for (int i = 2; i < n; i++) {
        int pick = arr[i] + prev2; 
        int notPick = prev;
        int curr = max(pick, notPick);
        prev2 = prev; 
        prev = curr; 
    }
    return prev; 
}


int main() {

    const int n = 9;
    int arr[] = {1, 2, 3, 1, 3, 5, 8, 1, 9};
    //here in this question 0 and n-1 houses are adjacent, so at a time we can either take 0th house and rest of the houses
    // or we can take (n-1)th house and the houses among the rest. and return max of case 1 and case2
    vector<int> temp1(arr, arr + n-1);
    vector<int> temp2(arr + 1, arr + n);
    for (int i = 0; i < n; i++) {
        if (i != n-1)
            temp1.push_back(arr[i]);
        if (i != 0) 
            temp2.push_back(arr[i]);
    }
    
    int case1 = maxSumofNonAdacentElements(n-1, temp1);
    int case2 = maxSumofNonAdacentElements(n-1, temp2); 

    cout << max(case1, case2) << "\n";


    return 0; 
}