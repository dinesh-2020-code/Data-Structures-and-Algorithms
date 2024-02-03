/**
 * Given an array of distinct integers arr and a target integer target, 
 * return a list of all unique combinations of candidates where the chosen
 * numbers sum to target. You may return the combinations in any order.
 * 
 *  I/p: arr[]={2, 3, 6, 7}; O/p: [2, 2, 3], [7]
 * 
 *  Problem Link: https://leetcode.com/problems/combination-sum/description/
*/

#include <iostream>
#include <vector>
using namespace std; 

void printVector(vector<int> &v) {
    
    for (int i = 0; i < v.size(); i++) 
        cout << v[i] << " ";
    cout << endl;
}
void solve(int ind, int size, int curr_sum, int arr[], vector<int> &ds) {

        //base case
        if (curr_sum < 0)
            return;
        if (ind >= size) {
            if (curr_sum == 0) {
                printVector(ds);
                return;
            }
            return;
        }

        ds.push_back(arr[ind]);
        solve(ind, size, curr_sum - arr[ind], arr, ds);
        ds.pop_back(); 
        solve(ind + 1, size, curr_sum, arr, ds);

    }

int main() 
{
    int arr[]={2, 3, 6, 7};
    int target = 7;
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> ds;
    solve(0, n, target, arr, ds);
    return 0; 
}