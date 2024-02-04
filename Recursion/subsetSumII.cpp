/**
 * Problem Link: https://leetcode.com/problems/subsets-ii/description/
 * Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
 * The solution set must not contain duplicate subsets. Return the solution in any order.
 * 
 * Input: nums = [1,2,2]
 * Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
 * 
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void printVector(vector<int> &v) {
    
    for (int i = 0; i < v.size(); i++) 
        cout << v[i] << " ";
    cout << endl;
}


void printSubset(int ind, int arr[], int n, vector<int> &ds) {

    printVector(ds);
    for (int i = ind; i < n; i++) {
        if (i > ind && arr[i] == arr[i-1])
            continue;
        ds.push_back(arr[i]);
        printSubset(i + 1, arr, n, ds);
        ds.pop_back();            
    }
}

int main() 
{
    int arr[] = {1, 5, 2, 3, 3, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n);
    vector <int> ds;
    printSubset(0, arr, n, ds);

    return 0;
}