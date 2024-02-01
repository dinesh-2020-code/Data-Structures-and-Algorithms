/**
 * Print All subsequences whose sum is K. 
 * 
 * For ex: arr = [1, 2, 1], K = 2
 *              Output: 2
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

int countSubsequencesWhoseSumisK(int ind, int sum, int k, int n, int arr[]) {
    //Base case
    if (ind == n) {
        if (sum == k)
            return 1;
        return 0;
    }

    //take or pick the current element
    sum += arr[ind];
    int left = countSubsequencesWhoseSumisK(ind + 1, sum, k, n, arr); 
    sum -= arr[ind];
    int right = countSubsequencesWhoseSumisK(ind + 1, sum, k, n, arr); // not pick the current element
    return left + right; 
}

int main()
{

    int arr[] = {1, 2, 1}; 
    int n = 3; 
    int k = 2;
    cout << countSubsequencesWhoseSumisK(0, 0, k, n, arr) << "\n";

    return 0; 
}