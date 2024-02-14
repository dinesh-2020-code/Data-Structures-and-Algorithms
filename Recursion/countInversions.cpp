/**
 * Problem Link: https://www.codingninjas.com/studio/problems/number-of-inversions_6840276
 * Problem statement
 * There is an integer array ‘A’ of size ‘N’.
 * Number of inversions in an array can be defined as the number of pairs of ‘i’, ‘j’ such that ‘i’ < ‘j’ and ‘A[i]’ > ‘A[j]’.
 * You must return the number of inversions in the array.
 * For example,
 * Input: A = [5, 3, 2, 1, 4], N = 5
 * Output: 7
 * Explanation: The pairs satisfying the condition for inversion are (1, 2), (1, 3), (1, 4), (1, 5), (2, 3), (2, 4), and (3, 4). 
 * The number of inversions in the array is 7.
 * 
*/

#include <iostream>
#include <vector>

using namespace std;


void merge(int arr[], int low, int mid, int high, int &inversionCount) {
    //Merge two sorted arrays
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> temp(n, 0);

    int i = low, j = mid + 1, k = 0; 
    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else { // arr[i] > arr[j]
            temp[k++] = arr[j++];
            inversionCount += (mid - i + 1);
        }
    }

    //if elements of left array left
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    //if elements of right array left
    while (j <= high) {
        temp[k++] = arr[j++];
    }

    //copying temp to arr
    for (i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }

}


void mergeSort(int arr[], int low, int high, int &inversionCount) {
    if (low >= high) {
        return;
    }

    int mid = (low + high) / 2;
    mergeSort(arr, low, mid, inversionCount);
    mergeSort(arr, mid + 1, high, inversionCount);
    merge(arr, low, mid, high, inversionCount);
}


int main() 
{
    int arr[] = {5, 3, 2, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int inversionCount = 0;
    mergeSort(arr, 0,n-1, inversionCount);
    cout << "Inversion Count : " << inversionCount << "\n";
    return 0;
}