/**
 *  Given a list of N integers, print sums of all subsets in it. 
 *  Output should be printed in increasing order of sums.
 * 
 *  Brute Force: Generate all the possible subsets which uses Power set algo (uses 2^n * n). 
 * 
 *  Optimal Solution: Recursion
 *  2^n Time
 * 
*/

#include <iostream>
using namespace std;


void printSubsetSums(int ind, int arr[], int n, int sum) {
    
    if (ind == n)
    {
        cout << sum << " ";
        return;
    }
    //pick 
    sum += arr[ind];
    printSubsetSums(ind + 1, arr, n, sum);
    // do not take current element
    sum -= arr[ind];
    printSubsetSums(ind + 1, arr, n, sum);

}
int main() 
{
    int arr[] = {3, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    printSubsetSums(0, arr, n, 0);

    return 0;
}