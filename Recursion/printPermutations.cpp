/**
 *  Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
 *  Example 1:
 *      Input: nums = [1,2,3] 
 *      Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 *  Problem link: https://leetcode.com/problems/permutations/description/
 * 
 *      Time complexity: n! * n
 *      Space Complexity: O(n) for map (solve()) and o(1) for solve2()
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std; 

void printVector(vector<int> &v) {
    
    for (int i = 0; i < v.size(); i++) 
        cout << v[i] << " ";
    cout << endl;
}


void solve(int size, int arr[], vector<int> &ds, unordered_map<int, int> &freq) {
    //Base case
    if (ds.size() == size) {
        printVector(ds);
        return;
    }
    for (int i = 0; i < size; i++) {
        if (!freq[arr[i]]) {
            freq[arr[i]] = 1;
            ds.push_back(arr[i]);
            solve(size, arr, ds, freq);
            ds.pop_back();
            freq[arr[i]] = 0;
        }
    }
}

// Approach 2 Space efficient uses swapping technique to generate permutations
void solve2(int ind, int size, int arr[]) {
    if (ind == size) {

        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    //Try all possible way for an index ind
    for (int i = ind; i < size; i++) {
        swap(arr[i], arr[ind]);
        solve2(ind + 1, size, arr);
        swap(arr[i], arr[ind]);
    }
}

int main()
{
    int arr[]={1, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> ds;
    unordered_map<int, int> freq;
    // solve(n, arr, ds, freq);
    solve2(0, n, arr);
    return 0; 
}
