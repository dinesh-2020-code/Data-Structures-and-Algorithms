/**
 * 
 * Problem Link: Combination Sum II LeetCode https://leetcode.com/problems/combination-sum-ii/description/
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
void solve(int ind, int size, int curr_sum, int arr[], vector<int> &ds) {
    //base case
    if (curr_sum == 0) {
        printVector(ds);
        return;
    }

    for (int i = ind; i < size; i++) {
        if (i > ind && arr[i] == arr[i-1]) // if consecutive elements are same then don't pick. first time you pick the element
            continue;
        if (arr[i] > curr_sum)
            break;
        ds.push_back(arr[i]);
        solve(i + 1, size, curr_sum - arr[i], arr, ds);
        ds.pop_back();
    }

}

int main() 
{
    int arr[]={10,1,2,7,6,1,5}; int target = 8;
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr, arr + n);
    vector<int> ds;
    solve(0, n, target, arr, ds);
    return 0; 
}