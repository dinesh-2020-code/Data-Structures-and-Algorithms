/**
 * 
 * Problem Statement: Given an array nums of size n, return the majority element.
 * The majority element is the element that appears more than ⌊n / 2⌋ times.
 * 
 * Input: nums = [2,2,1,1,1,2,2]    Output: 2
 *    Constraints:
 *      n == nums.length
 *      1 <= n <= 5 * 10^4
 *      -10^9 <= nums[i] <= 10^9
 *      
 *  Simple brute force is to make use of two loops and check the count of each element -> O(n * n)
 *  Better Approach : Use hashMap of elements to store the count and freq as soon as freq > n/2, print element -> O(n) time and space
 *  Space optimization to O(1): Use Moore vote algo (MVA)
*/

#include <iostream>

using namespace std;

//Moore Vote algorithm
// Time Complexity: O(n) 
// Aux space: O(1)
int findMajorityElement(int arr[], int n) {

    int cnt = 0;
    int ele;
    for (int i = 0; i < n; i++) {
        if (cnt == 0) {
            cnt = 1;
            ele = arr[i];
        }
        else if (arr[i] == ele)
            cnt++;
        else 
            cnt--;
    }
    int cnt1 = 0 ;
    for (int i = 0; i < n; i++) {
        if (arr[i] == ele)
            cnt1++;
    }
    if (cnt1 > n / 2)
        return ele;
    return -1;
}

int main() 
{
    int arr[] = {2,2,1,1,1,2,2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << findMajorityElement(arr, n) << "\n";
    return 0;
}