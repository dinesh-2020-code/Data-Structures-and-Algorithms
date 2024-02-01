/**
 * Print All subsequences. 
 * For an array of size n, we have atmost 2 ^ n subsequences. 
 * Subsequence: a contiguous or non-contiguous arrangement of elements by following order.
 * For ex: arr = [3, 1, 2], valid subsequences are: 
 *           [], [3], [1], [2], [3, 1], [3, 2], [1, 2], [3, 1, 2]
 * 
 * 
 *  Time complexity: O(2^n) as atmost for every place we have 2 options (either pick or not pick the current element)
 *  Aux space: O(n) as there will be atmost n recursive calls in recursive stack.
*/

#include <iostream>
#include <vector>
using namespace std;


void printVector(vector<int> v) {
    //This function prints the vector elements
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " "; 
    cout << endl; 
}

void printSubsequences(int ind, int n, int arr[], vector<int> &ds) {
    //Base case
    if (ind == n) {
        printVector(ds);
        return;
    }

    //take or pick the current element
    ds.push_back(arr[ind]);
    printSubsequences(ind + 1, n, arr, ds); 
    ds.pop_back(); 
    printSubsequences(ind + 1, n, arr, ds); // not pick the current element

}

int main()
{

    int arr[] = {3, 1, 2}; 
    int n = 3; 
    vector<int> ds; 
    printSubsequences(0, n, arr, ds);

    return 0; 
}